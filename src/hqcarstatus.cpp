#include <QDebug>
#include <QDateTime>

#include <hqcarstatus.h>

#define ValueChangeSet(name, v) do{if(m_##name!=(v)){m_##name=(v); emit name##Changed(v); qDebug()<<QString(#name)<<(v);}}while(0)

HqCarStatus::HqCarStatus(const QString &serialDev, QObject *parent) :
	CarStatus(serialDev, parent)
{
	initValues();

	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateERR()));

	m_functionTimer = new QTimer(this);
	connect(m_functionTimer, SIGNAL(timeout()), this, SLOT(updateFunction()));

	m_checkTimer = new QTimer(this);
	connect(m_checkTimer, SIGNAL(timeout()), this, SLOT(dealCheckKey()));
}

void HqCarStatus::startTime()
{
	m_timer->start(5000);
}

void HqCarStatus::stopTime()
{
	m_timer->stop();
	m_errType = NULL_ERR;
	emit errTypeChanged(m_errType);
}

void HqCarStatus::showCheckErr()
{
	if( m_functionTypes == MIN_EVENT && (m_errType == NULL_ERR || m_isTipedList == true) ) {
		if( m_tipedList.size() == 0 )
		{
			return;
		}
		m_isTipedList = true;
		m_errType = (WARNING_TIPS)m_tipedList[m_checkIndex];
		emit errTypeChanged(m_errType);
		m_checkTimer->start(5000);
		++m_checkIndex;
		if( m_checkIndex >= m_tipedList.size())
			m_checkIndex = 0;
	}
}

void HqCarStatus::updateFunction()
{
#ifdef ANIMOTION_DEBUG
	if( m_functionTypes >= MAX_EVENT )
		m_functionTypes = (FUNCTION_EVENT)(MIN_EVENT + 1);
	else
		m_functionTypes = (FUNCTION_EVENT)(m_functionTypes + 1);
	emit functionTypesChanged(m_functionTypes);
#else
	if( m_functionList[0] == m_functionTypes ) {
		if( (m_functionTypes >= ABA_EVENT && m_functionTypes <= LKPMORE_EVENT)
				|| (m_functionTypes >= ACC_EVENT && m_functionTypes <= CCS_EVENT) )
		{
			return;
		}
		popList(&m_functionList);
	}
	if( m_functionList.size() == 0 )
	{
		m_functionTimer->stop();
		m_functionTypes = MIN_EVENT;
	}
	else {
		m_functionTypes = (FUNCTION_EVENT)m_functionList[0];
	}
	if( ((m_functionTypes >= ACC_EVENT && m_functionTypes <= CCS_EVENT) || m_functionList.size() == 0) && m_preTipList.size() > 0 ) {
		m_functionTimer->stop();
		m_functionTypes = MIN_EVENT;
		emit functionTypesChanged(m_functionTypes);

		m_errType = (WARNING_TIPS)m_preTipList[0];
		emit errTypeChanged(m_errType);
		m_timer->start(5000);
	} else {
		emit functionTypesChanged(m_functionTypes);
	}
#endif
}

void HqCarStatus::dealCheckKey()
{
	m_checkTimer->stop();
	m_checkIndex = 0;
	m_isTipedList = false;
	m_errType = NULL_ERR;
	emit errTypeChanged(m_errType);

	if(m_preTipList.size() > 0) {
		m_errType = (WARNING_TIPS)m_preTipList[0];
		emit errTypeChanged(m_errType);
		m_timer->start(5000);
		return;
	}

	if(m_functionList.size() > 0) {
		m_functionTypes = (FUNCTION_EVENT)m_functionList[0];
		emit functionTypesChanged(m_functionTypes);
		m_functionTimer->start(5000);
	}
}
void HqCarStatus::updateERR()
{
#ifdef ANIMOTION_DEBUG
	if( m_errType >= MAX_WARNING_TIPS )
		m_errType = (WARNING_TIPS)(NULL_ERR + 1);
	else
		m_errType = (WARNING_TIPS)(m_errType + 1);
	emit errTypeChanged(m_errType);
#else

	if( m_preTipList[0] == m_errType ) {
		if(	 m_errType == OVER_SPEED_ERR
			 || m_errType == SET_CCS_ERR
			 || m_errType == ACC_CLOSE_ERR
			 || m_errType == LDW_CLOSE_ERR
			 || m_errType == AFS_CLOSE_ERR
			 || m_errType == ESP_CLOSE_ERR
			 || m_errType == FCW_CLOSE_ERR
			 || m_errType == FCW_CLOSE_ERR
			 || m_errType == ABA_CLOSE_ERR) {
			popList(&m_preTipList);
		} else {
			insertList(&m_tipedList, popList(&m_preTipList));
		}
	}
	if( m_preTipList.size() == 0 )
	{
		m_timer->stop();
		m_errType = NULL_ERR;
	}
	else
		m_errType = (WARNING_TIPS)m_preTipList[0];
	emit errTypeChanged(m_errType);

	if( m_functionList.size() > 0 &&  m_preTipList.size() == 0 ) {
		m_functionTypes = (FUNCTION_EVENT)m_functionList[0];
		emit functionTypesChanged(m_functionTypes);
		m_functionTimer->start(5000);
	}
#endif
}

HqCarStatus::HqCarStatus(QObject *parent) :
	CarStatus(parent)
{
	initValues();
}

