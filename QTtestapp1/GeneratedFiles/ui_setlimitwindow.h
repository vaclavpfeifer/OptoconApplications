/********************************************************************************
** Form generated from reading UI file 'setlimitwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETLIMITWINDOW_H
#define UI_SETLIMITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetLimitWindow
{
public:
    QDialogButtonBox *btn_OKCancel;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *SetLimitWindow)
    {
        if (SetLimitWindow->objectName().isEmpty())
            SetLimitWindow->setObjectName(QStringLiteral("SetLimitWindow"));
        SetLimitWindow->resize(365, 133);
        btn_OKCancel = new QDialogButtonBox(SetLimitWindow);
        btn_OKCancel->setObjectName(QStringLiteral("btn_OKCancel"));
        btn_OKCancel->setGeometry(QRect(160, 80, 156, 23));
        QFont font;
        font.setPointSize(7);
        btn_OKCancel->setFont(font);
        btn_OKCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SetLimitWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 101, 21));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        lineEdit = new QLineEdit(SetLimitWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 20, 141, 41));
        QFont font2;
        font2.setPointSize(24);
        lineEdit->setFont(font2);

        retranslateUi(SetLimitWindow);

        QMetaObject::connectSlotsByName(SetLimitWindow);
    } // setupUi

    void retranslateUi(QWidget *SetLimitWindow)
    {
        SetLimitWindow->setWindowTitle(QApplication::translate("SetLimitWindow", "SetLimitWindow", 0));
        label->setText(QApplication::translate("SetLimitWindow", "New Limit", 0));
        lineEdit->setPlaceholderText(QApplication::translate("SetLimitWindow", "3.000", 0));
    } // retranslateUi

};

namespace Ui {
    class SetLimitWindow: public Ui_SetLimitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLIMITWINDOW_H
