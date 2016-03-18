#include <QDebug>

#include <carstatus.h>

/*
 * TimeSetTopLimit：    set time top limit of seconds from 1970-01-01 00:00:00 to 2099-12-31 23:59:59
 * TimeSetLowerLimit：  set time lower limit of seconds from 1970-01-01 00:00:00 to 2000-01-01 00:00:00
 */
#define TimeSetTopLimit   0xF485E67F
#define TimeSetLowerLimit 0x386CD300

CarStatus::CarStatus(const QString &serialDev, QSerialPort *parent)
    : QSerialPort(parent)
{
    initValues();

#ifdef TIMER_FREQ
    startTimer(SETTINGSFTRAME_FREQ);
#endif

    this->setPortName(serialDev);

    if (this->open(QIODevice::ReadWrite)
            && this->setBaudRate(SERIAL_BAUD_RATE)
            && this->setDataBits(QSerialPort::Data8)
            && this->setParity(QSerialPort::NoParity)
            && this->setStopBits(QSerialPort::OneStop)
            && this->setFlowControl(QSerialPort::NoFlowControl)
            && this->clear(QSerialPort::AllDirections)) {
        qDebug() << "Succeed to open serial port.";
    } else {
        qDebug() << "Fail to open serial port: " << serialDev
                 << "\n" << this->errorString();
        return;
    }

    connect(this, SIGNAL(readyRead()), this, SLOT(readSerial()));

    sendSettingsFrame();
}

void CarStatus::initValues()
{
	m_active = true;

#ifdef Todi
    m_projectName = "Todi";
#elif MoLiHua
    m_projectName = "MoLiHua";
#elif Carnation
    m_projectName = "Carnation";
#else
    m_projectName = "NULL";
#endif

    // GeneralInfo
    m_tmpVersion = 0;
    m_relVersion = 0;
    m_hwVersion = 0;
    m_rpm = 0;
    m_dateTime = 0;
    m_speed = 0;
    m_waterTemp = 50;
    m_key1 = false;
    m_key2 = false;
    m_key3 = false;
    m_key4 = false;
    m_igOn = false;
	m_gear = 14;
    m_gearMode = 0;
    m_keyStatus = 0;
    m_lfDoor = false;
    m_rfDoor = false;
    m_lrDoor = false;
    m_rrDoor = false;
    m_hoodDoor = false;
    m_trunkDoor = false;
    m_odo = 0;
    m_avgSpeed = 0;
    m_avgFuelUnit = false;
    m_instantaneousFuelUnit = false;
    m_remainMileage = 0;
    m_trip1 = 0;
    m_fuel = 0;
    m_trip2 = 0;
    m_soc = 0;
    m_maintenanceMileage = 0;
    m_outTemp = 0;
    m_avgFuel = 0;
    m_instantaneousFuel = 0;
    m_batteryCurrent = 0;
    m_batteryVoltage = 0;

    m_date = "2000-01-01";
    m_time = "00:00";

    // General SettingsInfo
    m_commandReq = true;
    m_closeReq = false;
	m_tripClean = false;
	m_tripClean2 = false;
	m_avgSpeedClean = false;
    m_avgFuelClean = false;
    m_projectMode = false;
    m_alarmInterface = 0;
    m_interfaceSoundSync = 0;
    m_dateTimeSet = 0;
}

