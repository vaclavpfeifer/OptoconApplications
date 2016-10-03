#ifndef COMMUNICATION_COMMAND_H
#define COMMUNICATION_COMMAND_H

#include "Commands/AbstractCommand.h"
#include "Helpers/AbstractCommunicationHelper.h"
#include <memory>
#include <string>
#include "Common/AbstractLogger.h"
#include "Helpers/LogHelper.h"

#include <chrono>
#include <thread>

// TODO: create header files with possible Return values for execute method... And use domains and XORS 

class CommunicationCommand : public AbstractCommand
{
public:

	CommunicationCommand(const AbstractCommunicationHelper& ioCommunicationHelper, const QString& execStr) 
		: ioCommHelper(ioCommunicationHelper), execString(execStr)
	{
		
	}

	virtual ~CommunicationCommand();

	virtual int execute() const override
	{
		logger->Log(AbstractLogger::LogLevel::INFORMATION, "Communication command execution sucesfully started....");
			
		// std::this_thread::sleep_for(std::chrono::seconds(2)); // DEBUG ONLY!!

		QString response;
		auto rv = ioCommHelper.SendCommand(execString, response);

		
		if (QSerialPort::NoError == rv)
		{
			logger->Log(AbstractLogger::LogLevel::INFORMATION, "Communication command execution sucesfully finished....");
		}
		else
		{
			logger->Log(AbstractLogger::LogLevel::ERROR, "Communication command unable to execute... err: ");
		}

		return 0;
	}

protected:
	const AbstractCommunicationHelper& ioCommHelper;

	const QString execString = "COMM COMMAND DEFAULT"; // TODO:  this should be set in concrete command constructor 
	std::shared_ptr<AbstractLogger> logger = LogHelper::GetLogger();// TODO: do we want to have logger here? if the command will be called multiple times then it could save some time...
};

#endif
