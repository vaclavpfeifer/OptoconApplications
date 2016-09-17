#ifndef OPTOCON_BASIC_DEVELOPMENT_VIEW_H
#define OPTOCON_BASIC_DEVELOPMENT_VIEW_H

#include "ui_OptoconTargetEmbededView.h"
#include "Views/OptoconAbstractView.hpp"

class OptoconBasicDevelopmentView : public OptoconAbstractView
{	
	  Q_OBJECT

public:
	OptoconBasicDevelopmentView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);

	virtual ~OptoconBasicDevelopmentView();

	// Handlers
private:

	void ViewAll() ;
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
	
	Ui::MainWindowOptocon ui;
};

#endif
