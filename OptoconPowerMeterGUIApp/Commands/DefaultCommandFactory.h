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

    virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() override
	{		
		return std::make_shared<CommunicationCommand>(ioHelperClass);
	}
	
    virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() override
	{
		return std::make_shared<CommunicationCommand>(tcpIPHelperClass);
	}

    virtual std::shared_ptr<GUICommand> CreateGUICommand() const override
	{
		return std::make_shared<GUICommand>(viewModel);
	}

	virtual std::shared_ptr<WaveLengthChangedCommand> CreateWLChangedCmd(WaveLengthEnum waveLength) const override
	{
		return std::make_shared<WaveLengthChangedCommand>(ioHelperClass, waveLength);
	}


private:
	AbstractViewModel& viewModel;
	const SerialIOCommunicationHelper ioHelperClass;
	const TCPIPCommunicationHelper tcpIPHelperClass;
};



#endif 
