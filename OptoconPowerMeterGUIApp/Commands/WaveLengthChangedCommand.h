#ifndef WAVELENGTH_CHANGED_COMMAND_H
#define WAVELENGTH_CHANGED_COMMAND_H

#include "Commands/CommunicationCommand.h"
#include "Common/CommonDeclarations.h"
#include "Common/AbstractLogger.h"
#include "Helpers/LogHelper.h"

class WaveLengthChangedCommand : public CommunicationCommand
{
public:
	WaveLengthChangedCommand(AbstractCommunicationHelper& ioCommunicationHelper, WaveLengthEnum waveLength) 
		: CommunicationCommand(ioCommunicationHelper), waveLength(waveLength)
	{

	}

	virtual ~WaveLengthChangedCommand();

	int execute() override
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