void CarStatus::readSerial()
{
    m_recv += this->readAll();

    while (m_recv.length() >= MAGIC_FRAME_LEN + 1) {
        if ((uint8_t)0xAA != (uint8_t)m_recv[0]) {

            /* finding HEAD 0xAA */
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
            /* found HEAD 0xAA */
            QByteArray bf = m_recv.left(MAGIC_FRAME_LEN);
            MagicFrame *magicFrame = (MagicFrame *)bf.data();

            /* deal general frame */
            if(magicFrame->length == GENERAL_INFO_LEN && magicFrame->magic == MAGIC_GENERAL_UP) {
                if (m_recv.length() >= GENERAL_FRAME_LEN && (uint8_t)0x55 == (uint8_t)m_recv[GENERAL_FRAME_LEN-1]) {

                    QByteArray bf = m_recv.left(GENERAL_FRAME_LEN);
                    m_recv.remove(0, GENERAL_FRAME_LEN);
                    GeneralFrame *generalFrame = (GeneralFrame *)bf.data();
                    if (generalFrame->crc == crc16Check((uint8_t *)(&(generalFrame->magic)), MAGIC_LEN + GENERAL_INFO_LEN)) {
                        getGeneralSerial(generalFrame->generalInfo);
#ifdef DEBUG
                        qDebug() << "originGeneralInfoData: " << bf.toHex();
#endif
                    }
                }
                else {
                    if (m_recv.length() < GENERAL_FRAME_LEN) break;
                    else { m_recv.remove(0, 1); continue; }
                }
            }
#if (defined Todi) || (defined MoLiHua) || (defined Carnation)
            /* deal special frame */
            else if (magicFrame->length == SPECIAL_INFO_LEN && magicFrame->magic == MAGIC_SPECIAL_UP) {
                if (m_recv.length() >= SPECIAL_FRAME_LEN && (uint8_t)0x55 == (uint8_t)m_recv[SPECIAL_FRAME_LEN-1]) {

                    QByteArray bf = m_recv.left(SPECIAL_FRAME_LEN);
                    m_recv.remove(0, SPECIAL_FRAME_LEN);
                    SpecialFrame *specialFrame = (SpecialFrame *)bf.data();
                    if (specialFrame->crc == crc16Check((uint8_t *)(&(specialFrame->magic)), MAGIC_LEN + SPECIAL_INFO_LEN)) {
                        getSpecialSerial(specialFrame->specialInfo);
#ifdef DEBUG
                        qDebug() << "originSpecialInfoData: " << bf.toHex();
#endif
                    }
                }
                else {
                    if (m_recv.length() < SPECIAL_FRAME_LEN) break;
                    else { m_recv.remove(0, 1); continue; }
                }
            }
#endif
            /* deal error frame */
            else m_recv.remove(0, 1);
        }
    }
}

bool CarStatus::sendSerial(const QByteArray &data)
{
    if (this->write(data) != -1) {
        qDebug() << "sendData: " << data.toHex();
        qDebug() << "Send serial port data succeeded.";
        return true;
    }
    else {
        qDebug() << "Send serial port data failed.";
        return false;
    }
}

void CarStatus::getGeneralSerial(GeneralInfo data)
{
    if (m_active) {
        BoolValueChangeSet(tmpVersion, data.tmpVersion);
        BoolValueChangeSet(relVersion, data.relVersion);
        BoolValueChangeSet(hwVersion, data.hwVersion);
        BoolValueChangeSet(rpm, data.rpm);
        BoolValueChangeSet(dateTime,data.dateTime);
        BoolValueChangeSet(speed, data.speed);
        BoolValueChangeSet(waterTemp, data.waterTemp);
        BoolValueChangeSet(key1, data.key1);
        BoolValueChangeSet(key2, data.key2);
        BoolValueChangeSet(key3, data.key3);
        BoolValueChangeSet(key4, data.key4);
        BoolValueChangeSet(igOn, data.igOn);
        BoolValueChangeSet(gear, data.gear);
        BoolValueChangeSet(gearMode, data.gearMode);
        BoolValueChangeSet(keyStatus, data.keyStatus);
        BoolValueChangeSet(lfDoor, data.lfDoor);
        BoolValueChangeSet(rfDoor, data.rfDoor);
        BoolValueChangeSet(lrDoor, data.lrDoor);
        BoolValueChangeSet(rrDoor, data.rrDoor);
        BoolValueChangeSet(hoodDoor, data.hoodDoor);
        BoolValueChangeSet(trunkDoor, data.trunkDoor);
        BoolValueChangeSet(odo, data.odo);
        BoolValueChangeSet(avgSpeed, data.avgSpeed);
        BoolValueChangeSet(avgFuelUnit, data.avgFuelUnit);
        BoolValueChangeSet(instantaneousFuelUnit, data.instantaneousFuelUnit);
        BoolValueChangeSet(remainMileage, data.remainMileage);
        BoolValueChangeSet(trip1, data.trip1);
        BoolValueChangeSet(fuel, data.fuel);
        BoolValueChangeSet(trip2, data.trip2);
        BoolValueChangeSet(soc, data.soc);
        BoolValueChangeSet(maintenanceMileage, data.maintenanceMileage);
        BoolValueChangeSet(outTemp, data.outTemp);
        BoolValueChangeSet(avgFuel, data.avgFuel);
        BoolValueChangeSet(instantaneousFuel, data.instantaneousFuel);
        BoolValueChangeSet(batteryCurrent, data.batteryCurrent);
        BoolValueChangeSet(batteryVoltage, data.batteryVoltage);

        updateTime(data.dateTime);
    }
}
#if (defined Todi) || (defined MoLiHua) || (defined Carnation)
void CarStatus::getSpecialSerial(SpecialInfo data)
{
    Q_UNUSED(data);
}
#endif

