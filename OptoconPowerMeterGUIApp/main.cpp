#include <QtWidgets/QApplication>
#include "Views/OptoconAbstractView.hpp"
#include "Views/OptoconBasicDevelopmentView.h"
#include "Views/OptoconTargetEmbededView.h"
#include "ViewModels/BasicViewModel.h"
#include "Commands/DefaultCommandFactory.h"

#include <QtDebug>
#include <stdio.h>
#include <fstream>
#include <mutex>
#include "Helpers/LogHelper.h"



int main(int argc, char *argv[])
{	
	// TODO: problem if new logger is registered after some logger has already been taken then the original - need to destroy previous intance --> use reference counting
	LogHelper::RegisterLogger(new QtLogger(AbstractLogger::INFORMATION));
	auto logger = LogHelper::GetLogger();	
	

	logger->Log(AbstractLogger::DEBUG, "Debug started...");
	logger->Log(AbstractLogger::INFORMATION, "Information entry...");
	logger->Log(AbstractLogger::WARNING, "Warning entry...");	


	QApplication a(argc, argv);

	// Create View Model	
	// auto viewModel = std::make_shared<BasicViewModel>();
	BasicViewModel viewModel;

	// Create additional dependencies
	DefaultCommandFactory cmdFactory(viewModel);
	
	// Create View with proper ViewModel
	//OptoconAbstractView w;
    //auto view = std::make_unique<OptoconBasicDevelopmentView>(cmdFactory, viewModel);

    //auto view = std::make_unique<OptoconTargetEmbededView>(cmdFactory, viewModel); // make_unique is c++14 feature
    auto view = std::make_shared<OptoconTargetEmbededView>(cmdFactory, viewModel);

	view->show();
	return a.exec();
}

