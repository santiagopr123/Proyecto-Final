#include "ventanap.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaP w;
    w.setFixedSize(1140,540);
    w.show();
    return a.exec();
}
