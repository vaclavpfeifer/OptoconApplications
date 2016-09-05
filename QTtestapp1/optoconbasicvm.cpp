#include "optoconbasicvm.hpp"
#include "qtexteditcustom.hpp"

OptoconBasicVM::OptoconBasicVM(QWidget * parent) : QMainWindow(parent)
{
	// Default set-up (using UI)
	ui.setupUi(this);

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
	/*QObject::connect(ui.textEdit_A1, SIGNAL(someSignal()), this, SLOT(CheckedA1()));
	QObject::connect(ui.textEdit_A2, SIGNAL(clicked()), this, SLOT(CheckedA2()));
	QObject::connect(ui.textEdit_A3, SIGNAL(clicked()), this, SLOT(CheckedA3()));
	QObject::connect(ui.textEdit_A4, SIGNAL(clicked()), this, SLOT(CheckedA4()));*/


	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
	
	QObject::connect(ui.PB_Set, SIGNAL(clicked()), this, SLOT(onBtnClick_SetLimit()));

	QObject::connect(ui.RB_MM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));
	//QObject::connect(ui.RB_SM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));
	
	QObject::connect(ui.PB_850, SIGNAL(clicked()), this, SLOT(onWaveLength850Clicked()));
	QObject::connect(ui.PB_1300, SIGNAL(clicked()), this, SLOT(onWaveLength1300Clicked()));
	QObject::connect(ui.PB_1310, SIGNAL(clicked()), this, SLOT(onWaveLength1310Clicked()));
	QObject::connect(ui.PB_1550, SIGNAL(clicked()), this, SLOT(onWaveLength1550Clicked()));
	QObject::connect(ui.PB_OFF, SIGNAL(clicked()), this, SLOT(onWaveLengthOFFClicked()));

	QObject::connect(ui.PB_dB, SIGNAL(clicked()), this, SLOT(onReference_dBClicked()));
	QObject::connect(ui.PB_dBm, SIGNAL(clicked()), this, SLOT(onReference_dBMmClicked()));

	QMetaObject::connectSlotsByName(this);
}

OptoconBasicVM::OptoconBasicVM(AbstractViewModel* viewModel, int a) 
{
	OptoconBasicVM(nullptr);

}


OptoconBasicVM::~OptoconBasicVM() 
{
	
}

void OptoconBasicVM::ViewAll()
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
	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);

}

void OptoconBasicVM::CheckedA1()
{
	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
}

void OptoconBasicVM::CheckedA2()
{
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
}

void OptoconBasicVM::CheckedA3()
{
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
}

void OptoconBasicVM::CheckedA4()
{
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);
}

void OptoconBasicVM::CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit)
{
	if (checkedBox->isChecked())
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: yellow }");

		// TODO: style sheets are not working for inherited widgets - cutom edits
		//textEdit->setStyleSheet("QTextEditCustom { background-color: yellow }");
	}
	else
	{		
		textEdit->setStyleSheet("QTextEdit { background-color: white }");
	}
}

void OptoconBasicVM::CheckLimit()
{
	// TODO: orint additional minus marks??
}

void OptoconBasicVM::onNewLimitSet(QString newLimit) const
{
	ui.textEdit_Limit->setText(newLimit);
}

void OptoconBasicVM::onBtnClick_SetLimit()
{
	auto limitWindow = new SetLimitWindow(this);
	limitWindow->setWindowModality(Qt::ApplicationModal);
	limitWindow->show();

	/*auto *wdg = new QWidget;
	wdg->setWindowModality(Qt::ApplicationModal);
	wdg->show();*/
}

void OptoconBasicVM::onRBStatusChanged(bool isChecked)
{
	DisableWaveLengthButtons();
	if (isChecked)
	{		
		ui.PB_1310->setChecked(true);
	}
	else
	{
		ui.PB_850->setChecked(true);
	}

	// TODO: Here we should emit signal that status has been changed (to disable the previous state)
}
