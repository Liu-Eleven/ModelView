#include "widget.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection() || !createXml()) return 0;

    Widget w;
    w.show();

    return a.exec();
}
