#include <QDebug>
#include <QDateTime>

#include <serial.h>
#include <carstatus.h>

CarStatus::CarStatus(const QString &serialDev, QObject *parent) :
	QObject(parent)
{
	m_serial = new Serial(serialDev, this);
	// door signal and slot
	connect(this, SIGNAL(sendLeftFrontDoorChanged(bool)), this, SLOT(leftFrontDoorDeal(bool)));
	connect(this, SIGNAL(sendLeftRearDoorChanged(bool)), this, SLOT(leftRearDoorDeal(bool)));
	connect(this, SIGNAL(sendRightFrontDoorChanged(bool)), this, SLOT(rightFrontDoorDeal(bool)));
	connect(this, SIGNAL(sendRightRearDoorChanged(bool)), this, SLOT(rightRearDoorDeal(bool)));
	connect(this, SIGNAL(sendHoodDoorChanged(bool)), this, SLOT(hoodDoorDeal(bool)));
	connect(this, SIGNAL(sendTrunkDoorChanged(bool)), this, SLOT(trunkDoorDeal(bool)));

	connect(this, SIGNAL(key0Changed(bool)), this, SLOT(key0Deal(bool)));
	connect(this, SIGNAL(key1Changed(bool)), this, SLOT(key1Deal(bool)));
	connect(this, SIGNAL(key2Changed(bool)), this, SLOT(key2Deal(bool)));
	connect(this, SIGNAL(key3Changed(bool)), this, SLOT(key3Deal(bool)));
	connect(this, SIGNAL(key4Changed(bool)), this, SLOT(key4Deal(bool)));
	connect(this, SIGNAL(key5Changed(bool)), this, SLOT(key5Deal(bool)));
	connect(this, SIGNAL(key6Changed(bool)), this, SLOT(key6Deal(bool)));
	connect(this, SIGNAL(key7Changed(bool)), this, SLOT(key7Deal(bool)));
}

CarStatus::CarStatus(QObject *parent) :
    QObject(parent)
{
    m_serial = NULL;
}

// all have
void CarStatus::setHwVer(uint v)
{
	if (m_hwVer == v)
		return;

	m_hwVer = v;
	emit hwVerChanged(v);
}

void CarStatus::setReleaseVer(uint v)
{
	if (m_releaseVer == v)
		return;

	m_releaseVer = v;
	emit releaseVerChanged(v);
}

void CarStatus::setBetaVer(uint v)
{
	if (m_betaVer == v)
		return;

	m_betaVer = v;
	emit betaVerChanged(v);
}

void CarStatus::setRpm(uint v)
{
	if( v > 500 && v < 1000 ) {
		u_int16_t averageValue = 0;

		if( m_rpmList.size() <= 20 )
			m_rpmList.append(v);
		else {
			m_rpmList.pop_front();
			m_rpmList.append(v);
		}

		for( int i = 0; i < m_rpmList.size(); i++ ) {
			averageValue += m_rpmList.at(i);
		}

		averageValue = averageValue / m_rpmList.size();

		if( m_rpm == averageValue )
			return;

		m_rpm = averageValue;
	} else {
		if( m_rpm == v )
			return;

		m_rpm = v;
	}

	emit rpmChanged(m_rpm);
}

void CarStatus::setDate(uint v)
{
	QDateTime date;
	date.setTimeSpec(Qt::UTC);
	date.setTime_t(v);
	m_date = date.toString("yyyy-MM-dd");
	emit dateChanged(m_date);
}

void CarStatus::setTime(uint v)
{
	QDateTime time;
	time.setTimeSpec(Qt::UTC);
	time.setTime_t(v);
	m_time = time.toString("hh:mm");
	emit timeChanged(m_time);
}

