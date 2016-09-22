#ifndef QT_LOGGER_H
#define QT_LOGGER_H

#include "Common/AbstractLogger.h"
#include <mutex>
#include <QtDebug>


//typedef void(*QtMessageHandler)(QtMsgType, const QMessageLogContext &, const QString &);
//
//typedef void(QtLogger::*myMessageOutputToFile)(QtMsgType, const QMessageLogContext &, const QString &);

class QtLogger : public AbstractLogger
{
public:
	QtLogger(LogLevel minLogLevel, QString logFileName = "_ApplicationLog.txt") //: minimumLogLevel(minLogLevel)
	{
		minimumLogLevel = minLogLevel;
		//QtLogger::logFileName = logFileName;

		// Do initialization here:
		//qInstallMessageHandler(myMessageOutputToFile);		
		
		//QtMessageHandler ptr = &QtLogger::myMessageOutputToFileTest;

		//void QtLogger::*ptr = &this->myMessageOutputToFileTest;

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

	void SetLogFileName(QString newLogFileName) override
	{
		QtLogger::logFileName = newLogFileName;
	}

private:
	std::mutex myMutex;
	LogLevel minimumLogLevel = LogLevel::ERROR;
	static QString logFileName;



	static void myMessageOutputToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
	{		
		// TODO: move to c++ streams....
		// TODO: this piece of code is being initialized only once, in order to support different log file names, we need to change to local method
		auto pFile = fopen(logFileName.toStdString().c_str(), "a+");

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
};

#endif

