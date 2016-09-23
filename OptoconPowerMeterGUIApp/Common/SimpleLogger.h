#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H
#include "Common/AbstractLogger.h"
#include <QMutex>
#include <QMetaEnum>
#include <iostream>

class SimpleLogger : public AbstractLogger
{
public:
	SimpleLogger(AbstractLogger::LogLevel minimumLogLevel, QString logFileName)
		: log_file_name_(logFileName), minimum_log_level_(minimumLogLevel)
	{
		
	}

	virtual ~SimpleLogger();


	void Log(LogLevel logLevel, QString msg) override
	{
		QMutexLocker locker(&mutex);

		// TODO: set up to file
		// Should we keep file open for whole app execution frame? or close each time / after some inactivity time???

		if (logLevel >= minimum_log_level_)
		{
			std::cout << logLevelEnumMap[logLevel] << "\t" << msg.toStdString() << std::endl;
		}
	}

private:
	QMutex mutex;
	QString log_file_name_;
	AbstractLogger::LogLevel minimum_log_level_;
};

#endif
