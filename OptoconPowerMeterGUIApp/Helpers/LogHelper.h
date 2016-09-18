#ifndef LOG_HELPER_H
#define LOG_HELPER_H
#include "Common/AbstractLogger.h"
#include "Common/QtLogger.h"

class LogHelper
{
private:
	LogHelper() 
	{		
		defaultLoggerImpl = new QtLogger(AbstractLogger::LogLevel::DEBUG);
		registeredLoggerImpl = defaultLoggerImpl;
	}
	virtual ~LogHelper()
	{
		int a = 0;
	}

public:
	static AbstractLogger* GetLogger()
	{
		return LogHelper::INSTANCE().registeredLoggerImpl;		
	}	

	LogHelper(LogHelper const&) = delete;
	void operator=(LogHelper const&) = delete;
	
	static void RegisterLogger(AbstractLogger* loggerImpl)
	{
		// TODO: remove previous instance --> move to reference counting objects...

		LogHelper::INSTANCE().registeredLoggerImpl = loggerImpl;
	}

protected:
	static LogHelper& INSTANCE()
	{
		static LogHelper instance;
		return instance;
	}

private:
	AbstractLogger* registeredLoggerImpl;

	AbstractLogger* defaultLoggerImpl;
};

#endif
