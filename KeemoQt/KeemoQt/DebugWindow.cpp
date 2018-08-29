#include "DebugWindow.hpp"
#include "ui_debugwindow.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{
    delete ui;
}
