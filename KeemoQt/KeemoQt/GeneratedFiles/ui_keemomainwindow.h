/********************************************************************************
** Form generated from reading UI file 'keemomainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEEMOMAINWINDOW_H
#define UI_KEEMOMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeemoMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionRestart;
    QAction *actionShow_Window;
    QAction *actionHide_Window;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEmulaiton;
    QMenu *menuDebug;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KeemoMainWindow)
    {
        if (KeemoMainWindow->objectName().isEmpty())
            KeemoMainWindow->setObjectName(QStringLiteral("KeemoMainWindow"));
        KeemoMainWindow->resize(400, 300);
        actionOpen = new QAction(KeemoMainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(KeemoMainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionPlay = new QAction(KeemoMainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionPause = new QAction(KeemoMainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionStop = new QAction(KeemoMainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionRestart = new QAction(KeemoMainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionShow_Window = new QAction(KeemoMainWindow);
        actionShow_Window->setObjectName(QStringLiteral("actionShow_Window"));
        actionHide_Window = new QAction(KeemoMainWindow);
        actionHide_Window->setObjectName(QStringLiteral("actionHide_Window"));
        centralWidget = new QWidget(KeemoMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        KeemoMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KeemoMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEmulaiton = new QMenu(menuBar);
        menuEmulaiton->setObjectName(QStringLiteral("menuEmulaiton"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        KeemoMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KeemoMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KeemoMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KeemoMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KeemoMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEmulaiton->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuEmulaiton->addAction(actionPlay);
        menuEmulaiton->addAction(actionPause);
        menuEmulaiton->addAction(actionStop);
        menuEmulaiton->addAction(actionRestart);
        menuDebug->addAction(actionShow_Window);
        menuDebug->addAction(actionHide_Window);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionPause);

        retranslateUi(KeemoMainWindow);

        QMetaObject::connectSlotsByName(KeemoMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *KeemoMainWindow)
    {
        KeemoMainWindow->setWindowTitle(QApplication::translate("KeemoMainWindow", "Keemo - GB Emulator", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("KeemoMainWindow", "Open", Q_NULLPTR));
        actionClose->setText(QApplication::translate("KeemoMainWindow", "Close", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("KeemoMainWindow", "Play", Q_NULLPTR));
        actionPause->setText(QApplication::translate("KeemoMainWindow", "Pause", Q_NULLPTR));
        actionStop->setText(QApplication::translate("KeemoMainWindow", "Stop", Q_NULLPTR));
        actionRestart->setText(QApplication::translate("KeemoMainWindow", "Restart", Q_NULLPTR));
        actionShow_Window->setText(QApplication::translate("KeemoMainWindow", "Show Window", Q_NULLPTR));
        actionHide_Window->setText(QApplication::translate("KeemoMainWindow", "Hide Window", Q_NULLPTR));
        label->setText(QApplication::translate("KeemoMainWindow", "La la la", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("KeemoMainWindow", "File", Q_NULLPTR));
        menuEmulaiton->setTitle(QApplication::translate("KeemoMainWindow", "Emulation", Q_NULLPTR));
        menuDebug->setTitle(QApplication::translate("KeemoMainWindow", "Debug", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeemoMainWindow: public Ui_KeemoMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEEMOMAINWINDOW_H
