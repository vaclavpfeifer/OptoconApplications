#ifndef ABSTRACT_COMMAND_FACTORY_H
#define ABSTRACT_COMMAND_FACTORY_H
#include "AbstractCommand.h"
#include <memory>

class AbstractCommandFactory
{
public:
	AbstractCommandFactory();
	virtual ~AbstractCommandFactory();

	virtual std::shared_ptr<AbstractCommand> CreateSerialIOCommand() = 0;
	virtual std::shared_ptr<AbstractCommand> CreateTCPIPCommand() = 0;
};

#endif