void HqCarStatus::initValues()
{
	m_active = false;
	// all have
	m_hwVer = 0;
	m_releaseVer = 0;
	m_betaVer = 0;
	m_rpm = 0;
	m_date = "";
	m_time = "";
	m_speed = 0;
	m_temprature = 0;
	m_gear = 0;
	m_gearMode = 0;
	m_keyStatus = 0;
	m_leftFrontDoor = false;
	m_rightFrontDoor = false;
	m_leftRearDoor = false;
	m_rightRearDoor = false;
	m_hoodDoor = false;
	m_trunkDoor = false;
	m_odo = 0;
	m_averageSpeed = 0;
	m_remainMileage = 0;
	m_trip1 = 0;
	m_trip2 = 0;
	m_averageFuelUint = false;
	m_instantaneousFuelUint = false;
	m_averageFuel = 0;
	m_instantaneousFuel = 0;
	m_fuel = 0;
	m_soc = 0;
	m_maintenanceMileage = 0;
	m_outTemprature = 0xffff;
	m_batteryCurrent = 0;
	m_batteryVoltage = 0;
	m_leftFrontDoorStep = 0;
	m_leftRearDoorStep = 0;
	m_rightFrontDoorStep = 0;
	m_rightRearDoorStep = 0;
	m_hoodDoorStep = 0;
	m_trunkDoorStep = 0;
	m_key0Step = 0;
	m_key0StepFlag = false;
	m_key1Step = 0;
	m_key1StepFlag = false;
	m_key2Step = 0;
	m_key2StepFlag = false;
	m_key3Step = 0;
	m_key3StepFlag = false;
	m_key4Step = 0;
	m_key4StepFlag = false;
	m_key5Step = 0;
	m_key5StepFlag = false;
	m_key6Step = 0;
	m_key6StepFlag = false;
	m_key7Step = 0;
	m_key7StepFlag = false;

	// MobileInfo
	m_nameLen = 0;
	m_name = "";
	m_numTypes = 0;
	m_numLen = 0;
	m_number = "";

	// SettingsInfo
	m_commandReq = false;
	m_closeReq = false;
	m_tripClean = false;
	m_averageSpeedClean = false;
	m_averageFuelClean = false;
	m_engineerMode = false;
	m_dateTime = 0;

	m_tripCleanFlag = false;

	// SpecialInfo
	m_brakeSysErr = false;
	m_powerSteerErr = false;
	m_fLTirePressLeak = false;
	m_fRTirePressLeak = false;
	m_rLTirePressLeak = false;
	m_rRTirePressLeak = false;
	m_fLTirePressMoreInfo = false;
	m_fRTirePressMoreInfo = false;
	m_rLTirePressMoreInfo = false;
	m_rRTirePressMoreInfo = false;
	m_engineControlErr = false;
	m_gearboxToohot = false;
	m_gearboxErr = false;
	m_accAutoOff = false;
	m_abaErr = false;
	m_fcwErr = false;
	m_absErr = false;
	m_hydraulicSysErr = false;
	m_espErr = false;
	m_tcsErr = false;
	m_coolSysErr = false;
	m_fluidToolow = false;
	m_engineOilErr = false;
	m_epbErr = false;
	m_autoHoldErr = false;
	m_accErr = false;
	m_pdcErr = false;
	m_checkAlternator = false;
	m_changeBrakePads = false;
	m_overSpeedLimit = false;
	m_fLTirePressInfo = false;
	m_fRTirePressInfo = false;
	m_rLTirePressInfo = false;
	m_rRTirePressInfo = false;
	m_airbagErr = false;
	m_refrigerantLow = false;
	m_accActiveErr = false;
	m_setCruise = false;
	m_ldwErr = false;
	m_emissionSysErr = false;
	m_passiveEntrySysErr = false;
	m_fLTirePressMonitorErr = false;
	m_fRTirePressMonitorErr = false;
	m_rLTirePressMonitorErr = false;
	m_rRTirePressMonitorErr = false;
	m_lFTurnLightErr = false;
	m_rFTurnLightErr = false;
	m_lRTurnLightErr = false;
	m_rRTurnLightErr = false;
	m_lRGroupLightErr = false;
	m_rRGroupLightErr = false;
	m_backupLightErr = false;
	m_nightVisionErr = false;
	m_afsErr = false;
	m_startAndStopSysErr = false;
	m_headlampAdjustErr = false;
	m_refillFuel = false;
	m_autoLightsWiperErr = false;
	m_cameraBlocked = false;
	m_raderBlockHotErr = false;
	m_lFLightErr = false;
	m_rFLightErr = false;
	m_lFPositionLightErr = false;
	m_rFPositionLightErr = false;
	m_lFFogLightErr = false;
	m_rFFogLightErr = false;
	m_licenseLightErr = false;
	m_ignitionSwitchErr = false;
	m_unknownKey = false;
	m_fourWDSysErr = false;
	m_scmSysErr = false;
	m_accClose = false;
	m_keyBatLow = false;
	m_refillCleanFluid = false;
	m_seatAdjustErr = false;
	m_xkmBeforeMaintenance = false;
	m_bluetoothMicrophoneErr = false;
	m_bluetoothSwitchErr = false;
	m_bluetoothAudioLineErr = false;
	m_steeringColumnLockErr = false;
	m_instrumentClusterErr = false;
	m_ldwClose = false;
	m_afsClose = false;
	m_espClose = false;
	m_abaActiveErr = false;
	m_fcwCloseErr = false;
	m_abaCloseErr = false;
	m_abaIndicator = false;
	m_avh = false;
	m_stopAndGoIndicator = 0;
	m_parkingCarUi = false;
	m_rearRightRadarFlicker = false;
	m_rearCentreRRadarFlicker = false;
	m_rearCentreLRadarFlicker = false;
	m_rearLeftRadarFlicker = false;
	m_frontRightRadarFlicker = false;
	m_frontCentreRRadarFlicker = false;
	m_frontCentreLRadarFlicker = false;
	m_frontLeftRadarFlicker = false;
	m_frontLeftRadarLevel = 0;
	m_frontCentreLRadarLevel = 0;
	m_frontCentreRRadarLevel = 0;
	m_frontRightRadarLevel = 0;
	m_rearRightRadarLevel = 0;
	m_rearCentreRRadarLevel = 0;
	m_rearCentreLRadarLevel = 0;
	m_rearLeftRadarLevel = 0;
	m_fcwNotice = false;
	m_fcwMoreNotice = false;
	m_lkpMoreRest = false;
	m_lkpRest = false;
	m_shift2P = false;
	m_slopeTooHigh = false;
	m_brakingPowerLow = false;
	m_keyInCar = false;
	m_keyInTrunk = false;
	m_keyStatus2Off = false;
	m_steerColumnLock = false;
	m_batLowStartEngine = false;
	m_startEngineSelf = false;
	m_shift2PN = false;
	m_lPress2Start24s = false;
	m_lampON = false;
	m_accUI = false;
	m_accIndicator = 0;
	m_accFlicker = false;
	m_frontCarDistanceLevel = 0;
	m_frontCarFlicker = false;
	m_frontCarSpeed = 0;
	m_accRecovery = false;
	m_frontCarStatus = 0;
	m_ccsSet = false;
	m_ccsIndicator = 0;
	m_ccsSpeed = 0;
	m_ldwOn = false;
	m_ldwIndicator = 0;
	m_ldwFlicker = false;
	m_ldwLeftIndicator = 0;
	m_ldwRightIndicator = 0;
	m_bluetoothStatus = 0;
	m_batValue = 0;
	m_mobileSingel = 0;
	m_highBeamLight = false;
	m_positionLight = false;
	m_frontFogLight = false;
	m_rearFogLight = false;
	m_engineOilLight = false;
	m_nightVisionLight = false;
	m_sysBattErr = false;
	m_mainErr = false;
	m_espLightFlick = false;
	m_fLTirePress = 0;
	m_fRTirePress = 0;
	m_rLTirePress = 0;
	m_rRTirePress = 0;
	m_fLTireTemp = 0;
	m_fRTireTemp = 0;
	m_rLTireTemp = 0;
	m_rRTireTemp = 0;
	m_fm = 0;
	m_am = 0;
	m_programNum = 0;
	m_soundMode = 8;

	m_errType = NULL_ERR;
	m_functionTypes = MIN_EVENT;

	m_functionList.clear();
	m_preTipList.clear();
	m_tipedList.clear();
	m_isTipedList = false;

	m_timer = NULL;
	m_functionTimer = NULL;
	m_checkTimer = NULL;
	m_checkIndex = 0;
}



void HqCarStatus::getGeneralSerial(GeneralInfo data)
{
	if(!m_active)
		return;
	setHwVer(data.hwVer);
	setReleaseVer(data.releaseVer);
	setBetaVer(data.betaVer);
	setRpm(data.rpm);
	setDate(data.time);
	setTime(data.time);
	setSpeed(data.speed);
	setTemprature(data.temprature);
	setKey0(data.key0);
	setKey1(data.key1);
	setKey2(data.key2);
	setKey3(data.key3);
	setKey4(data.key4);
	setKey5(data.key5);
	setKey6(data.key6);
	setKey7(data.key7);
	setGear(data.gear);
	setGearMode(data.gearMode);
	setKeyStatus(data.keyStatus);
	setLeftFrontDoor(data.leftFrontDoor);
	setRightFrontDoor(data.rightFrontDoor);
	setLeftRearDoor(data.leftRearDoor);
	setRightRearDoor(data.rightRearDoor);
	setHoodDoor(data.hoodDoor);
	setTrunkDoor(data.trunkDoor);
	setOdo(data.odo);
	setAverageSpeed(data.averageSpeed);
	setRemainMileage(data.remainMileage);
	setTrip1(data.trip1);
	setTrip2(data.trip2);
	setAverageFuelUint(data.averageFuelUint);
	setInstantaneousFuelUint(data.instantaneousFuelUint);
	setAverageFuel(data.averageFuel);
	setInstantaneousFuel(data.instantaneousFuel);
	setFuel(data.fuel);
	setSoc(data.soc);
	setMaintenanceMileage(data.maintenanceMileage);
	setOutTemprature(data.outTemprature);
	setBatteryCurrent(data.batteryCurrent);
	setBatteryVoltage(data.batteryVoltage);

	if (m_tripCleanFlag) {
		if (data.trip1 <= 1) {
			m_tripCleanFlag = false;
			m_tripClean = false;
		}
	}
}

