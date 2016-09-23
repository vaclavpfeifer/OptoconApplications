#ifndef ABSTRACT_COMMUNICATION_HELPER_H
#define ABSTRACT_COMMUNICATION_HELPER_H
#include <QSerialPort>


class AbstractCommunicationHelper
{
public:
	AbstractCommunicationHelper();
	virtual ~AbstractCommunicationHelper();

	// TODO: Wrap to some Common error type (for all type of comm)
	virtual QSerialPort::SerialPortError SendCommand(const QString& request, QString& response) = 0;

	virtual QString readData() const = 0;

	virtual void writeData(const QString& data) const = 0;
};

#endif
