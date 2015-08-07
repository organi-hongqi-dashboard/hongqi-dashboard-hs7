#ifndef CARSTATUS_H
#define CARSTATUS_H

#include <QString>

#include <serial.h>

/*
 * times for key debounce and long button
 */
#define KEY_DEBOUNCE_TIME 2     // 2 * 100ms = 200ms
#define KEY_LONG_TIME 15		// 15 * 100ms = 1500ms
/*
 * times for DOOR debounce
 */
#define DOOR_DEBOUNCE_TIME 2     // 2 * 100ms = 200ms

class CarStatus : public QObject
{
	Q_OBJECT

	// all have
	Q_PROPERTY(uint hwVer READ hwVer NOTIFY hwVerChanged)
	Q_PROPERTY(uint releaseVer READ releaseVer NOTIFY releaseVerChanged)
	Q_PROPERTY(uint betaVer READ betaVer NOTIFY betaVerChanged)
	Q_PROPERTY(uint rpm READ rpm NOTIFY rpmChanged)
	Q_PROPERTY(QString date READ date NOTIFY dateChanged)
	Q_PROPERTY(QString time READ time NOTIFY timeChanged)
	Q_PROPERTY(uint speed READ speed NOTIFY speedChanged)
	Q_PROPERTY(uint temprature READ temprature NOTIFY tempratureChanged)
#ifdef DEBUG
	// button info
	Q_PROPERTY(QString key0 READ key0 NOTIFY key0Changed)
	Q_PROPERTY(QString key1 READ key1 NOTIFY key1Changed)
	Q_PROPERTY(QString key2 READ key2 NOTIFY key2Changed)
	Q_PROPERTY(QString key3 READ key3 NOTIFY key3Changed)
	Q_PROPERTY(QString key4 READ key4 NOTIFY key4Changed)
	Q_PROPERTY(QString key5 READ key5 NOTIFY key5Changed)
	Q_PROPERTY(QString key6 READ key6 NOTIFY key6Changed)
	Q_PROPERTY(QString key7 READ key7 NOTIFY key7Changed)
#endif
	Q_PROPERTY(uint gear READ gear NOTIFY gearChanged)
	Q_PROPERTY(uint gearMode READ gearMode NOTIFY gearModeChanged)
	Q_PROPERTY(uint keyStatus READ keyStatus NOTIFY keyStatusChanged)
	Q_PROPERTY(bool leftFrontDoor READ leftFrontDoor NOTIFY leftFrontDoorChanged)
	Q_PROPERTY(bool rightFrontDoor READ rightFrontDoor NOTIFY rightFrontDoorChanged)
	Q_PROPERTY(bool leftRearDoor READ leftRearDoor NOTIFY leftRearDoorChanged)
	Q_PROPERTY(bool rightRearDoor READ rightRearDoor NOTIFY rightRearDoorChanged)
	Q_PROPERTY(bool hoodDoor READ hoodDoor NOTIFY hoodDoorChanged)
	Q_PROPERTY(bool trunkDoor READ trunkDoor NOTIFY trunkDoorChanged)
	Q_PROPERTY(uint odo READ odo NOTIFY odoChanged)
	Q_PROPERTY(uint averageSpeed READ averageSpeed NOTIFY averageSpeedChanged)
	Q_PROPERTY(uint remainMileage READ remainMileage NOTIFY remainMileageChanged)
	Q_PROPERTY(uint trip1 READ trip1 NOTIFY trip1Changed)
	Q_PROPERTY(uint trip2 READ trip2 NOTIFY trip2Changed)
	Q_PROPERTY(bool averageFuelUint READ averageFuelUint NOTIFY averageFuelUintChanged)
	Q_PROPERTY(bool instantaneousFuelUint READ instantaneousFuelUint NOTIFY instantaneousFuelUintChanged)
	Q_PROPERTY(uint averageFuel READ averageFuel NOTIFY averageFuelChanged)
	Q_PROPERTY(uint instantaneousFuel READ instantaneousFuel NOTIFY instantaneousFuelChanged)
	Q_PROPERTY(uint fuel READ fuel NOTIFY fuelChanged)
	Q_PROPERTY(uint soc READ soc NOTIFY socChanged)
	Q_PROPERTY(uint maintenanceMileage READ maintenanceMileage NOTIFY maintenanceMileageChanged)
	Q_PROPERTY(uint outTemprature READ outTemprature NOTIFY outTempratureChanged)
	Q_PROPERTY(uint batteryCurrent READ batteryCurrent NOTIFY batteryCurrentChanged)
	Q_PROPERTY(uint batteryVoltage READ batteryVoltage NOTIFY batteryVoltageChanged)


	// animation control
	Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
	explicit CarStatus(const QString &serialDev, QObject *parent = 0);
    explicit CarStatus(QObject *parent = 0);