void HqCarStatus::getSpecialSerial(SpecialInfo data)
{
	if(!m_active)
		return;

	// SpecialInfo
	setBrakeSysErr(data.brakeSysErr);
	setPowerSteerErr(data.powerSteerErr);
	setFLTirePressLeak(data.fLTirePressLeak);
	setFRTirePressLeak(data.fRTirePressLeak);
	setRLTirePressLeak(data.rLTirePressLeak);
	setRRTirePressLeak(data.rRTirePressLeak);
	setFLTirePressMoreInfo(data.fLTirePressMoreInfo);
	setFRTirePressMoreInfo(data.fRTirePressMoreInfo);
	setRLTirePressMoreInfo(data.rLTirePressMoreInfo);
	setRRTirePressMoreInfo(data.rRTirePressMoreInfo);
	setEngineControlErr(data.engineControlErr);
	setGearboxToohot(data.gearboxToohot);
	setGearboxErr(data.gearboxErr);
	setAccAutoOff(data.accAutoOff);
	setAbaErr(data.abaErr);
	setFcwErr(data.fcwErr);
	setAbsErr(data.absErr);
	setHydraulicSysErr(data.hydraulicSysErr);
	setEspErr(data.espErr);
	setTcsErr(data.tcsErr);
	setCoolSysErr(data.coolSysErr);
	setFluidToolow(data.fluidToolow);
	setEngineOilErr(data.engineOilErr);
	setEpbErr(data.epbErr);
	setAutoHoldErr(data.autoHoldErr);
	setAccErr(data.accErr);
	setPdcErr(data.pdcErr);
	setCheckAlternator(data.checkAlternator);
	setChangeBrakePads(data.changeBrakePads);
	setOverSpeedLimit(data.overSpeedLimit);
	setFLTirePressInfo(data.fLTirePressInfo);
	setFRTirePressInfo(data.fRTirePressInfo);
	setRLTirePressInfo(data.rLTirePressInfo);
	setRRTirePressInfo(data.rRTirePressInfo);
	setAirbagErr(data.airbagErr);
	setRefrigerantLow(data.refrigerantLow);
	setAccActiveErr(data.accActiveErr);
	setSetCruise(data.setCruise);
	setLdwErr(data.ldwErr);
	setEmissionSysErr(data.emissionSysErr);
	setPassiveEntrySysErr(data.passiveEntrySysErr);
	setFLTirePressMonitorErr(data.fLTirePressMonitorErr);
	setFRTirePressMonitorErr(data.fRTirePressMonitorErr);
	setRLTirePressMonitorErr(data.rLTirePressMonitorErr);
	setRRTirePressMonitorErr(data.rRTirePressMonitorErr);
	setLFTurnLightErr(data.lFTurnLightErr);
	setRFTurnLightErr(data.rFTurnLightErr);
	setLRTurnLightErr(data.lRTurnLightErr);
	setRRTurnLightErr(data.rRTurnLightErr);
	setLRGroupLightErr(data.lRGroupLightErr);
	setRRGroupLightErr(data.rRGroupLightErr);
	setBackupLightErr(data.backupLightErr);
	setNightVisionErr(data.nightVisionErr);
	setAfsErr(data.afsErr);
	setStartAndStopSysErr(data.startAndStopSysErr);
	setHeadlampAdjustErr(data.headlampAdjustErr);
	setRefillFuel(data.refillFuel);
	setAutoLightsWiperErr(data.autoLightsWiperErr);
	setCameraBlocked(data.cameraBlocked);
	setRaderBlockHotErr(data.raderBlockHotErr);
	setLFLightErr(data.lFLightErr);
	setRFLightErr(data.rFLightErr);
	setLFPositionLightErr(data.lFPositionLightErr);
	setRFPositionLightErr(data.rFPositionLightErr);
	setLFFogLightErr(data.lFFogLightErr);
	setRFFogLightErr(data.rFFogLightErr);
	setLicenseLightErr(data.licenseLightErr);
	setIgnitionSwitchErr(data.ignitionSwitchErr);
	setUnknownKey(data.unknownKey);
	setFourWDSysErr(data.fourWDSysErr);
	setScmSysErr(data.scmSysErr);
	setAccClose(data.accClose);
	setKeyBatLow(data.keyBatLow);
	setRefillCleanFluid(data.refillCleanFluid);
	setSeatAdjustErr(data.seatAdjustErr);
	setXkmBeforeMaintenance(data.xkmBeforeMaintenance);
	setBluetoothMicrophoneErr(data.bluetoothMicrophoneErr);
	setBluetoothSwitchErr(data.bluetoothSwitchErr);
	setBluetoothAudioLineErr(data.bluetoothAudioLineErr);
	setSteeringColumnLockErr(data.steeringColumnLockErr);
	setInstrumentClusterErr(data.instrumentClusterErr);
	setLdwClose(data.ldwClose);
	setAfsClose(data.afsClose);
	setEspClose(data.espClose);
	setAbaActiveErr(data.abaActiveErr);
	setFcwCloseErr(data.fcwCloseErr);
	setAbaCloseErr(data.abaCloseErr);
	setAbaIndicator(data.abaIndicator);
	setAvh(data.avh);
	setStopAndGoIndicator(data.stopAndGoIndicator);
	setParkingCarUi(data.parkingCarUi);
	setRearRightRadarFlicker(data.rearRightRadarFlicker);
	setRearCentreRRadarFlicker(data.rearCentreRRadarFlicker);
	setRearCentreLRadarFlicker(data.rearCentreLRadarFlicker);
	setRearLeftRadarFlicker(data.rearLeftRadarFlicker);
	setFrontRightRadarFlicker(data.frontRightRadarFlicker);
	setFrontCentreRRadarFlicker(data.frontCentreRRadarFlicker);
	setFrontCentreLRadarFlicker(data.frontCentreLRadarFlicker);
	setFrontLeftRadarFlicker(data.frontLeftRadarFlicker);
	setFrontLeftRadarLevel(data.frontLeftRadarLevel);
	setFrontCentreLRadarLevel(data.frontCentreLRadarLevel);
	setFrontCentreRRadarLevel(data.frontCentreRRadarLevel);
	setFrontRightRadarLevel(data.frontRightRadarLevel);
	setRearRightRadarLevel(data.rearRightRadarLevel);
	setRearCentreRRadarLevel(data.rearCentreRRadarLevel);
	setRearCentreLRadarLevel(data.rearCentreLRadarLevel);
	setRearLeftRadarLevel(data.rearLeftRadarLevel);
	setFcwNotice(data.fcwNotice);
	setFcwMoreNotice(data.fcwMoreNotice);
	setLkpMoreRest(data.lkpMoreRest);
	setLkpRest(data.lkpRest);
	setShift2P(data.shift2P);
	setSlopeTooHigh(data.slopeTooHigh);
	setBrakingPowerLow(data.brakingPowerLow);
	setKeyInCar(data.keyInCar);
	setKeyInTrunk(data.keyInTrunk);
	setKeyStatus2Off(data.keyStatus2Off);
	setSteerColumnLock(data.steerColumnLock);
	setBatLowStartEngine(data.batLowStartEngine);
	setStartEngineSelf(data.startEngineSelf);
	setShift2PN(data.shift2PN);
	setLPress2Start24s(data.lPress2Start24s);
	setLampON(data.lampON);
	setAccUI(data.accUI);
	setAccIndicator(data.accIndicator);
	setAccFlicker(data.accFlicker);
	setFrontCarDistanceLevel(data.frontCarDistanceLevel);
	setFrontCarFlicker(data.frontCarFlicker);
	setFrontCarSpeed(data.frontCarSpeed);
	setAccRecovery(data.accRecovery);
	setFrontCarStatus(data.frontCarStatus);
	setCcsSet(data.ccsSet);
	setCcsIndicator(data.ccsIndicator);
	setCcsSpeed(data.ccsSpeed);
	setLdwOn(data.ldwOn);
	setLdwIndicator(data.ldwIndicator);
	setLdwFlicker(data.ldwFlicker);
	setLdwLeftIndicator(data.ldwLeftIndicator);
	setLdwRightIndicator(data.ldwRightIndicator);
	setBluetoothStatus(data.bluetoothStatus);
	setBatValue(data.batValue);
	setMobileSingel(data.mobileSingel);
	setHighBeamLight(data.highBeamLight);
	setPositionLight(data.positionLight);
	setFrontFogLight(data.frontFogLight);
	setRearFogLight(data.rearFogLight);
	setEngineOilLight(data.engineOilLight);
	setNightVisionLight(data.nightVisionLight);
	setSysBattErr(data.sysBattErr);
	setMainErr(data.mainErr);
	setEspLightFlick(data.espLightFlick);
	setFLTirePress(data.fLTirePress);
	setFRTirePress(data.fRTirePress);
	setRLTirePress(data.rLTirePress);
	setRRTirePress(data.rRTirePress);
	setFLTireTemp(data.fLTireTemp);
	setFRTireTemp(data.fRTireTemp);
	setRLTireTemp(data.rLTireTemp);
	setRRTireTemp(data.rRTireTemp);
	setFm(data.fm);
	setAm(data.am);
	setProgramNum(data.programNum);
	setSoundMode(data.soundMode);
}

void HqCarStatus::getMobileSerial(MobileInfo data)
{
	if(!m_active)
		return;

	setNameLen(data.nameLen);
	setName(QString::fromUtf8((const char*)data.name));
	setNumTypes(data.numTypes);
	setNumLen(data.numLen);
	setNumber(QString::fromUtf8((const char*)data.number));
}

void HqCarStatus::setActive(bool v)
{
	if (m_active == v)
		return;

	m_active = v;

	if( m_active ) {
		m_serial->openSerial();
#ifdef TIMER_FREQ
		this->startTimer(SETTINGSFTRAME_FREQ);
		m_commandReq = true;
#endif
		connect(m_serial, SIGNAL(generalInfoChanged(GeneralInfo)), this, SLOT(getGeneralSerial(GeneralInfo)));
		connect(m_serial, SIGNAL(specialInfoChanged(SpecialInfo)), this, SLOT(getSpecialSerial(SpecialInfo)));
		connect(m_serial, SIGNAL(mobileInfoChanged(MobileInfo)), this, SLOT(getMobileSerial(MobileInfo)));
	} else {
		disconnect(m_serial, SIGNAL(generalInfoChanged(GeneralInfo)), this, SLOT(getGeneralSerial(GeneralInfo)));
		disconnect(m_serial, SIGNAL(specialInfoChanged(SpecialInfo)), this, SLOT(getSpecialSerial(SpecialInfo)));
		disconnect(m_serial, SIGNAL(mobileInfoChanged(MobileInfo)), this, SLOT(getMobileSerial(MobileInfo)));
	}
}

// MobileInfo
void HqCarStatus::setNameLen(uint v)
{
	if (m_nameLen == v)
		return;

	m_nameLen = v;
	emit nameLenChanged(v);
}
void HqCarStatus::setName(QString v)
{
	if (m_name == v)
		return;

	m_name = v;
	emit nameChanged(v);
}
void HqCarStatus::setNumTypes(uint v)
{
	if (m_numTypes == v)
		return;

	m_numTypes = v;
	emit numTypesChanged(v);
}
void HqCarStatus::setNumLen(uint v)
{
	if (m_numLen == v)
		return;

	m_numLen = v;
	emit numLenChanged(v);
}
void HqCarStatus::setNumber(QString v)
{
	if (m_number == v)
		return;

	m_number = v;
	emit numberChanged(v);
}
// SettingsInfo
void HqCarStatus::setCommandReq(bool v)
{
	if (m_commandReq == v)
		return;

	m_commandReq = v;
	emit commandReqChanged(v);
}
void HqCarStatus::setCloseReq(bool v)
{
	if (m_closeReq == v)
		return;

	m_closeReq = v;
	emit closeReqChanged(v);
}
void HqCarStatus::setTripClean(bool v)
{
	m_tripClean = v;

	if (m_tripClean) {
		m_tripCleanFlag = true;
	}
}
void HqCarStatus::setAverageSpeedClean(bool v)
{
	if (m_averageSpeedClean == v)
		return;

	m_averageSpeedClean = v;
	emit averageSpeedCleanChanged(v);
}
void HqCarStatus::setAverageFuelClean(bool v)
{
	if (m_averageFuelClean == v)
		return;

	m_averageFuelClean = v;
	emit averageFuelCleanChanged(v);
}
void HqCarStatus::setEngineerMode(bool v)
{
	if (m_engineerMode == v)
		return;

	m_engineerMode = v;
	emit engineerModeChanged(v);
}
void HqCarStatus::setDateTime(uint v)
{
	if (m_dateTime == v)
		return;

	m_dateTime = v;
	emit dateTimeChanged(v);
}

