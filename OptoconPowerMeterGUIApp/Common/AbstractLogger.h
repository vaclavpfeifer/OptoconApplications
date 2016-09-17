#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H
#include <qstring.h>

// TODO: Implement as a singleton + adapter?
// Or leave abstract class here and make adapters platform dependent (different log library for different platform?)

class AbstractLogger
{
protected:
	AbstractLogger();
public:	
	virtual ~AbstractLogger();

	static AbstractLogger& GetLogger()
	{
		return INSTANCE;
	}

	enum LogLevel
	{
		DEBUG,
		INFORMATION,
		WARNING,
		ERROR
	};

	void Log(LogLevel logLevel, QString msg)
	{
		
	}


protected:
	static AbstractLogger INSTANCE;
};

#endif