void CarStatus::setSpeed(uint v)
{
	if (m_speed == v)
		return;

	m_speed = v;
	emit speedChanged(v);
}
void CarStatus::setTemprature(uint v)
{
	if (m_temprature == v)
		return;

	m_temprature = v;
	emit tempratureChanged(v);
}
#ifdef DEBUG
void CarStatus::setKeyShow0(QString v)
{
	if (m_key0 == v)
		return;

	m_key0 = v;
	emit key0ShowChanged(v);
}

void CarStatus::setKeyShow1(QString v)
{
	if (m_key1 == v)
		return;

	m_key1 = v;
	emit key1ShowChanged(v);
}

void CarStatus::setKeyShow2(QString v)
{
	if (m_key2 == v)
		return;

	m_key2 = v;
	emit key2ShowChanged(v);
}

void CarStatus::setKeyShow3(QString v)
{
	if (m_key3 == v)
		return;

	m_key3 = v;
	emit key3ShowChanged(v);
}

void CarStatus::setKeyShow4(QString v)
{
	if (m_key4 == v)
		return;

	m_key4 = v;
	emit key4ShowChanged(v);
}

void CarStatus::setKeyShow5(QString v)
{
	if (m_key5 == v)
		return;

	m_key5 = v;
	emit key5ShowChanged(v);
}

void CarStatus::setKeyShow6(QString v)
{
	if (m_key6 == v)
		return;

	m_key6 = v;
	emit key6ShowChanged(v);
}

void CarStatus::setKeyShow7(QString v)
{
	if (m_key7 == v)
		return;

	m_key7 = v;
	emit key7ShowChanged(v);
}
#endif
void CarStatus::setKey0(bool v)
{
	emit key0Changed(v);
}
void CarStatus::setKey1(bool v)
{
	emit key1Changed(v);
}
void CarStatus::setKey2(bool v)
{
	emit key2Changed(v);
}
void CarStatus::setKey3(bool v)
{
	emit key3Changed(v);
}
void CarStatus::setKey4(bool v)
{
	emit key4Changed(v);
}
void CarStatus::setKey5(bool v)
{
	emit key5Changed(v);
}
void CarStatus::setKey6(bool v)
{
	emit key6Changed(v);
}
void CarStatus::setKey7(bool v)
{
	emit key7Changed(v);
}

void CarStatus::setGear(uint v)
{
	if (m_gear == v)
		return;

	m_gear = v;
	emit gearChanged(v);
}

void CarStatus::setGearMode(uint v)
{
	if (m_gearMode == v)
		return;

	m_gearMode = v;
	emit gearModeChanged(v);
}

void CarStatus::setKeyStatus(uint v)
{
	if (m_keyStatus == v)
		return;

	m_keyStatus = v;
	emit keyStatusChanged(v);
}

void CarStatus::setLeftFrontDoor(bool v)
{
	emit sendLeftFrontDoorChanged(v);
}

void CarStatus::setLeftRearDoor(bool v)
{
	emit sendLeftRearDoorChanged(v);
}

void CarStatus::setRightFrontDoor(bool v)
{
	emit sendRightFrontDoorChanged(v);
}

void CarStatus::setRightRearDoor(bool v)
{
	emit sendRightRearDoorChanged(v);
}

void CarStatus::setHoodDoor(bool v)
{
	emit sendHoodDoorChanged(v);
}

void CarStatus::setTrunkDoor(bool v)
{
	emit sendTrunkDoorChanged(v);
}

void CarStatus::setOdo(uint v)
{
	if (m_odo == v)
		return;

	m_odo = v;
	emit odoChanged(v);
}
void CarStatus::setAverageSpeed(uint v)
{
	if (m_averageSpeed == v)
		return;

	m_averageSpeed = v;
	emit averageSpeedChanged(v);
}
void CarStatus::setRemainMileage(uint v)
{
	if (m_remainMileage == v)
		return;

	m_remainMileage = v;
	emit remainMileageChanged(v);
}

