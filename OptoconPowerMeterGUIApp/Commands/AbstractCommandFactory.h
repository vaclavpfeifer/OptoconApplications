#ifndef ABSTRACT_COMMAND_FACTORY_H
#define ABSTRACT_COMMAND_FACTORY_H

#include "Commands/CommunicationCommand.h"
#include "Commands/GUICommand.h"
#include "Commands/WaveLengthChangedCommand.h"

#include <memory>

// Note that the mehtods needs to be const in order to be able to call from const reference/pointer

class AbstractCommandFactory
{
public:
	AbstractCommandFactory();
	virtual ~AbstractCommandFactory();

	// Or command factory should always return AbstractCommand?


	virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() const = 0;
	virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() const = 0;	
	virtual std::shared_ptr<GUICommand> CreateGUICommand() const = 0;

	virtual std::shared_ptr<AbstractCommand> CreateWLChangedCmd(WaveLengthEnum waveLength) const = 0;	
	virtual std::shared_ptr<AbstractCommand> CreateReferenceRequestedCmd() const = 0;
	virtual std::shared_ptr<AbstractCommand> CreateWavelengthRequestedCmd() const = 0;
	virtual std::shared_ptr<AbstractCommand> CreateSerialNumberRequestedCmd() const = 0;
	virtual std::shared_ptr<AbstractCommand> CreateActualShownValueRequestedCmd() const = 0;


	//virtual std::shared_ptr<AbstractCommand> CreateTestCommCmd() const = 0;

};

#endif
