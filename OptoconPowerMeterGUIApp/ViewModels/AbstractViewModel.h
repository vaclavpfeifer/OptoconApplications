#pragma once

class AbstractViewModel
{
public:
	AbstractViewModel();
	virtual ~AbstractViewModel();

	virtual void ViewAll() = 0;
};

