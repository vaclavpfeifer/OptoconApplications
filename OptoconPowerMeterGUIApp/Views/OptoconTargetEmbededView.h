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
	/*void CheckedA1();	
	void CheckedA2();
	void CheckedA3();
	void CheckedA4();*/

	void CheckedA1(bool isChecked);
	void CheckedA2(bool isChecked);
	void CheckedA3(bool isChecked);
	void CheckedA4(bool isChecked);

	void onWaveLength850Clicked();
	void onWaveLength1300Clicked();
	void onWaveLength1310Clicked();
	void onWaveLength1550Clicked();
	void onWaveLengthOFFClicked();
	void onReference_dBClicked();
	void onReference_dBMmClicked();	

	void onCheckLimitClicked(bool isChecked);


	void onNewLimitSet(QString newLimit);
	void onBtnClick_SetLimit();
	void onRBStatusChanged(bool isChecked) ;
	
	void ViewAll();
	void onViewAllClicked(bool isChecked)
	{
		viewModel.setA1Checked(isChecked);
		viewModel.setA2Checked(isChecked);
		viewModel.setA3Checked(isChecked);
		viewModel.setA4Checked(isChecked);
	}



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

	void OnReferenceChanged(bool isDb)
	{		
		if (isDb)
		{
			ui.PB_dBm->setChecked(false);
			ui.PB_dB->setChecked(true);
		}
		else
		{
			ui.PB_dBm->setChecked(true);
			ui.PB_dB->setChecked(false);
		}

		// TODO - add some action when this value is changed
	}

	void OnCheckedLimitChanged(bool isChecked)
	{
		// TODO - add some action here
	}

	void OnLimitValueChanged(double newLimitValue)
	{
		ui.textEdit_Limit->setText(QString::number(newLimitValue));
	}

	void OnA1CheckedChanged(bool isChecked)
	{
		CheckedHandler(ui.checkBox_A1, ui.textEdit_A1, isChecked);
	}

	void OnA2CheckedChanged(bool isChecked)
	{
		CheckedHandler(ui.checkBox_A2, ui.textEdit_A2, isChecked);
	}

	void OnA3CheckedChanged(bool isChecked)
	{
		CheckedHandler(ui.checkBox_A3, ui.textEdit_A3, isChecked);
	}

	void OnA4CheckedChanged(bool isChecked)
	{
		CheckedHandler(ui.checkBox_A4, ui.textEdit_A4, isChecked);
	}


private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
