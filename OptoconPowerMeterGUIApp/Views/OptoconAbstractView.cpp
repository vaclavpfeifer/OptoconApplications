#include "qtexteditcustom.hpp"
#include "setlimitwindow.h"
#include "Views/OptoconBasicDevelopmentView.h"

OptoconAbstractView::OptoconAbstractView(AbstractViewModel& viewModel, QWidget * parent) :
	QMainWindow(parent),
	viewModel(viewModel)
{
	// Put common signal/slot initialization here
	QObject::connect(this, SIGNAL(CBStateChanged(QCheckBox*, QTextEdit*)), this, SLOT(CheckedHandler(QCheckBox*, QTextEdit*)));
	
}


OptoconAbstractView::~OptoconAbstractView()
{	
}

void OptoconAbstractView::DisableWaveLengthButtons()
{
	// TODO: delete one of those when migrated all views to one option

	// For list 
    for (auto pb : waveLengthButtons)
	{
		pb->setChecked(false);
	}

	// for map
    for (auto pb : waveLengthButtonsMap)
	{
		pb.second->setChecked(false);
	}

}

void OptoconAbstractView::CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit, bool isChecked)
{
	if (isChecked)
	{
		checkedBox->setChecked(true);
		textEdit->setStyleSheet("QTextEdit { background-color: yellow }");
	}
	else
	{
		checkedBox->setChecked(false);
		textEdit->setStyleSheet("QTextEdit { background-color: white }");
	}
}

void OptoconAbstractView::InitializeCommonConnections()
{
	// TODO:: first check that object exists && cast will be valid as well? (Use macro for that??) - preliminary tests shows that this is not necessary...

	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_CHECK_ALL]), &QPushButton::clicked, [=](bool isChecked)
	                 {
		                 viewModel.setA1Checked(isChecked);
		                 viewModel.setA2Checked(isChecked);
		                 viewModel.setA3Checked(isChecked);
		                 viewModel.setA4Checked(isChecked);
	                 });

	QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A1]), &QPushButton::clicked, [=](bool isChecked) { this->viewModel.setA1Checked(isChecked); });
	QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A2]), &QPushButton::clicked, [=](bool isChecked) { this->viewModel.setA2Checked(isChecked); });
	QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A3]), &QPushButton::clicked, [=](bool isChecked) { this->viewModel.setA3Checked(isChecked); });
	QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A4]), &QPushButton::clicked, [=](bool isChecked) { this->viewModel.setA4Checked(isChecked); });

	QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_850], &QPushButton::clicked, [=]() { this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850); });
	QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1300], &QPushButton::clicked, [=]() { this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1300); });
	QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1310], &QPushButton::clicked, [=]() { this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310); });
	QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1500], &QPushButton::clicked, [=]() { this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500); });
	QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_OFF], &QPushButton::clicked, [=]() { this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF); });

	QObject::connect(qobject_cast<QRadioButton*>(allWidgetsCodeMap[WidgetsCodeMap::RADIO_BUTTON_MM]), &QRadioButton::toggled, [=](bool toggledValue)
	                 {
		                 // TODO: double check this value -- or check directly state of one and call accordingly
		                 this->viewModel.setSingleOrMultiMode(!toggledValue);
	                 });

	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_DB]), &QPushButton::clicked, [=]() { this->viewModel.setReferenceUnits(true); });
	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_DBM]), &QPushButton::clicked, [=]() { this->viewModel.setReferenceUnits(false); });

	QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_CHECK_LIMIT]), &QPushButton::clicked, [=](bool isChecked) { this->viewModel.setLimitChecked(isChecked); }); // Example of using lambdas	
	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_SET_LIMIT]), &QPushButton::clicked, [=]()
	                 {
		                 // Create new window
		                 auto limitWindow = new SetLimitWindow();
		                 //auto limitWindow = std::make_shared<SetLimitWindow>(this);

		                 limitWindow->setWindowModality(Qt::ApplicationModal);
		                 limitWindow->show();
		                 QObject::connect(limitWindow, &SetLimitWindow::LimitChanged, [=](QString newLimit) { viewModel.setLimitValue(newLimit.toDouble()); });
	                 });

	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_REFERENCE]), &QPushButton::clicked, [=]()
					{
						this->viewModel.RequestNewReferenceValue();
					});

	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_WAVELENGTH]), &QPushButton::clicked, [=]()
	{
		this->viewModel.RequestWaveLengthValue();
	});

	QObject::connect(qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_SERIALNUMBER]), &QPushButton::clicked, [=]()
	{
		this->viewModel.RequestSerialNumberValue();
	});

	//BINDING -- handlers for signals emited from viewModel

	QObject::connect(&viewModel, &AbstractViewModel::waveLengthChanged, this, &OptoconAbstractView::onWaveLengthChanged);
	QObject::connect(&viewModel, &AbstractViewModel::singleOrMultiModeChanged, this, &OptoconAbstractView::OnSingleOrMultiModeChanged);

	QObject::connect(&viewModel, &AbstractViewModel::referenceUnitsChanged, this, &OptoconAbstractView::OnReferenceChanged);

	QObject::connect(&viewModel, &AbstractViewModel::checkLimitChanged, [=](bool isChecked) { /*TODO: impl*/ });

	QObject::connect(&viewModel, &AbstractViewModel::limitChanged, [=](double newLimitValue)
	                 {
		                 auto teWidget = qobject_cast<QTextEdit*>(allWidgetsCodeMap[WidgetsCodeMap::TEXTBOX_LIMIT]);
		                 teWidget->setText(QString::number(newLimitValue));
	                 });

	/*QObject::connect(&viewModel, &AbstractViewModel::checkA1Changed, [=](bool isChecked)
	{
		auto chckbox = qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A1]);
		auto textEdit = qobject_cast<QTextEdit*>(allWidgetsCodeMap[WidgetsCodeMap::TEXTBOX_A1]);
		this->CheckedHandler(chckbox, textEdit, isChecked);
	});*/

	//END BINDING
}

void OptoconAbstractView::OnReferenceChanged(bool isDb)
{
	auto pbDb = qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_DB]);
	auto pbDbm = qobject_cast<QPushButton*>(allWidgetsCodeMap[WidgetsCodeMap::PUSHBUTTON_DBM]);

	if (isDb)
	{
		pbDbm->setChecked(false);
		pbDb->setChecked(true);
	}
	else
	{
		pbDbm->setChecked(true);
		pbDb->setChecked(false);
	}
}

void OptoconAbstractView::onWaveLengthChanged(WaveLengthEnum newWaveLength)
{
	DisableWaveLengthButtons();
	waveLengthButtonsMap[newWaveLength]->setChecked(true);
}

void OptoconAbstractView::OnSingleOrMultiModeChanged(bool isSm) const
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
