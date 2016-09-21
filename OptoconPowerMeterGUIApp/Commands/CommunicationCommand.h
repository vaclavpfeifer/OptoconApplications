#ifndef COMMUNICATION_COMMAND_H
#define COMMUNICATION_COMMAND_H

#include "Commands/AbstractCommand.h"
#include "Helpers/AbstractCommunicationHelper.h"
#include <memory>
#include <string>
#include "Common/AbstractLogger.h"
#include "Helpers/LogHelper.h"

// TODO: create header files with possible Return values for execute method...

class CommunicationCommand : public AbstractCommand
{
public:

	CommunicationCommand(const AbstractCommunicationHelper& ioCommunicationHelper) 
		: ioCommHelper(ioCommunicationHelper)
	{
		
	}

	virtual ~CommunicationCommand();

	virtual int execute() const override
	{
		logger->Log(AbstractLogger::LogLevel::INFORMATION, "Communication commands sucesfully executed....");

		return 0;
	}

protected:
	const AbstractCommunicationHelper& ioCommHelper;

	std::string execString = "COMM COMMAND DEFAULT  "; // TODO:  this should be set in concrete command constructor 
	std::shared_ptr<AbstractLogger> logger = LogHelper::GetLogger();// TODO: do we want to have logger here? if the command will be called multiple times then it could save some time...
};

#endif
