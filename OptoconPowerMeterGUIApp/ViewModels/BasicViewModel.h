#ifndef BASIC_VIEW_MODEL_H
#define BASIC_VIEW_MODEL_H

#include "AbstractViewModel.h"
#include "Helpers/SerialIOCommunicationHelper.h"
#include "Commands/CommunicationCommand.h"
#include "Commands/WaveLengthChangedCommand.h"
#include "Commands/AbstractCommandFactory.h"


class BasicViewModel : public AbstractViewModel
{
public:
	BasicViewModel(const AbstractCommandFactory& cmdFact)
		: AbstractViewModel(cmdFact)
	{
		auto cmd = commandFactory.CreateGUICommand();

		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_850, commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_850)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1310, commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1310)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1310, commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1310)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1500, commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1500)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_OFF, commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_OFF)));

		// Some default commands registration can be done as well!! -- TODO: do default registration in base class and allow overwriting of values when registering
		
	}

	virtual ~BasicViewModel();


};

#endif
