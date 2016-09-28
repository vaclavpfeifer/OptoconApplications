#include "ViewModels/AbstractViewModel.h"
#include "Common/AbstractLogger.h"
#include "Helpers/LogHelper.h"
#include "Helpers/CommandExecHelper.h"

AbstractViewModel::~AbstractViewModel()
{
}

// TODO: remove should emit as its not used anymore
void AbstractViewModel::setActiveWaveLength(WaveLengthEnum newWaveLength, bool shouldEmit)
{
	if (this->ActiveWaveLength != newWaveLength)
	{
		this->ActiveWaveLength = newWaveLength;

		this->registeredWaveLengthCommands[newWaveLength]->ExecCommand();
		///const CommandExecHelper cmdExecutor;
		//cmdExecutor.ExecuteCommand(cmd);

		emit waveLengthChanged(newWaveLength);
	}	
}

void AbstractViewModel::setSingleOrMultiMode(bool isSM)
{
	if (this->isSM != isSM)
	{
		this->isSM = isSM;
		emit singleOrMultiModeChanged(isSM);
	}
}

void AbstractViewModel::setSerialNumber(QString newSerialNumber)
{
	if (this->serialNumber != newSerialNumber)
	{
		this->serialNumber = newSerialNumber;
		emit serialNumberChanged(newSerialNumber);
	}
}

void AbstractViewModel::setReferenceUnits(bool isDb)
{
	if (this->isDb != isDb)
	{
		this->isDb = isDb;
		emit referenceUnitsChanged(isDb);
	}
}

void AbstractViewModel::setLimitChecked(bool isLimitChecked)
{
	if (this->isLimitChecked != isLimitChecked)
	{
		this->isLimitChecked = isLimitChecked;
		emit checkLimitChanged(isLimitChecked);
	}
}

void AbstractViewModel::setLimitValue(double newLimit)
{
	if (this->limitValue != newLimit)
	{
		this->limitValue = newLimit;
		emit limitChanged(newLimit);
	}
}

void AbstractViewModel::setA1Checked(bool isChecked)
{
	if (this->isA1Checked != isChecked)
	{
		this->isA1Checked = isChecked;		

		//auto cmd = this->registeredCommands[WidgetsCodeMap::CHECKBOX_A1];
		//cmdExecutor.ExecuteCommandAsync(cmd);

		// Update UI accordingly
		emit checkA1Changed(isChecked);

		// Execute command synchronously		
		
		//this->registeredCommands[WidgetsCodeMap::CHECKBOX_A1]->ExecCommand();		

		// TODO: how to solve start/stop already executing command?? Should I cancel thread directly?



	}
}

void AbstractViewModel::setA2Checked(bool isChecked)
{
	if (this->isA2Checked != isChecked)
	{
		this->isA2Checked = isChecked;
		emit checkA2Changed(isChecked);

		// Execute command asynchronously		
		this->registeredCommands[WidgetsCodeMap::CHECKBOX_A2]->ExecCommandAsync();
	}
}

void AbstractViewModel::setA3Checked(bool isChecked)
{
	if (this->isA3Checked != isChecked)
	{
		this->isA3Checked = isChecked;
		emit checkA3Changed(isChecked);

		// Execute command asynchronously		
		this->registeredCommands[WidgetsCodeMap::CHECKBOX_A3]->ExecCommandAsync([=](int result) -> void 
		{
			logger->Log(AbstractLogger::INFORMATION, "Successfully executed my callback handler...");
		});
	}
}

void AbstractViewModel::setA4Checked(bool isChecked)
{
	if (this->isA4Checked != isChecked)
	{
		this->isA4Checked = isChecked;
		emit checkA4Changed(isChecked);

		//emit check_A_Changed(4, isChecked); // testing )not used ATM)
	}
}

void AbstractViewModel::setA1Value(double newValue)
{
	if (this->a1Value != newValue)
	{
		this->a1Value = newValue;
		emit A1ValueChanged(newValue);
	}
}

void AbstractViewModel::setA2Value(double newValue)
{
	if (this->a2Value != newValue)
	{
		this->a2Value = newValue;
		emit A2ValueChanged(newValue);
	}
}

void AbstractViewModel::setA3Value(double newValue)
{
	if (this->a3Value != newValue)
	{
		this->a3Value = newValue;
		emit A3ValueChanged(newValue);
	}
}

void AbstractViewModel::setA4Value(double newValue)
{
	if (this->a4Value != newValue)
	{
		this->a4Value = newValue;
		emit A4ValueChanged(newValue);
	}
}
