#ifndef OPTOCON_BASIC_DEVELOPMENT_VIEW_H
#define OPTOCON_BASIC_DEVELOPMENT_VIEW_H

#include "ui_OptoconTargetEmbededView.h"
#include "Views/OptoconAbstractView.hpp"

class OptoconBasicDevelopmentView : public OptoconAbstractView
{	
	  Q_OBJECT // Must be here in order to signals work

public:
	OptoconBasicDevelopmentView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);

	virtual ~OptoconBasicDevelopmentView();

	// Handlers
private:

	void ViewAll() ;
	void CheckedA1() ;
	void CheckedA2() ;
	void CheckedA3() ;
	void CheckedA4() ;
	void onWaveLength850Clicked() ;
	void onWaveLength1300Clicked() ;
	void onWaveLength1310Clicked() ;
	void onWaveLength1550Clicked() ;
	void onWaveLengthOFFClicked() ;
	void onReference_dBClicked() ;
	void onReference_dBMmClicked() ;	
	void CheckLimit() ;
	void onNewLimitSet(QString newLimit) ;
	void onBtnClick_SetLimit() ;
	void onRBStatusChanged(bool isChecked) ;
	
	// binding 
	void onWaveLengthChangedTest(WaveLengthEnum newWaveLength);
	void onButtonExecGUICmdClicked();

	// Internal attributes
//private:
//	std::list<QPushButton*> waveLengthButtons;
//	void DisableWaveLengthButtons();
	
	Ui::MainWindowOptocon ui;
};

#endif
