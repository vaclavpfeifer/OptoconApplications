#ifndef DEFAULT_COMMAND_FACTORY_H
#define DEFAULT_COMMAND_FACTORY_H

//#include "Commands/AbstractCommand.h"
// #include "Commands/GUICommand.h"

// #include "Commands/CommunicationCommand.h"
#include "Commands/AbstractCommandFactory.h"
#include "Helpers/SerialIOCommunicationHelper.h"
#include "Helpers/TCPIPCommunicationHelper.h"

//#include "ViewModels/AbstractViewModel.h"
#include "ViewModels/BasicViewModel.h"


#include <memory>
#include <iostream>


// TODO: ctors should accept interfaces for IO comm helpers so we can inject only mocked helper and not create a whole new factory!!!

class DefaultCommandFactory : public AbstractCommandFactory
{
public:
	
	DefaultCommandFactory(AbstractViewModel& viewModel)
		: viewModel(viewModel), 
		  serialComHelperClass(SerialIOCommunicationHelper("COM3", QSerialPort::BaudRate::Baud19200, 6000)) // Initialize Serial COM helper class
	{

	}

	virtual ~DefaultCommandFactory();

	// -- TODO: Only testing and should return AbstractCommand instead

    virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() const override
	{		
		return std::make_shared<CommunicationCommand>(serialComHelperClass, "");
	}
	
    virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() const override
	{
		return std::make_shared<CommunicationCommand>(tcpIPHelperClass, "");
	}

    virtual std::shared_ptr<GUICommand> CreateGUICommand() const override
	{
		return std::make_shared<GUICommand>(viewModel);
	}


	// -----

	virtual std::shared_ptr<AbstractCommand> CreateWLChangedCmd(WaveLengthEnum waveLength) const override
	{
		return std::make_shared<WaveLengthChangedCommand>(serialComHelperClass, waveLength);
	}

	virtual std::shared_ptr<AbstractCommand> CreateReferenceRequestedCmd() const override
	{
		return std::make_shared<CommunicationCommand>(serialComHelperClass, "r");
	}

	virtual std::shared_ptr<AbstractCommand> CreateWavelengthRequestedCmd() const override
	{
		return std::make_shared<CommunicationCommand>(serialComHelperClass, "l");
	}

	std::shared_ptr<AbstractCommand> CreateSerialNumberRequestedCmd() const override
	{
		return std::make_shared<CommunicationCommand>(serialComHelperClass, "n");
	}

	std::shared_ptr<AbstractCommand> CreateActualShownValueRequestedCmd() const override
	{
		return std::make_shared<CommunicationCommand>(serialComHelperClass, "v");
	}


private:
	AbstractViewModel& viewModel;

	// Those should be changed/removed...
	const SerialIOCommunicationHelper serialComHelperClass;
	const TCPIPCommunicationHelper tcpIPHelperClass;
};



#endif 
