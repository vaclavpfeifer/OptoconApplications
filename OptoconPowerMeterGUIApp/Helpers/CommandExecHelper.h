#ifndef COMMAND_EXEC_HELPER_H
#define COMMAND_EXEC_HELPER_H

#include "Commands/AbstractCommand.h"
#include "Helpers/LogHelper.h"

#include <functional>

// TODO: Is this really necessary?
class AbstractExecHelper
{

};


class CommandExecHelper
{
public:
	CommandExecHelper()
	{
		
	}

	int ExecuteCommand(const AbstractCommand& cmd) const
	{
		return cmd.execute();
	}

	int ExecuteCommand(const std::shared_ptr<AbstractCommand> cmd) const
	{
		int rv = -1;

		if (cmd != nullptr)
		{
			rv = cmd->execute();
		}
		else
		{			
			logger->Log(AbstractLogger::WARNING, "Unable to execute, command is not registered....");
		}

		return rv;
	}

	// TODO: rather use shared_ptr because the command could go out of scope when un async!!
	void ExecuteCommandAsync(const AbstractCommand& cmd, std::function<void(int)> callback)
	{
		// Run Cmd Excution in another thread

		auto result = cmd.execute();

		// When finished run callback
		callback(result);
	}

	virtual ~CommandExecHelper();

private:
	// TODO: create local retrying method which will accept functor


private:
	int timeout = 10; // [s]
	int maxAttempts = 3; // retrying?
	bool isRetryingEnabled = false;

	const std::shared_ptr<AbstractLogger> logger = LogHelper::GetLogger();
};

#endif
