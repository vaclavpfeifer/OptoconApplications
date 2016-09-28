#include "ViewModels/BasicViewModel.h"

BasicViewModel::BasicViewModel(const AbstractCommandFactory& cmdFact): AbstractViewModel(cmdFact)
{
	auto cmd = commandFactory.CreateGUICommand();

	registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_850, std::make_shared<CommandExecHelper>(commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_850))));
	registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1300, std::make_shared<CommandExecHelper>(commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1300))));
	registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1310, std::make_shared<CommandExecHelper>(commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1310))));
	registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_1500, std::make_shared<CommandExecHelper>(commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_1500))));
	registeredWaveLengthCommands.insert(std::make_pair(WaveLengthEnum::WAVELENGTH_OFF, std::make_shared<CommandExecHelper>(commandFactory.CreateWLChangedCmd(WaveLengthEnum::WAVELENGTH_OFF))));

	// Some default commands registration can be done as well!! -- TODO: do default registration in base class and allow overwriting of values when registering

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A1,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateSerialIOCommand(), false, 3))); // This should set up command that should not be retried

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A2,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateSerialIOCommand(), true, 3))); // This should set up command that should be retried 3-times

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A3,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateSerialIOCommand()))); // This should set up command that should not be retried

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::CHECKBOX_A4,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateSerialIOCommand(), true, 5))); // This should set up command that should  be retried 5 times

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_REFERENCE,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateReferenceRequestedCmd(), false)));

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_WAVELENGTH,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateWavelengthRequestedCmd(), false)));

	registeredCommands.insert(std::make_pair(WidgetsCodeMap::PUSHBUTTON_SERIALNUMBER,
	                                         std::make_shared<CommandExecHelper>(commandFactory.CreateSerialNumberRequestedCmd(), false)));
}

BasicViewModel::~BasicViewModel()
{
}
