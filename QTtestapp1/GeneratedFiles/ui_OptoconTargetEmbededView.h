/********************************************************************************
** Form generated from reading UI file 'OptoconTargetEmbededView.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTOCONTARGETEMBEDEDVIEW_H
#define UI_OPTOCONTARGETEMBEDEDVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptoconTargetLinuxView
{
public:
    QAction *actionRefresh_Connection;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RB_SM;
    QRadioButton *RB_MM;
    QGroupBox *groupBox;
    QTextEdit *textEdit_Limit;
    QCheckBox *checkBox_CheckLimit;
    QPushButton *PB_Set;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_A1;
    QTextEdit *textEdit_A1;
    QTextEdit *textEdit_A2;
    QCheckBox *checkBox_A2;
    QTextEdit *textEdit_A3;
    QCheckBox *checkBox_A3;
    QTextEdit *textEdit_A4;
    QCheckBox *checkBox_A4;
    QPushButton *btn_selectAll;
    QPushButton *pushButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *PB_850;
    QPushButton *PB_1300;
    QPushButton *PB_1310;
    QPushButton *PB_1550;
    QPushButton *PB_OFF;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_dB;
    QPushButton *PB_dBm;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuDevice;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OptoconTargetLinuxView)
    {
        if (OptoconTargetLinuxView->objectName().isEmpty())
            OptoconTargetLinuxView->setObjectName(QStringLiteral("OptoconTargetLinuxView"));
        OptoconTargetLinuxView->resize(800, 600);
        actionRefresh_Connection = new QAction(OptoconTargetLinuxView);
        actionRefresh_Connection->setObjectName(QStringLiteral("actionRefresh_Connection"));
        actionExit = new QAction(OptoconTargetLinuxView);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(OptoconTargetLinuxView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(630, 50, 181, 54));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RB_SM = new QRadioButton(layoutWidget);
        RB_SM->setObjectName(QStringLiteral("RB_SM"));
        QFont font;
        font.setPointSize(30);
        RB_SM->setFont(font);
        RB_SM->setChecked(true);

        horizontalLayout->addWidget(RB_SM);

        RB_MM = new QRadioButton(layoutWidget);
        RB_MM->setObjectName(QStringLiteral("RB_MM"));
        RB_MM->setFont(font);

        horizontalLayout->addWidget(RB_MM);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 320, 961, 501));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        textEdit_Limit = new QTextEdit(groupBox);
        textEdit_Limit->setObjectName(QStringLiteral("textEdit_Limit"));
        textEdit_Limit->setGeometry(QRect(470, 20, 151, 91));
        textEdit_Limit->setFont(font);
        textEdit_Limit->setReadOnly(true);
        checkBox_CheckLimit = new QCheckBox(groupBox);
        checkBox_CheckLimit->setObjectName(QStringLiteral("checkBox_CheckLimit"));
        checkBox_CheckLimit->setGeometry(QRect(240, 20, 221, 91));
        checkBox_CheckLimit->setFont(font);
        checkBox_CheckLimit->setChecked(true);
        checkBox_CheckLimit->setTristate(false);
        PB_Set = new QPushButton(groupBox);
        PB_Set->setObjectName(QStringLiteral("PB_Set"));
        PB_Set->setGeometry(QRect(640, 20, 111, 91));
        PB_Set->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 140, 941, 361));
        checkBox_A1 = new QCheckBox(groupBox_2);
        checkBox_A1->setObjectName(QStringLiteral("checkBox_A1"));
        checkBox_A1->setGeometry(QRect(10, 10, 71, 91));
        checkBox_A1->setFont(font);
        checkBox_A1->setChecked(false);
        checkBox_A1->setTristate(false);
        textEdit_A1 = new QTextEdit(groupBox_2);
        textEdit_A1->setObjectName(QStringLiteral("textEdit_A1"));
        textEdit_A1->setGeometry(QRect(90, 10, 261, 91));
        textEdit_A1->setReadOnly(true);
        textEdit_A2 = new QTextEdit(groupBox_2);
        textEdit_A2->setObjectName(QStringLiteral("textEdit_A2"));
        textEdit_A2->setGeometry(QRect(90, 120, 261, 91));
        textEdit_A2->setReadOnly(true);
        checkBox_A2 = new QCheckBox(groupBox_2);
        checkBox_A2->setObjectName(QStringLiteral("checkBox_A2"));
        checkBox_A2->setGeometry(QRect(10, 120, 71, 91));
        checkBox_A2->setFont(font);
        checkBox_A2->setChecked(false);
        checkBox_A2->setTristate(false);
        textEdit_A3 = new QTextEdit(groupBox_2);
        textEdit_A3->setObjectName(QStringLiteral("textEdit_A3"));
        textEdit_A3->setGeometry(QRect(610, 10, 261, 91));
        textEdit_A3->setReadOnly(true);
        checkBox_A3 = new QCheckBox(groupBox_2);
        checkBox_A3->setObjectName(QStringLiteral("checkBox_A3"));
        checkBox_A3->setGeometry(QRect(530, 10, 71, 91));
        checkBox_A3->setFont(font);
        checkBox_A3->setChecked(false);
        checkBox_A3->setTristate(false);
        textEdit_A4 = new QTextEdit(groupBox_2);
        textEdit_A4->setObjectName(QStringLiteral("textEdit_A4"));
        textEdit_A4->setGeometry(QRect(610, 120, 261, 91));
        textEdit_A4->setReadOnly(true);
        checkBox_A4 = new QCheckBox(groupBox_2);
        checkBox_A4->setObjectName(QStringLiteral("checkBox_A4"));
        checkBox_A4->setGeometry(QRect(530, 120, 71, 91));
        checkBox_A4->setFont(font);
        checkBox_A4->setChecked(false);
        checkBox_A4->setTristate(false);
        btn_selectAll = new QPushButton(groupBox_2);
        btn_selectAll->setObjectName(QStringLiteral("btn_selectAll"));
        btn_selectAll->setGeometry(QRect(310, 230, 281, 91));
        btn_selectAll->setFont(font);
        btn_selectAll->setCheckable(true);
        btn_selectAll->setChecked(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 40, 211, 91));
        pushButton->setFont(font);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(340, 150, 471, 58));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        PB_850 = new QPushButton(layoutWidget_2);
        PB_850->setObjectName(QStringLiteral("PB_850"));
        PB_850->setFont(font);
        PB_850->setCheckable(true);
        PB_850->setChecked(true);
        PB_850->setFlat(true);

        horizontalLayout_2->addWidget(PB_850);

        PB_1300 = new QPushButton(layoutWidget_2);
        PB_1300->setObjectName(QStringLiteral("PB_1300"));
        PB_1300->setFont(font);
        PB_1300->setCheckable(true);
        PB_1300->setFlat(true);

        horizontalLayout_2->addWidget(PB_1300);

        PB_1310 = new QPushButton(layoutWidget_2);
        PB_1310->setObjectName(QStringLiteral("PB_1310"));
        PB_1310->setFont(font);
        PB_1310->setCheckable(true);
        PB_1310->setChecked(false);
        PB_1310->setAutoDefault(false);
        PB_1310->setFlat(true);

        horizontalLayout_2->addWidget(PB_1310);

        PB_1550 = new QPushButton(layoutWidget_2);
        PB_1550->setObjectName(QStringLiteral("PB_1550"));
        PB_1550->setFont(font);
        PB_1550->setCheckable(true);
        PB_1550->setAutoDefault(true);
        PB_1550->setFlat(true);

        horizontalLayout_2->addWidget(PB_1550);

        PB_OFF = new QPushButton(layoutWidget_2);
        PB_OFF->setObjectName(QStringLiteral("PB_OFF"));
        PB_OFF->setFont(font);
        PB_OFF->setCheckable(true);
        PB_OFF->setFlat(true);

        horizontalLayout_2->addWidget(PB_OFF);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(460, 240, 171, 58));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        PB_dB = new QPushButton(layoutWidget_3);
        PB_dB->setObjectName(QStringLiteral("PB_dB"));
        PB_dB->setFont(font);
        PB_dB->setCheckable(true);
        PB_dB->setFlat(true);

        horizontalLayout_3->addWidget(PB_dB);

        PB_dBm = new QPushButton(layoutWidget_3);
        PB_dBm->setObjectName(QStringLiteral("PB_dBm"));
        PB_dBm->setFont(font);
        PB_dBm->setCheckable(true);
        PB_dBm->setChecked(true);
        PB_dBm->setFlat(true);

        horizontalLayout_3->addWidget(PB_dBm);

        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(270, 40, 311, 91));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 140, 281, 81));
        pushButton_2->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 230, 281, 81));
        pushButton_4->setFont(font);
        OptoconTargetLinuxView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OptoconTargetLinuxView);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuDevice = new QMenu(menubar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        OptoconTargetLinuxView->setMenuBar(menubar);
        statusbar = new QStatusBar(OptoconTargetLinuxView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        OptoconTargetLinuxView->setStatusBar(statusbar);

        menubar->addAction(menuDevice->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuDevice->addAction(actionRefresh_Connection);
        menuDevice->addSeparator();
        menuDevice->addAction(actionExit);

        retranslateUi(OptoconTargetLinuxView);

        QMetaObject::connectSlotsByName(OptoconTargetLinuxView);
    } // setupUi

    void retranslateUi(QMainWindow *OptoconTargetLinuxView)
    {
        OptoconTargetLinuxView->setWindowTitle(QApplication::translate("OptoconTargetLinuxView", "MainWindow", 0));
        actionRefresh_Connection->setText(QApplication::translate("OptoconTargetLinuxView", "Refresh Connection", 0));
        actionExit->setText(QApplication::translate("OptoconTargetLinuxView", "Exit", 0));
        RB_SM->setText(QApplication::translate("OptoconTargetLinuxView", "SM", 0));
        RB_MM->setText(QApplication::translate("OptoconTargetLinuxView", "MM", 0));
        groupBox->setTitle(QApplication::translate("OptoconTargetLinuxView", "Channels", 0));
        textEdit_Limit->setPlaceholderText(QApplication::translate("OptoconTargetLinuxView", "2.00", 0));
        checkBox_CheckLimit->setText(QApplication::translate("OptoconTargetLinuxView", "check limit", 0));
        PB_Set->setText(QApplication::translate("OptoconTargetLinuxView", "SET", 0));
        groupBox_2->setTitle(QString());
        checkBox_A1->setText(QApplication::translate("OptoconTargetLinuxView", "A1", 0));
        checkBox_A2->setText(QApplication::translate("OptoconTargetLinuxView", "A2", 0));
        checkBox_A3->setText(QApplication::translate("OptoconTargetLinuxView", "A3", 0));
        checkBox_A4->setText(QApplication::translate("OptoconTargetLinuxView", "A4", 0));
        btn_selectAll->setText(QApplication::translate("OptoconTargetLinuxView", "select all", 0));
        pushButton->setText(QApplication::translate("OptoconTargetLinuxView", "S/N", 0));
        PB_850->setText(QApplication::translate("OptoconTargetLinuxView", "850", 0));
        PB_1300->setText(QApplication::translate("OptoconTargetLinuxView", "1300", 0));
        PB_1310->setText(QApplication::translate("OptoconTargetLinuxView", "1310", 0));
        PB_1550->setText(QApplication::translate("OptoconTargetLinuxView", "1550", 0));
        PB_OFF->setText(QApplication::translate("OptoconTargetLinuxView", "OFF", 0));
        PB_dB->setText(QApplication::translate("OptoconTargetLinuxView", "dB", 0));
        PB_dBm->setText(QApplication::translate("OptoconTargetLinuxView", "dBm", 0));
        pushButton_2->setText(QApplication::translate("OptoconTargetLinuxView", "wave length", 0));
        pushButton_4->setText(QApplication::translate("OptoconTargetLinuxView", "reference", 0));
        menuDevice->setTitle(QApplication::translate("OptoconTargetLinuxView", "Device", 0));
        menuOptions->setTitle(QApplication::translate("OptoconTargetLinuxView", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class OptoconTargetLinuxView: public Ui_OptoconTargetLinuxView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTOCONTARGETEMBEDEDVIEW_H
