#include "optoconbasicvm.hpp"

OptoconBasicVM::OptoconBasicVM(QWidget * parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	/*QObject::connect(ui.btn_2, SIGNAL(clicked()), this, SLOT(slotTestMethod()));

	QMetaObject::connectSlotsByName(this);

	auto myModel = new MyModel(nullptr);
	ui.comboBox->setModel(myModel);*/

}

OptoconBasicVM::~OptoconBasicVM() {
	
}
