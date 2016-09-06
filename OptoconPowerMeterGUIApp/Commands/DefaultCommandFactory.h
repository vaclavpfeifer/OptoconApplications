#ifndef DEFAULT_COMMAND_FACTORY_H
#define DEFAULT_COMMAND_FACTORY_H

#include "Commands\AbstractCommand.h"
#include "Commands\CommunicationCommand.h"
#include "Commands\AbstractCommandFactory.h"
#include "Helpers/SerialIOCommunicationHelper.h"
#include "Helpers/TCPIPCommunicationHelper.h"


#include <memory>
#include <iostream>



class DefaultCommandFactory : public AbstractCommandFactory
{
public:
	DefaultCommandFactory()
	{			
	}

	virtual ~DefaultCommandFactory();

	inline virtual std::shared_ptr<AbstractCommand> CreateSerialIOCommand() override	
	{		
		return std::make_shared<CommunicationCommand>(ioHelperClass);
	}
	
	inline virtual std::shared_ptr<AbstractCommand> CreateTCPIPCommand() override
	{
		return std::make_shared<CommunicationCommand>(tcpIPHelperClass);
	}

private:
	SerialIOCommunicationHelper ioHelperClass;
	TCPIPCommunicationHelper tcpIPHelperClass;
};



#endif 
