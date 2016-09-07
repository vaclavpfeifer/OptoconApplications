#ifndef OPTOCON_ABSTRACT_VIEW_H
#define OPTOCON_ABSTRACT_VIEW_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels\AbstractViewModel.h"
#include "Commands/AbstractCommandFactory.h"
#include "Commands\CommunicationCommand.h"

// TODO: 


class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

// Constructors/Desstructors
public:
	// explicit OptoconAbstractView();

	explicit OptoconAbstractView(AbstractViewModel* viewModel, AbstractCommandFactory& cmdFactory, QWidget * parent = Q_NULLPTR);
	~OptoconAbstractView();

// Handlers
public slots:
	
	// TODO: here should goes common handlers for commands/ non-ui methods
	// TODO: Gui-related methods should be probably removed from here and just moved to concrete impl class
	
	virtual void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit);

	// Cmd Handlers
	void onWaveLengthSent(QString waveLength) const
	{
		if (waveLength == "850")
		{
			auto cmd = commandFactory.CreateSerialIOCommand();
			auto retVal = cmd->execute();


			viewModel->setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500);

			// TODO: retVal of commands or command directly could infkluence just ViewModel and view could be updated through binding...

		}
	}



signals:
	void CBStateChanged(QCheckBox* checkedBox, QTextEdit* textEdit);
	void WaveLengthChanged(QPushButton* clickedPB);

	// Cmd Signals
	void CommandWaveLengthSent(QString wl);

protected:
	AbstractViewModel* viewModel; // TODO: Move this to reference when started using!!!
	AbstractCommandFactory& commandFactory;
};



#endif
