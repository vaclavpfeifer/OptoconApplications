#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H
#include <qstring.h>

// TODO: Implement as a singleton + adapter?
// Or leave abstract class here and make adapters platform dependent (different log library for different platform?)

class AbstractLogger
{	
public:	
	AbstractLogger();
	virtual ~AbstractLogger();

	enum LogLevel
	{
		DEBUG,
		INFORMATION,
		WARNING,
		ERROR
	};

	virtual void Log(LogLevel logLevel, QString msg) = 0;	

};

#endif
