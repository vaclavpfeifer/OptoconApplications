#ifndef OPTOCON_BASIC_DEVELOPMENT_VIEW_H
#define OPTOCON_BASIC_DEVELOPMENT_VIEW_H

#include "ui_OptoconTargetEmbededView.h"
#include "Views/OptoconAbstractView.hpp"

class OptoconBasicDevelopmentView : public OptoconAbstractView
{	
	  Q_OBJECT

public:
	OptoconBasicDevelopmentView(AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);

	virtual ~OptoconBasicDevelopmentView();

private:
	void InitializeConnections() override;

private:	
	Ui::MainWindowOptocon ui;
};

#endif
