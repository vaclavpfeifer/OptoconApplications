#ifndef COMMUNICATION_COMMAND_H
#define COMMUNICATION_COMMAND_H

#include "Commands\AbstractCommand.h"
#include "Helpers/AbstractCommunicationHelper.h"
#include <memory>

// TODO: create header files with possible Return values for execute method...

class CommunicationCommand : public AbstractCommand
{
public:

	CommunicationCommand(AbstractCommunicationHelper& ioCommunicationHelper) : ioCommHelper(ioCommunicationHelper)
	{
		
	}

	virtual ~CommunicationCommand();


	int execute() override
	{
		return 0;
	}

private:
	AbstractCommunicationHelper& ioCommHelper;
};

#endif
