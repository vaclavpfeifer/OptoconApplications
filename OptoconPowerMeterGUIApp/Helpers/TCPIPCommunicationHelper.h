#ifndef TCP_IP_COMMUNICATION_HELPER_H
#define TCP_IP_COMMUNICATION_HELPER_H

#include "Helpers/AbstractCommunicationHelper.h"

class TCPIPCommunicationHelper : public AbstractCommunicationHelper
{
public:
	TCPIPCommunicationHelper();
	virtual ~TCPIPCommunicationHelper();
	
	
	QSerialPort::SerialPortError SendCommand(const QString& request, QString& response) override
	{
		throw new std::exception("Not Implemented Exception");
	}

	QString readData() const override
	{
		throw new std::exception("Not Implemented Exception");
	}

	void writeData(const QString& data) const override
	{
		throw new std::exception("Not Implemented Exception");
	}

};

#endif
