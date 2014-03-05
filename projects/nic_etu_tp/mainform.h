#pragma once

#include <QWidget>
#include <vector>

#include <ui_mainform.h>

#include "execution_config.h"
#include "server_state.h"
#include "nicserver.h"

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    void on_start_server_btn_clicked();
    void on_pause_server_btn_clicked();
    void on_clear_log_btn_clicked();
    //void on_terminate_server_btn_clicked();


public slots:
    void on_update_statistic(int received, int transmitted);
    void on_client_added(const QString& client);
    void on_client_removed(const QString& client);

private:
    ym::execution_config get_execution_config() const;
    void update_widgets_state(bool prev_state = false);

    QString create_state_window_title(ym::service_state::State state) const;

private:
    void show_error(const QString& message, QWidget* widget);
    void show_error(const QString& message);

    void write_log(const QString& message);



private:
    Ui::mainForm ui_;

    ym::service_state::State prev_state_;
    ym::NICServer *server_;

    bool is_stop_btn_pressed_;
    int num_of_clients_;
};