// SpecialInfo
void HqCarStatus::setBrakeSysErr(bool v)
{
	if (m_brakeSysErr == v)
		return;

	m_brakeSysErr = v;
	dealErrList(v, BRAKESYS_ERR);
	emit brakeSysErrChanged(v);
}
void HqCarStatus::setPowerSteerErr(bool v)
{
	if (m_powerSteerErr == v)
		return;

	m_powerSteerErr = v;
	dealErrList(v, POWER_STEER_ERR);
	emit powerSteerErrChanged(v);
}
void HqCarStatus::setFLTirePressLeak(bool v)
{
	if (m_fLTirePressLeak == v)
		return;
	m_fLTirePressLeak = v;

	dealErrList(m_fLTirePressLeak || m_fRTirePressLeak || m_rLTirePressLeak || m_rRTirePressLeak, TIREPRESSURE_LEAK_ERR);
	emit fLTirePressLeakChanged(v);
}
void HqCarStatus::setFRTirePressLeak(bool v)
{
	if (m_fRTirePressLeak == v)
		return;
	m_fRTirePressLeak = v;

	dealErrList(m_fLTirePressLeak || m_fRTirePressLeak || m_rLTirePressLeak || m_rRTirePressLeak, TIREPRESSURE_LEAK_ERR);
	emit fRTirePressLeakChanged(v);
}
void HqCarStatus::setRLTirePressLeak(bool v)
{
	if (m_rLTirePressLeak == v)
		return;
	m_rLTirePressLeak = v;

	dealErrList(m_fLTirePressLeak || m_fRTirePressLeak || m_rLTirePressLeak || m_rRTirePressLeak, TIREPRESSURE_LEAK_ERR);
	emit rLTirePressLeakChanged(v);
}
void HqCarStatus::setRRTirePressLeak(bool v)
{
	if (m_rRTirePressLeak == v)
		return;
	m_rRTirePressLeak = v;

	dealErrList(m_fLTirePressLeak || m_fRTirePressLeak || m_rLTirePressLeak || m_rRTirePressLeak, TIREPRESSURE_LEAK_ERR);
	emit rRTirePressLeakChanged(v);
}
void HqCarStatus::setFLTirePressMoreInfo(bool v)
{
	if (m_fLTirePressMoreInfo == v)
		return;
	m_fLTirePressMoreInfo = v;

	dealErrList(m_fLTirePressMoreInfo || m_fRTirePressMoreInfo || m_rLTirePressMoreInfo || m_rRTirePressMoreInfo, CHECK_TIREP_MORE_ERR);
	emit fLTirePressMoreInfoChanged(v);
}
void HqCarStatus::setFRTirePressMoreInfo(bool v)
{
	if (m_fRTirePressMoreInfo == v)
		return;
	m_fRTirePressMoreInfo = v;

	dealErrList(m_fLTirePressMoreInfo || m_fRTirePressMoreInfo || m_rLTirePressMoreInfo || m_rRTirePressMoreInfo, CHECK_TIREP_MORE_ERR);
	emit fRTirePressMoreInfoChanged(v);
}
void HqCarStatus::setRLTirePressMoreInfo(bool v)
{
	if (m_rLTirePressMoreInfo == v)
		return;
	m_rLTirePressMoreInfo = v;

	dealErrList(m_fLTirePressMoreInfo || m_fRTirePressMoreInfo || m_rLTirePressMoreInfo || m_rRTirePressMoreInfo, CHECK_TIREP_MORE_ERR);
	emit rLTirePressMoreInfoChanged(v);
}
void HqCarStatus::setRRTirePressMoreInfo(bool v)
{
	if (m_rRTirePressMoreInfo == v)
		return;
	m_rRTirePressMoreInfo = v;

	dealErrList(m_fLTirePressMoreInfo || m_fRTirePressMoreInfo || m_rLTirePressMoreInfo || m_rRTirePressMoreInfo, CHECK_TIREP_MORE_ERR);
	emit rRTirePressMoreInfoChanged(v);
}
void HqCarStatus::setEngineControlErr(bool v)
{
	if (m_engineControlErr == v)
		return;

	m_engineControlErr = v;

	dealErrList(v, ENGINE_CTRLSYS_ERR);
	emit engineControlErrChanged(v);
}
void HqCarStatus::setGearboxToohot(bool v)
{
	if (m_gearboxToohot == v)
		return;
	m_gearboxToohot = v;

	dealErrList(v, GEARBOX_HOT_ERR);
	emit gearboxToohotChanged(v);
}
void HqCarStatus::setGearboxErr(bool v)
{
	if (m_gearboxErr == v)
		return;

	m_gearboxErr = v;
	dealErrList(v, GEAR_ERR);
	emit gearboxErrChanged(v);
}

