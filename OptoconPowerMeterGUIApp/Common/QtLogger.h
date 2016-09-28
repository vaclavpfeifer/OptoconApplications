#ifndef QT_LOGGER_H
#define QT_LOGGER_H

#include "Common/AbstractLogger.h"
#include <mutex>
#include <QtDebug>
#include <QDateTime>

//typedef void(*QtMessageHandler)(QtMsgType, const QMessageLogContext &, const QString &);
//
//typedef void(QtLogger::*myMessageOutputToFile)(QtMsgType, const QMessageLogContext &, const QString &);

class QtLogger : public AbstractLogger
{
public:
	QtLogger(LogLevel minLogLevel, QString logFileName = "_ApplicationLog.txt") //: minimumLogLevel(minLogLevel)
	;

	virtual ~QtLogger();

	void Log(LogLevel logLevel, QString msg) override;

private:
	std::mutex myMutex;
	LogLevel minimumLogLevel = LogLevel::ERROR;
	static QString logFileName;

	static void myMessageOutputToFile(QtMsgType type, const QMessageLogContext& context, const QString& msg);
};

#endif

