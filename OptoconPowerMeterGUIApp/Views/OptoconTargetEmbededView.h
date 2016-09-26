#ifndef OPTOCON_TARGET_EMBEDED_VIEW_H
#define OPTOCON_TARGET_EMBEDED_VIEW_H

#include "Views/OptoconAbstractView.hpp"
#include "ui_OptoconTargetEmbededView.h"

class OptoconTargetEmbededView : public OptoconAbstractView
{
	Q_OBJECT

public:
	OptoconTargetEmbededView(AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);
	virtual ~OptoconTargetEmbededView();

private:
	void InitializeConnections() override;

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