	// all have
	uint hwVer()const { return m_hwVer; }
	uint releaseVer()const { return m_releaseVer; }
	uint betaVer()const { return m_betaVer; }
	uint rpm()const { return m_rpm; }
	QString date()const { return m_date; }
	QString time()const { return m_time; }
	uint speed()const { return m_speed; }
	uint temprature()const { return m_temprature; }
#ifdef DEBUG
	// button info
	QString key0()const { return m_key0; }
	QString key1()const { return m_key1; }
	QString key2()const { return m_key2; }
	QString key3()const { return m_key3; }
	QString key4()const { return m_key4; }
	QString key5()const { return m_key5; }
	QString key6()const { return m_key6; }
	QString key7()const { return m_key7; }
#endif
	uint gear()const { return m_gear; }
	uint gearMode()const { return m_gearMode; }
	uint keyStatus()const { return m_keyStatus; }
	bool leftFrontDoor()const { return m_leftFrontDoor; }
	bool rightFrontDoor()const { return m_rightFrontDoor; }
	bool leftRearDoor()const { return m_leftRearDoor; }
	bool rightRearDoor()const { return m_rightRearDoor; }
	bool hoodDoor()const { return m_hoodDoor; }
	bool trunkDoor()const { return m_trunkDoor; }
	uint odo()const { return m_odo; }
	uint averageSpeed()const { return m_averageSpeed; }
	uint remainMileage()const { return m_remainMileage; }
	uint trip1()const { return m_trip1; }
	uint trip2()const { return m_trip2; }
	bool averageFuelUint()const { return m_averageFuelUint; }
	bool instantaneousFuelUint()const { return m_instantaneousFuelUint; }
	uint averageFuel()const { return m_averageFuel; }
	uint instantaneousFuel()const { return m_instantaneousFuel; }
	uint fuel()const { return m_fuel; }
	uint soc()const { return m_soc; }
	uint maintenanceMileage()const { return m_maintenanceMileage; }
	uint outTemprature()const { return m_outTemprature; }
	uint batteryCurrent()const { return m_batteryCurrent; }
	uint batteryVoltage()const { return m_batteryVoltage; }

	// animation control
	virtual void setActive(bool)=0;
	bool active()const { return m_active; }

signals:
	// all have
	void hwVerChanged(uint);
	void releaseVerChanged(uint);
	void betaVerChanged(uint);
	void rpmChanged(uint);
	void dateChanged(QString);
	void timeChanged(QString);
	void speedChanged(uint);
	void tempratureChanged(uint);
	void key0Changed(bool);
	void key1Changed(bool);
	void key2Changed(bool);
	void key3Changed(bool);
	void key4Changed(bool);
	void key5Changed(bool);
	void key6Changed(bool);
	void key7Changed(bool);
	void gearChanged(uint);
	void gearModeChanged(uint);
	void keyStatusChanged(uint);
	void leftFrontDoorChanged(bool);
	void rightFrontDoorChanged(bool);
	void leftRearDoorChanged(bool);
	void rightRearDoorChanged(bool);
	void hoodDoorChanged(bool);
	void trunkDoorChanged(bool);
	void odoChanged(uint);
	void averageSpeedChanged(uint);
	void remainMileageChanged(uint);
	void trip1Changed(uint);
	void trip2Changed(uint);
	void averageFuelUintChanged(bool);
	void instantaneousFuelUintChanged(bool);
	void averageFuelChanged(uint);
	void instantaneousFuelChanged(uint);
	void fuelChanged(uint);
	void socChanged(uint);
	void maintenanceMileageChanged(uint);
	void outTempratureChanged(uint);
	void batteryCurrentChanged(uint);
	void batteryVoltageChanged(uint);

	void activeChanged(bool);

	// door info
	void sendLeftFrontDoorChanged(bool);
	void sendLeftRearDoorChanged(bool);
	void sendRightFrontDoorChanged(bool);
	void sendRightRearDoorChanged(bool);
	void sendHoodDoorChanged(bool);
	void sendTrunkDoorChanged(bool);

#ifdef DEBUG
	void key0ShowChanged(QString);
	void key1ShowChanged(QString);
	void key2ShowChanged(QString);
	void key3ShowChanged(QString);
	void key4ShowChanged(QString);
	void key5ShowChanged(QString);
	void key6ShowChanged(QString);
	void key7ShowChanged(QString);
#else
	Q_INVOKABLE void key0Short();
	Q_INVOKABLE void key1Short();
	Q_INVOKABLE void key2Short();
	Q_INVOKABLE void key3Short();
	Q_INVOKABLE void key4Short();
	Q_INVOKABLE void key5Short();
	Q_INVOKABLE void key6Short();
	Q_INVOKABLE void key7Short();
	Q_INVOKABLE void key0Long();
	Q_INVOKABLE void key1Long();
	Q_INVOKABLE void key2Long();
	Q_INVOKABLE void key3Long();
	Q_INVOKABLE void key4Long();
	Q_INVOKABLE void key5Long();
	Q_INVOKABLE void key6Long();
	Q_INVOKABLE void key7Long();
#endif

protected slots:
	virtual void getGeneralSerial(GeneralInfo data)=0;
	virtual void getSpecialSerial(SpecialInfo data)=0;
	virtual void getMobileSerial(MobileInfo data)=0;
	// door info
	void leftFrontDoorDeal(bool);
	void leftRearDoorDeal(bool);
	void rightFrontDoorDeal(bool);
	void rightRearDoorDeal(bool);
	void hoodDoorDeal(bool);
	void trunkDoorDeal(bool);

