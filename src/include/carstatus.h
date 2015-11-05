#ifndef CARSTATUS_H
#define CARSTATUS_H

#include <QString>
#include <QDateTime>
#include <QByteArray>
#include <QSerialPort>
#include <QTimerEvent>

#include <protocol.h>
#ifdef Todi
#include <todi_protocol.h>
#elif MoLiHua
#include <molihua_protocol.h>
#elif Carnation
#include <carnation_protocol.h>
#endif

/*
 * BoolValueChangeSet:    change recv signal value normally
 * NumValueChangeSet:     change recv signal value by range of (min, max)
 * NumValueErrChangeSet:  change recv signal value by range of (min, max), or 0xFF... if error happen
 */
#define BoolValueChangeSet(name, v) do { if (m_##name != (v)) { m_##name = (v); emit name##Changed(v); }} while (0)
#define NumValueChangeSet(name, v, min, max) do { if (qAbs(m_##name - qBound(min, v, max)) > 0.001) { m_##name = qBound(min, v, max); emit name##Changed(qBound(min, v, max)); }} while (0)
#define NumValueErrChangeSet(name, v, min, max, e) do { if (e == v) { m_##name = (v); emit name##Changed(v);} else { if (qAbs(m_##name - qBound(min, v, max)) > 0.001) { m_##name = qBound(min, v, max); emit name##Changed(qBound(min, v, max)); }}} while (0)


class CarStatus : public QSerialPort
{
    Q_OBJECT

    // GeneralInfo
    Q_PROPERTY(uint tmpVersion MEMBER m_tmpVersion NOTIFY tmpVersionChanged)
    Q_PROPERTY(uint relVersion MEMBER m_relVersion NOTIFY relVersionChanged)
    Q_PROPERTY(uint hwVersion MEMBER m_hwVersion NOTIFY hwVersionChanged)
    Q_PROPERTY(uint rpm MEMBER m_rpm NOTIFY rpmChanged)
    Q_PROPERTY(uint dateTime MEMBER m_dateTime NOTIFY dateTimeChanged)
    Q_PROPERTY(QDateTime qDateTime MEMBER m_qDateTime NOTIFY qDateTimeChanged)
    Q_PROPERTY(QString date MEMBER m_date NOTIFY dateChanged)
    Q_PROPERTY(QString time MEMBER m_time NOTIFY timeChanged)
    Q_PROPERTY(uint speed MEMBER m_speed NOTIFY speedChanged)
    Q_PROPERTY(uint waterTemp MEMBER m_waterTemp NOTIFY waterTempChanged)
    Q_PROPERTY(bool key1 MEMBER m_key1 NOTIFY key1Changed)
    Q_PROPERTY(bool key2 MEMBER m_key2 NOTIFY key2Changed)
    Q_PROPERTY(bool key3 MEMBER m_key3 NOTIFY key3Changed)
    Q_PROPERTY(bool key4 MEMBER m_key4 NOTIFY key4Changed)
    Q_PROPERTY(bool igOn MEMBER m_igOn NOTIFY igOnChanged)
    Q_PROPERTY(uint gear MEMBER m_gear NOTIFY gearChanged)
    Q_PROPERTY(uint gearMode MEMBER m_gearMode NOTIFY gearModeChanged)
    Q_PROPERTY(uint keyStatus MEMBER m_keyStatus NOTIFY keyStatusChanged)
    Q_PROPERTY(bool lfDoor MEMBER m_lfDoor NOTIFY lfDoorChanged)
    Q_PROPERTY(bool rfDoor MEMBER m_rfDoor NOTIFY rfDoorChanged)
    Q_PROPERTY(bool lrDoor MEMBER m_lrDoor NOTIFY lrDoorChanged)
    Q_PROPERTY(bool rrDoor MEMBER m_rrDoor NOTIFY rrDoorChanged)
    Q_PROPERTY(bool hoodDoor MEMBER m_hoodDoor NOTIFY hoodDoorChanged)
    Q_PROPERTY(bool trunkDoor MEMBER m_trunkDoor NOTIFY trunkDoorChanged)
    Q_PROPERTY(uint odo MEMBER m_odo NOTIFY odoChanged)
    Q_PROPERTY(uint avgSpeed MEMBER m_avgSpeed NOTIFY avgSpeedChanged)
    Q_PROPERTY(bool avgFuelUnit MEMBER m_avgFuelUnit NOTIFY avgFuelUnitChanged)
    Q_PROPERTY(bool instantaneousFuelUnit MEMBER m_instantaneousFuelUnit NOTIFY instantaneousFuelUnitChanged)
    Q_PROPERTY(uint remainMileage MEMBER m_remainMileage NOTIFY remainMileageChanged)
    Q_PROPERTY(uint trip1 MEMBER m_trip1 NOTIFY trip1Changed)
    Q_PROPERTY(uint fuel MEMBER m_fuel NOTIFY fuelChanged)
    Q_PROPERTY(uint trip2 MEMBER m_trip2 NOTIFY trip2Changed)
    Q_PROPERTY(uint soc MEMBER m_soc NOTIFY socChanged)
    Q_PROPERTY(uint maintenanceMileage MEMBER m_maintenanceMileage NOTIFY maintenanceMileageChanged)
    Q_PROPERTY(qreal outTemp MEMBER m_outTemp NOTIFY outTempChanged)
    Q_PROPERTY(uint avgFuel MEMBER m_avgFuel NOTIFY avgFuelChanged)
    Q_PROPERTY(qreal instantaneousFuel MEMBER m_instantaneousFuel NOTIFY instantaneousFuelChanged)
    Q_PROPERTY(qreal batteryCurrent MEMBER m_batteryCurrent NOTIFY batteryCurrentChanged)
    Q_PROPERTY(qreal batteryVoltage MEMBER m_batteryVoltage NOTIFY batteryVoltageChanged)

