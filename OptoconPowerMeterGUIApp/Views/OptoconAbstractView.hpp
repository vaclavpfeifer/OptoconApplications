#ifndef OPTOCON_ABSTRACT_VIEW_H
#define OPTOCON_ABSTRACT_VIEW_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels\AbstractViewModel.h"
#include "Commands/AbstractCommandFactory.h"
#include "Commands\CommunicationCommand.h"
#include <vector>
// #include "CommonOptoconSignals.h"

// TODO: 


class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

// Constructors/Desstructors
public:
	// explicit OptoconAbstractView();

	explicit OptoconAbstractView(AbstractViewModel& viewModel, AbstractCommandFactory& cmdFactory, QWidget * parent = Q_NULLPTR);
	~OptoconAbstractView();

// Handlers
public slots:
	
	// TODO: here should goes common handlers for commands/ non-ui methods
	// TODO: Gui-related methods should be probably removed from here and just moved to concrete impl class
	
	virtual void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit); // THis should be removed whn updated in development view


signals:
	void CBStateChanged(QCheckBox* checkedBox, QTextEdit* textEdit);
	void WaveLengthChanged(QPushButton* clickedPB);

	// Cmd Signals
	void CommandWaveLengthSent(QString wl);

	// Shared Methods
protected:
	void DisableWaveLengthButtons();
	void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit, bool isChecked)
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


protected:
	AbstractViewModel& viewModel; // TODO: Move this to reference when started using!!!
	AbstractCommandFactory& commandFactory;

	std::vector<QPushButton*> waveLengthButtons;
};



#endif
