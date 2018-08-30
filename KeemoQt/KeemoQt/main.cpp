#include "KeemoMainWindow.hpp"
#include "DebuggerWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeemoMainWindow w;

    // first we create the debugger
    w.createDebugger();

    // the we move the main window
    w.move(0,0);


    // then we show both
    w.show();
    w.showDebugger();
    QApplication::setActiveWindow(&w);

    return a.exec();
}
