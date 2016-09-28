#ifndef POLLING_COMMAND_H
#define POLLING_COMMAND_H
#include "CommunicationCommand.h"
#include <functional>
#include <chrono>

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
		while(shouldExit)
		{
			auto rv = CommunicationCommand::execute(); // call base class execute

			updateViewModelCallback(10);

			// Some sleep Cond -- TODO: change to some autoreset event??
			std::this_thread::sleep_for(std::chrono::seconds(1));

			//					
		}

		return 0;
	}

public slots:

	// TODO: This should later set up some cond variable instead
	void exitPollingCommand()
	{
		this->shouldExit = true;
	}



private:
	int pollingInterval = 1000; // [ms]
	volatile bool shouldExit = false;

	const std::function<void(double)> updateViewModelCallback;

	// TODO: register callback which can be updated? Or register member to update??

};

#endif
