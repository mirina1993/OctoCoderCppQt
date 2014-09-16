#include <QtGui>
#include "MyTCP.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyServer server(2323);
    server.show();
    return a.exec();
}
