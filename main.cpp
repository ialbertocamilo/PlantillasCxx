#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QMessageBox msg;
    msg.setText("hola mundo");
    msg.show();
    
    return a.exec();
}
