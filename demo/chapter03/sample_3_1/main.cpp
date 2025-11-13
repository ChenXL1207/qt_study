#include "mainwindow.h"
#include "ui_page1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    ui_page1 w;
    w.show();
    return a.exec();
}
