#include "Views/OptoconBasicDevelopmentView.h"
#include "setlimitwindow.h"

OptoconBasicDevelopmentView::OptoconBasicDevelopmentView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent)
	: OptoconAbstractView(viewModel, cmdFactory, parent)
{
	ui.setupUi(this);

	// TODO: Move common initialization to abstract class and call here

	// Custom-Widget set-up
	/*ui.textEdit_A1 = new QTextEditCustom(ui.groupBox_2);
	ui.textEdit_A1->setObjectName(QStringLiteral("textEdit_A1"));
	ui.textEdit_A1->setGeometry(QRect(90, 10, 261, 91));
	ui.textEdit_A1->setReadOnly(true);*/
	
	// Initialize internal members:
	waveLengthButtons.push_back(ui.PB_850);
	waveLengthButtons.push_back(ui.PB_1300);
	waveLengthButtons.push_back(ui.PB_1310);
	waveLengthButtons.push_back(ui.PB_1550);
	waveLengthButtons.push_back(ui.PB_OFF);
	
	
	// Set up signal/slot connections
	QObject::connect(ui.btn_selectAll, SIGNAL(clicked()), this, SLOT(ViewAll()));
		
	QObject::connect(ui.checkBox_A1, SIGNAL(clicked()), this, SLOT(CheckedA1()));
	QObject::connect(ui.checkBox_A2, SIGNAL(clicked()), this, SLOT(CheckedA2()));
	QObject::connect(ui.checkBox_A3, SIGNAL(clicked()), this, SLOT(CheckedA3()));
	QObject::connect(ui.checkBox_A4, SIGNAL(clicked()), this, SLOT(CheckedA4()));
	
	// TODO: this should be put on as soon as clicked on texedit works!!
	/*QObject::connect(ui.textEdit_A1, SIGNAL(someSignal()), this, SLOT(onCheckedA1Clicked()));
	QObject::connect(ui.textEdit_A2, SIGNAL(clicked()), this, SLOT(onCheckedA2Clicked()));
	QObject::connect(ui.textEdit_A3, SIGNAL(clicked()), this, SLOT(onCheckedA3Clicked()));
	QObject::connect(ui.textEdit_A4, SIGNAL(clicked()), this, SLOT(onCheckedA4Clicked()));*/
	
	
	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
		
	QObject::connect(ui.PB_Set, SIGNAL(clicked()), this, SLOT(onBtnClick_SetLimit()));
	
	QObject::connect(ui.RB_MM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));
	//QObject::connect(ui.RB_SM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));
		
	QObject::connect(ui.PB_850, SIGNAL(clicked()), this, SLOT(onWaveLength850Clicked()));
	QObject::connect(ui.PB_1300, SIGNAL(clicked()), this, SLOT(onWaveLength1300Clicked()));
	QObject::connect(ui.PB_1310, SIGNAL(clicked()), this, SLOT(onWaveLength1310Clicked()));
	QObject::connect(ui.PB_1550, SIGNAL(clicked()), this, SLOT(onWaveLength1550Clicked()));
	QObject::connect(ui.PB_OFF, SIGNAL(clicked()), this, SLOT(onWaveLengthOFFClicked()));
	



	// SET BINDING (one way binding)
	QObject::connect(&viewModel, SIGNAL(waveLengthChanged(WaveLengthEnum)), this, SLOT(onWaveLengthChangedTest(WaveLengthEnum)));
	// QObject::connect(this, SIGNAL(waveLengthChanged(WaveLengthEnum)), viewModel.get(), SLOT(setActiveWaveLength(WaveLengthEnum))); // Not working
	//QObject::connect(ui.PB_1300, SIGNAL(clicked()), this, SLOT(onWaveLength1300Clicked()));




	// END BINDING



	//QObject::connect(this, &viewModel->waveLengthChanged, viewModel.get(), );
	
	/*QObject::connect(ui.PB_1310, SIGNAL(clicked()), this, SLOT(onWaveLength1310Clicked()));
	QObject::connect(ui.PB_1550, SIGNAL(clicked()), this, SLOT(onWaveLength1550Clicked()));
	QObject::connect(ui.PB_OFF, SIGNAL(clicked()), this, SLOT(onWaveLengthOFFClicked()));*/

	// Testing command buttons
	QObject::connect(ui.PB_execGUICmd, SIGNAL(clicked()), this, SLOT(onButtonExecGUICmdClicked()));



	// radio buttons

	QObject::connect(ui.PB_dB, SIGNAL(clicked()), this, SLOT(onReference_dBClicked()));
	QObject::connect(ui.PB_dBm, SIGNAL(clicked()), this, SLOT(onReference_dBMmClicked()));
	

	QMetaObject::connectSlotsByName(this);
}

OptoconBasicDevelopmentView::~OptoconBasicDevelopmentView()
{
}


// INSERTED

void OptoconBasicDevelopmentView::ViewAll()
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

	// Emit signals about checked check box state
	/*emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);*/

}

