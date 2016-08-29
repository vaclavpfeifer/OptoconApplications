/********************************************************************************
** Form generated from reading UI file 'qttestapp1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTESTAPP1_H
#define UI_QTTESTAPP1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTtestapp1Class
{
public:
    QAction *actionExit;
    QAction *actionOpen;
    QWidget *centralWidget;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_RemoveText;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QPushButton *quitButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTtestapp1Class)
    {
        if (QTtestapp1Class->objectName().isEmpty())
            QTtestapp1Class->setObjectName(QStringLiteral("QTtestapp1Class"));
        QTtestapp1Class->resize(1121, 343);
        actionExit = new QAction(QTtestapp1Class);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen = new QAction(QTtestapp1Class);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(QTtestapp1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_1 = new QPushButton(centralWidget);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        btn_1->setGeometry(QRect(30, 20, 151, 81));
        btn_2 = new QPushButton(centralWidget);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        btn_2->setGeometry(QRect(210, 20, 151, 81));
        btn_RemoveText = new QPushButton(centralWidget);
        btn_RemoveText->setObjectName(QStringLiteral("btn_RemoveText"));
        btn_RemoveText->setGeometry(QRect(380, 20, 151, 81));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 190, 1131, 101));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(560, 20, 171, 31));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(1040, 140, 75, 41));
        QTtestapp1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTtestapp1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1121, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        QTtestapp1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTtestapp1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTtestapp1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTtestapp1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTtestapp1Class->setStatusBar(statusBar);
        QWidget::setTabOrder(btn_1, btn_RemoveText);
        QWidget::setTabOrder(btn_RemoveText, textEdit);
        QWidget::setTabOrder(textEdit, comboBox);
        QWidget::setTabOrder(comboBox, btn_2);
        QWidget::setTabOrder(btn_2, quitButton);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(QTtestapp1Class);
        QObject::connect(btn_1, SIGNAL(clicked()), QTtestapp1Class, SLOT(close()));

        QMetaObject::connectSlotsByName(QTtestapp1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QTtestapp1Class)
    {
        QTtestapp1Class->setWindowTitle(QApplication::translate("QTtestapp1Class", "QTtestapp1", 0));
        actionExit->setText(QApplication::translate("QTtestapp1Class", "Exit", 0));
        actionOpen->setText(QApplication::translate("QTtestapp1Class", "Open", 0));
        btn_1->setText(QApplication::translate("QTtestapp1Class", "button_1", 0));
        btn_2->setText(QApplication::translate("QTtestapp1Class", "button_2", 0));
        btn_RemoveText->setText(QApplication::translate("QTtestapp1Class", "RemoveText", 0));
        quitButton->setText(QApplication::translate("QTtestapp1Class", "Quit", 0));
        menuFile->setTitle(QApplication::translate("QTtestapp1Class", "File", 0));
        menuAbout->setTitle(QApplication::translate("QTtestapp1Class", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class QTtestapp1Class: public Ui_QTtestapp1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTESTAPP1_H