void HqCarStatus::setAccAutoOff(bool v)
{
	if (m_accAutoOff == v)
		return;

	m_accAutoOff = v;
	dealErrList(v, ACC_AUTO_OFF_ERR);
	emit accAutoOffChanged(v);
}
void HqCarStatus::setAbaErr(bool v)
{
	if (m_abaErr == v)
		return;

	m_abaErr = v;
	dealErrList(v, ABA_ERR);
	emit abaErrChanged(v);
}
void HqCarStatus::setFcwErr(bool v)
{
	if (m_fcwErr == v)
		return;

	m_fcwErr = v;
	dealErrList(v, FCW_ERR);
	emit fcwErrChanged(v);
}
void HqCarStatus::setAbsErr(bool v)
{
	if (m_absErr == v)
		return;

	m_absErr = v;
	dealErrList(v, ABS_ERR);
	emit absErrChanged(v);
}
void HqCarStatus::setHydraulicSysErr(bool v)
{
	if (m_hydraulicSysErr == v)
		return;

	m_hydraulicSysErr = v;
	dealErrList(v, HYDRAULICSYS_ERR);
	emit hydraulicSysErrChanged(v);
}
void HqCarStatus::setEspErr(bool v)
{
	if (m_espErr == v)
		return;

	m_espErr = v;
	dealErrList(v, ESP_ERR);
	emit espErrChanged(v);
}
void HqCarStatus::setTcsErr(bool v)
{
	if (m_tcsErr == v)
		return;

	m_tcsErr = v;
	dealErrList(v, TCS_ERR);
	emit tcsErrChanged(v);
}
void HqCarStatus::setCoolSysErr(bool v)
{
	if (m_coolSysErr == v)
		return;

	m_coolSysErr = v;
	dealErrList(v, COOLSYS_ERR);
	emit coolSysErrChanged(v);
}
void HqCarStatus::setFluidToolow(bool v)
{
	if (m_fluidToolow == v)
		return;

	m_fluidToolow = v;
	dealErrList(v, FLUID_LOW_ERR);
	emit fluidToolowChanged(v);
}
void HqCarStatus::setEngineOilErr(bool v)
{
	if (m_engineOilErr == v)
		return;

	m_engineOilErr = v;
	dealErrList(v, ENGINEOIL_LOW_ERR);
	emit engineOilErrChanged(v);
}
void HqCarStatus::setEpbErr(bool v)
{
	if (m_epbErr == v)
		return;

	m_epbErr = v;
	dealErrList(v, EPB_ERR);
	emit epbErrChanged(v);
}
void HqCarStatus::setAutoHoldErr(bool v)
{
	if (m_autoHoldErr == v)
		return;

	m_autoHoldErr = v;
	dealErrList(v, AUTO_HOLD_ERR);
	emit autoHoldErrChanged(v);
}
void HqCarStatus::setAccErr(bool v)
{
	if (m_accErr == v)
		return;

	m_accErr = v;
	dealErrList(v, ACC_ERR);
	emit accErrChanged(v);
}
void HqCarStatus::setPdcErr(bool v)
{
	if (m_pdcErr == v)
		return;

	m_pdcErr = v;
	dealErrList(v, PDC_ERR);
	emit pdcErrChanged(v);
}
void HqCarStatus::setCheckAlternator(bool v)
{
	if (m_checkAlternator == v)
		return;

	m_checkAlternator = v;
	dealErrList(v, CHECK_ALTERNATOR_ERR);
	emit checkAlternatorChanged(v);
}
void HqCarStatus::setChangeBrakePads(bool v)
{
	if (m_changeBrakePads == v)
		return;

	m_changeBrakePads = v;
	dealErrList(v, CHANGE_BRAKEPAD_ERR);
	emit changeBrakePadsChanged(v);
}
void HqCarStatus::setOverSpeedLimit(bool v)
{
	if (m_overSpeedLimit == v)
		return;

	m_overSpeedLimit = v;
	dealErrList(v, OVER_SPEED_ERR);
	emit overSpeedLimitChanged(v);
}
void HqCarStatus::setFLTirePressInfo(bool v)
{
	if (m_fLTirePressInfo == v)
		return;
	m_fLTirePressInfo = v;
	dealErrList(m_fLTirePressInfo || m_fRTirePressInfo || m_rLTirePressInfo || m_rRTirePressInfo, CHECK_TIREP_ERR);
	emit fLTirePressInfoChanged(v);
}
void HqCarStatus::setFRTirePressInfo(bool v)
{
	if (m_fRTirePressInfo == v)
		return;
	m_fRTirePressInfo = v;
	dealErrList(m_fLTirePressInfo || m_fRTirePressInfo || m_rLTirePressInfo || m_rRTirePressInfo, CHECK_TIREP_ERR);

	emit fRTirePressInfoChanged(v);
}
void HqCarStatus::setRLTirePressInfo(bool v)
{
	if (m_rLTirePressInfo == v)
		return;
	m_rLTirePressInfo = v;
	dealErrList(m_fLTirePressInfo || m_fRTirePressInfo || m_rLTirePressInfo || m_rRTirePressInfo, CHECK_TIREP_ERR);

	emit rLTirePressInfoChanged(v);
}
void HqCarStatus::setRRTirePressInfo(bool v)
{
	if (m_rRTirePressInfo == v)
		return;
	m_rRTirePressInfo = v;
	dealErrList(m_fLTirePressInfo || m_fRTirePressInfo || m_rLTirePressInfo || m_rRTirePressInfo, CHECK_TIREP_ERR);

	emit rRTirePressInfoChanged(v);
}
void HqCarStatus::setAirbagErr(bool v)
{
	if (m_airbagErr == v)
		return;

	m_airbagErr = v;
	dealErrList(v, AIRBAG_ERR);
	emit airbagErrChanged(v);
}
void HqCarStatus::setRefrigerantLow(bool v)
{
	if (m_refrigerantLow == v)
		return;

	m_refrigerantLow = v;
	dealErrList(v, REFRIGERANT_LOW_ERR);
	emit refrigerantLowChanged(v);
}
void HqCarStatus::setAccActiveErr(bool v)
{
	if (m_accActiveErr == v)
		return;

	m_accActiveErr = v;
	dealErrList(v, ACC_ACTIVE_ERR);
	emit accActiveErrChanged(v);
}
void HqCarStatus::setSetCruise(bool v)
{
	if (m_setCruise == v)
		return;

	m_setCruise = v;
	dealErrList(v, SET_CCS_ERR);
	emit setCruiseChanged(v);
}
void HqCarStatus::setLdwErr(bool v)
{
	if (m_ldwErr == v)
		return;

	m_ldwErr = v;
	dealErrList(v, LDW_ERR);
	emit ldwErrChanged(v);
}
void HqCarStatus::setEmissionSysErr(bool v)
{
	if (m_emissionSysErr == v)
		return;

	m_emissionSysErr = v;
	dealErrList(v, EMISSIONSYS_ERR);
	emit emissionSysErrChanged(v);
}
void HqCarStatus::setPassiveEntrySysErr(bool v)
{
	if (m_passiveEntrySysErr == v)
		return;

	m_passiveEntrySysErr = v;
	dealErrList(v, PASSIVEENTRYSYS_ERR);
	emit passiveEntrySysErrChanged(v);
}
void HqCarStatus::setFLTirePressMonitorErr(bool v)
{
	if (m_fLTirePressMonitorErr == v)
		return;
	m_fLTirePressMonitorErr = v;

	dealErrList(m_fLTirePressMonitorErr || m_fRTirePressMonitorErr || m_rLTirePressMonitorErr || m_rRTirePressMonitorErr, TIREP_MONITOR_ERR);
	emit fLTirePressMonitorErrChanged(v);
}


void HqCarStatus::setFRTirePressMonitorErr(bool v)
{
	if (m_fRTirePressMonitorErr == v)
		return;
	m_fRTirePressMonitorErr = v;

	dealErrList(m_fLTirePressMonitorErr || m_fRTirePressMonitorErr || m_rLTirePressMonitorErr || m_rRTirePressMonitorErr, TIREP_MONITOR_ERR);

	emit fRTirePressMonitorErrChanged(v);
}


void HqCarStatus::setRLTirePressMonitorErr(bool v)
{
	if (m_rLTirePressMonitorErr == v)
		return;
	m_rLTirePressMonitorErr = v;

	dealErrList(m_fLTirePressMonitorErr || m_fRTirePressMonitorErr || m_rLTirePressMonitorErr || m_rRTirePressMonitorErr, TIREP_MONITOR_ERR);

	emit rLTirePressMonitorErrChanged(v);
}


void HqCarStatus::setRRTirePressMonitorErr(bool v)
{
	if (m_rRTirePressMonitorErr == v)
		return;
	m_rRTirePressMonitorErr = v;

	dealErrList(m_fLTirePressMonitorErr || m_fRTirePressMonitorErr || m_rLTirePressMonitorErr || m_rRTirePressMonitorErr, TIREP_MONITOR_ERR);

	emit rRTirePressMonitorErrChanged(v);
}
void HqCarStatus::setLFTurnLightErr(bool v)
{
	if (m_lFTurnLightErr == v)
		return;

	m_lFTurnLightErr = v;
	dealErrList(v, LFTURNLIGHT_ERR);
	emit lFTurnLightErrChanged(v);
}
void HqCarStatus::setRFTurnLightErr(bool v)
{
	if (m_rFTurnLightErr == v)
		return;

	m_rFTurnLightErr = v;
	dealErrList(v, RFTURNLIGHT_ERR);
	emit rFTurnLightErrChanged(v);
}
void HqCarStatus::setLRTurnLightErr(bool v)
{
	if (m_lRTurnLightErr == v)
		return;

	m_lRTurnLightErr = v;
	dealErrList(v, LRTURNLIGHT_ERR);
	emit lRTurnLightErrChanged(v);
}
void HqCarStatus::setRRTurnLightErr(bool v)
{
	if (m_rRTurnLightErr == v)
		return;

	m_rRTurnLightErr = v;
	dealErrList(v, RRTURNLIGHT_ERR);
	emit rRTurnLightErrChanged(v);
}
void HqCarStatus::setLRGroupLightErr(bool v)
{
	if (m_lRGroupLightErr == v)
		return;

	m_lRGroupLightErr = v;
	dealErrList(v, LRGROUPLIGHT_ERR);
	emit lRGroupLightErrChanged(v);
}
void HqCarStatus::setRRGroupLightErr(bool v)
{
	if (m_rRGroupLightErr == v)
		return;

	m_rRGroupLightErr = v;
	dealErrList(v, RRGROUPLIGHT_ERR);
	emit rRGroupLightErrChanged(v);
}
void HqCarStatus::setBackupLightErr(bool v)
{
	if (m_backupLightErr == v)
		return;

	m_backupLightErr = v;
	dealErrList(v, BACKUPLIGHT_ERR);
	emit backupLightErrChanged(v);
}
void HqCarStatus::setNightVisionErr(bool v)
{
	if (m_nightVisionErr == v)
		return;

	m_nightVisionErr = v;
	dealErrList(v, NIGHT_VIEW_ERR);
	emit nightVisionErrChanged(v);
}
void HqCarStatus::setAfsErr(bool v)
{
	if (m_afsErr == v)
		return;

	m_afsErr = v;
	dealErrList(v, AFS_ERR);
	emit afsErrChanged(v);
}
void HqCarStatus::setStartAndStopSysErr(bool v)
{
	if (m_startAndStopSysErr == v)
		return;

	m_startAndStopSysErr = v;
	dealErrList(v, STARTANDSTOPSYS_ERR);
	emit startAndStopSysErrChanged(v);
}
void HqCarStatus::setHeadlampAdjustErr(bool v)
{
	if (m_headlampAdjustErr == v)
		return;

	m_headlampAdjustErr = v;
	dealErrList(v, HEADLAMP_ADJUST_ERR);
	emit headlampAdjustErrChanged(v);
}
void HqCarStatus::setRefillFuel(bool v)
{
	if (m_refillFuel == v)
		return;

	m_refillFuel = v;
	dealErrList(v, REFILL_FUEL_ERR);
	emit refillFuelChanged(v);
}
void HqCarStatus::setAutoLightsWiperErr(bool v)
{
	if (m_autoLightsWiperErr == v)
		return;

	m_autoLightsWiperErr = v;
	dealErrList(v, AUTOLIGHTWIPER_ERR);
	emit autoLightsWiperErrChanged(v);
}
void HqCarStatus::setCameraBlocked(bool v)
{
	if (m_cameraBlocked == v)
		return;

	m_cameraBlocked = v;
	dealErrList(v, CAMERABLOCKED_ERR);
	emit cameraBlockedChanged(v);
}
void HqCarStatus::setRaderBlockHotErr(bool v)
{
	if (m_raderBlockHotErr == v)
		return;

	m_raderBlockHotErr = v;
	dealErrList(v, RADERBLOCK_HOT_ERR);
	emit raderBlockHotErrChanged(v);
}
void HqCarStatus::setLFLightErr(bool v)
{
	if (m_lFLightErr == v)
		return;

	m_lFLightErr = v;
	dealErrList(v, LFLIGHT_ERR);
	emit lFLightErrChanged(v);
}
void HqCarStatus::setRFLightErr(bool v)
{
	if (m_rFLightErr == v)
		return;

	m_rFLightErr = v;
	dealErrList(v, RFLIGHT_ERR);
	emit rFLightErrChanged(v);
}
void HqCarStatus::setLFPositionLightErr(bool v)
{
	if (m_lFPositionLightErr == v)
		return;

	m_lFPositionLightErr = v;
	dealErrList(v, LFPOSITIONLIGHT_ERR);
	emit lFPositionLightErrChanged(v);
}
void HqCarStatus::setRFPositionLightErr(bool v)
{
	if (m_rFPositionLightErr == v)
		return;

	m_rFPositionLightErr = v;
	dealErrList(v, RFPOSITIONLIGHT_ERR);
	emit rFPositionLightErrChanged(v);
}
void HqCarStatus::setLFFogLightErr(bool v)
{
	if (m_lFFogLightErr == v)
		return;

	m_lFFogLightErr = v;
	dealErrList(v, LFFOGLIGHT_ERR);
	emit lFFogLightErrChanged(v);
}

