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


		return QSerialPort::NoError;
	}
};

#endif
