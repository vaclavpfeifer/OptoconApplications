#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H
#include "Common/AbstractLogger.h"
#include <QMutex>
#include <QMetaEnum>
#include <iostream>
#include <fstream>
#include <qdatetime.h>

class SimpleLogger : public AbstractLogger
{
public:
	SimpleLogger(AbstractLogger::LogLevel minimumLogLevel, QString logFileName)
		: log_file_name_(logFileName), minimum_log_level_(minimumLogLevel)
	{		
	}

	virtual ~SimpleLogger();


	void Log(LogLevel logLevel, QString msg) override;

private:
	QMutex mutex;
	QString log_file_name_;
	AbstractLogger::LogLevel minimum_log_level_;
};

#endif
