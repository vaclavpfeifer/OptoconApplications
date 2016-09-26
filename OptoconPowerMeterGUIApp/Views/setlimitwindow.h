#ifndef SETLIMITWINDOWTEST_H
#define SETLIMITWINDOWTEST_H

#include <QWidget>
#include "ui_setlimitwindow.h"

class QMainWindow;

class SetLimitWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SetLimitWindow(QObject* caller = nullptr);
	~SetLimitWindow();

public slots:
	void OnDialogBoxOKClicked();
	void OnDialogBoxCancelClicked();

signals:
	void LimitChanged(QString newLimit);

private:
	Ui::SetLimitWindow ui;
};

#endif // SETLIMITWINDOWTEST_H