//void OptoconBasicDevelopmentView::CheckedA1()
//{
//	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
//}
//
//void OptoconBasicDevelopmentView::CheckedA2()
//{
//	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
//}
//
//void OptoconBasicDevelopmentView::CheckedA3()
//{
//	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
//}
//
//void OptoconBasicDevelopmentView::CheckedA4()
//{
//	// emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);
//
//	CheckedHandler(ui.checkBox_A4, ui.textEdit_A4);
//
//	// vs. directly call CheckedHandler
//}

void OptoconBasicDevelopmentView::onWaveLength850Clicked()
{
	// TODO: check whether already clicked

	//DisableWaveLengthButtons();
	//ui.PB_850->setChecked(true);

	//emit WaveLengthChanged(ui.PB_850);

	// QString* str = new QString("850");

	// emit CommandWaveLengthSent(QString("850"));

	// TODO: emit vs. directly call handler....

	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850, true);


}

void OptoconBasicDevelopmentView::onWaveLength1300Clicked()
{
	//DisableWaveLengthButtons();
	//ui.PB_1300->setChecked(true);
	
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1300, true);


	// TODO: checking binding....
	//emit viewModel->waveLengthChanged(WaveLengthEnum::WAVELENGTH_1300);
}

void OptoconBasicDevelopmentView::onWaveLength1310Clicked()
{
	//DisableWaveLengthButtons();
	//ui.PB_1310->setChecked(true);
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310, true);

	//emit viewModel->waveLengthChanged(WaveLengthEnum::WAVELENGTH_1310);
}

void OptoconBasicDevelopmentView::onWaveLength1550Clicked()
{
	//DisableWaveLengthButtons();
	//ui.PB_1550->setChecked(true);
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500, true);

	//emit viewModel->waveLengthChanged(WaveLengthEnum::WAVELENGTH_1500);
}

void OptoconBasicDevelopmentView::onWaveLengthOFFClicked()
{
	//DisableWaveLengthButtons();
	//ui.PB_OFF->setChecked(true);
	viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF, true);
	//emit viewModel->waveLengthChanged(WaveLengthEnum::WAVELENGTH_OFF);
}




// TODO: 
void OptoconBasicDevelopmentView::onReference_dBClicked()
{
	ui.PB_dB->setChecked(true);
	ui.PB_dBm->setChecked(false);
}

void OptoconBasicDevelopmentView::onReference_dBMmClicked()
{
	ui.PB_dB->setChecked(false);
	ui.PB_dBm->setChecked(true);
}

void OptoconBasicDevelopmentView::CheckLimit()
{
	// TODO: orint additional minus marks??
}

void OptoconBasicDevelopmentView::onNewLimitSet(QString newLimit)
{
	ui.textEdit_Limit->setText(newLimit);
}

void OptoconBasicDevelopmentView::onBtnClick_SetLimit()
{
	auto limitWindow = new SetLimitWindow(this);
	limitWindow->setWindowModality(Qt::ApplicationModal);
	limitWindow->show();

	/*auto *wdg = new QWidget;
	wdg->setWindowModality(Qt::ApplicationModal);
	wdg->show();*/
}

void OptoconBasicDevelopmentView::onRBStatusChanged(bool isChecked)
{
	//DisableWaveLengthButtons();
	if (isChecked)
	{
		viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310, true);
		//ui.PB_1310->setChecked(true);
	}
	else
	{
		viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850, true);
		//ui.PB_850->setChecked(true);
	}

	// TODO: Here we should emit signal that status has been changed (to disable the previous state)
}

void OptoconBasicDevelopmentView::onWaveLengthChangedTest(WaveLengthEnum newWaveLength)
{
	DisableWaveLengthButtons();

	switch (newWaveLength)
	{
	case WaveLengthEnum::WAVELENGTH_850:
		ui.PB_850->setChecked(true);
		//this->onWaveLength850Clicked();
		break;
	case WaveLengthEnum::WAVELENGTH_1300:
		ui.PB_1300->setChecked(true);
		//this->onWaveLength1300Clicked();
		break;
	case WaveLengthEnum::WAVELENGTH_1310:
		ui.PB_1310->setChecked(true);
		//this->onWaveLength1310Clicked();
		break;
	case WaveLengthEnum::WAVELENGTH_1500:
		ui.PB_1550->setChecked(true);
		//this->onWaveLength1550Clicked();
		break;
	case WaveLengthEnum::WAVELENGTH_OFF:
		ui.PB_OFF->setChecked(true);
		//this->onWaveLengthOFFClicked();
		break;
	}

}

void OptoconBasicDevelopmentView::onButtonExecGUICmdClicked()
{
	// Create and execute command
	auto cmd = commandFactory.CreateGUICommand();
	//cmd.setViewModel(viewModel);
	auto retVal = cmd->execute();


	// TODO: Should we call some method on viewModel which returns AbstractCommand type and that type then will be executed here?? 
	// vs. execute directly on viewModel...

}



//void OptoconBasicDevelopmentView::DisableWaveLengthButtons()
//{
//	for each (auto pb in waveLengthButtons)
//	{
//		pb->setChecked(false);
//	}
//}
