#ifndef QTTESTAPP1_H
#define QTTESTAPP1_H

#include <QtWidgets/QMainWindow>
#include "ui_qttestapp1.h"

class QTtestapp1 : public QMainWindow
{
	Q_OBJECT

public:
	// Constructors/destructors...
	explicit QTtestapp1(QWidget *parent = 0);
	virtual ~QTtestapp1();

	// Public methods...
	inline void method()
	{
		// this->ui.btn_RemoveText
	}

	// Here goes signal-handlers
private slots:
	static void on_quitButton_clicked();
	void on_btn_RemoveText_clicked();
	inline void slotTestMethod()
	{
		//qApp->quit();
		this->ui.textEdit->setPlainText("sdfsdfsdfsdfsdfsdfsdfsd ");
	}


	// TODO: Where to get list of default slots/signals?

private:
	Ui::QTtestapp1Class ui;
};

#endif // QTTESTAPP1_H
