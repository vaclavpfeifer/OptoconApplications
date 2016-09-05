#ifndef MAIN_WINDOW_OPTOCON_H
#define MAIN_WINDOW_OPTOCON_H

#include "ui_OptoconBasicDevelopmentView.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ViewModels\AbstractViewModel.h"

class OptoconAbstractView : public QMainWindow
{
	Q_OBJECT

// Constructors/Desstructors
public:
	explicit OptoconAbstractView(QWidget * parent = Q_NULLPTR);

	explicit OptoconAbstractView(AbstractViewModel* viewModel, int a);
	~OptoconAbstractView();


// Handlers
public slots:

	// A-A4 set-up
	void ViewAll();
	void CheckedA1();
	void CheckedA2();
	void CheckedA3();
	void CheckedA4();

	void onWaveLength850Clicked();

	void onWaveLength1300Clicked();

	void onWaveLength1310Clicked();

	void onWaveLength1550Clicked();

	void onWaveLengthOFFClicked();

	void onReference_dBClicked() const;

	void onReference_dBMmClicked() const;

	static void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit);

	// Limit Set-up
	static void CheckLimit();

	void onNewLimitSet(QString newLimit) const;

	void onBtnClick_SetLimit();

	void onRBStatusChanged(bool isChecked);

// Events
signals:
	void CBStateChanged(QCheckBox* checkedBox, QTextEdit* textEdit);
	void WaveLengthChanged(QPushButton* clickedPB);

protected:
	std::list<QPushButton*> waveLengthButtons;

	void DisableWaveLengthButtons();

public:
	// TODO: make pure virtual...
	inline virtual QTextEdit* GetTextEditA1()
	{
		return ui.textEdit_A1;
	}

private:
	Ui::MainWindowOptocon ui;

	// Ui::OptoconTargetLinuxView ui;
};



#endif
