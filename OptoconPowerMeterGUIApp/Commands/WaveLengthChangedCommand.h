#ifndef WAVELENGTH_CHANGED_COMMAND_H
#define WAVELENGTH_CHANGED_COMMAND_H

#include "Commands/CommunicationCommand.h"
#include "Common/CommonDeclarations.h"
#include "Common/AbstractLogger.h"
#include "Helpers/LogHelper.h"

class WaveLengthChangedCommand : public CommunicationCommand
{
public:
	WaveLengthChangedCommand(const AbstractCommunicationHelper& ioCommunicationHelper, WaveLengthEnum waveLength) 
		: CommunicationCommand(ioCommunicationHelper, "DEFAULT_WAVE_LENGTH_CHANGED"), waveLength(waveLength)
	{
		// execString = "WAVE LENGTH CHANGED exec string..."; // or move to initialization for better performance
	}

	virtual ~WaveLengthChangedCommand()
	{
		int a = 5;
	}

	int execute() const override
	{
		auto logger = LogHelper::GetLogger();

		switch (waveLength)
		{
		case WAVELENGTH_850:
			logger->Log(AbstractLogger::INFORMATION, "Wavelength 850 command sucesfully executed....");
			break;
		case WAVELENGTH_1300:
			logger->Log(AbstractLogger::INFORMATION, "Wavelength 1300 command sucesfully executed....");
			break;
		case WAVELENGTH_1310:
			logger->Log(AbstractLogger::INFORMATION, "Wavelength 1310 command sucesfully executed....");
			break;
		case WAVELENGTH_1500:
			logger->Log(AbstractLogger::INFORMATION, "Wavelength 1500 command sucesfully executed....");
			break;
		case WAVELENGTH_OFF:
			logger->Log(AbstractLogger::INFORMATION, "Wavelength OFF command sucesfully executed....");
			break;
		default:
			break;
		}

		return 0;
	}

private:
	WaveLengthEnum waveLength;
};

#endif
