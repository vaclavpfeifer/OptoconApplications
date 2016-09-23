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
	{
		minimumLogLevel = minLogLevel;
		QtLogger::logFileName = logFileName;

		qInstallMessageHandler(myMessageOutputToFile);
	}

	virtual ~QtLogger();

	void Log(LogLevel logLevel, QString msg) override
	{
		std::lock_guard<std::mutex> lock(myMutex);

		if (logLevel >= minimumLogLevel)
		{
			switch (logLevel)
			{
			case LogLevel::DEBUG:
				qDebug() << msg;
				break;
			case LogLevel::INFORMATION:
				qInfo() << msg;
				break;
			case LogLevel::WARNING:
				qWarning() << msg;
				break;
			case LogLevel::ERROR:
				qCritical() << msg;
				break;
			default: break;
			}
		}
	}	

private:
	std::mutex myMutex;
	LogLevel minimumLogLevel = LogLevel::ERROR;
	static QString logFileName;

	static void myMessageOutputToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
	{		
		// TODO: move to c++ streams....
		// TODO: this piece of code is being initialized only once, in order to support different log file names, we need to change to local method
		// , context.file, context.line, context.function

		auto pFile = fopen(logFileName.toStdString().c_str(), "a+");


		// TODO: CHAR SET PROBLEM!!!
		auto dateTimeStr = QDateTime::currentDateTime().toString(Qt::ISODate).toStdString().c_str();

		auto now = QDateTime::currentDateTime().toString(Qt::LocalDate);
		auto nowStd = now.toStdString();


		QByteArray localMsg = msg.toLocal8Bit();
		switch (type) 
		{
		case QtDebugMsg:			
			fprintf(pFile, "%s DEBUG: %s\n", dateTimeStr, localMsg.constData());
			break;
		case QtInfoMsg:
			fprintf(pFile, "%s INFO: %s\n", dateTimeStr, localMsg.constData());
			break;
		case QtWarningMsg:
			fprintf(pFile, "%s WARNING: %s\n", dateTimeStr, localMsg.constData());
			break;
		case QtCriticalMsg:
			fprintf(pFile, "%s ERROR: %s\n", dateTimeStr, localMsg.constData());
			break;
		case QtFatalMsg:
			fprintf(pFile, "%s FATAL: %s\n", dateTimeStr, localMsg.constData());
			abort();
		default:
			break;
		}

		fflush(pFile);
		fclose(pFile);
	}
};

#endif

