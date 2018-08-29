#include "KeemoMainWindow.hpp"
#include "DebuggerWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeemoMainWindow w;

    w.setName("lalalalal");
    w.show();

    w.createDebugger();
    w.showDebugger();

    return a.exec();
}
