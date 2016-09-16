#include "OptoconTargetEmbededView.h"
#include "setlimitwindow.h"

OptoconTargetEmbededView::OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent) 
	: OptoconAbstractView(viewModel, cmdFactory, parent)
{
	ui.setupUi(this);

	// Initialize internal members:
	waveLengthButtons.push_back(ui.PB_850);
	waveLengthButtons.push_back(ui.PB_1300);
	waveLengthButtons.push_back(ui.PB_1310);
	waveLengthButtons.push_back(ui.PB_1550);
	waveLengthButtons.push_back(ui.PB_OFF);

	// TODO: Set either viewmodel or gui accordingly.




	// Set up signal/slot connections
	// QObject::connect(ui.btn_selectAll, SIGNAL(clicked()), this, SLOT(ViewAll()));
	QObject::connect(ui.btn_selectAll, SIGNAL(clicked(bool)), this, SLOT(onViewAllClicked(bool)));


	//QObject::connect(ui.checkBox_A1, SIGNAL(clicked()), this, SLOT(CheckedA1()));
	/*QObject::connect(ui.checkBox_A2, SIGNAL(clicked()), this, SLOT(CheckedA2()));
	QObject::connect(ui.checkBox_A3, SIGNAL(clicked()), this, SLOT(CheckedA3()));
	QObject::connect(ui.checkBox_A4, SIGNAL(clicked()), this, SLOT(CheckedA4()));*/
	
	QObject::connect(ui.checkBox_A1, SIGNAL(clicked(bool)), this, SLOT(CheckedA1(bool)));
	QObject::connect(ui.checkBox_A2, SIGNAL(clicked(bool)), this, SLOT(CheckedA2(bool)));
	QObject::connect(ui.checkBox_A3, SIGNAL(clicked(bool)), this, SLOT(CheckedA3(bool)));
	QObject::connect(ui.checkBox_A4, SIGNAL(clicked(bool)), this, SLOT(CheckedA4(bool)));

	QObject::connect(ui.PB_850, SIGNAL(clicked()), this, SLOT(onWaveLength850Clicked()));
	QObject::connect(ui.PB_1300, SIGNAL(clicked()), this, SLOT(onWaveLength1300Clicked()));
	QObject::connect(ui.PB_1310, SIGNAL(clicked()), this, SLOT(onWaveLength1310Clicked()));
	QObject::connect(ui.PB_1550, SIGNAL(clicked()), this, SLOT(onWaveLength1550Clicked()));
	QObject::connect(ui.PB_OFF, SIGNAL(clicked()), this, SLOT(onWaveLengthOFFClicked()));

	// radio buttons MM/SM
	QObject::connect(ui.RB_MM, SIGNAL(toggled(bool)), this, SLOT(OnSingleOrMultiModeTogled(bool)));

	// radio buttons dB/dBm (different approach)
	QObject::connect(ui.PB_dB, SIGNAL(clicked()), this, SLOT(onReference_dBClicked()));
	QObject::connect(ui.PB_dBm, SIGNAL(clicked()), this, SLOT(onReference_dBMmClicked()));

	// Checked Set Limit
	QObject::connect(ui.checkBox_CheckLimit, SIGNAL(clicked(bool)), this, SLOT(onCheckLimitClicked(bool)));

	QObject::connect(ui.PB_Set, SIGNAL(clicked()), this, SLOT(onBtnClick_SetLimit()));

	// SET BINDING (one way binding)
	QObject::connect(&viewModel, SIGNAL(waveLengthChanged(WaveLengthEnum)), this, SLOT(onWaveLengthChanged(WaveLengthEnum)));
	QObject::connect(&viewModel, SIGNAL(singleOrMultiModeChanged(bool)), this, SLOT(OnSingleOrMultiModeChanged(bool)));
	QObject::connect(&viewModel, SIGNAL(referenceChanged(bool)), this, SLOT(OnReferenceChanged(bool)));
	
	QObject::connect(&viewModel, SIGNAL(checkLimitChanged(bool)), this, SLOT(OnCheckedLimitChanged(bool)));
	QObject::connect(&viewModel, SIGNAL(limitChanged(double)), this, SLOT(OnLimitValueChanged(double)));


	QObject::connect(&viewModel, SIGNAL(checkA1Changed(bool)), this, SLOT(OnA1CheckedChanged(bool)));
	QObject::connect(&viewModel, SIGNAL(checkA2Changed(bool)), this, SLOT(OnA2CheckedChanged(bool)));
	QObject::connect(&viewModel, SIGNAL(checkA3Changed(bool)), this, SLOT(OnA3CheckedChanged(bool)));
	QObject::connect(&viewModel, SIGNAL(checkA4Changed(bool)), this, SLOT(OnA4CheckedChanged(bool)));
	// END BINDING

	QMetaObject::connectSlotsByName(this);
}


