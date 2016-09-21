#ifndef COMPOSITE_COMMAND_H
#define COMPOSITE_COMMAND_H

#include <vector>
#include <memory>
#include "Commands/AbstractCommand.h"

// Intention is to run another 1..n commands

class CompositeCommand : public AbstractCommand
{
public:
	CompositeCommand(std::vector<std::shared_ptr<AbstractCommand>>& commandsToExecute)
		: registeredCommands(commandsToExecute)
	{

	}

	// TODO: Add constructor supporing var args...

	virtual ~CompositeCommand();

	virtual int execute() const override
	{
		for each (auto cmd in registeredCommands)
		{
			auto result = cmd->execute();

			// TODO: log/do smth with result --> e.g. do not run another command if the previous one failed???
		}
		
		return 0;
	}

protected:
	std::vector<std::shared_ptr<AbstractCommand>> registeredCommands;
};

#endif
