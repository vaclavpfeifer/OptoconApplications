#include <QtWidgets/QApplication>
#include "Views\OptoconAbstractView.hpp"
#include "Views\OptoconBasicDevelopmentView.h"
#include "Views\OptoconTargetEmbededView.h"
#include "ViewModels\BasicViewModel.h"
#include "Commands\DefaultCommandFactory.h"

int main(int argc, char *argv[])
{	
	// TODO: add some logger
	// TODO: add builder pattern - for mocking / debugging / app release version...
	// qApp->addLibraryPath("C:\\Qt\\Qt5.7.0\\5.7\\msvc2015\\bin");
	

	//auto commandFactory = std::make_shared<DefaultCommandFactory>();

	QApplication a(argc, argv);
	DefaultCommandFactory cmdFactory;


	// Create View Model
	// VM is not used at this point

	// TODO: switch viewModel to reference and update code accordinghly..
	auto viewModel = std::make_shared<BasicViewModel>();

	//OptoconAbstractView w;
	// Create View with proper ViewModel
	auto view = std::make_unique<OptoconBasicDevelopmentView>(cmdFactory, viewModel);
	//auto view = std::make_unique<OptoconTargetEmbededView>(cmdFactory);


	//// auto view = new OptoconTargetEmbededView();


	view->show();
	return a.exec();
}