OptoconTargetEmbededView::~OptoconTargetEmbededView()
{
}

void OptoconTargetEmbededView::onWaveLengthChanged(WaveLengthEnum newWaveLength)
{
	DisableWaveLengthButtons();

	switch (newWaveLength)
	{
	case WaveLengthEnum::WAVELENGTH_850:
		// ui.PB_850->setChecked(true);
		waveLengthButtons[0]->setChecked(true);
		break;
	case WaveLengthEnum::WAVELENGTH_1300:
		// ui.PB_1300->setChecked(true);
		waveLengthButtons[1]->setChecked(true);
		break;
	case WaveLengthEnum::WAVELENGTH_1310:
		// ui.PB_1310->setChecked(true);
		waveLengthButtons[2]->setChecked(true);
		break;
	case WaveLengthEnum::WAVELENGTH_1500:
		// ui.PB_1550->setChecked(true);
		waveLengthButtons[3]->setChecked(true);
		break;
	case WaveLengthEnum::WAVELENGTH_OFF:
		// ui.PB_OFF->setChecked(true);
		waveLengthButtons[4]->setChecked(true);
		break;
	}

}

void OptoconTargetEmbededView::ViewAll()
{
	if (this->ui.btn_selectAll->isChecked())
	{
		this->ui.checkBox_A1->setCheckState(Qt::Checked);
		this->ui.checkBox_A2->setCheckState(Qt::Checked);
		this->ui.checkBox_A3->setCheckState(Qt::Checked);
		this->ui.checkBox_A4->setCheckState(Qt::Checked);
	}
	else
	{
		this->ui.checkBox_A1->setCheckState(Qt::Unchecked);
		this->ui.checkBox_A2->setCheckState(Qt::Unchecked);
		this->ui.checkBox_A3->setCheckState(Qt::Unchecked);
		this->ui.checkBox_A4->setCheckState(Qt::Unchecked);
	}

	// TODO: replace by changes in ViewModel 

	// Emit signals about checked check box state
	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);

}

void OptoconTargetEmbededView::CheckedA1(bool isChecked)
{
	viewModel.setA1Checked(isChecked);
}

void OptoconTargetEmbededView::CheckedA2(bool isChecked)
{
	viewModel.setA2Checked(isChecked);
}
void OptoconTargetEmbededView::CheckedA3(bool isChecked)
{
	viewModel.setA3Checked(isChecked);
}
void OptoconTargetEmbededView::CheckedA4(bool isChecked)
{
	viewModel.setA4Checked(isChecked);
}

//void OptoconTargetEmbededView::CheckedA1()
//{
//	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
//}
//
//void OptoconTargetEmbededView::CheckedA2()
//{
//	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
//}
//
//void OptoconTargetEmbededView::CheckedA3()
//{
//	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
//}
//
//void OptoconTargetEmbededView::CheckedA4()
//{
//	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);
//}

void OptoconTargetEmbededView::onWaveLength850Clicked()
{
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850);
}

void OptoconTargetEmbededView::onWaveLength1300Clicked()
{
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1300);
}

void OptoconTargetEmbededView::onWaveLength1310Clicked()
{
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310);
}

void OptoconTargetEmbededView::onWaveLength1550Clicked()
{
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500);
}

void OptoconTargetEmbededView::onWaveLengthOFFClicked()
{
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF);
}

void OptoconTargetEmbededView::onReference_dBClicked()
{
	viewModel.setReference(true);
}

void OptoconTargetEmbededView::onReference_dBMmClicked()
{
	viewModel.setReference(false);
}

//void OptoconTargetEmbededView::CheckedHandler(QCheckBox * checkedBox, QTextEdit * textEdit)
//{
//}

void OptoconTargetEmbededView::onCheckLimitClicked(bool isChecked)
{
	viewModel.setLimitChecked(isChecked);
}

void OptoconTargetEmbededView::onBtnClick_SetLimit()
{
	// Create new window
	auto limitWindow = new SetLimitWindow(this);
	limitWindow->setWindowModality(Qt::ApplicationModal);
	limitWindow->show();
}

void OptoconTargetEmbededView::onNewLimitSet(QString newLimit)
{
	viewModel.setLimitValue(newLimit.toDouble());
}

void OptoconTargetEmbededView::onRBStatusChanged(bool isChecked)
{
}


