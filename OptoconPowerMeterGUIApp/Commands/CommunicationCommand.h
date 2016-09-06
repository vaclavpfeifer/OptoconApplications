#ifndef COMMUNICATION_COMMAND_H
#define COMMUNICATION_COMMAND_H

#include "Commands\AbstractCommand.h"


// TODO: create header files with possible Return values for execute method...

class CommunicationCommand : public AbstractCommand
{
public:
	CommunicationCommand();
	CommunicationCommand(int a) {};
	virtual ~CommunicationCommand();

	inline int execute() override
	{
		return 0;
	}
};

#endif