void CarStatus::setTrip1(uint v)
{
	if (m_trip1 == v)
		return;

	m_trip1 = v;
	emit trip1Changed(v);
}

void CarStatus::setTrip2(uint v)
{
	if (m_trip2 == v)
		return;

	m_trip2 = v;
	emit trip2Changed(v);
}

void CarStatus::setAverageFuelUint(bool v)
{
	if (m_averageFuelUint == v)
		return;
	m_averageFuelUint = v;

	emit averageFuelUintChanged(v);
}

void CarStatus::setInstantaneousFuelUint(bool v)
{
	if (m_instantaneousFuelUint == v)
		return;

	m_instantaneousFuelUint = v;

	emit instantaneousFuelUintChanged(v);
}


void CarStatus::setAverageFuel(uint v)
{
	if (m_averageFuel == v)
		return;

	m_averageFuel = v;
	emit averageFuelChanged(v);
}

void CarStatus::setInstantaneousFuel(uint v)
{
	if (m_instantaneousFuel == v)
		return;

	m_instantaneousFuel = v;
	emit instantaneousFuelChanged(v);
}

void CarStatus::setFuel(uint v)
{
	if (m_fuel == v)
		return;

	m_fuel = v;
	emit fuelChanged(v);
}

void CarStatus::setSoc(uint v)
{
	if (m_soc == v)
		return;

	m_soc = v;
	emit socChanged(v);
}

void CarStatus::setMaintenanceMileage(uint v)
{
	if (m_maintenanceMileage == v)
		return;

	m_maintenanceMileage = v;
	emit maintenanceMileageChanged(v);
}

void CarStatus::setOutTemprature(uint v)
{
	if (m_outTemprature == v)
		return;

	m_outTemprature = v;
	emit outTempratureChanged(v);
}

void CarStatus::setBatteryCurrent(uint v)
{
	if (m_batteryCurrent == v)
		return;

	m_batteryCurrent = v;
	emit batteryCurrentChanged(v);
}

void CarStatus::setBatteryVoltage(uint v)
{
	if (m_batteryVoltage == v)
		return;

	m_batteryVoltage = v;
	emit batteryVoltageChanged(v);
}

void CarStatus::leftFrontDoorDeal(bool v)
{
	if (m_leftFrontDoorStep == 0 && v != m_leftFrontDoor)
		++m_leftFrontDoorStep;

	// key debounce
	if (m_leftFrontDoorStep >= 1 && m_leftFrontDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_leftFrontDoor) {
			m_leftFrontDoorStep = 0;
		}
		++m_leftFrontDoorStep;
	}

	if (m_leftFrontDoorStep == DOOR_DEBOUNCE_TIME && v != m_leftFrontDoor) {
		// the key is LeftButton
		++m_leftFrontDoorStep;
		m_leftFrontDoor = v;
		emit leftFrontDoorChanged(m_leftFrontDoor);
	}

	if (m_leftFrontDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_leftFrontDoor) {
		m_leftFrontDoorStep = 0;
	}
}


void CarStatus::leftRearDoorDeal(bool v)
{
	if (m_leftRearDoorStep == 0 && v != m_leftRearDoor)
		++m_leftRearDoorStep;

	// key debounce
	if (m_leftRearDoorStep >= 1 && m_leftRearDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_leftRearDoor) {
			m_leftRearDoorStep = 0;
		}
		++m_leftRearDoorStep;
	}

	if (m_leftRearDoorStep == DOOR_DEBOUNCE_TIME && v != m_leftRearDoor) {
		// the key is LeftButton
		++m_leftRearDoorStep;
		m_leftRearDoor = v;
		emit leftRearDoorChanged(m_leftRearDoor);
	}

	if (m_leftRearDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_leftRearDoor) {
		m_leftRearDoorStep = 0;
	}
}


