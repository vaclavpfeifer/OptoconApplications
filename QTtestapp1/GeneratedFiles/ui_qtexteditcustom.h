/********************************************************************************
** Form generated from reading UI file 'qtexteditcustom.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEXTEDITCUSTOM_H
#define UI_QTEXTEDITCUSTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_QTextEditCustom
{
public:
    QPushButton *pushButton;

    void setupUi(QTextEdit *QTextEditCustom)
    {
        if (QTextEditCustom->objectName().isEmpty())
            QTextEditCustom->setObjectName(QStringLiteral("QTextEditCustom"));
        QTextEditCustom->resize(434, 113);
        pushButton = new QPushButton(QTextEditCustom);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(354, 82, 81, 31));

        retranslateUi(QTextEditCustom);

        QMetaObject::connectSlotsByName(QTextEditCustom);
    } // setupUi

    void retranslateUi(QTextEdit *QTextEditCustom)
    {
        QTextEditCustom->setWindowTitle(QApplication::translate("QTextEditCustom", "QTextEditCustom", 0));
        pushButton->setText(QApplication::translate("QTextEditCustom", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class QTextEditCustom: public Ui_QTextEditCustom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEXTEDITCUSTOM_H