void CarStatus::updateTime(uint v)
{
    m_qDateTime.setTime_t(v);
    emit qDateTimeChanged(m_qDateTime);
    m_date = m_qDateTime.toString("yyyy-MM-dd");
    emit dateChanged(m_date);

    m_time = m_qDateTime.toString("hh:mm");
    emit timeChanged(m_time);
}

void CarStatus::sendSettingsFrame()
{
    SettingsFrame settingsFrame;
    memset(&settingsFrame, 0, SETTINGS_FRAME_LEN);

    settingsFrame.head = 0xAA;
    settingsFrame.length = SETTINGS_INFO_LEN;

    settingsFrame.settingsInfo.commandReq = m_commandReq;
    settingsFrame.settingsInfo.closeReq = m_closeReq;

    if (m_tripClean && m_trip1 == 0)
        m_tripClean = false;
    settingsFrame.settingsInfo.tripClean = m_tripClean;

	if (m_tripClean2 && m_trip2 == 0)
		m_tripClean2 = false;
	settingsFrame.settingsInfo.tripClean2 = m_tripClean2;

    if (m_avgSpeedClean && m_avgSpeed == 0)
        m_avgSpeedClean = false;
    settingsFrame.settingsInfo.avgSpeedClean = m_avgSpeedClean;

    if (m_avgFuelClean && m_avgFuel == 0)
        m_avgFuelClean = false;
    settingsFrame.settingsInfo.avgFuelClean = m_avgFuelClean;

    settingsFrame.settingsInfo.projectMode = m_projectMode;

    settingsFrame.settingsInfo.alarmInterface = m_alarmInterface;
    settingsFrame.settingsInfo.interfaceSoundSync = m_interfaceSoundSync;

    if (abs(m_dateTime - m_dateTimeSet) <= 2)
        m_dateTimeSet = 0;
    else if (m_dateTimeSet > TimeSetTopLimit || m_dateTimeSet < TimeSetLowerLimit)
        m_dateTimeSet = 0;
    settingsFrame.settingsInfo.dateTimeSet = m_dateTimeSet;

    settingsFrame.magic = MAGIC_GENERAL_DOWN;

    settingsFrame.crc = crc16Check((uint8_t *)(&(settingsFrame.magic)), MAGIC_LEN + SETTINGS_INFO_LEN);
    settingsFrame.tail = 0x55;

    this-> sendSerial(QByteArray((char *)&settingsFrame, SETTINGS_FRAME_LEN));
}

#ifdef TIMER_FREQ
void CarStatus::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    sendSettingsFrame();
}
#endif
