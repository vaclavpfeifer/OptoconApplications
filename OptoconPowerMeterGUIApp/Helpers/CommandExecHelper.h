#ifndef COMMAND_EXEC_HELPER_H
#define COMMAND_EXEC_HELPER_H

#include "Commands/AbstractCommand.h"
#include "Helpers/LogHelper.h"

#include <functional>
#include <thread>

// TODO: Is this really necessary?
class AbstractExecHelper
{

};



class CommandExecHelper
{
public:
	CommandExecHelper()
	{
		// This ctor should be deleted or go private
	}

	CommandExecHelper(const std::shared_ptr<AbstractCommand> cmd, bool shouldRetry = false, int maxRetryAttempts = 3)
		: commandToExecute(cmd), isRetryingEnabled(shouldRetry), maxAttempts(maxRetryAttempts)
	{

	}

	virtual ~CommandExecHelper();

	// TODO: add more states which can be xor - i.e. RUN/ON_HOLD && FAILED/SUCCESS 
	// THe idea is to have multiple kind of information in commandstatus
	enum CommandExecStatus
	{
		NOT_STARTED, // Default state
		IN_PROGRESS,
		FAILED,
		SUCCESS
	};


	//TODO: Can be made static!!
	static int ExecuteCommand(const std::shared_ptr<AbstractCommand> cmd, bool isRetryingEnabled = false, int maxAttempts = 3)
	{		
		auto execFcn = [=]()  -> int {
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
		};

		if (isRetryingEnabled)
		{
			for (int i = 0; i < maxAttempts; ++i)
			{
				// TODO: Should i catch some Exceptions? Timeout, IO Serial COM, ... ? 

				logger->Log(AbstractLogger::INFORMATION, "Command execution started - attempt: " + i);

				auto res =  execFcn();

				if (0 == res) // sucesfully completed
				{
					logger->Log(AbstractLogger::INFORMATION, "Command execution - attempt: SUCESFULLY FINISHED" + i);
				}

				// Log Failed attempt
				logger->Log(AbstractLogger::WARNING, "Command execution - attempt:  finished - FAILED" + i);
			}

			return -1;
		}		
		else
		{
			return execFcn(); // return result with no retrying
		}
	}

	// TODO: can be made static
	static void ExecuteCommandAsync(const std::shared_ptr<AbstractCommand> cmd, bool isRetryingEnabled = false, int maxAttempts = 3, std::function<void(int)> callback = nullptr)
	{
		// TODO: should the local thread value be made static and destroyed at the end? or how to thread is/should be destroyed?

		// Mutable means that values captured by value can be changed!
		auto thread = new std::thread([=]() -> void {			
			//auto result = cmd->execute();
			auto result = ExecuteCommand(cmd);

			// When finished run callback
			if(callback != nullptr)
				callback(result);
		});		
	}
	
	static void ExecuteCommandAsync(const std::shared_ptr<AbstractCommand> cmd, std::function<void(int)> callback = nullptr)
	{
		ExecuteCommandAsync(cmd, false, 3, callback);
	}

	int ExecCommand()
	{	
		if (commandToExecute == nullptr)
		{
			// Throw exc unable to execute cmd - not registered -- or retVal?
			return -1;
		}
		else
		{
			this->commandRetVal = ExecuteCommand(commandToExecute, this->isRetryingEnabled, this->maxAttempts);			
			return this->commandRetVal;
		}
	}	

	//// TODO: enable callback registration in constructor as well??
	//// TODO: move previous two methods to static and commandToexecute should be bind by reference!!
	void ExecCommandAsync(std::function<void(int)> callback = nullptr)
	{
		if (commandToExecute == nullptr)
		{
			// Throw exc unable to execute cmd - not registered
		}
		else
		{
			// Need to use this lambda to get retVal and after that execute user-defined (if any) callback
			ExecuteCommandAsync(commandToExecute, this->isRetryingEnabled, this->maxAttempts, [=](int retVal) -> void { 
				this->commandRetVal = retVal; 

				// And run the original callback
				if (callback != nullptr)
				{
					callback(this->commandRetVal);
				}
			});						
		}
	}

private:
	static const std::shared_ptr<AbstractLogger> logger; // = LogHelper::GetLogger();
	
	const int timeout = 10; // [s]
	const int maxAttempts = 3; // retrying?
	const bool isRetryingEnabled = false;
	const std::shared_ptr<AbstractCommand> commandToExecute = nullptr;	

	CommandExecStatus commandStatus = CommandExecStatus::NOT_STARTED;
	int commandRetVal = 0; // OK
};

#endif
