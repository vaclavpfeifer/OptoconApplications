// TODO: change to IFDEFINED!

#pragma once

#include "AbstractViewModel.h"
#include "ui_OptoconBasicDevelopmentView.h"

class BasicViewModel : public AbstractViewModel
{
public:
	BasicViewModel();

	virtual ~BasicViewModel();

	virtual void ViewAll()
	{

	}

protected:
	Ui::MainWindowOptocon ui;

};

