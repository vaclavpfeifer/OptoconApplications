#include "qtexteditcustom.hpp"

QTextEditCustom::QTextEditCustom(QWidget* caller) : QTextEdit()
{
	// setupUi(this);

	emit someSignal();
}

QTextEditCustom::~QTextEditCustom() {
	
}

void QTextEditCustom::mousePressEvent(QMouseEvent *event)
{
	emit someSignal();
}

void QTextEditCustom::mouseReleaseEvent(QMouseEvent *e)
{
	emit someSignal();
}

void QTextEditCustom::mouseDoubleClickEvent(QMouseEvent *e)
{
	emit someSignal();
}