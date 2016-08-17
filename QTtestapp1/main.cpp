#include "qttestapp1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QGuiApplication a(argc, argv); // Without widgets

	QTtestapp1 w;
	w.show();


	return a.exec();
}
