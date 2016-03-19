#include <QDebug>
#include <QDateTime>
#include <QTimerEvent>

#include <carnation_carstatus.h>

CarnationCarStatus::CarnationCarStatus(const QString &serialDev, QSerialPort *parent)
    : CarStatus(serialDev, parent)
{
    initValues();

    /* For middle Tips show */
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateERR()));

    m_checkTimer = new QTimer(this);
    connect(m_checkTimer, SIGNAL(timeout()), this, SLOT(dealCheckKey()));
}

void CarnationCarStatus::initValues()
{
    // SpecialInfo
    m_leftHandDrive = false;
    m_rightHandDrive = false;
    m_highBeam = false;
    m_dippedBeam = false;
    m_positionLight = false;
    m_frontFogLight = false;
    m_rearFogLight = false;
    m_auxiliaryHighBeam = false;

    m_safetyBeltLight = false;
    m_airBagLight = false;
    m_engineFaultLight = false;
    m_absFault = false;
    m_oilPressureLow = false;
    m_batteryFaultLight = false;
    m_brakeSystemFailure = false;
    m_parkingLight = false;

    m_oilLowLight = false;
    m_coolantLowLight = false;
	m_espLight = 0;
//    m_espOffLight = false;
    m_afsOffLight = false;
    m_milLight = false;
	m_gearboxErrLight =false;
	m_changeBrakePadsLight =false;
	m_electronicParkingLight =false;

    m_breakSystemPic = false;
    m_brakeFluidPic = false;
    m_addOilPic = false;
    m_batteryFaultPic = false;
    m_oilPressureLowPic = false;
    m_coolantSystemErrPic = false;
    m_absFaultPic = false;
    m_epbFaultPic = false;

    m_engineCtlFaultPic = false;
    m_exhaustEmissionPic = false;
    m_espFaultPic = false;
    m_airBagFaultPic = false;
    m_speedChangerErrPic = false;
    m_speedChaTempHighPic = false;
    m_coolantHighTempPic = false;
    m_tcsErrPic = false;
    m_changeBrakeFrontPic = false;
    m_changeBrakeRearPic = false;

    // Special SettingsInfo
    // TODO: nothing to do

    // Tips
    m_errType = NULL_ERR;
    m_warningTipSrc = "";

    warning_tip_str[NULL_ERR] = "";
    warning_tip_str[BREAK_SYS_PIC] = "qrc:/qml/qml/content/warning/BrakingMoreErr.qml";
    warning_tip_str[BREAK_FLUID_PIC] = "qrc:/qml/qml/content/warning/BrakingErr.qml";
    warning_tip_str[ADD_OIL_PIC] = "qrc:/qml/qml/content/warning/OilShortErr.qml";
    warning_tip_str[BATTERY_FAULT_PIC] = "qrc:/qml/qml/content/warning/ChargingSysErr.qml";
    warning_tip_str[OIL_PRESSURE_LOW_PIC] = "qrc:/qml/qml/content/warning/OilPreLowErr.qml";
    warning_tip_str[COLLANT_SYS_ERR_PIC] = "qrc:/qml/qml/content/warning/CoolErr.qml";
    warning_tip_str[ABS_FAULT_PIC] = "qrc:/qml/qml/content/warning/AbsErr.qml";
    warning_tip_str[EPB_FAULT_PIC] = "qrc:/qml/qml/content/warning/EpbErr.qml";
    warning_tip_str[ENGINE_CTL_FAULT_PIC] = "qrc:/qml/qml/content/warning/EngineErr.qml";
    warning_tip_str[EXHAUST_EMISSING_PIC] = "qrc:/qml/qml/content/warning/WasteGasMonitoringSysErr.qml";
    warning_tip_str[ESP_FAULT_PIC] = "qrc:/qml/qml/content/warning/EspErr.qml";
    warning_tip_str[AIRBAG_FAULT_PIC] = "qrc:/qml/qml/content/warning/SafeErr.qml";
    warning_tip_str[SPEED_CHANGER_ERR_PIC] = "qrc:/qml/qml/content/warning/GearErr.qml";
    warning_tip_str[SPEED_CHA_TEMP_HIGH_PIC] = "qrc:/qml/qml/content/warning/GearShiftTemHighErr.qml";
    warning_tip_str[COOLANT_HIGH_TEMP_PIC] = "qrc:/qml/qml/content/warning/CoolWaterErr.qml";
    warning_tip_str[TCS_ERR_PIC] = "qrc:/qml/qml/content/warning/TcsErr.qml";
	warning_tip_str[CHANGE_BRAKE_FRONT_PIC] = "qrc:/qml/qml/content/warning/ChangeBrakeFront.qml";
	warning_tip_str[CHANGE_BRAKE_REAR_PIC] = "qrc:/qml/qml/content/warning/ChangeBrakeRear.qml";
    warning_tip_str[MAX_WARNING_TIPS] = "";

    m_preTipList.clear();
    m_tipedList.clear();
    m_isTipedList = false;

    m_timer = NULL;
    m_checkTimer = NULL;
    m_checkIndex = 0;

    // button
    m_key1Step = 0;
    m_key1StepFlag = false;
    m_key2Step = 0;
    m_key2StepFlag = false;
    m_key3Step = 0;
    m_key3StepFlag = false;
    m_key4Step = 0;
    m_key4StepFlag = false;
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
        dealErrButtonShow(key1, data.key1);
        dealErrButtonShow(key2, data.key2);
        BoolValueChangeSet(key3, data.key3);
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
		NumValueErrChangeSet(avgSpeed, data.avgSpeed, (uint32_t) 0, (uint32_t) 240, 0xFF);
        BoolValueChangeSet(avgFuelUnit, data.avgFuelUnit);
        BoolValueChangeSet(instantaneousFuelUnit, data.instantaneousFuelUnit);
        NumValueErrChangeSet(remainMileage, data.remainMileage, (uint16_t) 0, (uint16_t) 999, 0xFFFF);
        NumValueErrChangeSet(trip1, data.trip1, (uint32_t) 0, (uint32_t) 9999, 0xFFFFFF);
        NumValueChangeSet(fuel, data.fuel, (uint32_t) 0, (uint32_t) 100);
        NumValueErrChangeSet(trip2, data.trip2, (uint32_t) 0, (uint32_t) 9999, 0xFFFFFF);
        NumValueChangeSet(soc, data.soc, (uint32_t) 0, (uint32_t) 100);
        NumValueChangeSet(maintenanceMileage, data.maintenanceMileage, (uint16_t) 0, (uint16_t) 50000);
        NumValueErrChangeSet(outTemp, data.outTemp, (uint16_t) 0, (uint16_t) 2045, 0xFFFF);
        NumValueErrChangeSet(avgFuel, data.avgFuel, (uint16_t)0, (uint16_t) 300, (uint16_t) 0xFFFF);
        NumValueErrChangeSet(instantaneousFuel, data.instantaneousFuel, (uint16_t) 0, (uint16_t) 450, 0xFFFF);
        qDebug() << "instantaneousFuel: " << m_instantaneousFuel;
        qDebug() << "outTemp: " << m_outTemp;
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
        BoolValueChangeSet(highBeam, data.highBeam);
        BoolValueChangeSet(dippedBeam, data.dippedBeam);
        BoolValueChangeSet(positionLight, data.positionLight);
        BoolValueChangeSet(frontFogLight, data.frontFogLight);
        BoolValueChangeSet(rearFogLight, data.rearFogLight);
        BoolValueChangeSet(auxiliaryHighBeam, data.auxiliaryHighBeam);

        BoolValueChangeSet(safetyBeltLight, data.safetyBeltLight);
        BoolValueChangeSet(airBagLight, data.airBagLight);
        BoolValueChangeSet(engineFaultLight, data.engineFaultLight);
        BoolValueChangeSet(absFault, data.absFault);
        BoolValueChangeSet(oilPressureLow, data.oilPressureLow);
        BoolValueChangeSet(batteryFaultLight, data.batteryFaultLight);
        BoolValueChangeSet(brakeSystemFailure, data.brakeSystemFailure);
        BoolValueChangeSet(parkingLight, data.parkingLight);

        BoolValueChangeSet(oilLowLight, data.oilLowLight);
        BoolValueChangeSet(coolantLowLight, data.coolantLowLight);
        BoolValueChangeSet(espLight, data.espLight);
		//BoolValueChangeSet(espOffLight, data.espOffLight);
		BoolValueChangeSet(afsOffLight, data.afsOffLight);
		BoolValueChangeSet(milLight, data.milLight);
		BoolValueChangeSet(gearboxErrLight, data.gearboxErrLight);
		BoolValueChangeSet(changeBrakePadsLight, data.changeBrakePadsLight);
		BoolValueChangeSet(electronicParkingLight, data.electronicParkingLight);

        dealErrShow(breakSystemPic, data.breakSystemPic, BREAK_SYS_PIC);
        dealErrShow(brakeFluidPic, data.brakeFluidPic, BREAK_FLUID_PIC);
        dealErrShow(addOilPic, data.addOilPic, ADD_OIL_PIC);
        dealErrShow(batteryFaultPic, data.batteryFaultPic, BATTERY_FAULT_PIC);
        dealErrShow(oilPressureLowPic, data.oilPressureLowPic, OIL_PRESSURE_LOW_PIC);
        dealErrShow(coolantSystemErrPic, data.coolantSystemErrPic, COLLANT_SYS_ERR_PIC);
        dealErrShow(absFaultPic, data.absFaultPic, ABS_FAULT_PIC);
        dealErrShow(epbFaultPic, data.epbFaultPic, EPB_FAULT_PIC);

        dealErrShow(engineCtlFaultPic, data.engineCtlFaultPic, ENGINE_CTL_FAULT_PIC);
        dealErrShow(exhaustEmissionPic, data.exhaustEmissionPic, EXHAUST_EMISSING_PIC);
        dealErrShow(espFaultPic, data.espFaultPic, ESP_FAULT_PIC);
        dealErrShow(airBagFaultPic, data.airBagFaultPic, AIRBAG_FAULT_PIC);
        dealErrShow(speedChangerErrPic, data.speedChangerErrPic, SPEED_CHANGER_ERR_PIC);
        dealErrShow(speedChaTempHighPic, data.speedChaTempHighPic, SPEED_CHA_TEMP_HIGH_PIC);
        dealErrShow(coolantHighTempPic, data.coolantHighTempPic, COOLANT_HIGH_TEMP_PIC);
        dealErrShow(tcsErrPic, data.tcsErrPic, TCS_ERR_PIC);
        dealErrShow(changeBrakeFrontPic, data.changeBrakeFrontPic, CHANGE_BRAKE_FRONT_PIC);
        dealErrShow(changeBrakeRearPic, data.changeBrakeRearPic, CHANGE_BRAKE_REAR_PIC);

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

/* For middle tips show */
void CarnationCarStatus::showCheckErr()  // deal key press
{
    if (m_errType == NULL_ERR || m_isTipedList == true) {
        if (m_tipedList.size() == 0)
        {
            return;
        }
        m_isTipedList = true;
        m_errType = (WARNING_TIPS)m_tipedList[m_checkIndex];
        m_warningTipSrc = warning_tip_str[m_errType];
        emit warningTipSrcChanged(m_warningTipSrc);
        // send m_errType to MCU, sync the interface and sound.
        // where there is a interface show, there is a sound.
        m_alarmInterface = m_errType;
        sendSettingsFrame();

        m_checkTimer->start(5000);
        ++m_checkIndex;
        if( m_checkIndex >= m_tipedList.size())
            m_checkIndex = 0;
    }
}

void CarnationCarStatus::dealCheckKey()     // for time out event
{
    m_checkTimer->stop();
    m_checkIndex = 0;
    m_isTipedList = false;
    m_errType = NULL_ERR;

    if(m_preTipList.size() > 0) {
        m_errType = (WARNING_TIPS)m_preTipList[0];
        m_warningTipSrc = warning_tip_str[m_errType];
        emit warningTipSrcChanged(m_warningTipSrc);
        // send m_errType to MCU, sync the interface and sound.
        // where there is a interface show, there is a sound.
        m_alarmInterface = m_errType;
        sendSettingsFrame();

        m_timer->start(5000);
        return;
    } else {
        // send m_errType to MCU, sync the interface and sound.
        // where there is a interface show, there is a sound.
        m_alarmInterface = m_errType;
        sendSettingsFrame();

        m_warningTipSrc = warning_tip_str[m_errType];
        emit warningTipSrcChanged(m_warningTipSrc);
    }
}

void CarnationCarStatus::updateERR()
{
#ifdef ANIMOTION_DEBUG
    if( m_errType >= MAX_WARNING_TIPS )
        m_errType = (WARNING_TIPS)(NULL_ERR + 1);
    else
        m_errType = (WARNING_TIPS)(m_errType + 1);
    m_warningTipSrc = warning_tip_str[m_errType];
    emit warningTipSrcChanged(m_warningTipSrc);
#else

    // pop list m_preTipList and insert list m_tipedList
    insertList(&m_tipedList, popList(&m_preTipList));

    if( m_preTipList.size() == 0 )
    {
        m_timer->stop();
        m_errType = NULL_ERR;
        // send m_errType to MCU, sync the interface and sound.
        // where there is a interface show, there is a sound.
        m_alarmInterface = m_errType;
        sendSettingsFrame();

        m_warningTipSrc = warning_tip_str[m_errType];
        emit warningTipSrcChanged(m_warningTipSrc);
    }
    else
    {
        m_errType = (WARNING_TIPS)m_preTipList[0];
        m_warningTipSrc = warning_tip_str[m_errType];
        emit warningTipSrcChanged(m_warningTipSrc);
        // send m_errType to MCU, sync the interface and sound.
        // where there is a interface show, there is a sound.
        m_alarmInterface = m_errType;
        sendSettingsFrame();
    }


#endif
}
void CarnationCarStatus::insertList(QList<uint> *list, uint idn)
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

void CarnationCarStatus::removeList(QList<uint> *list, uint idn)
{
    list->removeAll(idn);
    if (list->isEmpty())
        list->clear();
}

uint CarnationCarStatus::popList(QList<uint> *list)
{
    if (list->isEmpty())
        return 0;

    return list->takeFirst();
}

/* note: in func insertList, we have ordered the list by errType. The object
 *      with smaller errType will be shown first and it will interrupt other
 *      object which is being shown, but the one who is interrupted will be
 *      shown later again. */
void CarnationCarStatus::dealErrList(bool isInsert, WARNING_TIPS errType)
{
    if(isInsert) {
        insertList(&m_preTipList, (uint)errType);
        if( errType == m_preTipList[0]
                && m_isTipedList == false) {
            m_errType = (WARNING_TIPS)m_preTipList[0];
            m_warningTipSrc = warning_tip_str[m_errType];
            emit warningTipSrcChanged(m_warningTipSrc);
            // send m_errType to MCU, sync the interface and sound.
            // where there is a interface show, there is a sound.
            m_alarmInterface = m_errType;
            sendSettingsFrame();

            m_timer->start(5000);
        }
    } else {
        removeList(&m_preTipList, errType);
        removeList(&m_tipedList, errType);
    }
}

/* anti shake and showCheckErr */
void CarnationCarStatus::key1Deal(bool v)
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

                // deal check list and emit signal to qml
                showCheckErr();
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

        // deal check list and emit signal to qml
        showCheckErr();
    }

    if (m_key1Step == KEY_LONG_TIME + 1 && !v) {
        m_key1Step = 0;
    }
}

void CarnationCarStatus::key2Deal(bool v)
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
				emit okButtonShort();
				//showCheckErr();
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
		emit okButtonLong();
#endif
    }

    if (m_key2Step == KEY_LONG_TIME + 1 && !v) {
        m_key2Step = 0;
#ifdef DEBUG
        setKeyShow2("NONE");
#endif
    }
}

void CarnationCarStatus::key3Deal(bool v)
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
//                emit key3Short();
                showCheckErr();
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
//        emit key3Long();
        showCheckErr();
#endif
    }

    if (m_key3Step == KEY_LONG_TIME + 1 && !v) {
        m_key3Step = 0;
#ifdef DEBUG
        setKeyShow3("NONE");
#endif
    }
}

void CarnationCarStatus::key4Deal(bool v)
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
//                emit key4Short();
                showCheckErr();
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
//        emit key4Long();
        showCheckErr();
#endif
    }

    if (m_key4Step == KEY_LONG_TIME + 1 && !v) {
        m_key4Step = 0;
#ifdef DEBUG
        setKeyShow4("NONE");
#endif
    }
}
