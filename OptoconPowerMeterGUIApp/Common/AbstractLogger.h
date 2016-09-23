#ifndef ABSTRACT_LOGGER_H
#define ABSTRACT_LOGGER_H
#include <qstring.h>
#include <qobjectdefs.h>
#include <qobject.h>
#include <QMetaEnum>

// TODO: Implement as a singleton + adapter?
// Or leave abstract class here and make adapters platform dependent (different log library for different platform?)

class AbstractLogger : QObject
{	
	Q_OBJECT

public:	
	AbstractLogger()
	{	
		// Should this be made static? or initialized elsewhere?
		QMetaObject obj = AbstractLogger::staticMetaObject;
		QMetaEnum tmpObj = obj.enumerator(0);
		for (int i = 0; i < tmpObj.keyCount(); i++)
		{
			auto value = tmpObj.key(i);
			auto key = tmpObj.value(i);
			logLevelEnumMap[static_cast<LogLevel>(key)] = value;
		}		
	}


	virtual ~AbstractLogger();

	enum LogLevel
	{
		DEBUG,
		INFORMATION,
		WARNING,
		ERROR
	};
	Q_ENUM(LogLevel)

	

	virtual void Log(LogLevel logLevel, QString msg) = 0;	

protected:
	std::map<LogLevel, const char*> logLevelEnumMap;
};

#endif
