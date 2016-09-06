#include "OptoconTargetEmbededView.h"
#include "setlimitwindow.h"

OptoconTargetEmbededView::OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory) : OptoconAbstractView(nullptr, cmdFactory)
{
	ui.setupUi(this);

	// Set up signal/slot connections
	QObject::connect(ui.btn_selectAll, SIGNAL(clicked()), this, SLOT(ViewAll()));

	QObject::connect(ui.checkBox_A1, SIGNAL(clicked()), this, SLOT(CheckedA1()));
	QObject::connect(ui.checkBox_A2, SIGNAL(clicked()), this, SLOT(CheckedA2()));
	QObject::connect(ui.checkBox_A3, SIGNAL(clicked()), this, SLOT(CheckedA3()));
	QObject::connect(ui.checkBox_A4, SIGNAL(clicked()), this, SLOT(CheckedA4()));

	// QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
}


OptoconTargetEmbededView::~OptoconTargetEmbededView()
{
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

	// Emit signals about checked check box state
	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);

}

void OptoconTargetEmbededView::CheckedA1()
{
	emit CBStateChanged(ui.checkBox_A1, ui.textEdit_A1);
}

void OptoconTargetEmbededView::CheckedA2()
{
	emit CBStateChanged(ui.checkBox_A2, ui.textEdit_A2);
}

void OptoconTargetEmbededView::CheckedA3()
{
	emit CBStateChanged(ui.checkBox_A3, ui.textEdit_A3);
}

void OptoconTargetEmbededView::CheckedA4()
{
	emit CBStateChanged(ui.checkBox_A4, ui.textEdit_A4);
}


void OptoconTargetEmbededView::onWaveLength850Clicked()
{
}

void OptoconTargetEmbededView::onWaveLength1300Clicked()
{
}

void OptoconTargetEmbededView::onWaveLength1310Clicked()
{
}

void OptoconTargetEmbededView::onWaveLength1550Clicked()
{
}

void OptoconTargetEmbededView::onWaveLengthOFFClicked()
{
}

void OptoconTargetEmbededView::onReference_dBClicked()
{
}

void OptoconTargetEmbededView::onReference_dBMmClicked()
{
}

//void OptoconTargetEmbededView::CheckedHandler(QCheckBox * checkedBox, QTextEdit * textEdit)
//{
//}

void OptoconTargetEmbededView::CheckLimit()
{
}

void OptoconTargetEmbededView::onNewLimitSet(QString newLimit)
{
}

void OptoconTargetEmbededView::onBtnClick_SetLimit()
{
}

void OptoconTargetEmbededView::onRBStatusChanged(bool isChecked)
{
}