void CarStatus::rightFrontDoorDeal(bool v)
{
	if (m_rightFrontDoorStep == 0 && v != m_rightFrontDoor)
		++m_rightFrontDoorStep;

	// key debounce
	if (m_rightFrontDoorStep >= 1 && m_rightFrontDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_rightFrontDoor) {
			m_rightFrontDoorStep = 0;
		}
		++m_rightFrontDoorStep;
	}

	if (m_rightFrontDoorStep == DOOR_DEBOUNCE_TIME && v != m_rightFrontDoor) {
		// the key is LeftButton
		++m_rightFrontDoorStep;
		m_rightFrontDoor = v;
		emit rightFrontDoorChanged(m_rightFrontDoor);
	}

	if (m_rightFrontDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_rightFrontDoor) {
		m_rightFrontDoorStep = 0;
	}
}


void CarStatus::rightRearDoorDeal(bool v)
{
	if (m_rightRearDoorStep == 0 && v != m_rightRearDoor)
		++m_rightRearDoorStep;

	// key debounce
	if (m_rightRearDoorStep >= 1 && m_rightRearDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_rightRearDoor) {
			m_rightRearDoorStep = 0;
		}
		++m_rightRearDoorStep;
	}

	if (m_rightRearDoorStep == DOOR_DEBOUNCE_TIME && v != m_rightRearDoor) {
		// the key is LeftButton
		++m_rightRearDoorStep;
		m_rightRearDoor = v;
		emit rightRearDoorChanged(m_rightRearDoor);
	}

	if (m_rightRearDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_rightRearDoor) {
		m_rightRearDoorStep = 0;
	}
}


void CarStatus::hoodDoorDeal(bool v)
{
	if (m_hoodDoorStep == 0 && v != m_hoodDoor)
		++m_hoodDoorStep;

	// key debounce
	if (m_hoodDoorStep >= 1 && m_hoodDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_hoodDoor) {
			m_hoodDoorStep = 0;
		}
		++m_hoodDoorStep;
	}

	if (m_hoodDoorStep == DOOR_DEBOUNCE_TIME && v != m_hoodDoor) {
		// the key is LeftButton
		++m_hoodDoorStep;
		m_hoodDoor = v;
		emit hoodDoorChanged(m_hoodDoor);
	}

	if (m_hoodDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_hoodDoor) {
		m_hoodDoorStep = 0;
	}
}


void CarStatus::trunkDoorDeal(bool v)
{
	if (m_trunkDoorStep == 0 && v != m_trunkDoor)
		++m_trunkDoorStep;

	// key debounce
	if (m_trunkDoorStep >= 1 && m_trunkDoorStep < DOOR_DEBOUNCE_TIME) {
		if (v == m_trunkDoor) {
			m_trunkDoorStep = 0;
		}
		++m_trunkDoorStep;
	}

	if (m_trunkDoorStep == DOOR_DEBOUNCE_TIME && v != m_trunkDoor) {
		// the key is LeftButton
		++m_trunkDoorStep;
		m_trunkDoor = v;
		emit trunkDoorChanged(m_trunkDoor);
	}

	if (m_trunkDoorStep == DOOR_DEBOUNCE_TIME + 1 && v == m_trunkDoor) {
		m_trunkDoorStep = 0;
	}
}

void CarStatus::key0Deal(bool v)
{
	if (m_key0Step == 0 && v)
		++m_key0Step;

	// key debounce
	if (m_key0Step >= 1 && m_key0Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key0Step = 0;
		}
		++m_key0Step;
	}

	// LongKey deal
	if (m_key0Step >= KEY_DEBOUNCE_TIME && m_key0Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key0StepFlag) {
				// the key is shortButton
				m_key0Step = 0;
#ifdef DEBUG
				setKeyShow0("ShortButton");
#else
				emit key0Short();
#endif
			}
			m_key0StepFlag = true;
		}
		else {
			m_key0StepFlag = false;
		}
		++m_key0Step;
	}

	if (m_key0Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key0Step;
#ifdef DEBUG
		setKeyShow0("LongButton");
#else
		emit key0Long();
#endif
	}

	if (m_key0Step == KEY_LONG_TIME + 1 && !v) {
		m_key0Step = 0;
#ifdef DEBUG
		setKeyShow0("NONE");
#endif
	}
}

