#include <QtWidgets/QApplication>
#include "Views\OptoconAbstractView.hpp"
#include "Views\OptoconBasicDevelopmentView.h"
#include "Views\OptoconTargetEmbededView.h"
#include "ViewModels\BasicViewModel.h"
#include "Commands\CommandFactory.h"

int main(int argc, char *argv[])
{
	// TODO: move to reference counting 
	// TODO: add some logger

	// qApp->addLibraryPath("C:\\Qt\\Qt5.7.0\\5.7\\msvc2015\\bin");

	auto commandFactory = new CommandFactory();

	auto cmd = commandFactory->CreateCommand2();


	QApplication a(argc, argv);

	// Create View Model
	// VM is not used at this point
	auto viewModel = new BasicViewModel();

	//OptoconAbstractView w;
	// Create View with proper ViewModel
	auto view = new OptoconBasicDevelopmentView(viewModel);
	// auto view = new OptoconTargetEmbededView();


	view->show();
	return a.exec();
	delete view;
}
