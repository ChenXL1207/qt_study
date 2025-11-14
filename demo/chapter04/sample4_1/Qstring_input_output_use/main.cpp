#include "mainwindow.h"
#include "uipage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uipage w;
    // MainWindow w;
    w.show();
    return a.exec();
}