void CarStatus::key1Deal(bool v)
{
	if (m_key1Step == 0 && v)
		++m_key1Step;

	// key debounce
	if (m_key1Step >= 1 && m_key1Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key1Step = 0;
		}
		++m_key1Step;
	}

	// LongKey deal
	if (m_key1Step >= KEY_DEBOUNCE_TIME && m_key1Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key1StepFlag) {
				// the key is shortButton
				m_key1Step = 0;
#ifdef DEBUG
				setKeyShow1("ShortButton");
#else
				emit key1Short();
#endif
			}
			m_key1StepFlag = true;
		}
		else {
			m_key1StepFlag = false;
		}
		++m_key1Step;
	}

	if (m_key1Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key1Step;
#ifdef DEBUG
		setKeyShow1("LongButton");
#else
		emit key1Long();
#endif
	}

	if (m_key1Step == KEY_LONG_TIME + 1 && !v) {
		m_key1Step = 0;
#ifdef DEBUG
		setKeyShow1("NONE");
#endif
	}
}

void CarStatus::key2Deal(bool v)
{
	if (m_key2Step == 0 && v)
		++m_key2Step;

	// key debounce
	if (m_key2Step >= 1 && m_key2Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key2Step = 0;
		}
		++m_key2Step;
	}

	// LongKey deal
	if (m_key2Step >= KEY_DEBOUNCE_TIME && m_key2Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key2StepFlag) {
				// the key is shortButton
				m_key2Step = 0;
#ifdef DEBUG
				setKeyShow2("ShortButton");
#else
				emit key2Short();
#endif
			}
			m_key2StepFlag = true;
		}
		else {
			m_key2StepFlag = false;
		}
		++m_key2Step;
	}

	if (m_key2Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key2Step;
#ifdef DEBUG
		setKeyShow2("LongButton");
#else
		emit key2Long();
#endif
	}

	if (m_key2Step == KEY_LONG_TIME + 1 && !v) {
		m_key2Step = 0;
#ifdef DEBUG
		setKeyShow2("NONE");
#endif
	}
}

void CarStatus::key3Deal(bool v)
{
	if (m_key3Step == 0 && v)
		++m_key3Step;

	// key debounce
	if (m_key3Step >= 1 && m_key3Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key3Step = 0;
		}
		++m_key3Step;
	}

	// LongKey deal
	if (m_key3Step >= KEY_DEBOUNCE_TIME && m_key3Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key3StepFlag) {
				// the key is shortButton
				m_key3Step = 0;
#ifdef DEBUG
				setKeyShow3("ShortButton");
#else
				emit key3Short();
#endif
			}
			m_key3StepFlag = true;
		}
		else {
			m_key3StepFlag = false;
		}
		++m_key3Step;
	}

	if (m_key3Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key3Step;
#ifdef DEBUG
		setKeyShow3("LongButton");
#else
		emit key3Long();
#endif
	}

	if (m_key3Step == KEY_LONG_TIME + 1 && !v) {
		m_key3Step = 0;
#ifdef DEBUG
		setKeyShow3("NONE");
#endif
	}
}

