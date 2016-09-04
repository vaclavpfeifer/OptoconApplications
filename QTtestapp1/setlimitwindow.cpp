#include "ui_setlimitwindow.h"
#include "setlimitwindow.h"
#include <QPushButton>

//SetLimitWindow::SetLimitWindow(QWidget *parent) : QWidget(parent)
//{
//	ui.setupUi(this);	
//
//	QObject::connect(ui.btn_OKCancel, SIGNAL(clicked(QAbstractButton*)), this, SLOT(onDialogBoxClick(QAbstractButton*)));
//	
//	// TODO: find out how to set button action roles and then use those accept/reject signals
//	// QObject::connect(ui.btn_OKCancel, SIGNAL(accepted()), this, SLOT(onDialogBoxCancelClick()));
//
//
//	// Set-up parrent - child connection
//	QObject::connect(ui.btn_OKCancel, SIGNAL(LimitChanged(QString*)), parent, SLOT(textEdit_Limit(QString*)));
//
//	QMetaObject::connectSlotsByName(this);
//}

SetLimitWindow::SetLimitWindow(QObject* caller) : QWidget(nullptr) // There is no parrent and thus new window is rendered
{
	ui.setupUi(this);

	QObject::connect(ui.btn_OKCancel, SIGNAL(clicked(QAbstractButton*)), this, SLOT(onDialogBoxClick(QAbstractButton*)));

	// TODO: find out how to set button action roles and then use those accept/reject signals
	// QObject::connect(ui.btn_OKCancel, SIGNAL(accepted()), this, SLOT(onDialogBoxCancelClick()));


	// Set-up parrent - child connection
	QObject::connect(this, SIGNAL(LimitChanged(QString)), caller, SLOT(onNewLimitSet(QString)));

	QMetaObject::connectSlotsByName(this);
}

SetLimitWindow::~SetLimitWindow()
{

}

void SetLimitWindow::onDialogBoxClick(QAbstractButton* clickedBtn)
{	
	// TODO: add some form validations (to enable only valid number)

	if(clickedBtn->text() == "OK")
	{		
		QString str = ui.lineEdit->text();
		emit LimitChanged(str);
	}
	this->close();	
}

void SetLimitWindow::onDialogBoxCancelClick(QAbstractButton* btn)
{
	this->close();
}
