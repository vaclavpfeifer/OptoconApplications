#include "qttestapp1.h"
#include "mymodel.h"

QTtestapp1::QTtestapp1(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.btn_2, SIGNAL(clicked()), this, SLOT(slotTestMethod()));

	QMetaObject::connectSlotsByName(this);

	auto myModel = new MyModel(nullptr);
	ui.comboBox->setModel(myModel);
}

QTtestapp1::~QTtestapp1()
{

}

void QTtestapp1::on_quitButton_clicked()
{
	qApp->quit();
}

void QTtestapp1::on_btn_RemoveText_clicked()
{
	this->ui.textEdit->clear();
}