void CarStatus::key4Deal(bool v)
{
	if (m_key4Step == 0 && v)
		++m_key4Step;

	// key debounce
	if (m_key4Step >= 1 && m_key4Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key4Step = 0;
		}
		++m_key4Step;
	}

	// LongKey deal
	if (m_key4Step >= KEY_DEBOUNCE_TIME && m_key4Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key4StepFlag) {
				// the key is shortButton
				m_key4Step = 0;
#ifdef DEBUG
				setKeyShow4("ShortButton");
#else
				emit key4Short();
#endif
			}
			m_key4StepFlag = true;
		}
		else {
			m_key4StepFlag = false;
		}
		++m_key4Step;
	}

	if (m_key4Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key4Step;
#ifdef DEBUG
		setKeyShow4("LongButton");
#else
		emit key4Long();
#endif
	}

	if (m_key4Step == KEY_LONG_TIME + 1 && !v) {
		m_key4Step = 0;
#ifdef DEBUG
		setKeyShow4("NONE");
#endif
	}
}

void CarStatus::key5Deal(bool v)
{
	if (m_key5Step == 0 && v)
		++m_key5Step;

	// key debounce
	if (m_key5Step >= 1 && m_key5Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key5Step = 0;
		}
		++m_key5Step;
	}

	// LongKey deal
	if (m_key5Step >= KEY_DEBOUNCE_TIME && m_key5Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key5StepFlag) {
				// the key is shortButton
				m_key5Step = 0;
#ifdef DEBUG
				setKeyShow5("ShortButton");
#else
				emit key5Short();
#endif
			}
			m_key5StepFlag = true;
		}
		else {
			m_key5StepFlag = false;
		}
		++m_key5Step;
	}

	if (m_key5Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key5Step;
#ifdef DEBUG
		setKeyShow5("LongButton");
#else
		emit key5Long();
#endif
	}

	if (m_key5Step == KEY_LONG_TIME + 1 && !v) {
		m_key5Step = 0;
#ifdef DEBUG
		setKeyShow5("NONE");
#endif
	}
}

void CarStatus::key6Deal(bool v)
{
	if (m_key6Step == 0 && v)
		++m_key6Step;

	// key debounce
	if (m_key6Step >= 1 && m_key6Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key6Step = 0;
		}
		++m_key6Step;
	}

	// LongKey deal
	if (m_key6Step >= KEY_DEBOUNCE_TIME && m_key6Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key6StepFlag) {
				// the key is shortButton
				m_key6Step = 0;
#ifdef DEBUG
				setKeyShow6("ShortButton");
#else
				emit key6Short();
#endif
			}
			m_key6StepFlag = true;
		}
		else {
			m_key6StepFlag = false;
		}
		++m_key6Step;
	}

	if (m_key6Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key6Step;
#ifdef DEBUG
		setKeyShow6("LongButton");
#else
		emit key6Long();
#endif
	}

	if (m_key6Step == KEY_LONG_TIME + 1 && !v) {
		m_key6Step = 0;
#ifdef DEBUG
		setKeyShow6("NONE");
#endif
	}
}

void CarStatus::key7Deal(bool v)
{
	if (m_key7Step == 0 && v)
		++m_key7Step;

	// key debounce
	if (m_key7Step >= 1 && m_key7Step < KEY_DEBOUNCE_TIME) {
		if(!v) {
			m_key7Step = 0;
		}
		++m_key7Step;
	}

	// LongKey deal
	if (m_key7Step >= KEY_DEBOUNCE_TIME && m_key7Step < KEY_LONG_TIME) {
		if (!v) {
			if (m_key7StepFlag) {
				// the key is shortButton
				m_key7Step = 0;
#ifdef DEBUG
				setKeyShow7("ShortButton");
#else
				emit key7Short();
#endif
			}
			m_key7StepFlag = true;
		}
		else {
			m_key7StepFlag = false;
		}
		++m_key7Step;
	}

	if (m_key7Step == KEY_LONG_TIME && v) {
		// the key is LongButton
		++m_key7Step;
#ifdef DEBUG
		setKeyShow7("LongButton");
#else
		emit key7Long();
#endif
	}

	if (m_key7Step == KEY_LONG_TIME + 1 && !v) {
		m_key7Step = 0;
#ifdef DEBUG
		setKeyShow7("NONE");
#endif
	}
}

