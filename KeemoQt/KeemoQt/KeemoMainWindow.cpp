#include "KeemoMainWindow.hpp"
#include "ui_keemomainwindow.h"
#include <QFileDialog>

KeemoMainWindow::KeemoMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeemoMainWindow)
{
    ui->setupUi(this);
}

KeemoMainWindow::~KeemoMainWindow()
{
    destroyDebugger();
    delete ui;
}

void KeemoMainWindow::closeDebugger(){
    debugger->hide();
}

void KeemoMainWindow::createDebugger(){
    debugger = new DebuggerWindow();
}

void KeemoMainWindow::destroyDebugger(){
    if(debugger)
        delete debugger;
}

void KeemoMainWindow::showDebugger(){
    debugger->show();
}


void KeemoMainWindow::setName(const QString &name){
    ui->lineEdit->setText(name);
}

QString KeemoMainWindow::name() const {
    return ui->lineEdit->text();
}

//overrides
void KeemoMainWindow::closeEvent(QCloseEvent *event){
    QMainWindow::closeEvent(event);
    QApplication::quit();
}

// actions
void KeemoMainWindow::on_actionOpen_triggered()
{
    filePath = QFileDialog::getOpenFileName(
                this,
                tr("Open Image"),
                nullptr,
                tr("GB Roms (*.gb)")
                );
}