	// button info
	void key0Deal(bool);
	void key1Deal(bool);
	void key2Deal(bool);
	void key3Deal(bool);
	void key4Deal(bool);
	void key5Deal(bool);
	void key6Deal(bool);
	void key7Deal(bool);
protected:
	virtual void initValues()=0;

	void setHwVer(uint);
	void setReleaseVer(uint);
	void setBetaVer(uint);
	void setRpm(uint);
	void setDate(uint);
	void setTime(uint);
	void setSpeed(uint);
	void setTemprature(uint);
	void setKey0(bool);
	void setKey1(bool);
	void setKey2(bool);
	void setKey3(bool);
	void setKey4(bool);
	void setKey5(bool);
	void setKey6(bool);
	void setKey7(bool);
	void setGear(uint);
	void setGearMode(uint);
	void setKeyStatus(uint);
	void setLeftFrontDoor(bool);
	void setRightFrontDoor(bool);
	void setLeftRearDoor(bool);
	void setRightRearDoor(bool);
	void setHoodDoor(bool);
	void setTrunkDoor(bool);
	void setOdo(uint);
	void setAverageSpeed(uint);
	void setRemainMileage(uint);
	void setTrip1(uint);
	void setTrip2(uint);
	void setAverageFuelUint(bool);
	void setInstantaneousFuelUint(bool);
	void setAverageFuel(uint);
	void setInstantaneousFuel(uint);
	void setFuel(uint);
	void setSoc(uint);
	void setMaintenanceMileage(uint);
	void setOutTemprature(uint);
	void setBatteryCurrent(uint);
	void setBatteryVoltage(uint);

#ifdef DEBUG
	void setKeyShow0(QString);
	void setKeyShow1(QString);
	void setKeyShow2(QString);
	void setKeyShow3(QString);
	void setKeyShow4(QString);
	void setKeyShow5(QString);
	void setKeyShow6(QString);
	void setKeyShow7(QString);
#endif
	
	// door info
	void sendLeftFrontDoor(bool);
	void sendLeftRearDoor(bool);
	void sendRightFrontDoor(bool);
	void sendRightRearDoor(bool);
	void sendHoodDoor(bool);
	void sendTrunkDoor(bool);

	bool m_active;
	// all have
	uint m_hwVer;
	uint m_releaseVer;
	uint m_betaVer;
	uint m_rpm;
	QString m_date;
	QString m_time;
	uint m_speed;
	uint m_temprature;
#ifdef DEBUG
	// button info
	QString m_key0;
	QString m_key1;
	QString m_key2;
	QString m_key3;
	QString m_key4;
	QString m_key5;
	QString m_key6;
	QString m_key7;
#endif
	uint m_gear;
	uint m_gearMode;
	uint m_keyStatus;
	bool m_leftFrontDoor;
	bool m_rightFrontDoor;
	bool m_leftRearDoor;
	bool m_rightRearDoor;
	bool m_hoodDoor;
	bool m_trunkDoor;
	uint m_odo;
	uint m_averageSpeed;
	uint m_remainMileage;
	uint m_trip1;
	uint m_trip2;
	bool m_averageFuelUint;
	bool m_instantaneousFuelUint;
	uint m_averageFuel;
	uint m_instantaneousFuel;
	uint m_fuel;
	uint m_soc;
	uint m_maintenanceMileage;
	uint m_outTemprature;
	uint m_batteryCurrent;
	uint m_batteryVoltage;
	
	uint m_leftFrontDoorStep;
	uint m_leftRearDoorStep;
	uint m_rightFrontDoorStep;
	uint m_rightRearDoorStep;
	uint m_hoodDoorStep;
	uint m_trunkDoorStep;

	uint m_key0Step;
	bool m_key0StepFlag;
	uint m_key1Step;
	bool m_key1StepFlag;
	uint m_key2Step;
	bool m_key2StepFlag;
	uint m_key3Step;
	bool m_key3StepFlag;
	uint m_key4Step;
	bool m_key4StepFlag;
	uint m_key5Step;
	bool m_key5StepFlag;
	uint m_key6Step;
	bool m_key6StepFlag;
	uint m_key7Step;
	bool m_key7StepFlag;

	Serial *m_serial;


	QList<u_int16_t> m_rpmList;
};

#endif // CARSTATUS_H
