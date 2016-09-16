#ifndef SETLIMITWINDOWTEST_H
#define SETLIMITWINDOWTEST_H

#include <QWidget>
#include "ui_setlimitwindow.h"

class QMainWindow;

class SetLimitWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SetLimitWindow(QObject* caller);
	~SetLimitWindow();

public slots:
	void onDialogBoxClick(QAbstractButton* btn);
	void onDialogBoxCancelClick(QAbstractButton* btn);

signals:
	void LimitChanged(QString newLimit);

private:
	Ui::SetLimitWindow ui;
};

#endif // SETLIMITWINDOWTEST_H
