#include "SimpleLogger.h"



SimpleLogger::~SimpleLogger()
{
}

void SimpleLogger::Log(LogLevel logLevel, QString msg)
{
	QMutexLocker locker(&mutex);

	// TODO: set up to file
	// Should we keep file open for whole app execution frame? or close each time / after some inactivity time???

	if (logLevel >= minimum_log_level_)
	{
		auto dateTime = QDateTime::currentDateTime();
		auto ddd = dateTime.toString(Qt::TextDate).toStdString();

		std::ofstream myfile;
		myfile.open(log_file_name_.toStdString(), std::ios::app);

		myfile << ddd << "\t" << logLevelEnumMap[logLevel] << "\t" << msg.toStdString() << std::endl;

		myfile.close();
	}
}
