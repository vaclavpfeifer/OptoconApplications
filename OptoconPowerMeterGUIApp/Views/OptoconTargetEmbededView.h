#ifndef OPTOCON_TARGET_EMBEDED_VIEW_H
#define OPTOCON_TARGET_EMBEDED_VIEW_H

#include "Views/OptoconAbstractView.hpp"
#include "ui_OptoconTargetEmbededView.h"

class OptoconTargetEmbededView : public OptoconAbstractView
{
	Q_OBJECT

public:
	OptoconTargetEmbededView(AbstractCommandFactory& cmdFactory, AbstractViewModel& viewModel, QWidget * parent = Q_NULLPTR);
	virtual ~OptoconTargetEmbededView();

private:
	void InitializeConnections() override;

private slots: 
	void onNewLimitSet(QString newLimit) const; // Handler called when limitsetwindow exited & value set
	
	// Binding handlers (handlers raised in viewModel)
	void onWaveLengthChanged(WaveLengthEnum newWaveLength);
	void OnSingleOrMultiModeChanged(bool isSm) const;
	void OnReferenceChanged(bool isDb) const;

private:
	Ui::OptoconTargetLinuxView ui;
};

#endif
