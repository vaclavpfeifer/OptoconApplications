#ifndef MAIN_WINDOW_OPTOCON_H
#define MAIN_WINDOW_OPTOCON_H
#include <QObject>

#include <QtWidgets/QMainWindow>
#include "ui_Optocon_Base_View.h"

class OptoconBasicVM : public QMainWindow
{
	Q_OBJECT

public:
	explicit OptoconBasicVM(QWidget * parent = Q_NULLPTR);
	~OptoconBasicVM();

private:
	Ui::MainWindowOptocon ui;
};

#endif
