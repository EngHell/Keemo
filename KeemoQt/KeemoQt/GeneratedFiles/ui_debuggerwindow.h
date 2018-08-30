/********************************************************************************
** Form generated from reading UI file 'debuggerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGGERWINDOW_H
#define UI_DEBUGGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebuggerWindow
{
public:
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionNext_Step;
    QAction *actionStop;
    QAction *actionRestart;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_14;
    QLabel *label_8;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_8;
    QLabel *label_12;
    QLineEdit *lineEdit_11;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QLabel *label_10;
    QLineEdit *lineEdit_12;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_15;
    QLabel *label_15;
    QLabel *label_16;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DebuggerWindow)
    {
        if (DebuggerWindow->objectName().isEmpty())
            DebuggerWindow->setObjectName(QStringLiteral("DebuggerWindow"));
        DebuggerWindow->resize(467, 336);
        actionPlay = new QAction(DebuggerWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionPause = new QAction(DebuggerWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionNext_Step = new QAction(DebuggerWindow);
        actionNext_Step->setObjectName(QStringLiteral("actionNext_Step"));
        actionStop = new QAction(DebuggerWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionRestart = new QAction(DebuggerWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        centralwidget = new QWidget(DebuggerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 6, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 3, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 2, 8, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 4, 6, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 6, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 1, 11, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 3, 8, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 3, 9, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 2, 11, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 9, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 8, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 6, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 9, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 0, 11, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 9, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 3, 11, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 6, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 8, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 4, 2, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout->addWidget(lineEdit_14, 4, 8, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout_3->addWidget(lineEdit_15, 0, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_3->addWidget(textBrowser, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        DebuggerWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DebuggerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DebuggerWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(DebuggerWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        DebuggerWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionPlay);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionNext_Step);
        toolBar->addAction(actionStop);
        toolBar->addAction(actionRestart);

        retranslateUi(DebuggerWindow);

        QMetaObject::connectSlotsByName(DebuggerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DebuggerWindow)
    {
        DebuggerWindow->setWindowTitle(QApplication::translate("DebuggerWindow", "Debugger", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("DebuggerWindow", "Play", Q_NULLPTR));
        actionPause->setText(QApplication::translate("DebuggerWindow", "Pause", Q_NULLPTR));
        actionNext_Step->setText(QApplication::translate("DebuggerWindow", "Next Step", Q_NULLPTR));
        actionStop->setText(QApplication::translate("DebuggerWindow", "Stop", Q_NULLPTR));
        actionRestart->setText(QApplication::translate("DebuggerWindow", "Restart", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DebuggerWindow", "Registers", Q_NULLPTR));
        label_3->setText(QApplication::translate("DebuggerWindow", "B", Q_NULLPTR));
        label_4->setText(QApplication::translate("DebuggerWindow", "C", Q_NULLPTR));
        label_7->setText(QApplication::translate("DebuggerWindow", "H", Q_NULLPTR));
        label_14->setText(QApplication::translate("DebuggerWindow", "PC", Q_NULLPTR));
        label_8->setText(QApplication::translate("DebuggerWindow", "L", Q_NULLPTR));
        label_12->setText(QApplication::translate("DebuggerWindow", "HL", Q_NULLPTR));
        label_11->setText(QApplication::translate("DebuggerWindow", "DE", Q_NULLPTR));
        label_5->setText(QApplication::translate("DebuggerWindow", "D", Q_NULLPTR));
        label_6->setText(QApplication::translate("DebuggerWindow", "E", Q_NULLPTR));
        label_9->setText(QApplication::translate("DebuggerWindow", "AF", Q_NULLPTR));
        label_10->setText(QApplication::translate("DebuggerWindow", "BC", Q_NULLPTR));
        label->setText(QApplication::translate("DebuggerWindow", "A", Q_NULLPTR));
        label_2->setText(QApplication::translate("DebuggerWindow", "F", Q_NULLPTR));
        label_13->setText(QApplication::translate("DebuggerWindow", "SP", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DebuggerWindow", "OP Code", Q_NULLPTR));
        label_15->setText(QApplication::translate("DebuggerWindow", "Hex", Q_NULLPTR));
        label_16->setText(QApplication::translate("DebuggerWindow", "DissAssembly", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("DebuggerWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DebuggerWindow: public Ui_DebuggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGGERWINDOW_H
