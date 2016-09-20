#ifndef OPTOCON_ABSTRACT_VIEW_H
#define OPTOCON_ABSTRACT_VIEW_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels/AbstractViewModel.h"
#include "Commands/AbstractCommandFactory.h"
#include "Commands/CommunicationCommand.h"
#include <vector>
#include "setlimitwindow.h"


class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

public:
	explicit OptoconAbstractView(AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);
	~OptoconAbstractView();

	virtual void InitializeConnections() = 0;

// Shared Methods
protected:
	void DisableWaveLengthButtons();
	static void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit, bool isChecked);
	virtual void InitializeCommonConnections();

// protected slots:
	virtual void OnReferenceChanged(bool isDb);
	virtual void onWaveLengthChanged(WaveLengthEnum newWaveLength);
	virtual void OnSingleOrMultiModeChanged(bool isSm) const;

protected:
	AbstractViewModel& viewModel;	
	std::vector<QPushButton*> waveLengthButtons;

	std::map<WaveLengthEnum, QPushButton*> waveLengthButtonsMap; // Move to reference_Counting objects?
	std::map<WidgetsCodeMap, QWidget*> allWidgetsCodeMap; // Or for specific widget type use specific map??
};



#endif