void HqCarStatus::setRFFogLightErr(bool v)
{
	if (m_rFFogLightErr == v)
		return;

	m_rFFogLightErr = v;
	dealErrList(v, RFFOGLIGHT_ERR);
	emit rFFogLightErrChanged(v);
}
void HqCarStatus::setLicenseLightErr(bool v)
{
	if (m_licenseLightErr == v)
		return;

	m_licenseLightErr = v;
	dealErrList(v, LICENSELIGHT_ERR);
	emit licenseLightErrChanged(v);
}
void HqCarStatus::setIgnitionSwitchErr(bool v)
{
	if (m_ignitionSwitchErr == v)
		return;

	m_ignitionSwitchErr = v;
	dealErrList(v, IGNITIONSWITCH_ERR);
	emit ignitionSwitchErrChanged(v);
}
void HqCarStatus::setUnknownKey(bool v)
{
	if (m_unknownKey == v)
		return;

	m_unknownKey = v;
	dealErrList(v, UNKNOWNKEY_ERR);
	emit unknownKeyChanged(v);
}
void HqCarStatus::setFourWDSysErr(bool v)
{
	if (m_fourWDSysErr == v)
		return;

	m_fourWDSysErr = v;
	dealErrList(v, FOURWDSYS_ERR);
	emit fourWDSysErrChanged(v);
}
void HqCarStatus::setScmSysErr(bool v)
{
	if (m_scmSysErr == v)
		return;

	m_scmSysErr = v;
	dealErrList(v, SCMSYS_ERR);
	emit scmSysErrChanged(v);
}
void HqCarStatus::setAccClose(bool v)
{
	if (m_accClose == v)
		return;

	m_accClose = v;
	dealErrList(v, ACC_CLOSE_ERR);
	emit accCloseChanged(v);
}
void HqCarStatus::setKeyBatLow(bool v)
{
	if (m_keyBatLow == v)
		return;

	m_keyBatLow = v;
	dealErrList(v, KEYBAT_LOW_ERR);
	emit keyBatLowChanged(v);
}
void HqCarStatus::setRefillCleanFluid(bool v)
{
	if (m_refillCleanFluid == v)
		return;

	m_refillCleanFluid = v;
	dealErrList(v, REFILLCLEANFLUID_ERR);
	emit refillCleanFluidChanged(v);
}
void HqCarStatus::setSeatAdjustErr(bool v)
{
	if (m_seatAdjustErr == v)
		return;

	m_seatAdjustErr = v;
	dealErrList(v, SEAT_ADJUST_ERR);
	emit seatAdjustErrChanged(v);
}
void HqCarStatus::setXkmBeforeMaintenance(bool v)
{
	if (m_xkmBeforeMaintenance == v)
		return;

	m_xkmBeforeMaintenance = v;
	dealErrList(v, XKMBEFOREMAINTENANCE);
	emit xkmBeforeMaintenanceChanged(v);
}
void HqCarStatus::setBluetoothMicrophoneErr(bool v)
{
	if (m_bluetoothMicrophoneErr == v)
		return;

	m_bluetoothMicrophoneErr = v;
	dealErrList(v, BLUETOOTHMIC_ERR);
	emit bluetoothMicrophoneErrChanged(v);
}
void HqCarStatus::setBluetoothSwitchErr(bool v)
{
	if (m_bluetoothSwitchErr == v)
		return;

	m_bluetoothSwitchErr = v;
	dealErrList(v, BLUETOOTHSWITCH_ERR);
	emit bluetoothSwitchErrChanged(v);
}
void HqCarStatus::setBluetoothAudioLineErr(bool v)
{
	if (m_bluetoothAudioLineErr == v)
		return;

	m_bluetoothAudioLineErr = v;
	dealErrList(v, BLUETOOTHAUDIOLINE_ERR);
	emit bluetoothAudioLineErrChanged(v);
}
void HqCarStatus::setSteeringColumnLockErr(bool v)
{
	if (m_steeringColumnLockErr == v)
		return;

	m_steeringColumnLockErr = v;
	dealErrList(v, STEERCOLUMNLOCK_ERR);
	emit steeringColumnLockErrChanged(v);
}
void HqCarStatus::setInstrumentClusterErr(bool v)
{
	if (m_instrumentClusterErr == v)
		return;

	m_instrumentClusterErr = v;
	dealErrList(v, INSTRUMENTCLUSTER_ERR);
	emit instrumentClusterErrChanged(v);
}
void HqCarStatus::setLdwClose(bool v)
{
	if (m_ldwClose == v)
		return;

	m_ldwClose = v;
	dealErrList(v, LDW_CLOSE_ERR);
	emit ldwCloseChanged(v);
}
void HqCarStatus::setAfsClose(bool v)
{
	if (m_afsClose == v)
		return;

	m_afsClose = v;
	dealErrList(v, AFS_CLOSE_ERR);
	emit afsCloseChanged(v);
}
void HqCarStatus::setEspClose(bool v)
{
	if (m_espClose == v)
		return;

	m_espClose = v;
	dealErrList(v, ESP_CLOSE_ERR);
	emit espCloseChanged(v);
}
void HqCarStatus::setAbaActiveErr(bool v)
{
	if (m_abaActiveErr == v)
		return;

	m_abaActiveErr = v;
	dealErrList(v, ABA_ACTIVE_ERR);
	emit abaActiveErrChanged(v);
}
void HqCarStatus::setFcwCloseErr(bool v)
{
	if (m_fcwCloseErr == v)
		return;

	m_fcwCloseErr = v;
	dealErrList(v, FCW_CLOSE_ERR);
	emit fcwCloseErrChanged(v);
}
void HqCarStatus::setAbaCloseErr(bool v)
{
	if (m_abaCloseErr == v)
		return;

	m_abaCloseErr = v;
	dealErrList(v, ABA_CLOSE_ERR);
	emit abaCloseErrChanged(v);
}
void HqCarStatus::setAbaIndicator(bool v)
{
	if (m_abaIndicator == v)
		return;

	m_abaIndicator = v;
	dealFunctionList(v, ABA_EVENT);
	emit abaIndicatorChanged(v);
}
void HqCarStatus::setAvh(bool v)
{
	if (m_avh == v)
		return;

	m_avh = v;
	emit avhChanged(v);
}

void HqCarStatus::setStopAndGoIndicator(uint v)
{
	if (m_stopAndGoIndicator == v)
		return;

	m_stopAndGoIndicator = v;
	emit stopAndGoIndicatorChanged(v);
}
void HqCarStatus::setParkingCarUi(bool v)
{
	if (m_parkingCarUi == v)
		return;

	m_parkingCarUi = v;
	dealFunctionList(v, PDC_EVENT);
	emit parkingCarUiChanged(v);
}

