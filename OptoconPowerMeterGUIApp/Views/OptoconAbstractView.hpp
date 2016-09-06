#ifndef OPTOCON_ABSTRACT_VIEW_H
#define OPTOCON_ABSTRACT_VIEW_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels\AbstractViewModel.h"

// TODO: 


class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

// Constructors/Desstructors
public:
	// explicit OptoconAbstractView();

	explicit OptoconAbstractView(AbstractViewModel* viewModel, QWidget * parent = Q_NULLPTR);
	~OptoconAbstractView();

// Handlers
public slots:
	
	// TODO: here should goes common handlers for commands/ non-ui methods
	// TODO: Gui-related methods should be probably removed from here and just moved to concrete impl class


	// Virtual methods with default implementation
	virtual void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit);

	// Pure virtual methods -- must be implemented
	// A-A4 set-up
	virtual void ViewAll() = 0;
	virtual void CheckedA1() = 0;
	virtual void CheckedA2() = 0;
	virtual void CheckedA3() = 0;
	virtual void CheckedA4() = 0;

	virtual void onWaveLength850Clicked() = 0;

	virtual void onWaveLength1300Clicked() = 0;

	virtual void onWaveLength1310Clicked() = 0;

	virtual void onWaveLength1550Clicked() = 0;

	virtual void onWaveLengthOFFClicked() = 0;

	virtual void onReference_dBClicked() = 0;

	virtual void onReference_dBMmClicked() = 0;	
	
	// Limit Set-up
	virtual void CheckLimit() = 0;

	virtual void onNewLimitSet(QString newLimit) = 0;

	virtual void onBtnClick_SetLimit() = 0;

	virtual void onRBStatusChanged(bool isChecked) = 0;

// Events
signals:
	void CBStateChanged(QCheckBox* checkedBox, QTextEdit* textEdit);
	void WaveLengthChanged(QPushButton* clickedPB);

};



#endif
