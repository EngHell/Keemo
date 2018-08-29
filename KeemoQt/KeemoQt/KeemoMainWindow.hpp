#pragma once
#ifndef KEEMOMAINWINDOW_HPP
#define KEEMOMAINWINDOW_HPP

#include <QMainWindow>
#include "DebuggerWindow.hpp"

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
    void destroyDebugger();
    void showDebugger();
    void setName(const QString &name);
    QString name() const;

    // overrides

protected:
    // members
    QString filePath;

    //overrides
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actionOpen_triggered();

private:
    DebuggerWindow* debugger =  nullptr;
    Ui::KeemoMainWindow *ui;

};

#endif // KEEMOMAINWINDOW_HPP
