#ifndef Carnation_CARSTATUS_H
#define Carnation_CARSTATUS_H

#include <QTimer>
#include <QTimerEvent>

#include <carstatus.h>

/*
 * times for button
 */
#define KEY_PRESS_TIME 2     // 2 * 100ms = 200ms

/*
 * times for key debounce and long button
 */
#define KEY_DEBOUNCE_TIME 2     // 2 * 100ms = 200ms
#define KEY_LONG_TIME 15		// 15 * 100ms = 1500ms


class CarnationCarStatus : public CarStatus
{
    Q_OBJECT

    // SpecialInfo
    Q_PROPERTY(bool leftHandDrive MEMBER m_leftHandDrive NOTIFY leftHandDriveChanged)
    Q_PROPERTY(bool rightHandDrive MEMBER m_rightHandDrive NOTIFY rightHandDriveChanged)
    Q_PROPERTY(bool highBeam MEMBER m_highBeam NOTIFY highBeamChanged)
    Q_PROPERTY(bool dippedBeam MEMBER m_dippedBeam NOTIFY dippedBeamChanged)
    Q_PROPERTY(bool positionLight MEMBER m_positionLight NOTIFY positionLightChanged)
    Q_PROPERTY(bool frontFogLight MEMBER m_frontFogLight NOTIFY frontFogLightChanged)
    Q_PROPERTY(bool rearFogLight MEMBER m_rearFogLight NOTIFY rearFogLightChanged)
    Q_PROPERTY(bool auxiliaryHighBeam MEMBER m_auxiliaryHighBeam NOTIFY auxiliaryHighBeamChanged)

    Q_PROPERTY(bool safetyBeltLight MEMBER m_safetyBeltLight NOTIFY safetyBeltLightChanged)
    Q_PROPERTY(bool airBagLight MEMBER m_airBagLight NOTIFY airBagLightChanged)
    Q_PROPERTY(bool engineFaultLight MEMBER m_engineFaultLight NOTIFY engineFaultLightChanged)
    Q_PROPERTY(bool absFault MEMBER m_absFault NOTIFY absFaultChanged)
    Q_PROPERTY(bool oilPressureLow MEMBER m_oilPressureLow NOTIFY oilPressureLowChanged)
    Q_PROPERTY(bool batteryFaultLight MEMBER m_batteryFaultLight NOTIFY batteryFaultLightChanged)
    Q_PROPERTY(bool brakeSystemFailure MEMBER m_brakeSystemFailure NOTIFY brakeSystemFailureChanged)
    Q_PROPERTY(bool parkingLight MEMBER m_parkingLight NOTIFY parkingLightChanged)

    Q_PROPERTY(bool oilLowLight MEMBER m_oilLowLight NOTIFY oilLowLightChanged)
    Q_PROPERTY(bool coolantLowLight MEMBER m_coolantLowLight NOTIFY coolantLowLightChanged)
	Q_PROPERTY(int espLight MEMBER m_espLight NOTIFY espLightChanged)
//    Q_PROPERTY(bool espOffLight MEMBER m_espOffLight NOTIFY espOffLightChanged)
    Q_PROPERTY(bool afsOffLight MEMBER m_afsOffLight NOTIFY afsOffLightChanged)
    Q_PROPERTY(bool milLight MEMBER m_milLight NOTIFY milLightChanged)
	Q_PROPERTY(bool gearboxErrLight MEMBER m_gearboxErrLight NOTIFY gearboxErrLightChanged)
	Q_PROPERTY(bool changeBrakePadsLight MEMBER m_changeBrakePadsLight NOTIFY changeBrakePadsLightChanged)
	Q_PROPERTY(bool electronicParkingLight MEMBER m_electronicParkingLight NOTIFY electronicParkingLightChanged)

