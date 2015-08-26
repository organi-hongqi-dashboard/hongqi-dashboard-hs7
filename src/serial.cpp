#include <QDebug>
#include <QSerialPort>

#include <serial.h>

#define SERIAL_READ_BUFFER_SIZE 2048	// 2048 Byte

Serial::Serial(const QString &serialDev, QObject *parent) :
	QObject(parent)
{
	m_serial = new QSerialPort(this);
	m_serial->setPortName(serialDev);
	m_frameType = NULL_TYPE;

	/*
	 * the serial port should be protected against receiving too much data,
	 * which may eventually cause the application to run out of memory.
	 */
	m_serial->setReadBufferSize(SERIAL_READ_BUFFER_SIZE);



}

void Serial::readSerial()
{
	m_recv += m_serial->readAll();

#ifdef HONGQI_RECV
	if( m_recv.length() >= (int)sizeof(MagicFrame) &&  m_frameType == NULL_TYPE ) {
		if( (uint8_t)0xAA != (uint8_t)m_recv[0] ) {
			/* finding HEAD 0xAA */
			bool found0xAA = false;

			for (int i = 0; i < m_recv.length(); ++i) {
				if ((uint8_t)0xAA == (uint8_t)m_recv[i]) {
					m_recv.remove(0, i);
					/* finded HEAD 0xAA */
					QByteArray bf = m_recv.left(MAGIC_FRAME_LEN);
					MagicFrame *magicFrame = (MagicFrame *)bf.data();
					/* deal Frame types */
					if(magicFrame->length == GENERAL_INFO_LEN && magicFrame->magic == MAGIC_GENERAL) {
						m_frameType = GENERAL_TYPE;
						found0xAA = true;
						break;
					}
					if(magicFrame->length == SPECIAL_INFO_LEN && magicFrame->magic == MAGIC_SPECIAL) {
						m_frameType = SPECIAL_TYPE;
						found0xAA = true;
						break;
					}
					/* Frame types err, finding HEAD 0xAA again */
					if( m_frameType == NULL_TYPE ) {
						//m_recv.remove(0, 1);
						continue;
					}
				}
			}
			if (!found0xAA) m_recv.clear();
		} else {
			/* finded HEAD 0xAA */
			QByteArray bf = m_recv.left(MAGIC_FRAME_LEN);
			MagicFrame *magicFrame = (MagicFrame *)bf.data();
			/* deal Frame types */
			if(magicFrame->length == GENERAL_INFO_LEN && magicFrame->magic == MAGIC_GENERAL) {
				m_frameType = GENERAL_TYPE;
			}
			if(magicFrame->length == SPECIAL_INFO_LEN && magicFrame->magic == MAGIC_SPECIAL) {
				m_frameType = SPECIAL_TYPE;
			}
			/* Frame types err, finding HEAD 0xAA again */
			if( m_frameType == NULL_TYPE ) {
				m_recv.remove(0, 1);
			}
		}
	}

	if( m_recv.length() >= (int)sizeof(GeneralFrame) &&  m_frameType == GENERAL_TYPE ) {
		/* deal Frame tail */
		if ((uint8_t)0x55 != (uint8_t)m_recv[GENERAL_FRAME_LEN-1]) {
			/* Frame tail err, finding HEAD 0xAA again */
			m_recv.remove(0, 1);
			m_frameType = NULL_TYPE;
		}
		else {
			/* Frame tail, all right */
			QByteArray bf = m_recv.left(GENERAL_FRAME_LEN);
			m_recv.remove(0, GENERAL_FRAME_LEN);
			GeneralFrame *generalFrame = (GeneralFrame *)bf.data();
			/* check Frame crc */
			if (generalFrame->crc == crc16Check((uint8_t *)(&(generalFrame->magic)), MAGIC_LEN + sizeof(GeneralInfo)))
			{
				emit generalInfoChanged(generalFrame->generalInfo);
				m_frameType = NULL_TYPE;
			}
		}
	}

	if( m_recv.length() >= (int)sizeof(SpecialFrame) &&  m_frameType == SPECIAL_TYPE ) {
		/* deal Frame tail */
		if ((uint8_t)0x55 != (uint8_t)m_recv[SPECIAL_FRAME_LEN-1]) {
			/* Frame tail err, finding HEAD 0xAA again */
			m_recv.remove(0, 1);
			m_frameType = NULL_TYPE;
		}
		else {
			/* Frame tail, all right */
			QByteArray bf = m_recv.left(SPECIAL_FRAME_LEN);
			m_recv.remove(0, SPECIAL_FRAME_LEN);
			SpecialFrame *specialFrame = (SpecialFrame *)bf.data();
			/* check Frame crc */
			if (specialFrame->crc == crc16Check((uint8_t *)(&(specialFrame->magic)), MAGIC_LEN + sizeof(SpecialInfo)))
			{
				emit specialInfoChanged(specialFrame->specialInfo);
				m_frameType = NULL_TYPE;
			}
		}
	}

	//	while (m_recv.length() >= (int)sizeof(MagicFrame) ) {
	//		if ((uint8_t)0xAA != (uint8_t)m_recv[0] && m_frameType == NULL_TYPE) {
	//			/* finding HEAD 0xAA */
	//			bool found0xAA = false;
	//			for (int i = 0; i < m_recv.length(); ++i) {
	//				if ((uint8_t)0xAA == (uint8_t)m_recv[i]) {
	//					m_recv.remove(0, i);
	//					found0xAA = true;
	//					continue;
	//				}
	//			}
	//			if (!found0xAA) m_recv.clear();
	//		}
	//		else {
	//			/* finded HEAD 0xAA */
	//			QByteArray bf = m_recv.left(MAGIC_FRAME_LEN);
	//			MagicFrame *magicFrame = (MagicFrame *)bf.data();

	//			/* deal Frame types */
	//			if(magicFrame->length == GENERAL_INFO_LEN && magicFrame->magic == MAGIC_GENERAL) {
	//				m_frameType = GENERAL_TYPE;
	//				/* deal Frame content,GENERAL_TYPE */
	//				if (m_recv.length() >= (int)sizeof(GeneralFrame)) {
	//					/* deal Frame tail */
	//					if ((uint8_t)0x55 != (uint8_t)m_recv[GENERAL_FRAME_LEN-1]) {
	//						/* Frame tail err, finding HEAD 0xAA again */
	//						m_recv.remove(0, 1);
	//						continue;
	//					}
	//					else {
	//						/* Frame tail, all right */
	//						QByteArray bf = m_recv.left(GENERAL_FRAME_LEN);
	//						m_recv.remove(0, GENERAL_FRAME_LEN);
	//						GeneralFrame *generalFrame = (GeneralFrame *)bf.data();
	//						/* check Frame crc */
	//						if (generalFrame->crc == crc16Check((uint8_t *)(&(generalFrame->magic)), MAGIC_LEN + sizeof(GeneralInfo)))
	//						{
	//							emit generalInfoChanged(generalFrame->generalInfo);
	//							m_frameType = NULL_TYPE;
	//							continue;
	//						}
	//					}
	//				} else {
	//					//length too short
	//					return;
	//				}
	//			}

	//			if(magicFrame->length == SPECIAL_INFO_LEN && magicFrame->magic == MAGIC_SPECIAL) {
	//				m_frameType = SPECIAL_TYPE;
	//				/* deal Frame content,SPECIAL_TYPE */
	//				if (m_recv.length() >= (int)sizeof(SpecialFrame)) {
	//					/* deal Frame tail */
	//					if ((uint8_t)0x55 != (uint8_t)m_recv[SPECIAL_FRAME_LEN-1]) {
	//						/* Frame tail err, finding HEAD 0xAA again */
	//						m_recv.remove(0, 1);
	//						continue;
	//					}
	//					else {
	//						/* Frame tail, all right */
	//						QByteArray bf = m_recv.left(SPECIAL_FRAME_LEN);
	//						m_recv.remove(0, SPECIAL_FRAME_LEN);
	//						SpecialFrame *specialFrame = (SpecialFrame *)bf.data();
	//						/* check Frame crc */
	//						if (specialFrame->crc == crc16Check((uint8_t *)(&(specialFrame->magic)), MAGIC_LEN + sizeof(SpecialInfo)))
	//						{
	//							emit specialInfoChanged(specialFrame->specialInfo);
	//							m_frameType = NULL_TYPE;
	//							continue;
	//						}
	//					}
	//				} else {
	//					//length too short
	//					return;
	//				}
	//			}

	//			if(magicFrame->length == MOBILE_INFO_LEN && magicFrame->magic == MAGIC_MOBILE) {
	//				m_frameType = MOBILE_TYPE;
	//				/* deal Frame content,MOBILE_TYPE */
	//				if (m_recv.length() >= (int)sizeof(MobileFrame)) {
	//					/* deal Frame tail */
	//					if ((uint8_t)0x55 != (uint8_t)m_recv[MOBILE_FRAME_LEN-1]) {
	//						/* Frame tail err, finding HEAD 0xAA again */
	//						m_recv.remove(0, 1);
	//						continue;
	//					}
	//					else {
	//						/* Frame tail, all right */
	//						QByteArray bf = m_recv.left(MOBILE_FRAME_LEN);
	//						m_recv.remove(0, MOBILE_FRAME_LEN);
	//						MobileFrame *mobileFrame = (MobileFrame *)bf.data();
	//						/* check Frame crc */
	//						if (mobileFrame->crc == crc16Check((uint8_t *)(&(mobileFrame->magic)), MAGIC_LEN + sizeof(MobileInfo)))
	//						{
	//							emit mobileInfoChanged(mobileFrame->mobileInfo);
	//							m_frameType = NULL_TYPE;
	//							continue;
	//						}
	//					}
	//				} else {
	//					//length too short
	//					return;
	//				}
	//			}
	//			/* Frame types err, finding HEAD 0xAA again */
	//			if( m_frameType == NULL_TYPE ) {
	//				m_recv.remove(0, 1);
	//				continue;
	//			}
	//		}
	//	}
#endif

#ifdef HONGQI_TRAN
	while (m_recv.length() >= (int)sizeof(SettingsFrame)) {
		if ((uint8_t)0xAA != (uint8_t)m_recv[0]) {
			bool found0xAA = false;
			for (int i = 0; i < m_recv.length(); ++i) {
				if ((uint8_t)0xAA == (uint8_t)m_recv[i]) {
					m_recv.remove(0, i);
					found0xAA = true;
					break;
				}
			}
			if (!found0xAA) m_recv.clear();
		}
		else {
			if ((uint8_t)0x55 != (uint8_t)m_recv[SETTINGS_FRAME_LEN-1]) {
				m_recv.remove(0, 1);
			}
			else {
				QByteArray bf = m_recv.left(SETTINGS_FRAME_LEN);
				m_recv.remove(0, SETTINGS_FRAME_LEN);
				SettingsFrame *settingsFrame = (SettingsFrame *)bf.data();
				if (settingsFrame->crc == crc16Check((uint8_t *)(&(settingsFrame->magic)), MAGIC_LEN + sizeof(SettingsInfo)))
					emit serialChanged(settingsFrame->settingsInfo);
			}
		}
	}
#endif
}

