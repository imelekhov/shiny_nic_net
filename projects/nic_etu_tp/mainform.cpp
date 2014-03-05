#include "mainform.h"
#include "excep.h"

#include <boost/thread.hpp>
#include <stdint.h>

#include <QMessageBox>
#include <QTime>
#include <QRegExpValidator>

#include <boost/optional.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
    , prev_state_(ym::service_state::Init)
    , server_(new ym::NICServer())
    , is_stop_btn_pressed_(false)
    , num_of_clients_(0)
{
    ui_.setupUi(this);

    uint16_t hardware_conc = boost::thread::hardware_concurrency();

    ui_.conf_num_of_threads_sb->setValue(hardware_conc);
    ui_.conf_num_of_threads_sb->setMinimum(1);

    QRegExp rx("[1-9]\\d{0,5}");
    ui_.conf_input_port_le->setValidator(new QRegExpValidator(rx));
    ui_.conf_ouput_port_le->setValidator(new QRegExpValidator(rx));

    connect(server_, SIGNAL(update_statistic(int,int)),
            this, SLOT(on_update_statistic(int,int)));

    connect(server_, SIGNAL(clientAdded(QString)),
            this, SLOT(on_client_added(QString)));

    connect(server_, SIGNAL(clientRemoved(QString)),
            this, SLOT(on_client_removed(QString)));

    update_widgets_state(true);
}

MainForm::~MainForm()
{
}

void MainForm::on_start_server_btn_clicked()
{

    boost::optional<ym::execution_config> service_config;

    try
    {
        service_config = get_execution_config();
    }
    catch (const ym::widget_error& err)
    {
        show_error(err.message(), err.widget());
    }
    catch (const ym::base_error& err)
    {
        show_error(err.message());
    }
    catch (const std::exception&)
    {
        show_error(tr("Unexpected configuration error"));
    }

    if (service_config)
    {
        // test
        /*
        uint16_t input_port = service_config->port_input;
        uint16_t output_port = service_config->port_output;
        uint16_t num_threads = service_config->thread_in_pool;
        */
        // start service!!! async_start
        server_->set_num_of_threads(service_config->thread_in_pool);
        server_->start(service_config->port_input,
                              service_config->port_output);

        QString log_msg;
        if (server_->state() == ym::service_state::Started)
            log_msg = tr("NIC started successfully");
        else if (server_->state() == ym::service_state::UDPfailed)
            log_msg = tr("Couldn't bind to UDP (receive) socket");
        else
            log_msg = tr("Couldn't start NIC server");

        write_log(log_msg);
    }

    // TODO: update widgets states!!!
    update_widgets_state();
}

void MainForm::on_pause_server_btn_clicked()
{
    if (!is_stop_btn_pressed_)
    {
        ui_.pause_server_btn->setText(tr("Resume"));
        server_->stop();
        write_log(tr("NIC server was stopped"));
        is_stop_btn_pressed_ = true;
    }
    else
    {
        ui_.pause_server_btn->setText(tr("Pause"));
        server_->resume();
        write_log(tr("NIC server was resumed"));
        is_stop_btn_pressed_ = false;
    }

    update_widgets_state();
}

/*
void MainForm::on_terminate_server_btn_clicked()
{
    is_stop_btn_pressed_ = false;
    ui_.pause_server_btn->setText(tr("Pause"));

    server_->terminate();
    write_log(tr("NIC server was terminated"));
    update_widgets_state();
}
*/

void MainForm::on_clear_log_btn_clicked()
{
    ui_.log_pte->clear();
}

void MainForm::on_update_statistic(int received, int transmitted)
{
    ui_.stat_receive_data_le->setText(QString::number(received));
    ui_.stat_transmit_data_le->setText(QString::number(transmitted));
}

void MainForm::on_client_added(const QString &client)
{
    write_log(tr("client ") + client + tr(" added"));
    num_of_clients_++;
    ui_.stat_num_of_users_le->setText(QString::number(num_of_clients_));
}

void MainForm::on_client_removed(const QString &client)
{
    write_log(tr("client ") + client + tr(" removed"));
    num_of_clients_--;
    ui_.stat_num_of_users_le->setText(QString::number(num_of_clients_));
}

ym::execution_config MainForm::get_execution_config() const
{

    uint16_t num_of_threads_in_pool;
    uint16_t port_input;
    uint16_t port_output;
    QWidget* crnt_widget;

    try
    {
        crnt_widget = ui_.conf_num_of_threads_sb;
        num_of_threads_in_pool = boost::numeric_cast<uint16_t>(ui_.conf_num_of_threads_sb->value());
        crnt_widget = ui_.conf_input_port_le;
        port_input  = boost::lexical_cast<uint16_t>(ui_.conf_input_port_le->text().toStdString());
        crnt_widget = ui_.conf_ouput_port_le;
        port_output = boost::lexical_cast<uint16_t>(ui_.conf_ouput_port_le->text().toStdString());
    }
    catch (const boost::numeric::bad_numeric_cast&)
    {
        boost::throw_exception(ym::widget_error(crnt_widget, tr("Invalid value")));
    }

    return ym::execution_config(num_of_threads_in_pool, port_input, port_output);
}

void MainForm::update_widgets_state(bool ignore_prev_state)
{
    const ym::service_state::State crnt_state = server_->state();
    if ((crnt_state != prev_state_) || ignore_prev_state)
    {
        bool is_server_init       = (ym::service_state::Init       == crnt_state);
        bool is_server_started    = (ym::service_state::Started    == crnt_state);
        bool is_server_stopped    = (ym::service_state::Stopped    == crnt_state);
        bool is_server_resumed    = (ym::service_state::Resumed    == crnt_state);

        if (is_server_init)
        {
            ui_.start_server_btn->setEnabled(true);
            ui_.pause_server_btn->setEnabled(false);
            ui_.ConfWidget->setEnabled(true);
        }
        if (is_server_stopped)
        {
            ui_.start_server_btn->setEnabled(false);
            ui_.pause_server_btn->setEnabled(is_stop_btn_pressed_);
            ui_.ConfWidget->setEnabled(false);
        }
        if (is_server_started || is_server_resumed)
        {
            ui_.start_server_btn->setEnabled(false);
            ui_.pause_server_btn->setEnabled(true);
            ui_.ConfWidget->setEnabled(false);
        }


        QString window_title = tr("NIC server");
        QString window_title_tail = create_state_window_title(crnt_state);
        if (!window_title_tail.isNull())
        {
            window_title = tr("%1 (%2)").arg(window_title).arg(window_title_tail);
        }
        setWindowTitle(window_title);
    }

    prev_state_ = crnt_state;

}

QString MainForm::create_state_window_title(ym::service_state::State state) const
{
    switch (state)
    {
    case ym::service_state::Stopped:
        return tr("paussed");
    case ym::service_state::Resumed:
        return tr("working");
    case ym::service_state::Started:
        return tr("starting");
    case ym::service_state::Init:
        return tr("init state");
    default:
        return tr("unknown state");
    }
}

void MainForm::show_error(const QString &message, QWidget *widget)
{
    if (widget)
    {
        widget->setFocus();
    }
    QMessageBox::critical(this, tr("Invalid server configuration"), message);
}

void MainForm::show_error(const QString &message)
{
    show_error(message, NULL);
}

void MainForm::write_log(const QString &message)
{
    const QString log_msg =
            tr("[%1] %2").arg(QTime::currentTime().toString(Qt::SystemLocaleLongDate)).arg(message);

    ui_.log_pte->appendPlainText(log_msg);
    ui_.log_pte->moveCursor(QTextCursor::End);
}
