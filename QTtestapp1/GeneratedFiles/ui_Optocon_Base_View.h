/********************************************************************************
** Form generated from reading UI file 'Optocon_Base_View.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTOCON_BASE_VIEW_H
#define UI_OPTOCON_BASE_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowOptocon
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QTextEdit *textEdit_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_11;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QCheckBox *checkBox_3;
    QTextEdit *textEdit_5;
    QCheckBox *checkBox_4;
    QTextEdit *textEdit_6;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_12;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowOptocon)
    {
        if (MainWindowOptocon->objectName().isEmpty())
            MainWindowOptocon->setObjectName(QStringLiteral("MainWindowOptocon"));
        MainWindowOptocon->resize(969, 822);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowOptocon->sizePolicy().hasHeightForWidth());
        MainWindowOptocon->setSizePolicy(sizePolicy);
        MainWindowOptocon->setMouseTracking(false);
        MainWindowOptocon->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindowOptocon);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 211, 91));
        QFont font;
        font.setPointSize(30);
        pushButton->setFont(font);
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(540, 10, 81, 81));
        radioButton->setFont(font);
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(620, 10, 91, 81));
        radioButton_2->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(220, 0, 311, 91));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 100, 281, 81));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 100, 91, 81));
        pushButton_3->setFont(font);
        pushButton_3->setCheckable(true);
        pushButton_3->setFlat(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 280, 961, 501));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(470, 20, 151, 91));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(240, 20, 221, 91));
        checkBox->setFont(font);
        checkBox->setChecked(true);
        checkBox->setTristate(false);
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(640, 20, 111, 91));
        pushButton_11->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 140, 941, 361));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 10, 71, 91));
        checkBox_2->setFont(font);
        checkBox_2->setChecked(true);
        checkBox_2->setTristate(false);
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(90, 10, 261, 91));
        textEdit_4 = new QTextEdit(groupBox_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(90, 120, 261, 91));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 120, 71, 91));
        checkBox_3->setFont(font);
        checkBox_3->setChecked(true);
        checkBox_3->setTristate(false);
        textEdit_5 = new QTextEdit(groupBox_2);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(610, 10, 261, 91));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(530, 10, 71, 91));
        checkBox_4->setFont(font);
        checkBox_4->setChecked(true);
        checkBox_4->setTristate(false);
        textEdit_6 = new QTextEdit(groupBox_2);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(610, 120, 261, 91));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(530, 120, 71, 91));
        checkBox_5->setFont(font);
        checkBox_5->setChecked(true);
        checkBox_5->setTristate(false);
        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(310, 230, 281, 91));
        pushButton_12->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 190, 281, 81));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(390, 100, 91, 81));
        pushButton_5->setFont(font);
        pushButton_5->setCheckable(true);
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 100, 91, 81));
        pushButton_6->setFont(font);
        pushButton_6->setCheckable(true);
        pushButton_6->setChecked(true);
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(620, 100, 91, 81));
        pushButton_7->setFont(font);
        pushButton_7->setCheckable(true);
        pushButton_7->setFlat(true);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(730, 100, 91, 81));
        pushButton_8->setFont(font);
        pushButton_8->setCheckable(true);
        pushButton_8->setFlat(true);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(410, 180, 91, 81));
        pushButton_9->setFont(font);
        pushButton_9->setCheckable(true);
        pushButton_9->setFlat(true);
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(500, 180, 91, 81));
        pushButton_10->setFont(font);
        pushButton_10->setCheckable(true);
        pushButton_10->setChecked(true);
        pushButton_10->setFlat(true);
        MainWindowOptocon->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowOptocon);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 969, 21));
        MainWindowOptocon->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowOptocon);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowOptocon->setStatusBar(statusbar);

        retranslateUi(MainWindowOptocon);

        QMetaObject::connectSlotsByName(MainWindowOptocon);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowOptocon)
    {
        MainWindowOptocon->setWindowTitle(QApplication::translate("MainWindowOptocon", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindowOptocon", "S/N", 0));
        radioButton->setText(QApplication::translate("MainWindowOptocon", "SM", 0));
        radioButton_2->setText(QApplication::translate("MainWindowOptocon", "MM", 0));
        pushButton_2->setText(QApplication::translate("MainWindowOptocon", "wave length", 0));
        pushButton_3->setText(QApplication::translate("MainWindowOptocon", "850", 0));
        groupBox->setTitle(QApplication::translate("MainWindowOptocon", "Channels", 0));
        checkBox->setText(QApplication::translate("MainWindowOptocon", "check limit", 0));
        pushButton_11->setText(QApplication::translate("MainWindowOptocon", "SET", 0));
        groupBox_2->setTitle(QString());
        checkBox_2->setText(QApplication::translate("MainWindowOptocon", "A1", 0));
        checkBox_3->setText(QApplication::translate("MainWindowOptocon", "A2", 0));
        checkBox_4->setText(QApplication::translate("MainWindowOptocon", "A3", 0));
        checkBox_5->setText(QApplication::translate("MainWindowOptocon", "A4", 0));
        pushButton_12->setText(QApplication::translate("MainWindowOptocon", "select all", 0));
        pushButton_4->setText(QApplication::translate("MainWindowOptocon", "reference", 0));
        pushButton_5->setText(QApplication::translate("MainWindowOptocon", "1300", 0));
        pushButton_6->setText(QApplication::translate("MainWindowOptocon", "1310", 0));
        pushButton_7->setText(QApplication::translate("MainWindowOptocon", "1550", 0));
        pushButton_8->setText(QApplication::translate("MainWindowOptocon", "OFF", 0));
        pushButton_9->setText(QApplication::translate("MainWindowOptocon", "dB", 0));
        pushButton_10->setText(QApplication::translate("MainWindowOptocon", "dBm", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowOptocon: public Ui_MainWindowOptocon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTOCON_BASE_VIEW_H
