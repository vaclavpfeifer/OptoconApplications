#ifndef ABSTRACT_VIEW_MODEL_H
#define ABSTRACT_VIEW_MODEL_H

#include "qobject.h"
#include "CommonDeclarations.h"

// TODO: Make method which will setUP viewModeles propery according to the default View Model settings


class AbstractViewModel : public QObject
{
	Q_OBJECT

public:
	AbstractViewModel();
	virtual ~AbstractViewModel();

	// Testing method
	virtual void ViewAll() = 0;

	virtual void setActiveWaveLength(WaveLengthEnum newWaveLength, bool shouldEmit = true)
	{
		if (this->ActiveWaveLength != newWaveLength)
		{
			this->ActiveWaveLength = newWaveLength;

			
		}

		if (shouldEmit)
			emit waveLengthChanged(newWaveLength);
	}

	virtual void setSingleOrMultiMode(bool isSM)
	{
		if (this->isSM != isSM)
		{
			this->isSM = isSM;
			emit singleOrMultiModeChanged(isSM);
		}
	}

	virtual void setSerialNumber(QString newSerialNumber)
	{
		if (this->serialNumber != newSerialNumber)
		{
			this->serialNumber = newSerialNumber;
			emit serialNumberChanged(newSerialNumber);
		}
	}

	virtual void setReference(bool isDb)
	{
		if (this->isDb != isDb)
		{
			this->isDb = isDb;
			emit referenceChanged(isDb);
		}
	}


signals:
	void waveLengthChanged(WaveLengthEnum newWL);
	void singleOrMultiModeChanged(bool isSM);
	void serialNumberChanged(QString newSerialNumber);
	void referenceChanged(bool isDb);
	void checkLimitChanged(bool isChecked);
	void limitChanged(double newLimit);
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
	bool isLimitChecked;
	double limitValue;
	bool isA1Checked;
	bool isA2Checked;
	bool isA3Checked;
	bool isA4Checked;
	double a1Value;
	double a2Value;
	double a3Value;
	double a4Value;
};

#endif
