#include <QCoreApplication>
#include "outnetferry.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    OutNetFerry *outNetFerry = new OutNetFerry();

    return a.exec();
}
