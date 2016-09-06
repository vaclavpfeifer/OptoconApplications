#include "qtexteditcustom.hpp"
#include "setlimitwindow.h"
#include "Views/OptoconBasicDevelopmentView.h"

OptoconAbstractView::OptoconAbstractView(AbstractViewModel* viewModel, QWidget * parent) : QMainWindow(parent)
{
	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));

}


OptoconAbstractView::~OptoconAbstractView()
{
	
}

void OptoconAbstractView::CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit)
{
	if (checkedBox->isChecked())
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: yellow }");

		// TODO: style sheets are not working for inherited widgets - cutom edits
		//textEdit->setStyleSheet("QTextEditCustom { background-color: yellow }");
	}
	else
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: white }");
	}
}
