#include "KeemoMainWindow.hpp"
#include "ui_keemomainwindow.h"
#include "../../KeemoLib/includes/Cartridge.hpp"
#include <QFileDialog>

KeemoMainWindow::KeemoMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::KeemoMainWindow)
{
	ui->setupUi(this);
    createRendererWidget();
}

KeemoMainWindow::~KeemoMainWindow()
{
	destroyDebugger();
    destroyRendererWidget();
	delete ui;
}

void KeemoMainWindow::closeDebugger(){
	debugger->hide();
}

void KeemoMainWindow::createDebugger(){
	debugger = new DebuggerWindow();
}

void KeemoMainWindow::createRendererWidget(){
    renderer = new SDLWidget(this->centralWidget());
}

void KeemoMainWindow::destroyDebugger(){
	if(debugger)
		delete debugger;
}

void KeemoMainWindow::destroyRendererWidget(){
    if(renderer)
        delete renderer;
}

void KeemoMainWindow::showDebugger(){
	debugger->show();
}

//overrides
void KeemoMainWindow::closeEvent(QCloseEvent *event){
	QMainWindow::closeEvent(event);
	QApplication::quit();
}

void KeemoMainWindow::moveEvent(QMoveEvent *event) {
    QPoint start = this->pos();
    QPoint offset{start.x() + this->width(), start.y()};

    if(debugger)
        debugger->move(offset);

    QMainWindow::moveEvent(event);
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

	if(!filePath.isEmpty())
	{
		if( KeemoLib::cartridge::loadCartridge(filePath.toLocal8Bit().constData()) )
		{
			QString title = QString::fromLocal8Bit(KeemoLib::cartridge::title.c_str());

			title += " - Keemo - GB Emulator";

			this->setWindowTitle(title);
		} 
		else
		{
			
		}

		
	}
}
