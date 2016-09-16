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
	OptoconTargetEmbededView::InitializeConnections();
}


OptoconTargetEmbededView::~OptoconTargetEmbededView()
{	
}

void OptoconTargetEmbededView::InitializeConnections()
{
	// Set up signal/slot connections	
	QObject::connect(ui.btn_selectAll, SIGNAL(clicked(bool)), this, SLOT(onViewAllClicked(bool))); // in slot form

	QObject::connect(ui.checkBox_A1, &QPushButton::clicked, this, &OptoconTargetEmbededView::onCheckedA1Clicked); // in c++ 11 variadic form
	QObject::connect(ui.checkBox_A2, &QPushButton::clicked, this, &OptoconTargetEmbededView::onCheckedA2Clicked);
	QObject::connect(ui.checkBox_A3, &QPushButton::clicked, this, &OptoconTargetEmbededView::onCheckedA3Clicked);
	QObject::connect(ui.checkBox_A4, &QPushButton::clicked, this, &OptoconTargetEmbededView::onCheckedA4Clicked); 

	QObject::connect(ui.PB_850, &QPushButton::clicked, this, &OptoconTargetEmbededView::onWaveLength850Clicked);
	QObject::connect(ui.PB_1300, &QPushButton::clicked, this, &OptoconTargetEmbededView::onWaveLength1300Clicked);
	QObject::connect(ui.PB_1310, &QPushButton::clicked, this, &OptoconTargetEmbededView::onWaveLength1310Clicked);
	QObject::connect(ui.PB_1550, &QPushButton::clicked, this, &OptoconTargetEmbededView::onWaveLength1550Clicked);
	QObject::connect(ui.PB_OFF, &QPushButton::clicked, this, &OptoconTargetEmbededView::onWaveLengthOFFClicked);

	// radio buttons MM/SM
	QObject::connect(ui.RB_MM, SIGNAL(toggled(bool)), this, SLOT(OnSingleOrMultiModeTogled(bool)));

	// radio buttons dB/dBm (different approach)
	QObject::connect(ui.PB_dB, SIGNAL(clicked()), this, SLOT(onReferencedBClicked()));
	QObject::connect(ui.PB_dBm, SIGNAL(clicked()), this, SLOT(onReferencedBMmClicked()));

	// Checked Set Limit
	//QObject::connect(ui.checkBox_CheckLimit, SIGNAL(clicked(bool)), this, SLOT(onCheckLimitClicked(bool)));
	QObject::connect(ui.checkBox_CheckLimit, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setLimitChecked(isChecked); }); // Example of using lambdas


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
	// QObject::connect(&viewModel, SIGNAL(checkA4Changed(bool)), this, SLOT(OnA4CheckedChanged(bool)));
	QObject::connect(&viewModel, &AbstractViewModel::checkA4Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A4, ui.textEdit_A4, isChecked); }); // Example of using lambdas
																																							   // END BINDING

	QMetaObject::connectSlotsByName(this);

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

void OptoconTargetEmbededView::OnSingleOrMultiModeChanged(bool isSm)
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

void OptoconTargetEmbededView::OnReferenceChanged(bool isDb)
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

void OptoconTargetEmbededView::OnCheckedLimitChanged(bool isChecked)
{
	// TODO - add some action here
}

void OptoconTargetEmbededView::OnLimitValueChanged(double newLimitValue)
{
	ui.textEdit_Limit->setText(QString::number(newLimitValue));
}

void OptoconTargetEmbededView::OnA1CheckedChanged(bool isChecked)
{
	CheckedHandler(ui.checkBox_A1, ui.textEdit_A1, isChecked);
}

void OptoconTargetEmbededView::OnA2CheckedChanged(bool isChecked)
{
	CheckedHandler(ui.checkBox_A2, ui.textEdit_A2, isChecked);
}

void OptoconTargetEmbededView::OnA3CheckedChanged(bool isChecked)
{
	CheckedHandler(ui.checkBox_A3, ui.textEdit_A3, isChecked);
}

void OptoconTargetEmbededView::OnA4CheckedChanged(bool isChecked)
{
	CheckedHandler(ui.checkBox_A4, ui.textEdit_A4, isChecked);
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

void OptoconTargetEmbededView::onCheckedA1Clicked(bool isChecked)
{
	viewModel.setA1Checked(isChecked);
}

void OptoconTargetEmbededView::onCheckedA2Clicked(bool isChecked)
{
	viewModel.setA2Checked(isChecked);
}
void OptoconTargetEmbededView::onCheckedA3Clicked(bool isChecked)
{
	viewModel.setA3Checked(isChecked);
}
void OptoconTargetEmbededView::onCheckedA4Clicked(bool isChecked)
{
	viewModel.setA4Checked(isChecked);
}

//void OptoconTargetEmbededView::onCheckedA1Clicked()
//{
//	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
//}
//
//void OptoconTargetEmbededView::onCheckedA2Clicked()
//{
//	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
//}
//
//void OptoconTargetEmbededView::onCheckedA3Clicked()
//{
//	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
//}
//
//void OptoconTargetEmbededView::onCheckedA4Clicked()
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

void OptoconTargetEmbededView::onReferencedBClicked()
{
	viewModel.setReference(true);
}

void OptoconTargetEmbededView::onReferencedBMmClicked()
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


