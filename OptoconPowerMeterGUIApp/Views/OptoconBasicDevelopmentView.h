#ifndef OPTOCON_BASIC_DEVELOPMENT_VIEW
#define OPTOCON_BASIC_DEVELOPMENT_VIEW

#include "ui_OptoconTargetEmbededView.h"
#include "OptoconAbstractView.hpp"

class OptoconBasicDevelopmentView : public OptoconAbstractView
{
	Q_OBJECT

public:
	OptoconBasicDevelopmentView();

	virtual ~OptoconBasicDevelopmentView();

	inline virtual QTextEdit* GetTextEditA1()
	{
		return ui.textEdit_A1;
	}

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
