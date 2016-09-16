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

private:
	void InitializeConnections() override;

private slots: 
	void onCheckedA1Clicked(bool isChecked);
	void onCheckedA2Clicked(bool isChecked);
	void onCheckedA3Clicked(bool isChecked);
	void onCheckedA4Clicked(bool isChecked);

	void onWaveLength850Clicked();
	void onWaveLength1300Clicked();
	void onWaveLength1310Clicked();
	void onWaveLength1550Clicked();
	void onWaveLengthOFFClicked();
	void onReferencedBClicked();
	void onReferencedBMmClicked();	

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
	void OnSingleOrMultiModeChanged(bool isSm);
	void OnReferenceChanged(bool isDb);
	void OnCheckedLimitChanged(bool isChecked);
	void OnLimitValueChanged(double newLimitValue);
	void OnA1CheckedChanged(bool isChecked);
	void OnA2CheckedChanged(bool isChecked);
	void OnA3CheckedChanged(bool isChecked);
	void OnA4CheckedChanged(bool isChecked);

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
