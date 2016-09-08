#ifndef ABSTRACT_COMMAND_FACTORY_H
#define ABSTRACT_COMMAND_FACTORY_H
#include "Commands\CommunicationCommand.h"
#include "Commands\GUICommand.h"
#include <memory>

class AbstractCommandFactory
{
public:
	AbstractCommandFactory();
	virtual ~AbstractCommandFactory();

	virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() = 0;
	virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() = 0;
	virtual std::shared_ptr<GUICommand> CreateGUICommand() = 0;
};

#endif