bool Serial::sendSerial(const QByteArray &data)
{
	if (m_serial->write(data) != -1) {
		//qDebug() << "Send serial port data succeeded.";
		return true;
	}
	else {
		//qDebug() << "Send serial port data failed.";
		return false;
	}
}

void Serial::clearSerial()
{
	m_serial->clear(QSerialPort::AllDirections);
	m_recv.clear();
}

void Serial::openSerial()
{
	if (m_serial->open(QIODevice::ReadWrite)
			&& m_serial->setBaudRate(BAUD_RATE)
			&& m_serial->setDataBits(QSerialPort::Data8)
			&& m_serial->setParity(QSerialPort::NoParity)
			&& m_serial->setStopBits(QSerialPort::OneStop)
			&& m_serial->setFlowControl(QSerialPort::NoFlowControl)
			&& m_serial->clear(QSerialPort::AllDirections)) {
		qDebug() << "Succeed to open serial port.";
	} else {
		qDebug() << "Fail to open serial port: ";
		return;
	}
	connectSerialSingal();
}

void Serial::connectSerialSingal()
{
	connect(m_serial, SIGNAL(readyRead()), this, SLOT(readSerial()));
	//qDebug()<<"connectSerialSingal";
}

void Serial::disconnectSerialSingal()
{
	disconnect(m_serial, SIGNAL(readyRead()), this, SLOT(readSerial()));
	//qDebug()<<"disconnectSerialSingal";

}
