#ifndef POLLING_COMMAND_H
#define POLLING_COMMAND_H
#include "CommunicationCommand.h"
#include <functional>
#include <chrono>
#include <atomic>

class PollingCommand : public CommunicationCommand
{
public:
	PollingCommand(const AbstractCommunicationHelper& ioCommunicationHelper, const QString& execStr,
				   std::function<void(double)> updateVMCallback = nullptr, int pollInterval = 1000)
		: CommunicationCommand(ioCommunicationHelper, execStr),
		pollingInterval(pollInterval)
	{
		//callback(121);
	}

	virtual ~PollingCommand();

	int execute() const override
	{
		while(this->shouldExit)
		{
			auto rv = CommunicationCommand::execute(); // call base class execute

			updateViewModelCallback(10);

			// Some sleep Cond -- TODO: change to some autoreset event??
			std::this_thread::sleep_for(std::chrono::seconds(1));

			//					
		}

		// we cant do this because its const method!! --> We should rather emit signals...
		// this->shouldExit = false;

		return 0;
	}

	// TODO: We could make this Qobject and put here signals like finished/in_progress and slots in executor could handle this and vice-versa
	// We could pass caller in ctor and create a link to enable command canceling...


public slots:

	// TODO: This should later set up some cond variable instead
	void exitPollingCommand()
	{
		this->shouldExit = true;
	}


public:
	void SetShouldExit(bool val)
	{
		// Put mutex here

		shouldExit = val;

	}


private:
	int pollingInterval = 1000; // [ms]
	std::atomic<bool> shouldExit = false;

	const std::function<void(double)> updateViewModelCallback;	

};

#endif
