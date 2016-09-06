#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "Commands\AbstractCommand.h"
#include "Commands\CommunicationCommand.h"
#include <memory>
#include <iostream>

class AbstractCommandFactory
{
public:
	AbstractCommandFactory() {};
	virtual ~AbstractCommandFactory() {};

	virtual std::shared_ptr<AbstractCommand> CreateCommand1() = 0;
	virtual std::shared_ptr<AbstractCommand> CreateCommand2() = 0;
};



class CommandFactory : AbstractCommandFactory
{
public:
	CommandFactory();
	virtual ~CommandFactory();

	inline virtual std::shared_ptr<AbstractCommand> CreateCommand1() override
	{
		//return std::shared_ptr<CommunicationCommand>();
		return std::make_shared<CommunicationCommand>();
	}
	
	inline virtual std::shared_ptr<AbstractCommand> CreateCommand2() override
	{
		return std::make_shared<CommunicationCommand>(2);
	}
};



#endif 
