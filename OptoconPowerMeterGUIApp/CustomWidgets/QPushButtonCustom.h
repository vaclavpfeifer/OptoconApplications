#ifndef QPUSHBUTTONCUSTOM_H
#define QPUSHBUTTONCUSTOM_H

#include "qpushbutton.h"

class QPushButtonCustom : public QPushButton
{
public:
	QPushButtonCustom() : isChecked(true)
	{		
	}

	virtual ~QPushButtonCustom();

	bool IsAllChecked() const
	{
		return this->isChecked;
	}

private:
	bool isChecked;

};


#endif
