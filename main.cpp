#include <QApplication>
#include "symulator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Symulator w;
    w.show();

    return a.exec();
}