    // General SettingsInfo
    Q_PROPERTY(bool commandReq MEMBER m_commandReq NOTIFY commandReqChanged)
    Q_PROPERTY(bool closeReq MEMBER m_closeReq NOTIFY closeReqChanged)
    Q_PROPERTY(bool tripClean MEMBER m_tripClean NOTIFY tripCleanChanged)
    Q_PROPERTY(bool avgSpeedClean MEMBER m_avgSpeedClean NOTIFY avgSpeedCleanChanged)
    Q_PROPERTY(bool avgFuelClean MEMBER m_avgFuelClean NOTIFY avgFuelCleanChanged)
    Q_PROPERTY(bool projectMode MEMBER m_projectMode NOTIFY projectModeChanged)
    Q_PROPERTY(uint alarmInterface MEMBER m_alarmInterface NOTIFY alarmInterfaceChanged)
    Q_PROPERTY(uint interfaceSoundSync MEMBER m_interfaceSoundSync NOTIFY interfaceSoundSyncChanged)
    Q_PROPERTY(uint dateTimeSet MEMBER m_dateTimeSet NOTIFY dateTimeSetChanged)

    // Enable receive info from serial
    Q_PROPERTY(bool active MEMBER m_active NOTIFY activeChanged)

    // Load Special.qml of different project
    Q_PROPERTY(QString projectName MEMBER m_projectName NOTIFY projectNameChanged)

public:
    explicit CarStatus(const QString &serialDev, QSerialPort *parent = 0);

    Q_INVOKABLE void sendSettingsFrame();

signals:
    // GeneralInfo
    void tmpVersionChanged(uint);
    void relVersionChanged(uint);
    void hwVersionChanged(uint);
    void rpmChanged(uint);
    void dateTimeChanged(uint);
    void qDateTimeChanged(QDateTime);
    void dateChanged(QString);
    void timeChanged(QString);
    void speedChanged(uint);
    void waterTempChanged(uint);
    void key1Changed(bool);
    void key2Changed(bool);
    void key3Changed(bool);
    void key4Changed(bool);
    void igOnChanged(bool);
    void gearChanged(uint);
    void gearModeChanged(uint);
    void keyStatusChanged(uint);
    void lfDoorChanged(bool);
    void rfDoorChanged(bool);
    void lrDoorChanged(bool);
    void rrDoorChanged(bool);
    void hoodDoorChanged(bool);
    void trunkDoorChanged(bool);
    void odoChanged(uint);
    void avgSpeedChanged(uint);
    void avgFuelUnitChanged(bool);
    void instantaneousFuelUnitChanged(bool);
    void remainMileageChanged(uint);
    void trip1Changed(uint);
    void fuelChanged(uint);
    void trip2Changed(uint);
    void socChanged(uint);
    void maintenanceMileageChanged(uint);
    void outTempChanged(qreal);
    void avgFuelChanged(uint);
    void instantaneousFuelChanged(qreal);
    void batteryCurrentChanged(qreal);
    void batteryVoltageChanged(qreal);

    void activeChanged(bool);

    void projectNameChanged(QString);

    // General SettingsInfo
    void commandReqChanged(bool);
    void closeReqChanged(bool);
    void tripCleanChanged(bool);
    void avgSpeedCleanChanged(bool);
    void avgFuelCleanChanged(bool);
    void projectModeChanged(bool);
    void alarmInterfaceChanged(uint);
    void interfaceSoundSyncChanged(uint);
    void dateTimeSetChanged(uint);

protected:

#ifdef TIMER_FREQ
    virtual void timerEvent(QTimerEvent *event);
#endif

    void initValues();

    // Set date and time to string
    void updateTime(uint);

    // GeneralInfo
    uint m_tmpVersion;
    uint m_relVersion;
    uint m_hwVersion;
    uint m_rpm;
    uint m_dateTime;
    QString m_date;
    QString m_time;
    QDateTime m_qDateTime;

    uint m_speed;
    uint m_waterTemp;
    bool m_key1;
    bool m_key2;
    bool m_key3;
    bool m_key4;
    bool m_igOn;
    uint m_gear;
    uint m_gearMode;
    uint m_keyStatus;
    bool m_lfDoor;
    bool m_rfDoor;
    bool m_lrDoor;
    bool m_rrDoor;
    bool m_hoodDoor;
    bool m_trunkDoor;
    uint m_odo;
    uint m_avgSpeed;
    bool m_avgFuelUnit;
    bool m_instantaneousFuelUnit;
    uint m_remainMileage;
    uint m_trip1;
    uint m_fuel;
    uint m_trip2;
    uint m_soc;
    uint m_maintenanceMileage;
    qreal m_outTemp;
    uint m_avgFuel;
    qreal m_instantaneousFuel;
    qreal m_batteryCurrent;
    qreal m_batteryVoltage;

    // General SettingsInfo
    bool m_commandReq;
    bool m_closeReq;
    bool m_tripClean;
    bool m_avgSpeedClean;
    bool m_avgFuelClean;
    bool m_projectMode;
    uint m_alarmInterface;
    uint m_interfaceSoundSync;
    uint m_dateTimeSet;

    bool m_active;

    QString m_projectName;

private slots:
    void readSerial();

protected:
    bool sendSerial(const QByteArray &data);

protected slots:
    virtual void getGeneralSerial(GeneralInfo data);
#if (defined Todi) || (defined MoLiHua) || (defined Carnation)
    virtual void getSpecialSerial(SpecialInfo data);
#endif
private:
    QByteArray m_recv;
};

#endif // CARSTATUS_H
