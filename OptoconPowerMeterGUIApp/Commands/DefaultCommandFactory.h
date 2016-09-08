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

	inline virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() override
	{		
		return std::make_shared<CommunicationCommand>(ioHelperClass);
	}
	
	inline virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() override
	{
		return std::make_shared<CommunicationCommand>(tcpIPHelperClass);
	}

	inline virtual std::shared_ptr<GUICommand> DefaultCommandFactory::CreateGUICommand()
	{
		return std::make_shared<GUICommand>();
	}


private:
	SerialIOCommunicationHelper ioHelperClass;
	TCPIPCommunicationHelper tcpIPHelperClass;	
};



#endif 