    Q_PROPERTY(bool breakSystemPic MEMBER m_breakSystemPic NOTIFY breakSystemPicChanged)
    Q_PROPERTY(bool brakeFluidPic MEMBER m_brakeFluidPic NOTIFY brakeFluidPicChanged)
    Q_PROPERTY(bool addOilPic MEMBER m_addOilPic NOTIFY addOilPicChanged)
    Q_PROPERTY(bool batteryFaultPic MEMBER m_batteryFaultPic NOTIFY batteryFaultPicChanged)
    Q_PROPERTY(bool oilPressureLowPic MEMBER m_oilPressureLowPic NOTIFY oilPressureLowPicChanged)
    Q_PROPERTY(bool coolantSystemErrPic MEMBER m_coolantSystemErrPic NOTIFY coolantSystemErrPicChanged)
    Q_PROPERTY(bool absFaultPic MEMBER m_absFaultPic NOTIFY absFaultPicChanged)
    Q_PROPERTY(bool epbFaultPic MEMBER m_epbFaultPic NOTIFY epbFaultPicChanged)

    Q_PROPERTY(bool engineCtlFaultPic MEMBER m_engineCtlFaultPic NOTIFY engineCtlFaultPicChanged)
    Q_PROPERTY(bool exhaustEmissionPic MEMBER m_exhaustEmissionPic NOTIFY exhaustEmissionPicChanged)
    Q_PROPERTY(bool espFaultPic MEMBER m_espFaultPic NOTIFY espFaultPicChanged)
    Q_PROPERTY(bool airBagFaultPic MEMBER m_airBagFaultPic NOTIFY airBagFaultPicChanged)
    Q_PROPERTY(bool speedChangerErrPic MEMBER m_speedChangerErrPic NOTIFY speedChangerErrPicChanged)
    Q_PROPERTY(bool speedChaTempHighPic MEMBER m_speedChaTempHighPic NOTIFY speedChaTempHighPicChanged)
    Q_PROPERTY(bool coolantHighTempPic MEMBER m_coolantHighTempPic NOTIFY coolantHighTempPicChanged)
	Q_PROPERTY(int tripAB MEMBER m_tripAB NOTIFY tripABChanged)
    Q_PROPERTY(bool tcsErrPic MEMBER m_tcsErrPic NOTIFY tcsErrPicChanged)
    Q_PROPERTY(bool changeBrakeFrontPic MEMBER m_changeBrakeFrontPic NOTIFY changeBrakeFrontPicChanged)
    Q_PROPERTY(bool changeBrakeRearPic MEMBER m_changeBrakeRearPic NOTIFY changeBrakeRearPicChanged)

    // Special SettingsInfo
    // TODO: nothing to do


    // tips
    Q_PROPERTY(WARNING_TIPS errType MEMBER m_errType NOTIFY errTypeChanged)
    Q_PROPERTY(QString warningTipSrc MEMBER m_warningTipSrc NOTIFY warningTipSrcChanged)

public:

    explicit CarnationCarStatus(const QString &serialDev, QSerialPort *parent = 0);

    enum WARNING_TIPS { NULL_ERR,

						BREAK_SYS_PIC, //制动系统严重故障
						BREAK_FLUID_PIC,//制动液液位过低
						ADD_OIL_PIC,//请加油！
                        BATTERY_FAULT_PIC,
						OIL_PRESSURE_LOW_PIC, //机油压力过低
						COLLANT_SYS_ERR_PIC, //冷却液系统故障
                        ABS_FAULT_PIC,
                        EPB_FAULT_PIC,

                        ENGINE_CTL_FAULT_PIC,
                        EXHAUST_EMISSING_PIC,
                        ESP_FAULT_PIC,
                        AIRBAG_FAULT_PIC,
                        SPEED_CHANGER_ERR_PIC,
                        SPEED_CHA_TEMP_HIGH_PIC,
                        COOLANT_HIGH_TEMP_PIC,
                        TCS_ERR_PIC,
                        CHANGE_BRAKE_FRONT_PIC,
                        CHANGE_BRAKE_REAR_PIC,

