#pragma once
#include <QWidget>
#include "ui_qtexteditcustom.h"
#include "qtextedit.h"

class QTextEditCustom : public QTextEdit //, public Ui::QTextEditCustom 
{
	Q_OBJECT

public:
	QTextEditCustom(QWidget* caller = nullptr);
	~QTextEditCustom();

protected:
	// TODO: how to receive click event???


	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *e);
	virtual void mouseDoubleClickEvent(QMouseEvent *e);

signals:
	void someSignal();

private:
	
};
