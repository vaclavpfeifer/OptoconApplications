#ifndef ABSTRACT_VIEW_MODEL_H
#define ABSTRACT_VIEW_MODEL_H

#include "qobject.h"
#include "Common/CommonDeclarations.h"
#include "Commands/AbstractCommand.h"
// #include "Commands/AbstractCommandFactory.h" 
#include <memory>

// TODO: Make method which will setUP viewModeles propery according to the default View Model settings
// TODO: move wavelenght enum here??

class AbstractCommandFactory; // --rather use forward declaration in order to avoid compile problems...


class AbstractViewModel : public QObject
{
	Q_OBJECT

public:
	AbstractViewModel(const AbstractCommandFactory& cmdFact)
		: commandFactory(cmdFact)
	{

	}

	virtual ~AbstractViewModel();

	virtual void setActiveWaveLength(WaveLengthEnum newWaveLength, bool shouldEmit = true);
	virtual void setSingleOrMultiMode(bool isSM);
	virtual void setSerialNumber(QString newSerialNumber);
	virtual void setReference(bool isDb);
	virtual void setLimitChecked(bool isLimitChecked);
	virtual void setLimitValue(double newLimit);
	virtual void setA1Checked(bool isChecked);
	virtual void setA2Checked(bool isChecked);
	virtual void setA3Checked(bool isChecked);
	virtual void setA4Checked(bool isChecked);
	virtual void setA1Value(double newValue);
	virtual void setA2Value(double newValue);
	virtual void setA3Value(double newValue);
	virtual void setA4Value(double newValue);


signals:
	void waveLengthChanged(WaveLengthEnum newWL);
	void singleOrMultiModeChanged(bool isSM);
	void serialNumberChanged(QString newSerialNumber);
	void referenceChanged(bool isDb);
	void checkLimitChanged(bool isChecked);
	void limitChanged(double newLimit);
	
	void check_A_Changed(int type, bool isChecked); // Just testing version // TODO: change int to ENUM???

	void checkA1Changed(bool isChecked);
	void checkA2Changed(bool isChecked);
	void checkA3Changed(bool isChecked);
	void checkA4Changed(bool isChecked);
	
	void A1ValueChanged(double newValue);
	void A2ValueChanged(double newValue);
	void A3ValueChanged(double newValue);
	void A4ValueChanged(double newValue);

	// Internal attributes
protected:
	QString serialNumber;	
	WaveLengthEnum ActiveWaveLength = WaveLengthEnum::WAVELENGTH_850;
	bool isSM = true;
	bool isDb = false;
	bool isLimitChecked = true;
	double limitValue = 2.0;
	bool isA1Checked = false;
	bool isA2Checked = false;
	bool isA3Checked = false;
	bool isA4Checked = false;
	double a1Value = 0;
	double a2Value = 0;
	double a3Value = 0;
	double a4Value = 0;


	// Each command can be registered to some possible user action -- commands should be able to run another commands
	std::map<WaveLengthEnum, std::shared_ptr<AbstractCommand>> registeredWaveLengthCommands;
	std::map<WidgetsCodeMap, std::shared_ptr<AbstractCommand>> allRegisteredCommands;
		
	const AbstractCommandFactory& commandFactory; // TODO: delete when not used elsewhere except ctor...

};

#endif
