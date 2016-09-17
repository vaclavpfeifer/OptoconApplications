#include "OptoconTargetEmbededView.h"
#include "setlimitwindow.h"

OptoconTargetEmbededView::OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent) 
	: OptoconAbstractView(viewModel, cmdFactory, parent)
{
	ui.setupUi(this);

	// Disable frame window
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	// Initialize internal members:
	waveLengthButtonsMap.insert(std::make_pair(WAVELENGTH_850, ui.PB_850));
	waveLengthButtonsMap.insert(std::make_pair(WAVELENGTH_1300, ui.PB_1300));
	waveLengthButtonsMap.insert(std::make_pair(WAVELENGTH_1310, ui.PB_1310));
	waveLengthButtonsMap.insert(std::make_pair(WAVELENGTH_1500, ui.PB_1550));
	waveLengthButtonsMap.insert(std::make_pair(WAVELENGTH_OFF, ui.PB_OFF));

	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A1, ui.checkBox_A1));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A2, ui.checkBox_A2));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A3, ui.checkBox_A3));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A4, ui.checkBox_A4));
	

	// TODO: Set either viewmodel or gui accordingly.
	
	// Set up signal/slot connections	
	OptoconTargetEmbededView::InitializeConnections();
}


OptoconTargetEmbededView::~OptoconTargetEmbededView()
{	
}

void OptoconTargetEmbededView::InitializeConnections()
{
	// Note that usage of Variadic form (c++11 - i.e. not using SIGNAL/SLOT macros) is better when later doing refactoring....


	// Set up signal/slot connections		
	QObject::connect(ui.btn_selectAll, &QPushButton::clicked, [=](bool isChecked)
	{
		viewModel.setA1Checked(isChecked);
		viewModel.setA2Checked(isChecked);
		viewModel.setA3Checked(isChecked);
		viewModel.setA4Checked(isChecked);
	});

	/*QObject::connect(ui.checkBox_A1, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA1Checked(isChecked); });
	QObject::connect(ui.checkBox_A2, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA2Checked(isChecked); });
	QObject::connect(ui.checkBox_A3, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA3Checked(isChecked); });
	QObject::connect(ui.checkBox_A4, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA4Checked(isChecked); });*/

	InitializeCommonConnections();

	/*QObject::connect(ui.PB_850, &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850); });
	QObject::connect(ui.PB_1300, &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1300); });
	QObject::connect(ui.PB_1310, &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310); });
	QObject::connect(ui.PB_1550, &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500); });
	QObject::connect(ui.PB_OFF, &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF); });*/

	// radio buttons MM/SM	
	QObject::connect(ui.RB_MM, &QRadioButton::toggled, [=](bool toggledValue)
	{
		// TODO: double check this value -- or check directly state of one and call accordingly
		this->viewModel.setSingleOrMultiMode(!toggledValue);
	});

	// radio buttons dB/dBm (different approach)
	QObject::connect(ui.PB_dB, &QPushButton::clicked, [=]() {this->viewModel.setReference(true); });
	QObject::connect(ui.PB_dBm, &QPushButton::clicked, [=]() {this->viewModel.setReference(false); });

	// Checked Set Limit	
	QObject::connect(ui.checkBox_CheckLimit, &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setLimitChecked(isChecked); }); // Example of using lambdas	
	QObject::connect(ui.PB_Set, &QPushButton::clicked, [=]()
	{
		// Create new window
		auto limitWindow = new SetLimitWindow(this);
		limitWindow->setWindowModality(Qt::ApplicationModal);
		limitWindow->show();

		// TODO: should I disconect as well?
		// QObject::connect(limitWindow, &SetLimitWindow::LimitChanged, this, &OptoconTargetEmbededView::onNewLimitSet);		
	});

	// SET BINDING (one way binding)
	QObject::connect(&viewModel, &AbstractViewModel::waveLengthChanged, this, &OptoconTargetEmbededView::onWaveLengthChanged);
	QObject::connect(&viewModel, &AbstractViewModel::singleOrMultiModeChanged, this, &OptoconTargetEmbededView::OnSingleOrMultiModeChanged);	
	QObject::connect(&viewModel, &AbstractViewModel::referenceChanged, this, &OptoconTargetEmbededView::OnReferenceChanged);

	QObject::connect(&viewModel, &AbstractViewModel::checkLimitChanged, [=](bool isChecked) {  /*TODO: impl*/ } );
	QObject::connect(&viewModel, &AbstractViewModel::limitChanged, [=](double newLimitValue)
	{
		this->ui.textEdit_Limit->setText(QString::number(newLimitValue));
	});	

	QObject::connect(&viewModel, &AbstractViewModel::checkA1Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A1, ui.textEdit_A1, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA2Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A2, ui.textEdit_A2, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA3Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A3, ui.textEdit_A3, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA4Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A4, ui.textEdit_A4, isChecked); });
	// END BINDING

	QMetaObject::connectSlotsByName(this);

}

void OptoconTargetEmbededView::onWaveLengthChanged(WaveLengthEnum newWaveLength)
{
	DisableWaveLengthButtons();
	waveLengthButtonsMap[newWaveLength]->setChecked(true);
}

void OptoconTargetEmbededView::OnSingleOrMultiModeChanged(bool isSm) const
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

void OptoconTargetEmbededView::OnReferenceChanged(bool isDb) const
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

void OptoconTargetEmbededView::onNewLimitSet(QString newLimit) const
{
	viewModel.setLimitValue(newLimit.toDouble());
}

