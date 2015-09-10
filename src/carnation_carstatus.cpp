#include <QDebug>
#include <QDateTime>
#include <QTimerEvent>

#include <carnation_carstatus.h>

CarnationCarStatus::CarnationCarStatus(const QString &serialDev, QSerialPort *parent)
    : CarStatus(serialDev, parent)
{
    initValues();
}

void CarnationCarStatus::initValues()
{
    // SpecialInfo
    m_leftHandDrive = false;
    m_rightHandDrive = false;
    m_brakeSystemFailure = false;
    m_chargeFault = false;
    m_oilPressureLow = false;
    m_absFault = false;
    m_epbFault = false;
    m_engineFault = false;
    m_milFault = false;
    m_espFault = false;
    m_srsFault = false;
    m_gearBoxFault = false;

    // Special SettingsInfo
    // TODO: nothing to do
}

/*
 * rewrite getGeneralSerial
 */
void CarnationCarStatus::getGeneralSerial(GeneralInfo data)
{
    if (m_active) {
        NumValueChangeSet(tmpVersion, data.tmpVersion, (uint16_t) 0, (uint16_t) 255);
        NumValueChangeSet(relVersion, data.relVersion, (uint16_t) 0, (uint16_t) 31);
        NumValueChangeSet(hwVersion, data.hwVersion, (uint16_t) 0, (uint16_t) 7);
        NumValueChangeSet(rpm, data.rpm, (uint16_t) 0, (uint16_t) 7000);
        NumValueChangeSet(dateTime,data.dateTime, (uint32_t) 0, (uint32_t) 0xFFFFFFFF);
        NumValueChangeSet(speed, data.speed, (uint8_t) 0, (uint8_t) 240);
        NumValueChangeSet(waterTemp, data.waterTemp, (uint8_t) 50, (uint8_t) 130);
        BoolValueChangeSet(key4, data.key4);
        BoolValueChangeSet(igOn, data.igOn);
        BoolValueChangeSet(gear, data.gear);
        NumValueChangeSet(gearMode, data.gearMode, (uint8_t) 0, (uint8_t) 3);
        NumValueChangeSet(keyStatus, data.keyStatus, (uint8_t) 0, (uint8_t) 3);
        BoolValueChangeSet(lfDoor, data.lfDoor);
        BoolValueChangeSet(rfDoor, data.rfDoor);
        BoolValueChangeSet(lrDoor, data.lrDoor);
        BoolValueChangeSet(rrDoor, data.rrDoor);
        BoolValueChangeSet(hoodDoor, data.hoodDoor);
        BoolValueChangeSet(trunkDoor, data.trunkDoor);
        NumValueErrChangeSet(odo, data.odo, (uint32_t) 0, (uint32_t) 999999, 0xFFFFFF);
        NumValueChangeSet(avgSpeed, data.avgSpeed, (uint32_t) 0, (uint32_t) 240);
        BoolValueChangeSet(avgFuelUnit, data.avgFuelUnit);
        BoolValueChangeSet(instantaneousFuelUnit, data.instantaneousFuelUnit);
        NumValueErrChangeSet(remainMileage, data.remainMileage, (uint16_t) 50, (uint16_t) 999, 0xFFFF);
        NumValueErrChangeSet(trip1, data.trip1, (uint32_t) 0, (uint32_t) 9999, 0xFFFFFF);
        NumValueChangeSet(fuel, data.fuel, (uint32_t) 0, (uint32_t) 100);
        NumValueErrChangeSet(trip2, data.trip2, (uint32_t) 0, (uint32_t) 9999, 0xFFFFFF);
        NumValueChangeSet(soc, data.soc, (uint32_t) 0, (uint32_t) 100);
        NumValueChangeSet(maintenanceMileage, data.maintenanceMileage, (uint16_t) 0, (uint16_t) 50000);
        NumValueChangeSet(outTemp, data.outTemp * 0.1 + (-40), (double) 0, (double) 164.5);
        NumValueErrChangeSet(avgFuel, data.avgFuel, (uint16_t)0, (uint16_t) 300, 0xFFFF);
        NumValueChangeSet(instantaneousFuel, data.instantaneousFuel * 0.1 + 0, (double) 0, (double) 45);
        NumValueChangeSet(batteryCurrent, data.batteryCurrent * 0.1 + (-500), (double)0, (double) 2000);
        NumValueChangeSet(batteryVoltage, data.batteryVoltage * 0.1 + 0, (double) 0, (double) 100);

        updateTime(data.dateTime);
    }

#ifdef DEBUG
    // GeneralInfo
    qDebug() << "hwVersion: " << data.hwVersion;
    qDebug() << "relVersion: " << data.relVersion;
    qDebug() << "tmpVersion: " << data.tmpVersion;
    qDebug() << "rpm: " << data.rpm;
    qDebug() << "dateTime: " << data.dateTime;
    qDebug() << "speed: " << data.speed;
    qDebug() << "key1: " << data.key1;
    qDebug() << "key2: " << data.key2;
    qDebug() << "key3: " << data.key3;
    qDebug() << "key4: " << data.key4;
    qDebug() << "igOn: " << data.igOn;
    qDebug() << "gear: " << data.gear;
    qDebug() << "gearMode: " << data.gearMode;
    qDebug() << "keyStatus: " << data.keyStatus;
    qDebug() << "lfDoor: " << data.lfDoor;
    qDebug() << "rfDoor: " << data.rfDoor;
    qDebug() << "lrDoor: " << data.lrDoor;
    qDebug() << "rrDoor: " << data.rrDoor;
    qDebug() << "hoodDoor: " << data.hoodDoor;
    qDebug() << "trunkDoor: " << data.trunkDoor;
    qDebug() << "odo: " << data.odo;
    qDebug() << "avgSpeed: " << data.avgSpeed;
    qDebug() << "avgFuelUnit: " << data.avgFuelUnit;
    qDebug() << "instantaneousFuelUnit: " << data.instantaneousFuelUnit;
    qDebug() << "remainMileage: " << data.remainMileage;
    qDebug() << "trip1: " << data.trip1;
    qDebug() << "fuel: " << data.fuel;
    qDebug() << "trip2: " << data.trip2;
    qDebug() << "soc: " << data.soc;
    qDebug() << "maintenanceMileage: " << data.maintenanceMileage;
    qDebug() << "outTemp: " << data.outTemp;
    qDebug() << "avgFuel: " << data.avgFuel;
    qDebug() << "instantaneousFuel: " << data.instantaneousFuel;
    qDebug() << "batteryCurrent: " << data.batteryCurrent;
    qDebug() << "batteryVoltage: " << data.batteryVoltage;
#endif
}

