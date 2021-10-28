#include "ventanap.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
    w.setFixedSize(500,540);
    w.show();

    return a.exec();
}
