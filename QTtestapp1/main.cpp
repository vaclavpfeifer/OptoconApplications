#include "qttestapp1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	qApp->addLibraryPath("C:\Qt\Qt5.7.0\5.7\msvc2015\bin");

	QApplication a(argc, argv);
	//QGuiApplication a(argc, argv); // Without widgets

	QTtestapp1 w;
	w.show();


	return a.exec();
}
