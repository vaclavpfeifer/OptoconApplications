#include "optoconbasicvm.hpp"

OptoconBasicVM::OptoconBasicVM(QWidget * parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	// Set up signal/slot connections
	QObject::connect(ui.btn_selectAll, SIGNAL(clicked()), this, SLOT(ViewAll()));
	
	QObject::connect(ui.checkBox_A1, SIGNAL(clicked()), this, SLOT(CheckedA1()));
	QObject::connect(ui.checkBox_A2, SIGNAL(clicked()), this, SLOT(CheckedA2()));
	QObject::connect(ui.checkBox_A3, SIGNAL(clicked()), this, SLOT(CheckedA3()));
	QObject::connect(ui.checkBox_A4, SIGNAL(clicked()), this, SLOT(CheckedA4()));

	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
	
	QObject::connect(ui.PB_Set, SIGNAL(clicked()), this, SLOT(onBtnClick_SetLimit()));

	QObject::connect(ui.RB_MM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));
	QObject::connect(ui.RB_SM, SIGNAL(toggled(bool)), this, SLOT(onRBStatusChanged(bool)));


	QMetaObject::connectSlotsByName(this);
}

OptoconBasicVM::~OptoconBasicVM() {
	
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
	if (!isChecked)
	{
		ui.PB_1300->setChecked(true);
	}
	else
	{
		ui.PB_850->setChecked(true);
	}

	// TODO: Here we should emit signal that status has been changed (to disable the previous state)




}
