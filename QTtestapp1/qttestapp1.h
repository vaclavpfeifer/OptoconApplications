#ifndef QTTESTAPP1_H
#define QTTESTAPP1_H

#include <QtWidgets/QMainWindow>
#include "ui_qttestapp1.h"
#include "ui_secondView.h"

// TODO: Create second initial UI class and define in makefile which should be compiled/linked

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
	// Ui::QTtestapp1Class ui;
	Ui::MainWindow ui;
};

#endif // QTTESTAPP1_H
