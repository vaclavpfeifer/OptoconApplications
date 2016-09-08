#ifndef GUI_COMMAND_H
#define GUI_COMMAND_H

#include "Commands\AbstractCommand.h"
#include "ViewModels\AbstractViewModel.h"
#include <functional>
#include <memory>

class GUICommand : public AbstractCommand
{
public:
	GUICommand()
	{

	}
	virtual ~GUICommand();

	// Inherited via AbstractCommand
	virtual int execute() override
	{
		// Disable WaveLength
		viewModel->setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF);


		// Call another commands? Or do this in some kind of composite command?


		return 0;
	}

	// TODO: or better registry viewModel to factory/OR for gui commands we should have execute with parameter which is taking ViewModel?
	void setViewModel(std::shared_ptr<AbstractViewModel>& vm)
	{
		this->viewModel = vm;
	}

	void setCustomCode(std::function<int()> predicate)
	{

	}

private:
	std::shared_ptr<AbstractViewModel> viewModel;
};

#endif