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

std::mutex myMutex;

void myMessageOutputToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	std::lock_guard<decltype(myMutex)> lock(std::mutex);
	auto pFile = fopen("_myLogfile.txt", "a+");

	QByteArray localMsg = msg.toLocal8Bit();
	switch (type) {
	case QtDebugMsg:		
		fprintf(pFile, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtInfoMsg:
		fprintf(pFile, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtWarningMsg:
		fprintf(pFile, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtCriticalMsg:
		fprintf(pFile, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtFatalMsg:
		fprintf(pFile, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		abort();
	default:
		break;
	}

	fflush(pFile);
	fclose(pFile);
}

int main(int argc, char *argv[])
{	

	// TODO wrap this to my logger
	qInstallMessageHandler(myMessageOutputToFile);


	//auto pFile = fopen("_myLogfile.txt", "w");
	//fprintf(pFile, "Started.....");
	//fflush(pFile);
	//fclose(pFile);

	//std::ofstream myfile;
	//myfile.open("_example.txt");
	//myfile << "Writing this to a file.\n";
	//myfile.close();


	// TODO: add some logger
	// TODO: add builder pattern - for mocking / debugging / app release version...
	// qApp->addLibraryPath("C:\\Qt\\Qt5.7.0\\5.7\\msvc2015\\bin");
	
	qDebug() << "Application started...";

	//auto commandFactory = std::make_shared<DefaultCommandFactory>();

	QApplication a(argc, argv);

	// Create View Model

	// VM is not used at this point

	// TODO: switch viewModel to reference and update code accordinghly..
	// auto viewModel = std::make_shared<BasicViewModel>();
	BasicViewModel viewModel;


	DefaultCommandFactory cmdFactory(viewModel);

	//OptoconAbstractView w;
	// Create View with proper ViewModel
    //auto view = std::make_unique<OptoconBasicDevelopmentView>(cmdFactory, viewModel);

    //auto view = std::make_unique<OptoconTargetEmbededView>(cmdFactory, viewModel); // make_unique is c++14 feature
    auto view = std::make_shared<OptoconTargetEmbededView>(cmdFactory, viewModel);

	view->show();
	return a.exec();
}

