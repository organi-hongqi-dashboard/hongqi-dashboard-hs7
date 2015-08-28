#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QByteArray>

#include <protocol.h>

class QSerialPort;

class Serial : public QObject
{
	Q_OBJECT
public:
	explicit Serial(const QString &serialDev, QObject *parent = 0);
	bool sendSerial(const QByteArray &data);
	void clearSerial();
	void connectSerialSingal();
	void disconnectSerialSingal();
	void openSerial();
signals:

#ifdef HONGQI_RECV
	void generalInfoChanged(GeneralInfo data);
	void specialInfoChanged(SpecialInfo data);
	void mobileInfoChanged(MobileInfo data);
#endif

#ifdef HONGQI_TRAN
	void serialChanged(SettingsInfo data);
#endif

private slots:
	void readSerial();

private:
	QByteArray m_recv;
	QSerialPort *m_serial;

	typedef enum {
		NULL_TYPE,
		GENERAL_TYPE,
		SPECIAL_TYPE,
		MOBILE_TYPE,
	}FRAME_TYPES;

	FRAME_TYPES m_frameType;
};

#endif // SERIAL_H