void HqCarStatus::setRearRightRadarFlicker(bool v)
{
	if (m_rearRightRadarFlicker == v)
		return;

	m_rearRightRadarFlicker = v;
	emit rearRightRadarFlickerChanged(v);
}
void HqCarStatus::setRearCentreRRadarFlicker(bool v)
{
	if (m_rearCentreRRadarFlicker == v)
		return;

	m_rearCentreRRadarFlicker = v;
	emit rearCentreRRadarFlickerChanged(v);
}
void HqCarStatus::setRearCentreLRadarFlicker(bool v)
{
	if (m_rearCentreLRadarFlicker == v)
		return;

	m_rearCentreLRadarFlicker = v;
	emit rearCentreLRadarFlickerChanged(v);
}
void HqCarStatus::setRearLeftRadarFlicker(bool v)
{
	if (m_rearLeftRadarFlicker == v)
		return;

	m_rearLeftRadarFlicker = v;
	emit rearLeftRadarFlickerChanged(v);
}
void HqCarStatus::setFrontRightRadarFlicker(bool v)
{
	if (m_frontRightRadarFlicker == v)
		return;

	m_frontRightRadarFlicker = v;
	emit frontRightRadarFlickerChanged(v);
}
void HqCarStatus::setFrontCentreRRadarFlicker(bool v)
{
	if (m_frontCentreRRadarFlicker == v)
		return;

	m_frontCentreRRadarFlicker = v;
	emit frontCentreRRadarFlickerChanged(v);
}
void HqCarStatus::setFrontCentreLRadarFlicker(bool v)
{
	if (m_frontCentreLRadarFlicker == v)
		return;

	m_frontCentreLRadarFlicker = v;
	emit frontCentreLRadarFlickerChanged(v);
}
void HqCarStatus::setFrontLeftRadarFlicker(bool v)
{
	if (m_frontLeftRadarFlicker == v)
		return;

	m_frontLeftRadarFlicker = v;
	emit frontLeftRadarFlickerChanged(v);
}
void HqCarStatus::setFrontLeftRadarLevel(uint v)
{
	if (m_frontLeftRadarLevel == v)
		return;

	m_frontLeftRadarLevel = v;
	emit frontLeftRadarLevelChanged(v);
}
void HqCarStatus::setFrontCentreLRadarLevel(uint v)
{
	if (m_frontCentreLRadarLevel == v)
		return;

	m_frontCentreLRadarLevel = v;
	emit frontCentreLRadarLevelChanged(v);
}
void HqCarStatus::setFrontCentreRRadarLevel(uint v)
{
	if (m_frontCentreRRadarLevel == v)
		return;

	m_frontCentreRRadarLevel = v;
	emit frontCentreRRadarLevelChanged(v);
}
void HqCarStatus::setFrontRightRadarLevel(uint v)
{
	if (m_frontRightRadarLevel == v)
		return;

	m_frontRightRadarLevel = v;
	emit frontRightRadarLevelChanged(v);
}
void HqCarStatus::setRearRightRadarLevel(uint v)
{
	if (m_rearRightRadarLevel == v)
		return;

	m_rearRightRadarLevel = v;
	emit rearRightRadarLevelChanged(v);
}
void HqCarStatus::setRearCentreRRadarLevel(uint v)
{
	if (m_rearCentreRRadarLevel == v)
		return;

	m_rearCentreRRadarLevel = v;
	emit rearCentreRRadarLevelChanged(v);
}
void HqCarStatus::setRearCentreLRadarLevel(uint v)
{
	if (m_rearCentreLRadarLevel == v)
		return;

	m_rearCentreLRadarLevel = v;
	emit rearCentreLRadarLevelChanged(v);
}
void HqCarStatus::setRearLeftRadarLevel(uint v)
{
	if (m_rearLeftRadarLevel == v)
		return;

	m_rearLeftRadarLevel = v;
	emit rearLeftRadarLevelChanged(v);
}
void HqCarStatus::setFcwNotice(bool v)
{
	if (m_fcwNotice == v)
		return;

	m_fcwNotice = v;
	dealFunctionList(v, FCW_EVENT);
	emit fcwNoticeChanged(v);
}
void HqCarStatus::setFcwMoreNotice(bool v)
{
	if (m_fcwMoreNotice == v)
		return;

	m_fcwMoreNotice = v;
	dealFunctionList(v, FCW_EVENT);
	emit fcwMoreNoticeChanged(v);
}
void HqCarStatus::setLkpMoreRest(bool v)
{
	if (m_lkpMoreRest == v)
		return;

	m_lkpMoreRest = v;
	dealFunctionList(v, LKPMORE_EVENT);
	emit lkpMoreRestChanged(v);
}
void HqCarStatus::setLkpRest(bool v)
{
	if (m_lkpRest == v)
		return;

	m_lkpRest = v;
	dealFunctionList(v, LKP_EVENT);
	emit lkpRestChanged(v);
}
void HqCarStatus::setShift2P(bool v)
{
	if (m_shift2P == v)
		return;

	m_shift2P = v;
	dealFunctionList(v, DRIVEINFO_SHIFT2P_EVENT);
	emit shift2PChanged(v);
}
void HqCarStatus::setSlopeTooHigh(bool v)
{
	if (m_slopeTooHigh == v)
		return;

	m_slopeTooHigh = v;
	dealFunctionList(v, DRIVEINFO_HIGHGRADIENT_EVENT);
	emit slopeTooHighChanged(v);
}
void HqCarStatus::setBrakingPowerLow(bool v)
{
	if (m_brakingPowerLow == v)
		return;

	m_brakingPowerLow = v;
	dealFunctionList(v, DRIVEINFO_BRAKINGPOWERLOW_EVENT);
	emit brakingPowerLowChanged(v);
}
void HqCarStatus::setKeyInCar(bool v)
{
	if (m_keyInCar == v)
		return;

	m_keyInCar = v;
	dealFunctionList(v, DRIVEINFO_KEYINCAR_EVENT);
	emit keyInCarChanged(v);
}
void HqCarStatus::setKeyInTrunk(bool v)
{
	if (m_keyInTrunk == v)
		return;

	m_keyInTrunk = v;
	dealFunctionList(v, DRIVEINFO_KEYINTRUNT_EVENT);
	emit keyInTrunkChanged(v);
}
void HqCarStatus::setKeyStatus2Off(bool v)
{
	if (m_keyStatus2Off == v)
		return;

	m_keyStatus2Off = v;
	dealFunctionList(v, DRIVEINFO_KEYSTATUS2OFF_EVENT);
	emit keyStatus2OffChanged(v);
}
void HqCarStatus::setSteerColumnLock(bool v)
{
	if (m_steerColumnLock == v)
		return;

	m_steerColumnLock = v;
	dealFunctionList(v, DRIVEINFO_STEERCOLUMNLOCK_EVENT);
	emit steerColumnLockChanged(v);
}
void HqCarStatus::setBatLowStartEngine(bool v)
{
	if (m_batLowStartEngine == v)
		return;

	m_batLowStartEngine = v;
	dealFunctionList(v, DRIVEINFO_BATLOWSTARTENGINE_EVENT);
	emit batLowStartEngineChanged(v);
}
void HqCarStatus::setStartEngineSelf(bool v)
{
	if (m_startEngineSelf == v)
		return;

	m_startEngineSelf = v;
	dealFunctionList(v, DRIVEINFO_STARTENGINESELF_EVENT);
	emit startEngineSelfChanged(v);
}
void HqCarStatus::setShift2PN(bool v)
{
	if (m_shift2PN == v)
		return;

	m_shift2PN = v;
	dealFunctionList(v, DRIVEINFO_SHIFT2PN_EVENT);
	emit shift2PNChanged(v);
}
void HqCarStatus::setLPress2Start24s(bool v)
{
	if (m_lPress2Start24s == v)
		return;

	m_lPress2Start24s = v;
	dealFunctionList(v, DRIVEINFO_LPRESS2START24S_EVENT);
	emit lPress2Start24sChanged(v);
}
void HqCarStatus::setLampON(bool v)
{
	if (m_lampON == v)
		return;

	m_lampON = v;
	dealFunctionList(v, DRIVEINFO_LAMPON_EVENT);
	emit lampONChanged(v);
}
void HqCarStatus::setAccUI(bool v)
{
	if (m_accUI == v)
		return;

	m_accUI = v;
	dealFunctionList(v, ACC_EVENT);
	emit accUIChanged(v);
}
void HqCarStatus::setAccIndicator(uint v)
{
	if (m_accIndicator == v)
		return;

	m_accIndicator = v;
	emit accIndicatorChanged(v);
}
void HqCarStatus::setAccFlicker(bool v)
{
	if (m_accFlicker == v)
		return;

	m_accFlicker = v;
	emit accFlickerChanged(v);
}
void HqCarStatus::setFrontCarDistanceLevel(uint v)
{
	if (m_frontCarDistanceLevel == v)
		return;

	m_frontCarDistanceLevel = v;
	emit frontCarDistanceLevelChanged(v);
}
void HqCarStatus::setFrontCarFlicker(bool v)
{
	if (m_frontCarFlicker == v)
		return;

	m_frontCarFlicker = v;
	emit frontCarFlickerChanged(v);
}
void HqCarStatus::setFrontCarSpeed(uint v)
{
	if (m_frontCarSpeed == v)
		return;

	m_frontCarSpeed = v;
	emit frontCarSpeedChanged(v);
}

void HqCarStatus::setAccRecovery(bool v)
{
	if (m_accRecovery == v)
		return;

	m_accRecovery = v;
	emit accRecoveryChanged(v);
}
void HqCarStatus::setFrontCarStatus(uint v)
{
	if (m_frontCarStatus == v)
		return;

	m_frontCarStatus = v;
	emit frontCarStatusChanged(v);
}

