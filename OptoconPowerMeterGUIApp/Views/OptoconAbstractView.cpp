#include "qtexteditcustom.hpp"
#include "setlimitwindow.h"
#include "Views/OptoconBasicDevelopmentView.h"

OptoconAbstractView::OptoconAbstractView(AbstractViewModel* viewModel, AbstractCommandFactory& cmdFactory, QWidget * parent) : QMainWindow(parent),
																						   viewModel(viewModel),
																						   commandFactory(cmdFactory)
{
	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));

	// Cmd signal connect
	QObject::connect(this, SIGNAL(CommandWaveLengthSent(QString)), this, SLOT(onWaveLengthSent(QString)));
}


OptoconAbstractView::~OptoconAbstractView()
{
	
}

void OptoconAbstractView::CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit)
{
	if (checkedBox->isChecked())
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: yellow }");		
	}
	else
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: white }");
	}
}
