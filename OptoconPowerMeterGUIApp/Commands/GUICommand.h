#ifndef GUI_COMMAND_H
#define GUI_COMMAND_H

#include "Commands\AbstractCommand.h"
#include <functional>

class GUICommand : public AbstractCommand
{
public:
	GUICommand();
	virtual ~GUICommand();

	// Inherited via AbstractCommand
	virtual int execute() override
	{
		return 0;
	}

	void setCustomCode(std::function<int()> predicate)
	{

	}

private:

};

#endif
