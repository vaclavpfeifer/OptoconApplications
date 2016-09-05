#ifndef MAIN_WINDOW_OPTOCON_H
#define MAIN_WINDOW_OPTOCON_H

#include <QObject>
#include <QtWidgets/QMainWindow>
#include "ui_Optocon_Base_View.h"
#include "ui_OptoconTargetEmbededView.h"
#include "ui_setlimitwindow.h"
#include "setlimitwindow.h"
#include <vector>


class OptoconBasicVM : public QMainWindow
{
	Q_OBJECT

// Constructors/Desstructors
public:
	explicit OptoconBasicVM(QWidget * parent = Q_NULLPTR);
	~OptoconBasicVM();


// Handlers
public slots:



	// A-A4 set-up
	void ViewAll();
	void CheckedA1();
	void CheckedA2();
	void CheckedA3();
	void CheckedA4();

	inline void onWaveLength850Clicked()
	{
		DisableWaveLengthButtons();
		ui.PB_850->setChecked(true);
		//emit WaveLengthChanged(ui.PB_850);
	}

	inline void onWaveLength1300Clicked()
	{
		DisableWaveLengthButtons();
		ui.PB_1300->setChecked(true);
	}

	inline void onWaveLength1310Clicked()
	{
		DisableWaveLengthButtons();
		ui.PB_1310->setChecked(true);
	}

	inline void onWaveLength1550Clicked()
	{
		DisableWaveLengthButtons();
		ui.PB_1550->setChecked(true);
	}

	inline void onWaveLengthOFFClicked()
	{
		DisableWaveLengthButtons();
		ui.PB_OFF->setChecked(true);
	}

	inline void onReference_dBClicked()
	{
		ui.PB_dB->setChecked(true);
		ui.PB_dBm->setChecked(false);
	}

	inline void onReference_dBMmClicked()
	{
		ui.PB_dB->setChecked(false);
		ui.PB_dBm->setChecked(true);
	}

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

	void DisableWaveLengthButtons()
	{
		for each (auto pb in waveLengthButtons)
		{
			pb->setChecked(false);
		}
	}

private:
	//Ui::MainWindowOptocon ui;

	Ui::OptoconTargetLinuxView ui;
};

#endif
