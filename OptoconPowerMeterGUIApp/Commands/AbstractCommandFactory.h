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

	virtual std::shared_ptr<CommunicationCommand> CreateSerialIOCommand() = 0;
	virtual std::shared_ptr<CommunicationCommand> CreateTCPIPCommand() = 0;	
	virtual std::shared_ptr<GUICommand> CreateGUICommand() const = 0;
	virtual std::shared_ptr<WaveLengthChangedCommand> CreateWLChangedCmd(WaveLengthEnum waveLength) const = 0;
};

#endif
