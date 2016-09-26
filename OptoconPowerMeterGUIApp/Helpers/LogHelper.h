#ifndef LOG_HELPER_H
#define LOG_HELPER_H
#include "Common/AbstractLogger.h"
#include "Common/QtLogger.h"
#include "Common/SimpleLogger.h"
// TODO: should keep map of registered loggers and tog to ALL!!!


class LogHelper
{
private:
	LogHelper() 
	{		
		//defaultLoggerImpl = new QtLogger(AbstractLogger::LogLevel::DEBUG);
		defaultLoggerImpl = std::make_shared<SimpleLogger>(AbstractLogger::LogLevel::DEBUG, "default_simple_log.txt");
		registeredLoggerImpl = defaultLoggerImpl;
	}
	virtual ~LogHelper()
	{
		int a = 0;
	}

public:
	static std::shared_ptr<AbstractLogger> GetLogger()
	{
		return LogHelper::INSTANCE().registeredLoggerImpl;		
	}	

	LogHelper(LogHelper const&) = delete;
	void operator=(LogHelper const&) = delete;
	
	static void RegisterLogger(std::shared_ptr<AbstractLogger> loggerImpl)
	{		
		LogHelper::INSTANCE().registeredLoggerImpl = loggerImpl;
	}

protected:
	static LogHelper& INSTANCE()
	{
		static LogHelper instance;
		return instance;
	}

private:
	std::shared_ptr<AbstractLogger> registeredLoggerImpl;

	std::shared_ptr<AbstractLogger> defaultLoggerImpl;
};

#endif
