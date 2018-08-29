#include "DebuggerWindow.hpp"
#include "ui_debuggerwindow.h"

DebuggerWindow::DebuggerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DebuggerWindow)
{
    ui->setupUi(this);
}

DebuggerWindow::~DebuggerWindow()
{
    delete ui;
}
