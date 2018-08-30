#pragma once
#ifndef KEEMOMAINWINDOW_HPP
#define KEEMOMAINWINDOW_HPP

#include <QMainWindow>
#include "DebuggerWindow.hpp"
#include "SDLWidget.h"

namespace Ui {
class KeemoMainWindow;
}

class KeemoMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //members

    //init dest
    explicit KeemoMainWindow(QWidget *parent = 0);
    ~KeemoMainWindow();

    // methods
    void closeDebugger();
    void createDebugger();
    void createRendererWidget();
    void destroyDebugger();
    void destroyRendererWidget();
    void showDebugger();

    // overrides

protected:
    // members
    QString filePath;

    //overrides
    void closeEvent(QCloseEvent *event);
    void moveEvent(QMoveEvent *event);

private slots:
    void on_actionOpen_triggered();

private:
    SDLWidget* renderer = Q_NULLPTR;
    DebuggerWindow* debugger =  Q_NULLPTR;
    Ui::KeemoMainWindow *ui;

};

#endif // KEEMOMAINWINDOW_HPP
