#ifndef COMPOSITE_COMMAND_H
#define COMPOSITE_COMMAND_H

#include <vector>
#include <memory>
#include "Commands/AbstractCommand.h"

// Intention is to run another 1..n commands

class CompositeCommand : public AbstractCommand
{
public:
	CompositeCommand(const std::vector<std::shared_ptr<AbstractCommand>>& commandsToExecute)
		: registeredCommands(commandsToExecute)
	{

	}

	// TODO: Add constructor supporing var args...

	virtual ~CompositeCommand();

	virtual int execute() const override
	{
		int res = -1;


        // TODO not working under linux!!
//		for each (auto cmd in registeredCommands)
//		{
//			res = cmd->execute();

//			// TODO: log/do smth with result --> e.g. do not run another command if the previous one failed???
//		}
		
		return res;
	}

protected:
	const std::vector<std::shared_ptr<AbstractCommand>> registeredCommands;
};

#endif
