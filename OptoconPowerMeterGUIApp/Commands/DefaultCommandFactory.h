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
		: viewModel(viewModel)
	{

	}

	// Test that provides example how to implement inheritance when using shared_ptr (cannot be done for ctors)
	/*template <typename T>
	auto DefaultCommandFactory(std::shared_ptr<T>& viewModel) -> decltype(DefaultCommandFactory( std::shared_ptr<AbstractViewModel>(viewModel) ) ) 
	{ 
		return DefaultCommandFactory(std::shared_ptr<AbstractViewModel>(viewModel));
	}*/
	
	//: viewModel(viewModel)
	/*{			
	}*/

	virtual ~DefaultCommandFactory();

    virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() const override
	{		
		return std::make_shared<CommunicationCommand>(serialComHelperClass);
	}
	
    virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() const override
	{
		return std::make_shared<CommunicationCommand>(tcpIPHelperClass);
	}

    virtual std::shared_ptr<GUICommand> CreateGUICommand() const override
	{
		return std::make_shared<GUICommand>(viewModel);
	}

	virtual std::shared_ptr<AbstractCommand> CreateWLChangedCmd(WaveLengthEnum waveLength) const override
	{
		return std::make_shared<WaveLengthChangedCommand>(serialComHelperClass, waveLength);
	}

	//std::shared_ptr<AbstractCommand> CreateTestCommCmd() const override
	//{
	//	return std::make_shared<WaveLengthChangedCommand>(serialComHelperClass, waveLength);
	//}

private:
	AbstractViewModel& viewModel;
	const SerialIOCommunicationHelper serialComHelperClass;
	const TCPIPCommunicationHelper tcpIPHelperClass;
};



#endif 
