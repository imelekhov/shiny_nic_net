#include <QApplication>
#include "nicserver.h"

#include "mainform.h"
//#include "thread_pool.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainForm main_form;
    main_form.show();

    return a.exec();
}
