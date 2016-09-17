#ifndef ABSTRACT_VIEW_MODEL_H
#define ABSTRACT_VIEW_MODEL_H

#include "qobject.h"
#include "Common/CommonDeclarations.h"

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

	virtual void setLimitChecked(bool isLimitChecked)
	{
		if (this->isLimitChecked != isLimitChecked)
		{
			this->isLimitChecked = isLimitChecked;
			emit checkLimitChanged(isLimitChecked);
		}
	}

	virtual void setLimitValue(double newLimit)
	{
		if (this->limitValue != newLimit)
		{
			this->limitValue = newLimit;
			emit limitChanged(newLimit);
		}
	}

	virtual void setA1Checked(bool isChecked)
	{
		if (this->isA1Checked != isChecked)
		{
			this->isA1Checked = isChecked;
			emit checkA1Changed(isChecked);

			emit check_A_Changed(1, isChecked); // testing )not used ATM)
		}
	}

	virtual void setA2Checked(bool isChecked)
	{
		if (this->isA2Checked != isChecked)
		{
			this->isA2Checked = isChecked;
			emit checkA2Changed(isChecked);

			emit check_A_Changed(2, isChecked); // testing )not used ATM)
		}
	}
	
	virtual void setA3Checked(bool isChecked)
	{
		if (this->isA3Checked != isChecked)
		{
			this->isA3Checked = isChecked;
			emit checkA3Changed(isChecked);

			emit check_A_Changed(3, isChecked); // testing )not used ATM)
		}
	}

	virtual void setA4Checked(bool isChecked)
	{
		if (this->isA4Checked != isChecked)
		{
			this->isA4Checked = isChecked;
			emit checkA4Changed(isChecked);

			emit check_A_Changed(4, isChecked); // testing )not used ATM)
		}
	}

	virtual void setA1Value(double newValue)
	{
		if (this->a1Value != newValue)
		{
			this->a1Value = newValue;
			emit A1ValueChanged(newValue);
		}
	}

	virtual void setA2Value(double newValue)
	{
		if (this->a2Value != newValue)
		{
			this->a2Value = newValue;
			emit A2ValueChanged(newValue);
		}
	}

	virtual void setA3Value(double newValue)
	{
		if (this->a3Value != newValue)
		{
			this->a3Value = newValue;
			emit A3ValueChanged(newValue);
		}
	}

	virtual void setA4Value(double newValue)
	{
		if (this->a4Value != newValue)
		{
			this->a4Value = newValue;
			emit A4ValueChanged(newValue);
		}
	}


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
};

#endif
