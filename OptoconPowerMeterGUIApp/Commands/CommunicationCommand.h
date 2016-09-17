#ifndef COMMUNICATION_COMMAND_H
#define COMMUNICATION_COMMAND_H

#include "Commands/AbstractCommand.h"
#include "Helpers/AbstractCommunicationHelper.h"
#include <memory>
#include <string>

// TODO: create header files with possible Return values for execute method...

class CommunicationCommand : public AbstractCommand
{
public:

	CommunicationCommand(AbstractCommunicationHelper& ioCommunicationHelper) : ioCommHelper(ioCommunicationHelper)
	{
		
	}

	virtual ~CommunicationCommand();

	virtual int execute() override
	{
		return 0;
	}

private:
	AbstractCommunicationHelper& ioCommHelper;
	std::string execString; // TODO:  this should be set in concrete command constructor 

};

#endif