                        MAX_WARNING_TIPS
                      };

//    struct warning_tip_s {
//        WARNING_TIPS warning_tip_type;
//        QString warning_tip_str;
//    };
//    struct warning_tip_s warning_tip[15] = {
//        {NULL_ERR, ""},

//        {BREAK_SYS_PIC, "qrc:/qml/qml/content/warning/BrakingMoreErr.qml"},
//        {ADD_OIL_PIC, "qrc:/qml/qml/content/warning/OilShortErr.qml"},
//        {BATTERY_FAULT_PIC, "qrc:/qml/qml/content/warning/ChargingSysErr.qml"},
//        {OIL_PRESSURE_LOW_PIC, "qrc:/qml/qml/content/warning/OilPreLowErr.qml"},
//        {COLLANT_SYS_ERR_PIC, "qrc:/qml/qml/content/warning/CoolErr.qml"},
//        {ABS_FAULT_PIC, "qrc:/qml/qml/content/warning/AbsErr.qml"},
//        {EPB_FAULT_PIC, "qrc:/qml/qml/content/warning/EpbErr.qml"},
//        {ENGINE_CTL_FAULT_PIC, "qrc:/qml/qml/content/warning/EngineErr.qml"},
//        {EXHAUST_EMISSING_PIC, "qrc:/qml/qml/content/warning/WasteGasMonitoringSysErr.qml"},
//        {ESP_FAULT_PIC, "qrc:/qml/qml/content/warning/EspErr.qml"},
//        {AIRBAG_FAULT_PIC, ""},
//        {SPEED_CHANGER_ERR_PIC, "qrc:/qml/qml/content/warning/GearErr.qml"},
//        {SPEED_CHA_TEMP_HIGH_PIC, "qrc:/qml/qml/content/warning/GearShiftTemHighErr.qml"},

//        {MAX_WARNING_TIPS, ""},
//    };

    void showCheckErr();

/* emit twice, one emit qml source for centre warning panel,
 *             one emit change signal for warning light */
#define dealErrShow(name, v, errType) \
    do { \
        if (m_##name != (v)) { \
            m_##name = (v); \
            dealErrList((v), (errType)); \
            emit name##Changed(v); \
        } \
    } while (0)

#define dealErrButtonShow(name, v) \
    do { \
        m_##name = (v); \
        name##Deal((v)); \
    } while (0)


signals:
    // SpecialInfo
    void leftHandDriveChanged(bool);
    void rightHandDriveChanged(bool);
    void highBeamChanged(bool);
    void dippedBeamChanged(bool);
    void positionLightChanged(bool);
    void frontFogLightChanged(bool);
    void rearFogLightChanged(bool);
    void auxiliaryHighBeamChanged(bool);

    void safetyBeltLightChanged(bool);
    void airBagLightChanged(bool);
    void engineFaultLightChanged(bool);
    void absFaultChanged(bool);
    void oilPressureLowChanged(bool);
    void batteryFaultLightChanged(bool);
    void brakeSystemFailureChanged(bool);
    void parkingLightChanged(bool);

    void oilLowLightChanged(bool);
    void coolantLowLightChanged(bool);
	void espLightChanged(int);
//    void espOffLightChanged(bool);
    void afsOffLightChanged(bool);
    void milLightChanged(bool);
	void gearboxErrLightChanged(bool);
	void changeBrakePadsLightChanged(bool);
	void electronicParkingLightChanged(bool);

    void breakSystemPicChanged(bool);
    void brakeFluidPicChanged(bool);
    void addOilPicChanged(bool);
    void batteryFaultPicChanged(bool);
    void oilPressureLowPicChanged(bool);
    void coolantSystemErrPicChanged(bool);
    void absFaultPicChanged(bool);
    void epbFaultPicChanged(bool);

