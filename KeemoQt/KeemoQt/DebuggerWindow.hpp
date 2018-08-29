#pragma once
#ifndef DEBUGGERWINDOW_HPP
#define DEBUGGERWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class DebuggerWindow;
}

class DebuggerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DebuggerWindow(QWidget *parent = 0);
    ~DebuggerWindow();

private:
    Ui::DebuggerWindow *ui;
};

#endif // DEBUGGERWINDOW_HPP
