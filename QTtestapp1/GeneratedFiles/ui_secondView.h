/********************************************************************************
** Form generated from reading UI file 'secondView.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDVIEW_H
#define UI_SECONDVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_RemoveText;
    QComboBox *comboBox;
    QPushButton *quitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(746, 481);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 310, 541, 101));
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setGeometry(QRect(30, 20, 151, 81));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setGeometry(QRect(30, 110, 151, 81));
        btn_RemoveText = new QPushButton(centralwidget);
        btn_RemoveText->setObjectName(QStringLiteral("btn_RemoveText"));
        btn_RemoveText->setGeometry(QRect(30, 210, 151, 81));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(410, 270, 171, 31));
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(660, 10, 75, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 746, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btn_1->setText(QApplication::translate("MainWindow", "button_1", 0));
        btn_2->setText(QApplication::translate("MainWindow", "button_2", 0));
        btn_RemoveText->setText(QApplication::translate("MainWindow", "RemoveText", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDVIEW_H