void HqCarStatus::setCcsSet(bool v)
{
	if (m_ccsSet == v)
		return;

	m_ccsSet = v;
	dealFunctionList(v, CCS_EVENT);
	emit ccsSetChanged(v);
}
void HqCarStatus::setCcsIndicator(uint v)
{
	if (m_ccsIndicator == v)
		return;

	m_ccsIndicator = v;
	emit ccsIndicatorChanged(v);
}
void HqCarStatus::setCcsSpeed(uint v)
{
	if (m_ccsSpeed == v)
		return;

	m_ccsSpeed = v;
	emit ccsSpeedChanged(v);
}
void HqCarStatus::setLdwOn(bool v)
{
	if (m_ldwOn == v)
		return;

	m_ldwOn = v;
	dealFunctionList(v, LDW_EVENT);
	emit ldwOnChanged(v);
}
void HqCarStatus::setLdwIndicator(uint v)
{
	if (m_ldwIndicator == v)
		return;

	m_ldwIndicator = v;
	emit ldwIndicatorChanged(v);
}
void HqCarStatus::setLdwFlicker(bool v)
{
	if (m_ldwFlicker == v)
		return;

	m_ldwFlicker = v;
	emit ldwFlickerChanged(v);
}
void HqCarStatus::setLdwLeftIndicator(uint v)
{
	if (m_ldwLeftIndicator == v)
		return;

	m_ldwLeftIndicator = v;
	emit ldwLeftIndicatorChanged(v);
}
void HqCarStatus::setLdwRightIndicator(uint v)
{
	if (m_ldwRightIndicator == v)
		return;

	m_ldwRightIndicator = v;
	emit ldwRightIndicatorChanged(v);
}
void HqCarStatus::setBluetoothStatus(uint v)
{
	if (m_bluetoothStatus == v)
		return;

	m_bluetoothStatus = v;
	emit bluetoothStatusChanged(v);
}
void HqCarStatus::setBatValue(uint v)
{
	if (m_batValue == v)
		return;

	m_batValue = v;
	emit batValueChanged(v);
}
void HqCarStatus::setMobileSingel(uint v)
{
	if (m_mobileSingel == v)
		return;

	m_mobileSingel = v;
	emit mobileSingelChanged(v);
}
void HqCarStatus::setHighBeamLight(bool v)
{
	if (m_highBeamLight == v)
		return;

	m_highBeamLight = v;
	emit highBeamLightChanged(v);
}
void HqCarStatus::setPositionLight(bool v)
{
	if (m_positionLight == v)
		return;

	m_positionLight = v;
	emit positionLightChanged(v);
}
void HqCarStatus::setFrontFogLight(bool v)
{
	if (m_frontFogLight == v)
		return;

	m_frontFogLight = v;
	emit frontFogLightChanged(v);
}
void HqCarStatus::setRearFogLight(bool v)
{
	if (m_rearFogLight == v)
		return;

	m_rearFogLight = v;
	emit rearFogLightChanged(v);
}
void HqCarStatus::setEngineOilLight(bool v)
{
	if (m_engineOilLight == v)
		return;

	m_engineOilLight = v;
	emit engineOilLightChanged(v);
}
void HqCarStatus::setNightVisionLight(bool v)
{
	if (m_nightVisionLight == v)
		return;

	m_nightVisionLight = v;
	emit nightVisionLightChanged(v);
}
void HqCarStatus::setSysBattErr(bool v)
{
	if (m_sysBattErr == v)
		return;

	m_sysBattErr = v;
	emit sysBattErrChanged(v);
}
void HqCarStatus::setMainErr(bool v)
{
	if (m_mainErr == v)
		return;

	m_mainErr = v;
	emit mainErrChanged(v);
}
void HqCarStatus::setEspLightFlick(bool v)
{
	if (m_espLightFlick == v)
		return;

	m_espLightFlick = v;
	emit espLightFlickChanged(v);
}
void HqCarStatus::setFLTirePress(uint v)
{
	if (m_fLTirePress == v)
		return;

	m_fLTirePress = v;
	emit fLTirePressChanged(v);
}
void HqCarStatus::setFRTirePress(uint v)
{
	if (m_fRTirePress == v)
		return;

	m_fRTirePress = v;
	emit fRTirePressChanged(v);
}
void HqCarStatus::setRLTirePress(uint v)
{
	if (m_rLTirePress == v)
		return;

	m_rLTirePress = v;
	emit rLTirePressChanged(v);
}
void HqCarStatus::setRRTirePress(uint v)
{
	if (m_rRTirePress == v)
		return;

	m_rRTirePress = v;
	emit rRTirePressChanged(v);
}
void HqCarStatus::setFLTireTemp(uint v)
{
	if (m_fLTireTemp == v)
		return;

	m_fLTireTemp = v;
	emit fLTireTempChanged(v);
}
void HqCarStatus::setFRTireTemp(uint v)
{
	if (m_fRTireTemp == v)
		return;

	m_fRTireTemp = v;
	emit fRTireTempChanged(v);
}
void HqCarStatus::setRLTireTemp(uint v)
{
	if (m_rLTireTemp == v)
		return;

	m_rLTireTemp = v;
	emit rLTireTempChanged(v);
}
void HqCarStatus::setRRTireTemp(uint v)
{
	if (m_rRTireTemp == v)
		return;

	m_rRTireTemp = v;
	emit rRTireTempChanged(v);
}
void HqCarStatus::setFm(uint v)
{
	if (m_fm == v)
		return;

	m_fm = v;
	emit fmChanged(v);
}
void HqCarStatus::setAm(uint v)
{
	if (m_am == v)
		return;

	m_am = v;
	emit amChanged(v);
}
void HqCarStatus::setProgramNum(uint v)
{
	if (m_programNum == v)
		return;

	m_programNum = v;
	emit programNumChanged(v);
}
void HqCarStatus::setSoundMode(uint v)
{
	if (m_soundMode == v)
		return;

	m_soundMode = v;
	emit soundModeChanged(v);
}

void HqCarStatus::insertList(QList<uint> *list, uint idn)
{
	int i = 0;
	for (; i < list->size(); i++) {
		if (list->at(i) == idn)
			return;

		if (list->at(i) > idn)
			break;
	}

	list->insert(i, idn);
}

void HqCarStatus::removeList(QList<uint> *list, uint idn)
{
	list->removeAll(idn);
	if (list->isEmpty())
		list->clear();
}

uint HqCarStatus::popList(QList<uint> *list)
{
	if (list->isEmpty())
		return 0;

	return list->takeFirst();
}

void HqCarStatus::dealErrList(bool isInsert, WARNING_TIPS errType)
{
	if(isInsert) {
		insertList(&m_preTipList, (uint)errType);
		if( errType == m_preTipList[0]
				&& ( m_functionTypes < ABA_EVENT || m_functionTypes >= ACC_EVENT)
				&& m_isTipedList == false) {
			m_functionTimer->stop();
			m_functionTypes = MIN_EVENT;
			emit functionTypesChanged(m_functionTypes);

			m_errType = (WARNING_TIPS)m_preTipList[0];
			emit errTypeChanged(m_errType);
			m_timer->start(5000);
		}
	} else {
		removeList(&m_preTipList, errType);
		removeList(&m_tipedList, errType);
	}
}

void HqCarStatus::dealFunctionList(bool isInsert, FUNCTION_EVENT functionType)
{
	if(isInsert) {
		insertList(&m_functionList, functionType);
		if( functionType == m_functionList[0] ) {
			if( (functionType >= ABA_EVENT && functionType <=  DRIVEINFO_LAMPON_EVENT) || m_preTipList.size() == 0 ) {
				m_timer->stop();
				m_errType = NULL_ERR;
				emit errTypeChanged(m_errType);

				m_functionTypes = (FUNCTION_EVENT)m_functionList[0];
				emit functionTypesChanged(m_functionTypes);
				m_functionTimer->start(5000);

				if( m_isTipedList == true ) {
					m_checkTimer->stop();
					m_isTipedList = false;
					m_checkIndex = 0;
				}
			}
		}
	} else {
		removeList(&m_functionList, functionType);
	}
}


#ifdef HONGQI_DEBUG
void HqCarStatus::sendUpFrame()
{
	setSerial();
}
#endif

void HqCarStatus::setSerial()
{
	SettingsFrame settingsFrame;
	memset(&settingsFrame, 0, sizeof(SettingsFrame));

	settingsFrame.head = 0xAA;
	settingsFrame.length = sizeof(SettingsInfo);

	settingsFrame.settingsInfo.commandReq = m_commandReq;
	settingsFrame.settingsInfo.closeReq = m_closeReq;
	settingsFrame.settingsInfo.tripClean = m_tripClean;
	settingsFrame.settingsInfo.averageSpeedClean = m_averageSpeedClean;
	settingsFrame.settingsInfo.averageFuelClean = m_averageFuelClean;
	settingsFrame.settingsInfo.engineerMode = m_engineerMode;
	settingsFrame.settingsInfo.dateTime = m_dateTime;
	settingsFrame.magic = MAGIC_SETTINGS;

	settingsFrame.crc = crc16Check((uint8_t *)(&(settingsFrame.magic)), MAGIC_LEN + sizeof(SettingsInfo));
	settingsFrame.tail = 0x55;
	m_serial->sendSerial(QByteArray((char *)&settingsFrame, sizeof(SettingsFrame)));
}

#ifdef TIMER_FREQ
void HqCarStatus::timerEvent(QTimerEvent *event)
{
	Q_UNUSED(event);
	setSerial();
}
#endif
