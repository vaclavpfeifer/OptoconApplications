#ifndef BASIC_VIEW_MODEL_H
#define BASIC_VIEW_MODEL_H

#include "AbstractViewModel.h"
#include "Helpers/SerialIOCommunicationHelper.h"
#include "Commands/DefaultCommandFactory.h"
#include "Commands/CommunicationCommand.h"
#include "Commands/WaveLengthChangedCommand.h"

class BasicViewModel : public AbstractViewModel
{
public:
	BasicViewModel()
	{
		// auto fact = new DefaultCommandFactory(*this);

		// register commands here

		// This is only test!!!!!
		//registeredWaveLengthCommands.insert(std::make_pair(0, new CommunicationCommand(*(new SerialIOCommunicationHelper()))));

		// Some default commands registration can be done as well!! -- TODO: do default registration in base class and allow overwriting of values when registering

		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_850, new WaveLengthChangedCommand(*(new SerialIOCommunicationHelper()), WaveLengthEnum::WAVELENGTH_850  )));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1300, new WaveLengthChangedCommand(*(new SerialIOCommunicationHelper()), WaveLengthEnum::WAVELENGTH_1300)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1310, new WaveLengthChangedCommand(*(new SerialIOCommunicationHelper()), WaveLengthEnum::WAVELENGTH_1310)));
		registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1500, new WaveLengthChangedCommand(*(new SerialIOCommunicationHelper()), WaveLengthEnum::WAVELENGTH_1500)));
		// registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_OFF, new WaveLengthChangedCommand(*(new SerialIOCommunicationHelper()), WaveLengthEnum::WAVELENGTH_OFF)));

	}

	virtual ~BasicViewModel();


};

#endif
