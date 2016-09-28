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
	BasicViewModel(const AbstractCommandFactory& cmdFact);
	virtual ~BasicViewModel();
};

#endif
