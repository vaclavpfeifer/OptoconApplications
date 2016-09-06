#ifndef OPTOCON_TARGET_EMBEDED_VIEW_H
#define OPTOCON_TARGET_EMBEDED_VIEW_H

#include "Views\OptoconAbstractView.hpp"
#include "ui_OptoconTargetEmbededView.h"

class OptoconTargetEmbededView : public OptoconAbstractView
{
public:
	OptoconTargetEmbededView();
	virtual ~OptoconTargetEmbededView();

private: 
	// Inherited via OptoconAbstractView
	virtual void CheckedA1() override;
	virtual void CheckedA2() override;
	virtual void CheckedA3() override;
	virtual void CheckedA4() override;
	virtual void onWaveLength850Clicked() override;
	virtual void onWaveLength1300Clicked() override;
	virtual void onWaveLength1310Clicked() override;
	virtual void onWaveLength1550Clicked() override;
	virtual void onWaveLengthOFFClicked() override;
	virtual void onReference_dBClicked() override;
	virtual void onReference_dBMmClicked() override;	
	virtual void CheckLimit() override;
	virtual void onNewLimitSet(QString newLimit) override;
	virtual void onBtnClick_SetLimit() override;
	virtual void onRBStatusChanged(bool isChecked) override;
	virtual void ViewAll();

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
