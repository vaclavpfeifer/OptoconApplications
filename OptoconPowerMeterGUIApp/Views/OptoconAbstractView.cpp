#include "qtexteditcustom.hpp"
#include "setlimitwindow.h"
#include "Views/OptoconBasicDevelopmentView.h"

OptoconAbstractView::OptoconAbstractView(AbstractViewModel& viewModel, AbstractCommandFactory& cmdFactory, QWidget * parent) : QMainWindow(parent),
																						   viewModel(viewModel),
																						   commandFactory(cmdFactory)
{
	// Put common signal/slot initialization here
	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
	

	// Call concrete initialization method
	// InitializeConnections();



	// Cmd signal connect
	// QObject::connect(this, SIGNAL(CommandWaveLengthSent(QString)), this, SLOT(onWaveLengthSent(QString)));


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

void OptoconAbstractView::DisableWaveLengthButtons()
{
	for each (auto pb in waveLengthButtons)
	{
		pb->setChecked(false);
	}
}

void OptoconAbstractView::CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit, bool isChecked)
{
	if (isChecked)
	{
		checkedBox->setChecked(true);
		textEdit->setStyleSheet("QTextEdit { background-color: yellow }");
	}
	else
	{
		checkedBox->setChecked(false);
		textEdit->setStyleSheet("QTextEdit { background-color: white }");
	}
}
