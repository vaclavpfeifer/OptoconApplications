#ifndef OPTOCON_TARGET_EMBEDED_VIEW_H
#define OPTOCON_TARGET_EMBEDED_VIEW_H

#include "Views\OptoconAbstractView.hpp"
#include "ui_OptoconTargetEmbededView.h"

class OptoconTargetEmbededView : public OptoconAbstractView
{
	Q_OBJECT

public:
	OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);
	virtual ~OptoconTargetEmbededView();

private slots: 
	// Inherited via OptoconAbstractView
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
	void onBtnClick_SetLimit();
	void onRBStatusChanged(bool isChecked) ;
	void ViewAll();

	void OnSingleOrMultiModeTogled(bool toggled)
	{
		// TODO: double check this value -- or check directly state of one and call accordingly
		viewModel.setSingleOrMultiMode(!toggled);
	}


	// Binding handlers (handlers raised in viewModel)
	void onWaveLengthChanged(WaveLengthEnum newWaveLength);
	void OnSingleOrMultiModeChanged(bool isSm)
	{
		if (!isSm)
		{
			viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310, true);			
		}
		else
		{
			viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850, true);			
		}
	}




private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
