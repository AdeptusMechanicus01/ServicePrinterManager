#include "widget.h"
#include<QFile>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile(":/stayl/dark.qss");
    if(styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qApp->setStyleSheet(styleFile.readAll());
        styleFile.close();
    }else{
        qDebug()<<"Ошибка загрузки стилей :"<<styleFile.errorString();
    }
    Widget w;
    w.show();
    return a.exec();
}
