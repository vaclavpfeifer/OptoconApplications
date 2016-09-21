#include <QtWidgets/QApplication>
#include "Views/OptoconAbstractView.hpp"
#include "Views/OptoconBasicDevelopmentView.h"
#include "Views/OptoconTargetEmbededView.h"
//#include "ViewModels/BasicViewModel.h"
#include "ViewModels/AbstractViewModel.h"
#include "Commands/DefaultCommandFactory.h"

#include <QtDebug>
#include <stdio.h>
#include <fstream>
#include <mutex>
#include "Helpers/LogHelper.h"



int main(int argc, char *argv[])
{	
	// TODO: problem if new logger is registered after some logger has already been taken then the original - need to destroy previous intance --> use reference counting
	// TODO: The hardcoded file name is used instead of updated one
	LogHelper::RegisterLogger(std::make_shared<QtLogger>(AbstractLogger::INFORMATION, "_NewLogFile.log"));
	LogHelper::SetQtLogFileName("_AnotherLogFileName.log");
	auto logger = LogHelper::GetLogger();	
	

	logger->Log(AbstractLogger::DEBUG, "Debug started...");
	logger->Log(AbstractLogger::INFORMATION, "Information entry...");
	logger->Log(AbstractLogger::WARNING, "Warning entry...");	


	QApplication a(argc, argv);

	// Create View Model & factory (circular dependency on each other) -- Or factory could be singleton and referenced statically???
	// auto viewModel = std::make_shared<BasicViewModel>();
	//BasicViewModel viewModel;
	std::shared_ptr<BasicViewModel> viewModel;
	std::shared_ptr<DefaultCommandFactory> cmdFactory;


	// It is possible to use shared_ptr<Base> but it needs to be cast -- i.e. use either static_pointer_cast or dynamic_pointer_cast
	cmdFactory = std::make_shared<DefaultCommandFactory>(*viewModel);
	viewModel = std::make_shared<BasicViewModel>(*cmdFactory);	
	
	


	// TODO: when circular references solved update to shared pointer inside the View....
	auto view = std::make_shared<OptoconTargetEmbededView>(*viewModel);
	view->show();

	return a.exec();
}

