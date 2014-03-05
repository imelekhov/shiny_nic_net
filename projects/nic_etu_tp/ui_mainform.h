/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created: Fri Feb 21 17:58:19 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Config_lbl;
    QWidget *ConfWidget;
    QGridLayout *gridLayout;
    QLabel *conf_input_port_lbl;
    QLabel *conf_num_of_threads_lbl;
    QSpinBox *conf_num_of_threads_sb;
    QLabel *conf_output_port_lbl;
    QLineEdit *conf_ouput_port_le;
    QSpacerItem *horizontalSpacer;
    QLineEdit *conf_input_port_le;
    QTabWidget *InfoWidget;
    QWidget *Statistics;
    QGridLayout *gridLayout_3;
    QLineEdit *stat_transmit_data_le;
    QLabel *stat_num_of_users_lbl;
    QLineEdit *stat_num_of_users_le;
    QLabel *stat_transmit_data_lbl;
    QLineEdit *stat_receive_data_le;
    QSpacerItem *verticalSpacer;
    QLabel *stat_receive_data_lbl;
    QSpacerItem *horizontalSpacer_3;
    QWidget *Log;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *log_pte;
    QWidget *ControlButtonWidget;
    QGridLayout *gridLayout_2;
    QPushButton *clear_log_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pause_server_btn;
    QPushButton *start_server_btn;

    void setupUi(QWidget *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QString::fromUtf8("mainForm"));
        mainForm->resize(400, 474);
        verticalLayout = new QVBoxLayout(mainForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Config_lbl = new QLabel(mainForm);
        Config_lbl->setObjectName(QString::fromUtf8("Config_lbl"));

        verticalLayout->addWidget(Config_lbl);

        ConfWidget = new QWidget(mainForm);
        ConfWidget->setObjectName(QString::fromUtf8("ConfWidget"));
        gridLayout = new QGridLayout(ConfWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        conf_input_port_lbl = new QLabel(ConfWidget);
        conf_input_port_lbl->setObjectName(QString::fromUtf8("conf_input_port_lbl"));

        gridLayout->addWidget(conf_input_port_lbl, 1, 0, 1, 1);

        conf_num_of_threads_lbl = new QLabel(ConfWidget);
        conf_num_of_threads_lbl->setObjectName(QString::fromUtf8("conf_num_of_threads_lbl"));

        gridLayout->addWidget(conf_num_of_threads_lbl, 0, 0, 1, 1);

        conf_num_of_threads_sb = new QSpinBox(ConfWidget);
        conf_num_of_threads_sb->setObjectName(QString::fromUtf8("conf_num_of_threads_sb"));

        gridLayout->addWidget(conf_num_of_threads_sb, 0, 2, 1, 1);

        conf_output_port_lbl = new QLabel(ConfWidget);
        conf_output_port_lbl->setObjectName(QString::fromUtf8("conf_output_port_lbl"));

        gridLayout->addWidget(conf_output_port_lbl, 2, 0, 1, 1);

        conf_ouput_port_le = new QLineEdit(ConfWidget);
        conf_ouput_port_le->setObjectName(QString::fromUtf8("conf_ouput_port_le"));

        gridLayout->addWidget(conf_ouput_port_le, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        conf_input_port_le = new QLineEdit(ConfWidget);
        conf_input_port_le->setObjectName(QString::fromUtf8("conf_input_port_le"));

        gridLayout->addWidget(conf_input_port_le, 1, 2, 1, 1);


        verticalLayout->addWidget(ConfWidget);

        InfoWidget = new QTabWidget(mainForm);
        InfoWidget->setObjectName(QString::fromUtf8("InfoWidget"));
        Statistics = new QWidget();
        Statistics->setObjectName(QString::fromUtf8("Statistics"));
        gridLayout_3 = new QGridLayout(Statistics);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stat_transmit_data_le = new QLineEdit(Statistics);
        stat_transmit_data_le->setObjectName(QString::fromUtf8("stat_transmit_data_le"));
        stat_transmit_data_le->setReadOnly(true);

        gridLayout_3->addWidget(stat_transmit_data_le, 2, 2, 1, 1);

        stat_num_of_users_lbl = new QLabel(Statistics);
        stat_num_of_users_lbl->setObjectName(QString::fromUtf8("stat_num_of_users_lbl"));

        gridLayout_3->addWidget(stat_num_of_users_lbl, 0, 0, 1, 1);

        stat_num_of_users_le = new QLineEdit(Statistics);
        stat_num_of_users_le->setObjectName(QString::fromUtf8("stat_num_of_users_le"));
        stat_num_of_users_le->setReadOnly(true);

        gridLayout_3->addWidget(stat_num_of_users_le, 0, 2, 1, 1);

        stat_transmit_data_lbl = new QLabel(Statistics);
        stat_transmit_data_lbl->setObjectName(QString::fromUtf8("stat_transmit_data_lbl"));

        gridLayout_3->addWidget(stat_transmit_data_lbl, 2, 0, 1, 1);

        stat_receive_data_le = new QLineEdit(Statistics);
        stat_receive_data_le->setObjectName(QString::fromUtf8("stat_receive_data_le"));
        stat_receive_data_le->setReadOnly(true);

        gridLayout_3->addWidget(stat_receive_data_le, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 2, 1, 1);

        stat_receive_data_lbl = new QLabel(Statistics);
        stat_receive_data_lbl->setObjectName(QString::fromUtf8("stat_receive_data_lbl"));

        gridLayout_3->addWidget(stat_receive_data_lbl, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        InfoWidget->addTab(Statistics, QString());
        Log = new QWidget();
        Log->setObjectName(QString::fromUtf8("Log"));
        gridLayout_4 = new QGridLayout(Log);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        log_pte = new QPlainTextEdit(Log);
        log_pte->setObjectName(QString::fromUtf8("log_pte"));
        log_pte->setReadOnly(true);

        gridLayout_4->addWidget(log_pte, 0, 0, 1, 1);

        InfoWidget->addTab(Log, QString());

        verticalLayout->addWidget(InfoWidget);

        ControlButtonWidget = new QWidget(mainForm);
        ControlButtonWidget->setObjectName(QString::fromUtf8("ControlButtonWidget"));
        gridLayout_2 = new QGridLayout(ControlButtonWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        clear_log_btn = new QPushButton(ControlButtonWidget);
        clear_log_btn->setObjectName(QString::fromUtf8("clear_log_btn"));

        gridLayout_2->addWidget(clear_log_btn, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        pause_server_btn = new QPushButton(ControlButtonWidget);
        pause_server_btn->setObjectName(QString::fromUtf8("pause_server_btn"));

        gridLayout_2->addWidget(pause_server_btn, 0, 3, 1, 1);

        start_server_btn = new QPushButton(ControlButtonWidget);
        start_server_btn->setObjectName(QString::fromUtf8("start_server_btn"));

        gridLayout_2->addWidget(start_server_btn, 0, 2, 1, 1);


        verticalLayout->addWidget(ControlButtonWidget);

        QWidget::setTabOrder(conf_num_of_threads_sb, conf_input_port_le);
        QWidget::setTabOrder(conf_input_port_le, conf_ouput_port_le);
        QWidget::setTabOrder(conf_ouput_port_le, InfoWidget);
        QWidget::setTabOrder(InfoWidget, stat_num_of_users_le);
        QWidget::setTabOrder(stat_num_of_users_le, stat_receive_data_le);
        QWidget::setTabOrder(stat_receive_data_le, stat_transmit_data_le);
        QWidget::setTabOrder(stat_transmit_data_le, clear_log_btn);
        QWidget::setTabOrder(clear_log_btn, start_server_btn);
        QWidget::setTabOrder(start_server_btn, pause_server_btn);
        QWidget::setTabOrder(pause_server_btn, log_pte);

        retranslateUi(mainForm);

        InfoWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QWidget *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "nic server", 0, QApplication::UnicodeUTF8));
        Config_lbl->setText(QApplication::translate("mainForm", "Configuration:", 0, QApplication::UnicodeUTF8));
        conf_input_port_lbl->setText(QApplication::translate("mainForm", "Input port:", 0, QApplication::UnicodeUTF8));
        conf_num_of_threads_lbl->setText(QApplication::translate("mainForm", "Threads in pool:", 0, QApplication::UnicodeUTF8));
        conf_output_port_lbl->setText(QApplication::translate("mainForm", "Output port:", 0, QApplication::UnicodeUTF8));
        conf_ouput_port_le->setText(QApplication::translate("mainForm", "21018", 0, QApplication::UnicodeUTF8));
        conf_input_port_le->setText(QApplication::translate("mainForm", "21017", 0, QApplication::UnicodeUTF8));
        stat_transmit_data_le->setText(QString());
        stat_num_of_users_lbl->setText(QApplication::translate("mainForm", "Number of users:", 0, QApplication::UnicodeUTF8));
        stat_transmit_data_lbl->setText(QApplication::translate("mainForm", "Transmit data, B:", 0, QApplication::UnicodeUTF8));
        stat_receive_data_lbl->setText(QApplication::translate("mainForm", "Receive data, B:", 0, QApplication::UnicodeUTF8));
        InfoWidget->setTabText(InfoWidget->indexOf(Statistics), QApplication::translate("mainForm", "Statistics", 0, QApplication::UnicodeUTF8));
        InfoWidget->setTabText(InfoWidget->indexOf(Log), QApplication::translate("mainForm", "Log", 0, QApplication::UnicodeUTF8));
        clear_log_btn->setText(QApplication::translate("mainForm", "Clear Log", 0, QApplication::UnicodeUTF8));
        pause_server_btn->setText(QApplication::translate("mainForm", "Pause", 0, QApplication::UnicodeUTF8));
        start_server_btn->setText(QApplication::translate("mainForm", "Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