    void engineCtlFaultPicChanged(bool);
    void exhaustEmissionPicChanged(bool);
    void espFaultPicChanged(bool);
    void airBagFaultPicChanged(bool);
    void speedChangerErrPicChanged(bool);
    void speedChaTempHighPicChanged(bool);
    void coolantHighTempPicChanged(bool);
	void tripABChanged(int);
    void tcsErrPicChanged(bool);
    void changeBrakeFrontPicChanged(bool);
    void changeBrakeRearPicChanged(bool);

    // Special SettingsInfo
    // TODO: nothing to do


    // tips
    void errTypeChanged(WARNING_TIPS);
    void warningTipSrcChanged(QString);

    void key1Changed(bool);
    void key2Changed(bool);
    void key3Changed(bool);
    void key4Changed(bool);

	Q_INVOKABLE void okButtonShort();
	Q_INVOKABLE void okButtonLong();

protected slots:
    // TODO: nothing to do

    // Tips
    void updateERR();
    void dealCheckKey();

    void key1Deal(bool);
    void key2Deal(bool);
    void key3Deal(bool);
    void key4Deal(bool);

protected:

#ifdef TIMER_FREQ
    virtual void timerEvent(QTimerEvent *event);
#endif

    void initValues();

    // SpecialInfo
    bool m_leftHandDrive;
    bool m_rightHandDrive;
    bool m_highBeam;
    bool m_dippedBeam;
    bool m_positionLight;
    bool m_frontFogLight;
    bool m_rearFogLight;
    bool m_auxiliaryHighBeam;

    bool m_safetyBeltLight;
    bool m_airBagLight;
    bool m_engineFaultLight;
    bool m_absFault;
    bool m_oilPressureLow;
    bool m_batteryFaultLight;
    bool m_brakeSystemFailure;
    bool m_parkingLight;

    bool m_oilLowLight;
    bool m_coolantLowLight;
	int m_espLight;
//    bool m_espOffLight;
    bool m_afsOffLight;
    bool m_milLight;
	bool m_gearboxErrLight;
	bool m_changeBrakePadsLight;
	bool m_electronicParkingLight;

    bool m_breakSystemPic;
    bool m_brakeFluidPic;
    bool m_addOilPic;
    bool m_batteryFaultPic;
    bool m_oilPressureLowPic;
    bool m_coolantSystemErrPic;
    bool m_absFaultPic;
    bool m_epbFaultPic;

    bool m_engineCtlFaultPic;
    bool m_exhaustEmissionPic;
    bool m_espFaultPic;
    bool m_airBagFaultPic;
    bool m_speedChangerErrPic;
    bool m_speedChaTempHighPic;
    bool m_coolantHighTempPic;
    bool m_tcsErrPic;
    bool m_changeBrakeFrontPic;
    bool m_changeBrakeRearPic;


    // Special SettingsInfo
    // TODO: nothing to do

    uint m_leftButtonStep;
    uint m_rightButtonStep;
    uint m_okButtonStep;

    // Tips
    WARNING_TIPS m_errType;
    QString m_warningTipSrc;
    QString warning_tip_str[MAX_WARNING_TIPS];

    void insertList(QList<uint> *list, uint idn);
    void removeList(QList<uint> *list, uint idn);
    uint popList(QList<uint> *list);

    void dealErrList(bool isInsert, WARNING_TIPS errType);
    void emitWarnTipSrc(WARNING_TIPS errType);

    QList<uint>	m_preTipList;
    QList<uint>	m_tipedList;
    bool m_isTipedList;

    QTimer *m_timer;
    QTimer *m_checkTimer;
    int m_checkIndex;

    // button
    uint m_key1Step;
    bool m_key1StepFlag;
    uint m_key2Step;
    bool m_key2StepFlag;
    uint m_key3Step;
    bool m_key3StepFlag;
    uint m_key4Step;
    bool m_key4StepFlag;

	int m_tripAB;

protected slots:
    virtual void getGeneralSerial(GeneralInfo data);
    virtual void getSpecialSerial(SpecialInfo data);
};

#endif // Carnation_CARSTATUS_H
