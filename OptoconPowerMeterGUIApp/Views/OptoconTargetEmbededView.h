#ifndef OPTOCON_TARGET_EMBEDED_VIEW_H
#define OPTOCON_TARGET_EMBEDED_VIEW_H

#include "Views\OptoconAbstractView.hpp"
#include "ui_OptoconTargetEmbededView.h"

class OptoconTargetEmbededView : public OptoconAbstractView
{
public:
	OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory);
	virtual ~OptoconTargetEmbededView();

private slots: 
	// Inherited via OptoconAbstractView
	virtual void CheckedA1() ;
	virtual void CheckedA2() ;
	virtual void CheckedA3() ;
	virtual void CheckedA4() ;
	virtual void onWaveLength850Clicked() ;
	virtual void onWaveLength1300Clicked() ;
	virtual void onWaveLength1310Clicked() ;
	virtual void onWaveLength1550Clicked() ;
	virtual void onWaveLengthOFFClicked() ;
	virtual void onReference_dBClicked() ;
	virtual void onReference_dBMmClicked() ;	
	virtual void CheckLimit() ;
	virtual void onNewLimitSet(QString newLimit) ;
	virtual void onBtnClick_SetLimit();
	virtual void onRBStatusChanged(bool isChecked) ;
	virtual void ViewAll();

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
