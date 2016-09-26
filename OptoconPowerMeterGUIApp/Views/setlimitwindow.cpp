#include "ui_setlimitwindow.h"
#include "setlimitwindow.h"
#include <QPushButton>
#include "OptoconTargetEmbededView.h"

SetLimitWindow::SetLimitWindow(QObject* caller) : QWidget(nullptr) // There is no parrent and thus new window is rendered
{
	ui.setupUi(this);
	QObject::connect(ui.btn_OKCancel, &QDialogButtonBox::accepted, this, &SetLimitWindow::OnDialogBoxOKClicked);
	QObject::connect(ui.btn_OKCancel, &QDialogButtonBox::rejected, this, &SetLimitWindow::OnDialogBoxCancelClicked);
}

SetLimitWindow::~SetLimitWindow()
{
}

void SetLimitWindow::OnDialogBoxOKClicked()
{
	QString str = ui.lineEdit->text();
	emit LimitChanged(str);
	this->close();
}

void SetLimitWindow::OnDialogBoxCancelClicked()
{
	this->close();
}
