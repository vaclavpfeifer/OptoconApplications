#ifndef SERIAL_IO_COMMUNICATION_HELPER_H
#define SERIAL_IO_COMMUNICATION_HELPER_H

#include "Helpers/AbstractCommunicationHelper.h"
#include <QtSerialPort/QSerialPort>
#include "Common/AbstractLogger.h"
#include "LogHelper.h"
#include <memory>
#include <QMutex>

class SerialIOCommunicationHelper : public AbstractCommunicationHelper
{
public:
	SerialIOCommunicationHelper(QString serialPortName = "DEF_SERIAL_PORT_NAME", int serialPortBaudRate = QSerialPort::Baud9600, int readTimeout = 5000)
		: serial_port_name_(serialPortName), serial_port_baud_rate_(serialPortBaudRate), readTimeout(readTimeout)
	{
	}

	virtual ~SerialIOCommunicationHelper();

	// TODO: Return static versions which will pass result by parameter and return error code?
	// TODO: should thsi class be singleton / or should be separate request processed sycnhonously (to access serial port one at a time?)


	QString readData()
	{
		QMutexLocker locker(&mutex); // Lock

		QString dataToReturn = "";
		QSerialPort serialPort;

		serialPort.setBaudRate(serial_port_baud_rate_);
		serialPort.setPortName(serial_port_name_);

		if (!serialPort.open(QIODevice::ReadOnly))
		{
			logger->Log(AbstractLogger::ERROR, QString("Failed to open %1, port: %2, error: %3").arg(serial_port_name_).arg(serial_port_name_).arg(serialPort.error()));
			return dataToReturn;
		}

		QByteArray readData = serialPort.readAll();

		while (serialPort.waitForReadyRead(readTimeout))
			readData.append(serialPort.readAll()); // READ DATA HERE

		if (serialPort.error() == QSerialPort::ReadError) 
		{
			logger->Log(AbstractLogger::ERROR, QString("Failed to open %1, port: %2, error: %3").arg(serial_port_name_).arg(serial_port_name_).arg(serialPort.error()));
		}
		else if (serialPort.error() == QSerialPort::TimeoutError && readData.isEmpty()) 
		{
			logger->Log(AbstractLogger::WARNING, QString("No data was currently available for reading from %1 port: %2").arg(serial_port_name_).arg(serial_port_name_));
		}		

		dataToReturn = QString::fromUtf8(readData);
		return dataToReturn;
	}

	void writeData(QString data)
	{
		QMutexLocker locker(&mutex); // Lock

		QSerialPort serialPort;

		serialPort.setBaudRate(serial_port_baud_rate_);
		serialPort.setPortName(serial_port_name_);

		if (!serialPort.open(QIODevice::WriteOnly))
		{
			logger->Log(AbstractLogger::ERROR, QString("Failed to open %1, port: %2, error: %3").arg(serial_port_name_).arg(serial_port_name_).arg(serialPort.error()));			
		}

		auto reqData = data.toLocal8Bit(); // Conver to byte array

		qint64 bytesWritten = serialPort.write(reqData);

		if (bytesWritten == -1) {
			/*standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
			return 1;*/
		}
		else if (bytesWritten != reqData.size()) {
			/*standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
			return 1;*/
		}
		else if (!serialPort.waitForBytesWritten(5000)) {
			/*standardOutput << QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
			return 1;*/
		}

	}

	// This should simulate request/response 
	// TODO: create new ERROR ENUM and wrap to this one (in order to use common interface)
	QSerialPort::SerialPortError SendCommand(const QString& request, QString& response) override
	{
		QMutexLocker locker(&mutex); // Lock

		QSerialPort serial;

		serial.setBaudRate(serial_port_baud_rate_);
		serial.setPortName(serial_port_name_);

		if (!serial.open(QIODevice::ReadWrite)) 
		{
			logger->Log(AbstractLogger::ERROR, QString("Failed to open for read/write %1, port: %2, error: %3").arg(serial_port_name_).arg(serial_port_name_).arg(serial.error()));
			return serial.error();
		}

		// write request
		QByteArray requestData = request.toLocal8Bit();
		serial.write(requestData);
		if (serial.waitForBytesWritten(writeTimeout)) {
			
			// read response
			if (serial.waitForReadyRead(readTimeout)) 
			{
				QByteArray responseData = serial.readAll();
				while (serial.waitForReadyRead(10))
					responseData += serial.readAll();

				response = QString(responseData);
			}
			else 
			{
				logger->Log(AbstractLogger::WARNING, QString("No data was currently available for reading from %1 port: %2").arg(serial_port_name_).arg(serial_port_name_));
			}
		}
		else 
		{
			logger->Log(AbstractLogger::WARNING, QString("Unable to write data within defined time frame port_name: %1 port: %2").arg(serial_port_name_).arg(serial_port_name_));			
		}

		return serial.error();
	}

private:
	std::shared_ptr<AbstractLogger> logger = LogHelper::GetLogger();
	QMutex mutex;

	QString serial_port_name_;
	int serial_port_baud_rate_;
	int readTimeout = 5000; //[ms]
	int writeTimeout = 5000; //[ms]
};

#endif
