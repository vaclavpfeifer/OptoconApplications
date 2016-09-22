#ifndef SERIAL_IO_COMMUNICATION_HELPER_H
#define SERIAL_IO_COMMUNICATION_HELPER_H

#include "Helpers/AbstractCommunicationHelper.h"
#include <QtSerialPort/QSerialPort>

class SerialIOCommunicationHelper : public AbstractCommunicationHelper
{
public:
	SerialIOCommunicationHelper();
	virtual ~SerialIOCommunicationHelper();

	void someMethod()
	{
		QSerialPort serialPort;
		QString serialPortName = "SERIAL_PORT_NAME";
		int serialPortBaudRate = QSerialPort::Baud9600;

		serialPort.setPortName(serialPortName);		
		serialPort.setBaudRate(serialPortBaudRate);

		if (!serialPort.open(QIODevice::ReadOnly)) {
			/*standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialPort.error()) << endl;
			return 1;*/
		}

		QByteArray readData = serialPort.readAll();

		while (serialPort.waitForReadyRead(5000))
			readData.append(serialPort.readAll());

		if (serialPort.error() == QSerialPort::ReadError) {
			/*standardOutput << QObject::tr("Failed to read from port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
			return 1;*/
		}
		else if (serialPort.error() == QSerialPort::TimeoutError && readData.isEmpty()) {
			/*standardOutput << QObject::tr("No data was currently available for reading from port %1").arg(serialPortName) << endl;
			return 0;*/
		}

		// standardOutput << QObject::tr("Data successfully received from port %1").arg(serialPortName) << endl;
		//standardOutput << readData << endl;

	}
};

#endif
