#ifndef Carnation_CARSTATUS_H
#define Carnation_CARSTATUS_H

#include <carstatus.h>

/*
 * times for button
 */
#define KEY_PRESS_TIME 2     // 2 * 100ms = 200ms

class CarnationCarStatus : public CarStatus
{
    Q_OBJECT

    // SpecialInfo
    Q_PROPERTY(bool leftHandDrive MEMBER m_leftHandDrive NOTIFY leftHandDriveChanged)
    Q_PROPERTY(bool rightHandDrive MEMBER m_rightHandDrive NOTIFY rightHandDriveChanged)
    Q_PROPERTY(bool brakeSystemFailure MEMBER m_brakeSystemFailure NOTIFY brakeSystemFailureChanged)
    Q_PROPERTY(bool chargeFault MEMBER m_chargeFault NOTIFY chargeFaultChanged)
    Q_PROPERTY(bool oilPressureLow MEMBER m_oilPressureLow NOTIFY oilPressureLowChanged)
    Q_PROPERTY(bool absFault MEMBER m_absFault NOTIFY absFaultChanged)
    Q_PROPERTY(bool epbFault MEMBER m_epbFault NOTIFY epbFaultChanged)
    Q_PROPERTY(bool engineFault MEMBER m_engineFault NOTIFY engineFaultChanged)
    Q_PROPERTY(bool milFault MEMBER m_milFault NOTIFY milFaultChanged)
    Q_PROPERTY(bool espFault MEMBER m_espFault NOTIFY espFaultChanged)
    Q_PROPERTY(bool srsFault MEMBER m_srsFault NOTIFY srsFaultChanged)
    Q_PROPERTY(bool gearBoxFault MEMBER m_gearBoxFault NOTIFY gearBoxFaultChanged)

    // Special SettingsInfo
    // TODO: nothing to do

public:

    explicit CarnationCarStatus(const QString &serialDev, QSerialPort *parent = 0);


signals:
    // SpecialInfo
    void leftHandDriveChanged(bool);
    void rightHandDriveChanged(bool);
    void brakeSystemFailureChanged(bool);
    void chargeFaultChanged(bool);
    void oilPressureLowChanged(bool);
    void absFaultChanged(bool);
    void epbFaultChanged(bool);
    void engineFaultChanged(bool);
    void milFaultChanged(bool);
    void espFaultChanged(bool);
    void srsFaultChanged(bool);
    void gearBoxFaultChanged(bool);

    // Special SettingsInfo
    // TODO: nothing to do

protected slots:
    // TODO: nothing to do

protected:

#ifdef TIMER_FREQ
    virtual void timerEvent(QTimerEvent *event);
#endif

    void initValues();

    // SpecialInfo
    bool m_leftHandDrive;
    bool m_rightHandDrive;
    bool m_brakeSystemFailure;
    bool m_chargeFault;
    bool m_oilPressureLow;
    bool m_absFault;
    bool m_epbFault;
    bool m_engineFault;
    bool m_milFault;
    bool m_espFault;
    bool m_srsFault;
    bool m_gearBoxFault;

    // Special SettingsInfo
    // TODO: nothing to do

    uint m_leftButtonStep;
    uint m_rightButtonStep;
    uint m_okButtonStep;

protected slots:
    virtual void getGeneralSerial(GeneralInfo data);
    virtual void getSpecialSerial(SpecialInfo data);
};

#endif // Carnation_CARSTATUS_H
