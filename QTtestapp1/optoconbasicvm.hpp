#ifndef MAIN_WINDOW_OPTOCON_H
#define MAIN_WINDOW_OPTOCON_H
#include <QObject>

#include <QtWidgets/QMainWindow>
#include "ui_Optocon_Base_View.h"
#include "ui_setlimitwindow.h"
#include "setlimitwindow.h"

class OptoconBasicVM : public QMainWindow
{
	Q_OBJECT

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

	static void CheckedHandler(QCheckBox* checkedBox, QTextEdit* textEdit);

	// Limit Set-up
	static void CheckLimit();

	void onNewLimitSet(QString newLimit) const;

	void onBtnClick_SetLimit();

	void onRBStatusChanged(bool isChecked);

// Events
signals:
	void CBStateChanged(QCheckBox* checkedBox, QTextEdit* textEdit);

private:
	Ui::MainWindowOptocon ui;
};

#endif
