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


void OptoconAbstractView::DisableWaveLengthButtons()
{
	// TODO: delete one of those when migrated all views to one option

	// For list 
    for (auto pb : waveLengthButtons)
	{
		pb->setChecked(false);
	}

	// for map
    for (auto pb : waveLengthButtonsMap)
	{
		pb.second->setChecked(false);
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