/*
 * rewrite getSpecialSerial
 */
void CarnationCarStatus::getSpecialSerial(SpecialInfo data)
{
    if (m_active) {
        BoolValueChangeSet(leftHandDrive, data.leftHandDrive);
        BoolValueChangeSet(rightHandDrive, data.rightHandDrive);
        BoolValueChangeSet(brakeSystemFailure, data.brakeSystemFailure);
        BoolValueChangeSet(chargeFault, data.chargeFault);
        BoolValueChangeSet(oilPressureLow, data.oilPressureLow);
        BoolValueChangeSet(absFault, data.absFault);
        BoolValueChangeSet(epbFault, data.epbFault);
        BoolValueChangeSet(engineFault, data.engineFault);
        BoolValueChangeSet(milFault, data.milFault);
        BoolValueChangeSet(espFault, data.espFault);
        BoolValueChangeSet(srsFault, data.srsFault);
        BoolValueChangeSet(gearBoxFault, data.gearBoxFault);
    }

#ifdef DEBUG
    // SpecialInfo
    qDebug() << "leftHandDrive: " << data.leftHandDrive;
    qDebug() << "rightHandDrive: " << data.rightHandDrive;
    qDebug() << "brakeSystemFailure: " << data.brakeSystemFailure;
    qDebug() << "chargeFault: " << data.chargeFault;
    qDebug() << "oilPressureLow: " << data.oilPressureLow;
    qDebug() << "absFault: " << data.absFault;
    qDebug() << "epbFault: " << data.epbFault;
    qDebug() << "engineFault: " << data.engineFault;
#endif
}

#ifdef TIMER_FREQ
void CarnationCarStatus::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    sendSettingsFrame();
}
#endif
