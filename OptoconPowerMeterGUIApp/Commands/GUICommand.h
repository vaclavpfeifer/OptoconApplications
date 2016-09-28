#ifndef GUI_COMMAND_H
#define GUI_COMMAND_H

// #include "Commands/AbstractCommand.h"
#include "ViewModels/AbstractViewModel.h"


#include <functional>
#include <memory>

class GUICommand : public AbstractCommand
{
public:
	GUICommand(AbstractViewModel& viewModel)
		: viewModel(viewModel)
	{

	}
	virtual ~GUICommand()
	{
		int a = 5;
	}

	// Inherited via AbstractCommand
	virtual int execute() const override
	{
		// Disable WaveLength
		viewModel.setActiveWaveLength(WaveLengthEnum::WAVELENGTH_OFF);		
		return 0;
	}

	/*int execute(std::function<int()> predicate)
	{
		return predicate();
	}*/

private:
	AbstractViewModel& viewModel;
};

#endif
