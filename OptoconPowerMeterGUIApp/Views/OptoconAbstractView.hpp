#ifndef OPTOCON_ABSTRACT_VIEW_H
#define OPTOCON_ABSTRACT_VIEW_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels/AbstractViewModel.h"
#include "Commands/AbstractCommandFactory.h"
#include "Commands/CommunicationCommand.h"
#include <vector>

// TODO: 


class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

public:
	explicit OptoconAbstractView(AbstractViewModel& viewModel, AbstractCommandFactory& cmdFactory, QWidget * parent = Q_NULLPTR);
	~OptoconAbstractView();

	virtual void InitializeConnections() = 0;

// Shared Methods
protected:
	void DisableWaveLengthButtons();
	static void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit, bool isChecked);

	virtual void InitializeCommonConnections()
	{
		// TODO:: first check that object exists && cast will be valid as well? (Use macro for that??) - preliminary tests shows that this is not necessary...

		QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A1]), &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA1Checked(isChecked); });
		QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A2]), &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA2Checked(isChecked); });
		QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A3]), &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA3Checked(isChecked); });
		QObject::connect(qobject_cast<QCheckBox*>(allWidgetsCodeMap[WidgetsCodeMap::CHECKBOX_A4]), &QPushButton::clicked, [=](bool isChecked) {this->viewModel.setA4Checked(isChecked); });

		QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_850], &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_850); });
		QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1300], &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1300); });
		QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1310], &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1310); });
		QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_1500], &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_1500); });
		QObject::connect(waveLengthButtonsMap[WaveLengthEnum::WAVELENGTH_OFF], &QPushButton::clicked, [=]() {this->viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF); });
	}

protected:
	AbstractViewModel& viewModel;
	AbstractCommandFactory& commandFactory;
	std::vector<QPushButton*> waveLengthButtons;

	std::map<WaveLengthEnum, QPushButton*> waveLengthButtonsMap;
	std::map<WidgetsCodeMap, QWidget*> allWidgetsCodeMap; // Or for specific widget type use specific map??
};



#endif
