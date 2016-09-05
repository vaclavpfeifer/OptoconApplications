#include <QtWidgets/QApplication>
#include "Views/OptoconAbstractView.hpp"

int main(int argc, char *argv[])
{
	// qApp->addLibraryPath("C:\\Qt\\Qt5.7.0\\5.7\\msvc2015\\bin");

	QApplication a(argc, argv);

	OptoconAbstractView w;
	w.show();


	return a.exec();
}
