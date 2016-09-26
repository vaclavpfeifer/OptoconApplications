#include "OptoconTargetEmbededView.h"
#include "setlimitwindow.h"

OptoconTargetEmbededView::OptoconTargetEmbededView(AbstractViewModel& viewModel, QWidget * parent) 
	: OptoconAbstractView(viewModel, parent)
{
	ui.setupUi(this);

// TODO: 
#if RELEASE
	// Disable frame window
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
#endif

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
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_CHECK_LIMIT, ui.checkBox_CheckLimit));

	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_CHECK_ALL, ui.btn_selectAll));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_DB, ui.PB_dB));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_DBM, ui.PB_dBm));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_SET_LIMIT, ui.PB_Set));

	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::RADIO_BUTTON_SM, ui.RB_SM));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::RADIO_BUTTON_MM, ui.RB_MM));

	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_A1, ui.textEdit_A1));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_A2, ui.textEdit_A2));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_A3, ui.textEdit_A3));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_A4, ui.textEdit_A4));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_LIMIT, ui.textEdit_Limit));
	allWidgetsCodeMap.insert(std::make_pair(WidgetsCodeMap::TEXTBOX_SERIAL_NUMBER, ui.textEdit_SN));


	// TODO: Set either viewmodel or gui accordingly.
	
	// Set up signal/slot connections	
	//OptoconTargetEmbededView::InitializeConnections();
}


OptoconTargetEmbededView::~OptoconTargetEmbededView()
{	
}

void OptoconTargetEmbededView::InitializeConnections()
{
	// Note that usage of Variadic form (c++11 - i.e. not using SIGNAL/SLOT macros) is better when later doing refactoring....
	// Set up signal/slot connections		
	//InitializeCommonConnections();


	// Additional binding set-up -- TODO: those should be moved to abstract class as well
	QObject::connect(&viewModel, &AbstractViewModel::checkA1Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A1, ui.textEdit_A1, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA2Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A2, ui.textEdit_A2, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA3Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A3, ui.textEdit_A3, isChecked); });
	QObject::connect(&viewModel, &AbstractViewModel::checkA4Changed, [=](bool isChecked) {this->CheckedHandler(ui.checkBox_A4, ui.textEdit_A4, isChecked); });
	// END BINDING
}
