#ifndef HONGQICARSTATUS_H
#define HONGQICARSTATUS_H

#include <QTimer>
#include <QTimerEvent>

#include <carstatus.h>



class HqCarStatus : public CarStatus
{
	Q_OBJECT
	Q_ENUMS(TipsEN)
	Q_ENUMS(FUNCTION_EVENT)
	Q_ENUMS(WARNING_TIPS)

	// MobileInfo
	Q_PROPERTY(uint nameLen READ nameLen NOTIFY nameLenChanged)
	Q_PROPERTY(QString name READ name NOTIFY nameChanged)
	Q_PROPERTY(uint numTypes READ numTypes NOTIFY numTypesChanged)
	Q_PROPERTY(uint numLen READ numLen NOTIFY numLenChanged)
	Q_PROPERTY(QString number READ number NOTIFY numberChanged)

	// SettingsInfo
	Q_PROPERTY(bool commandReq READ commandReq WRITE setCommandReq NOTIFY commandReqChanged)
	Q_PROPERTY(bool closeReq READ closeReq WRITE setCloseReq NOTIFY closeReqChanged)
	Q_PROPERTY(bool tripClean READ tripClean WRITE setTripClean NOTIFY tripCleanChanged)
	Q_PROPERTY(bool averageSpeedClean READ averageSpeedClean WRITE setAverageSpeedClean NOTIFY averageSpeedCleanChanged)
	Q_PROPERTY(bool averageFuelClean READ averageFuelClean WRITE setAverageFuelClean NOTIFY averageFuelCleanChanged)
	Q_PROPERTY(bool engineerMode READ engineerMode WRITE setEngineerMode NOTIFY engineerModeChanged)
	Q_PROPERTY(uint dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged)

	// SpecialInfo
	Q_PROPERTY(bool brakeSysErr READ brakeSysErr WRITE setBrakeSysErr NOTIFY brakeSysErrChanged)
	Q_PROPERTY(bool powerSteerErr READ powerSteerErr WRITE setPowerSteerErr NOTIFY powerSteerErrChanged)
	Q_PROPERTY(bool fLTirePressLeak READ fLTirePressLeak WRITE setFLTirePressLeak NOTIFY fLTirePressLeakChanged)
	Q_PROPERTY(bool fRTirePressLeak READ fRTirePressLeak WRITE setFRTirePressLeak NOTIFY fRTirePressLeakChanged)
	Q_PROPERTY(bool rLTirePressLeak READ rLTirePressLeak WRITE setRLTirePressLeak NOTIFY rLTirePressLeakChanged)
	Q_PROPERTY(bool rRTirePressLeak READ rRTirePressLeak WRITE setRRTirePressLeak NOTIFY rRTirePressLeakChanged)
	Q_PROPERTY(bool fLTirePressMoreInfo READ fLTirePressMoreInfo WRITE setFLTirePressMoreInfo NOTIFY fLTirePressMoreInfoChanged)
	Q_PROPERTY(bool fRTirePressMoreInfo READ fRTirePressMoreInfo WRITE setFRTirePressMoreInfo NOTIFY fRTirePressMoreInfoChanged)
	Q_PROPERTY(bool rLTirePressMoreInfo READ rLTirePressMoreInfo WRITE setRLTirePressMoreInfo NOTIFY rLTirePressMoreInfoChanged)
	Q_PROPERTY(bool rRTirePressMoreInfo READ rRTirePressMoreInfo WRITE setRRTirePressMoreInfo NOTIFY rRTirePressMoreInfoChanged)
	Q_PROPERTY(bool engineControlErr READ engineControlErr WRITE setEngineControlErr NOTIFY engineControlErrChanged)
	Q_PROPERTY(bool gearboxToohot READ gearboxToohot WRITE setGearboxToohot NOTIFY gearboxToohotChanged)
	Q_PROPERTY(bool gearboxErr READ gearboxErr WRITE setGearboxErr NOTIFY gearboxErrChanged)
	Q_PROPERTY(bool accAutoOff READ accAutoOff WRITE setAccAutoOff NOTIFY accAutoOffChanged)
	Q_PROPERTY(bool abaErr READ abaErr WRITE setAbaErr NOTIFY abaErrChanged)
	Q_PROPERTY(bool fcwErr READ fcwErr WRITE setFcwErr NOTIFY fcwErrChanged)
	Q_PROPERTY(bool absErr READ absErr WRITE setAbsErr NOTIFY absErrChanged)
	Q_PROPERTY(bool hydraulicSysErr READ hydraulicSysErr WRITE setHydraulicSysErr NOTIFY hydraulicSysErrChanged)
	Q_PROPERTY(bool espErr READ espErr WRITE setEspErr NOTIFY espErrChanged)
	Q_PROPERTY(bool tcsErr READ tcsErr WRITE setTcsErr NOTIFY tcsErrChanged)
	Q_PROPERTY(bool coolSysErr READ coolSysErr WRITE setCoolSysErr NOTIFY coolSysErrChanged)
	Q_PROPERTY(bool fluidToolow READ fluidToolow WRITE setFluidToolow NOTIFY fluidToolowChanged)
	Q_PROPERTY(bool engineOilErr READ engineOilErr WRITE setEngineOilErr NOTIFY engineOilErrChanged)
	Q_PROPERTY(bool epbErr READ epbErr WRITE setEpbErr NOTIFY epbErrChanged)
	Q_PROPERTY(bool autoHoldErr READ autoHoldErr WRITE setAutoHoldErr NOTIFY autoHoldErrChanged)
	Q_PROPERTY(bool accErr READ accErr WRITE setAccErr NOTIFY accErrChanged)
	Q_PROPERTY(bool pdcErr READ pdcErr WRITE setPdcErr NOTIFY pdcErrChanged)
	Q_PROPERTY(bool checkAlternator READ checkAlternator WRITE setCheckAlternator NOTIFY checkAlternatorChanged)
	Q_PROPERTY(bool changeBrakePads READ changeBrakePads WRITE setChangeBrakePads NOTIFY changeBrakePadsChanged)
	Q_PROPERTY(bool overSpeedLimit READ overSpeedLimit WRITE setOverSpeedLimit NOTIFY overSpeedLimitChanged)
	Q_PROPERTY(bool fLTirePressInfo READ fLTirePressInfo WRITE setFLTirePressInfo NOTIFY fLTirePressInfoChanged)
	Q_PROPERTY(bool fRTirePressInfo READ fRTirePressInfo WRITE setFRTirePressInfo NOTIFY fRTirePressInfoChanged)
	Q_PROPERTY(bool rLTirePressInfo READ rLTirePressInfo WRITE setRLTirePressInfo NOTIFY rLTirePressInfoChanged)
	Q_PROPERTY(bool rRTirePressInfo READ rRTirePressInfo WRITE setRRTirePressInfo NOTIFY rRTirePressInfoChanged)
	Q_PROPERTY(bool airbagErr READ airbagErr WRITE setAirbagErr NOTIFY airbagErrChanged)
	Q_PROPERTY(bool refrigerantLow READ refrigerantLow WRITE setRefrigerantLow NOTIFY refrigerantLowChanged)
	Q_PROPERTY(bool accActiveErr READ accActiveErr WRITE setAccActiveErr NOTIFY accActiveErrChanged)
	Q_PROPERTY(bool setCruise READ setCruise WRITE setSetCruise NOTIFY setCruiseChanged)
	Q_PROPERTY(bool ldwErr READ ldwErr WRITE setLdwErr NOTIFY ldwErrChanged)
	Q_PROPERTY(bool emissionSysErr READ emissionSysErr WRITE setEmissionSysErr NOTIFY emissionSysErrChanged)
	Q_PROPERTY(bool passiveEntrySysErr READ passiveEntrySysErr WRITE setPassiveEntrySysErr NOTIFY passiveEntrySysErrChanged)
	Q_PROPERTY(bool fLTirePressMonitorErr READ fLTirePressMonitorErr WRITE setFLTirePressMonitorErr NOTIFY fLTirePressMonitorErrChanged)
	Q_PROPERTY(bool fRTirePressMonitorErr READ fRTirePressMonitorErr WRITE setFRTirePressMonitorErr NOTIFY fRTirePressMonitorErrChanged)
	Q_PROPERTY(bool rLTirePressMonitorErr READ rLTirePressMonitorErr WRITE setRLTirePressMonitorErr NOTIFY rLTirePressMonitorErrChanged)
	Q_PROPERTY(bool rRTirePressMonitorErr READ rRTirePressMonitorErr WRITE setRRTirePressMonitorErr NOTIFY rRTirePressMonitorErrChanged)
	Q_PROPERTY(bool lFTurnLightErr READ lFTurnLightErr WRITE setLFTurnLightErr NOTIFY lFTurnLightErrChanged)
	Q_PROPERTY(bool rFTurnLightErr READ rFTurnLightErr WRITE setRFTurnLightErr NOTIFY rFTurnLightErrChanged)
	Q_PROPERTY(bool lRTurnLightErr READ lRTurnLightErr WRITE setLRTurnLightErr NOTIFY lRTurnLightErrChanged)
	Q_PROPERTY(bool rRTurnLightErr READ rRTurnLightErr WRITE setRRTurnLightErr NOTIFY rRTurnLightErrChanged)
	Q_PROPERTY(bool lRGroupLightErr READ lRGroupLightErr WRITE setLRGroupLightErr NOTIFY lRGroupLightErrChanged)
	Q_PROPERTY(bool rRGroupLightErr READ rRGroupLightErr WRITE setRRGroupLightErr NOTIFY rRGroupLightErrChanged)
	Q_PROPERTY(bool backupLightErr READ backupLightErr WRITE setBackupLightErr NOTIFY backupLightErrChanged)
	Q_PROPERTY(bool nightVisionErr READ nightVisionErr WRITE setNightVisionErr NOTIFY nightVisionErrChanged)
	Q_PROPERTY(bool afsErr READ afsErr WRITE setAfsErr NOTIFY afsErrChanged)
	Q_PROPERTY(bool startAndStopSysErr READ startAndStopSysErr WRITE setStartAndStopSysErr NOTIFY startAndStopSysErrChanged)
	Q_PROPERTY(bool headlampAdjustErr READ headlampAdjustErr WRITE setHeadlampAdjustErr NOTIFY headlampAdjustErrChanged)
	Q_PROPERTY(bool refillFuel READ refillFuel WRITE setRefillFuel NOTIFY refillFuelChanged)
	Q_PROPERTY(bool autoLightsWiperErr READ autoLightsWiperErr WRITE setAutoLightsWiperErr NOTIFY autoLightsWiperErrChanged)
	Q_PROPERTY(bool cameraBlocked READ cameraBlocked WRITE setCameraBlocked NOTIFY cameraBlockedChanged)
	Q_PROPERTY(bool raderBlockHotErr READ raderBlockHotErr WRITE setRaderBlockHotErr NOTIFY raderBlockHotErrChanged)
	Q_PROPERTY(bool lFLightErr READ lFLightErr WRITE setLFLightErr NOTIFY lFLightErrChanged)
	Q_PROPERTY(bool rFLightErr READ rFLightErr WRITE setRFLightErr NOTIFY rFLightErrChanged)
	Q_PROPERTY(bool lFPositionLightErr READ lFPositionLightErr WRITE setLFPositionLightErr NOTIFY lFPositionLightErrChanged)
	Q_PROPERTY(bool rFPositionLightErr READ rFPositionLightErr WRITE setRFPositionLightErr NOTIFY rFPositionLightErrChanged)
	Q_PROPERTY(bool lFFogLightErr READ lFFogLightErr WRITE setLFFogLightErr NOTIFY lFFogLightErrChanged)
	Q_PROPERTY(bool rFFogLightErr READ rFFogLightErr WRITE setRFFogLightErr NOTIFY rFFogLightErrChanged)
	Q_PROPERTY(bool licenseLightErr READ licenseLightErr WRITE setLicenseLightErr NOTIFY licenseLightErrChanged)
	Q_PROPERTY(bool ignitionSwitchErr READ ignitionSwitchErr WRITE setIgnitionSwitchErr NOTIFY ignitionSwitchErrChanged)
	Q_PROPERTY(bool unknownKey READ unknownKey WRITE setUnknownKey NOTIFY unknownKeyChanged)
	Q_PROPERTY(bool fourWDSysErr READ fourWDSysErr WRITE setFourWDSysErr NOTIFY fourWDSysErrChanged)
	Q_PROPERTY(bool scmSysErr READ scmSysErr WRITE setScmSysErr NOTIFY scmSysErrChanged)
	Q_PROPERTY(bool accClose READ accClose WRITE setAccClose NOTIFY accCloseChanged)
	Q_PROPERTY(bool keyBatLow READ keyBatLow WRITE setKeyBatLow NOTIFY keyBatLowChanged)
	Q_PROPERTY(bool refillCleanFluid READ refillCleanFluid WRITE setRefillCleanFluid NOTIFY refillCleanFluidChanged)
	Q_PROPERTY(bool seatAdjustErr READ seatAdjustErr WRITE setSeatAdjustErr NOTIFY seatAdjustErrChanged)
	Q_PROPERTY(bool xkmBeforeMaintenance READ xkmBeforeMaintenance WRITE setXkmBeforeMaintenance NOTIFY xkmBeforeMaintenanceChanged)
	Q_PROPERTY(bool bluetoothMicrophoneErr READ bluetoothMicrophoneErr WRITE setBluetoothMicrophoneErr NOTIFY bluetoothMicrophoneErrChanged)
	Q_PROPERTY(bool bluetoothSwitchErr READ bluetoothSwitchErr WRITE setBluetoothSwitchErr NOTIFY bluetoothSwitchErrChanged)
	Q_PROPERTY(bool bluetoothAudioLineErr READ bluetoothAudioLineErr WRITE setBluetoothAudioLineErr NOTIFY bluetoothAudioLineErrChanged)
	Q_PROPERTY(bool steeringColumnLockErr READ steeringColumnLockErr WRITE setSteeringColumnLockErr NOTIFY steeringColumnLockErrChanged)
	Q_PROPERTY(bool instrumentClusterErr READ instrumentClusterErr WRITE setInstrumentClusterErr NOTIFY instrumentClusterErrChanged)
	Q_PROPERTY(bool ldwClose READ ldwClose WRITE setLdwClose NOTIFY ldwCloseChanged)
	Q_PROPERTY(bool afsClose READ afsClose WRITE setAfsClose NOTIFY afsCloseChanged)
	Q_PROPERTY(bool espClose READ espClose WRITE setEspClose NOTIFY espCloseChanged)
	Q_PROPERTY(bool abaActiveErr READ abaActiveErr WRITE setAbaActiveErr NOTIFY abaActiveErrChanged)
	Q_PROPERTY(bool fcwCloseErr READ fcwCloseErr WRITE setFcwCloseErr NOTIFY fcwCloseErrChanged)
	Q_PROPERTY(bool abaCloseErr READ abaCloseErr WRITE setAbaCloseErr NOTIFY abaCloseErrChanged)
	Q_PROPERTY(bool abaIndicator READ abaIndicator WRITE setAbaIndicator NOTIFY abaIndicatorChanged)
	Q_PROPERTY(bool avh READ avh WRITE setAvh NOTIFY avhChanged)
	Q_PROPERTY(uint stopAndGoIndicator READ stopAndGoIndicator WRITE setStopAndGoIndicator NOTIFY stopAndGoIndicatorChanged)
	Q_PROPERTY(bool parkingCarUi READ parkingCarUi WRITE setParkingCarUi NOTIFY parkingCarUiChanged)
	Q_PROPERTY(bool rearRightRadarFlicker READ rearRightRadarFlicker WRITE setRearRightRadarFlicker NOTIFY rearRightRadarFlickerChanged)
	Q_PROPERTY(bool rearCentreRRadarFlicker READ rearCentreRRadarFlicker WRITE setRearCentreRRadarFlicker NOTIFY rearCentreRRadarFlickerChanged)
	Q_PROPERTY(bool rearCentreLRadarFlicker READ rearCentreLRadarFlicker WRITE setRearCentreLRadarFlicker NOTIFY rearCentreLRadarFlickerChanged)
	Q_PROPERTY(bool rearLeftRadarFlicker READ rearLeftRadarFlicker WRITE setRearLeftRadarFlicker NOTIFY rearLeftRadarFlickerChanged)
	Q_PROPERTY(bool frontRightRadarFlicker READ frontRightRadarFlicker WRITE setFrontRightRadarFlicker NOTIFY frontRightRadarFlickerChanged)
	Q_PROPERTY(bool frontCentreRRadarFlicker READ frontCentreRRadarFlicker WRITE setFrontCentreRRadarFlicker NOTIFY frontCentreRRadarFlickerChanged)
	Q_PROPERTY(bool frontCentreLRadarFlicker READ frontCentreLRadarFlicker WRITE setFrontCentreLRadarFlicker NOTIFY frontCentreLRadarFlickerChanged)
	Q_PROPERTY(bool frontLeftRadarFlicker READ frontLeftRadarFlicker WRITE setFrontLeftRadarFlicker NOTIFY frontLeftRadarFlickerChanged)
	Q_PROPERTY(uint frontLeftRadarLevel READ frontLeftRadarLevel WRITE setFrontLeftRadarLevel NOTIFY frontLeftRadarLevelChanged)
	Q_PROPERTY(uint frontCentreLRadarLevel READ frontCentreLRadarLevel WRITE setFrontCentreLRadarLevel NOTIFY frontCentreLRadarLevelChanged)
	Q_PROPERTY(uint frontCentreRRadarLevel READ frontCentreRRadarLevel WRITE setFrontCentreRRadarLevel NOTIFY frontCentreRRadarLevelChanged)
	Q_PROPERTY(uint frontRightRadarLevel READ frontRightRadarLevel WRITE setFrontRightRadarLevel NOTIFY frontRightRadarLevelChanged)
	Q_PROPERTY(uint rearRightRadarLevel READ rearRightRadarLevel WRITE setRearRightRadarLevel NOTIFY rearRightRadarLevelChanged)
	Q_PROPERTY(uint rearCentreRRadarLevel READ rearCentreRRadarLevel WRITE setRearCentreRRadarLevel NOTIFY rearCentreRRadarLevelChanged)
	Q_PROPERTY(uint rearCentreLRadarLevel READ rearCentreLRadarLevel WRITE setRearCentreLRadarLevel NOTIFY rearCentreLRadarLevelChanged)
	Q_PROPERTY(uint rearLeftRadarLevel READ rearLeftRadarLevel WRITE setRearLeftRadarLevel NOTIFY rearLeftRadarLevelChanged)
	Q_PROPERTY(bool fcwNotice READ fcwNotice WRITE setFcwNotice NOTIFY fcwNoticeChanged)
	Q_PROPERTY(bool fcwMoreNotice READ fcwMoreNotice WRITE setFcwMoreNotice NOTIFY fcwMoreNoticeChanged)
	Q_PROPERTY(bool lkpMoreRest READ lkpMoreRest WRITE setLkpMoreRest NOTIFY lkpMoreRestChanged)
	Q_PROPERTY(bool lkpRest READ lkpRest WRITE setLkpRest NOTIFY lkpRestChanged)
	Q_PROPERTY(bool shift2P READ shift2P WRITE setShift2P NOTIFY shift2PChanged)
	Q_PROPERTY(bool slopeTooHigh READ slopeTooHigh WRITE setSlopeTooHigh NOTIFY slopeTooHighChanged)
	Q_PROPERTY(bool brakingPowerLow READ brakingPowerLow WRITE setBrakingPowerLow NOTIFY brakingPowerLowChanged)
	Q_PROPERTY(bool keyInCar READ keyInCar WRITE setKeyInCar NOTIFY keyInCarChanged)
	Q_PROPERTY(bool keyInTrunk READ keyInTrunk WRITE setKeyInTrunk NOTIFY keyInTrunkChanged)
	Q_PROPERTY(bool keyStatus2Off READ keyStatus2Off WRITE setKeyStatus2Off NOTIFY keyStatus2OffChanged)
	Q_PROPERTY(bool steerColumnLock READ steerColumnLock WRITE setSteerColumnLock NOTIFY steerColumnLockChanged)
	Q_PROPERTY(bool batLowStartEngine READ batLowStartEngine WRITE setBatLowStartEngine NOTIFY batLowStartEngineChanged)
	Q_PROPERTY(bool startEngineSelf READ startEngineSelf WRITE setStartEngineSelf NOTIFY startEngineSelfChanged)
	Q_PROPERTY(bool shift2PN READ shift2PN WRITE setShift2PN NOTIFY shift2PNChanged)
	Q_PROPERTY(bool lPress2Start24s READ lPress2Start24s WRITE setLPress2Start24s NOTIFY lPress2Start24sChanged)
	Q_PROPERTY(bool lampON READ lampON WRITE setLampON NOTIFY lampONChanged)
	Q_PROPERTY(bool accUI READ accUI WRITE setAccUI NOTIFY accUIChanged)
	Q_PROPERTY(uint accIndicator READ accIndicator WRITE setAccIndicator NOTIFY accIndicatorChanged)
	Q_PROPERTY(bool accFlicker READ accFlicker WRITE setAccFlicker NOTIFY accFlickerChanged)
	Q_PROPERTY(uint frontCarDistanceLevel READ frontCarDistanceLevel WRITE setFrontCarDistanceLevel NOTIFY frontCarDistanceLevelChanged)
	Q_PROPERTY(bool frontCarFlicker READ frontCarFlicker WRITE setFrontCarFlicker NOTIFY frontCarFlickerChanged)
	Q_PROPERTY(uint frontCarSpeed READ frontCarSpeed WRITE setFrontCarSpeed NOTIFY frontCarSpeedChanged)
	Q_PROPERTY(bool accRecovery READ accRecovery WRITE setAccRecovery NOTIFY accRecoveryChanged)
	Q_PROPERTY(uint frontCarStatus READ frontCarStatus WRITE setFrontCarStatus NOTIFY frontCarStatusChanged)
	Q_PROPERTY(bool ccsSet READ ccsSet WRITE setCcsSet NOTIFY ccsSetChanged)
	Q_PROPERTY(uint ccsIndicator READ ccsIndicator WRITE setCcsIndicator NOTIFY ccsIndicatorChanged)
	Q_PROPERTY(uint ccsSpeed READ ccsSpeed WRITE setCcsSpeed NOTIFY ccsSpeedChanged)
	Q_PROPERTY(bool ldwOn READ ldwOn WRITE setLdwOn NOTIFY ldwOnChanged)
	Q_PROPERTY(uint ldwIndicator READ ldwIndicator WRITE setLdwIndicator NOTIFY ldwIndicatorChanged)
	Q_PROPERTY(bool ldwFlicker READ ldwFlicker WRITE setLdwFlicker NOTIFY ldwFlickerChanged)
	Q_PROPERTY(uint ldwLeftIndicator READ ldwLeftIndicator WRITE setLdwLeftIndicator NOTIFY ldwLeftIndicatorChanged)
	Q_PROPERTY(uint ldwRightIndicator READ ldwRightIndicator WRITE setLdwRightIndicator NOTIFY ldwRightIndicatorChanged)
	Q_PROPERTY(uint bluetoothStatus READ bluetoothStatus WRITE setBluetoothStatus NOTIFY bluetoothStatusChanged)
	Q_PROPERTY(uint batValue READ batValue WRITE setBatValue NOTIFY batValueChanged)
	Q_PROPERTY(uint mobileSingel READ mobileSingel WRITE setMobileSingel NOTIFY mobileSingelChanged)
	Q_PROPERTY(bool highBeamLight READ highBeamLight WRITE setHighBeamLight NOTIFY highBeamLightChanged)
	Q_PROPERTY(bool positionLight READ positionLight WRITE setPositionLight NOTIFY positionLightChanged)
	Q_PROPERTY(bool frontFogLight READ frontFogLight WRITE setFrontFogLight NOTIFY frontFogLightChanged)
	Q_PROPERTY(bool rearFogLight READ rearFogLight WRITE setRearFogLight NOTIFY rearFogLightChanged)
	Q_PROPERTY(bool engineOilLight READ engineOilLight WRITE setEngineOilLight NOTIFY engineOilLightChanged)
	Q_PROPERTY(bool nightVisionLight READ nightVisionLight WRITE setNightVisionLight NOTIFY nightVisionLightChanged)
	Q_PROPERTY(bool sysBattErr READ sysBattErr WRITE setSysBattErr NOTIFY sysBattErrChanged)
	Q_PROPERTY(bool mainErr READ mainErr WRITE setMainErr NOTIFY mainErrChanged)
	Q_PROPERTY(bool espLightFlick READ espLightFlick WRITE setEspLightFlick NOTIFY espLightFlickChanged)
	Q_PROPERTY(uint fLTirePress READ fLTirePress WRITE setFLTirePress NOTIFY fLTirePressChanged)
	Q_PROPERTY(uint fRTirePress READ fRTirePress WRITE setFRTirePress NOTIFY fRTirePressChanged)
	Q_PROPERTY(uint rLTirePress READ rLTirePress WRITE setRLTirePress NOTIFY rLTirePressChanged)
	Q_PROPERTY(uint rRTirePress READ rRTirePress WRITE setRRTirePress NOTIFY rRTirePressChanged)
	Q_PROPERTY(uint fLTireTemp READ fLTireTemp WRITE setFLTireTemp NOTIFY fLTireTempChanged)
	Q_PROPERTY(uint fRTireTemp READ fRTireTemp WRITE setFRTireTemp NOTIFY fRTireTempChanged)
	Q_PROPERTY(uint rLTireTemp READ rLTireTemp WRITE setRLTireTemp NOTIFY rLTireTempChanged)
	Q_PROPERTY(uint rRTireTemp READ rRTireTemp WRITE setRRTireTemp NOTIFY rRTireTempChanged)
	Q_PROPERTY(uint fm READ fm WRITE setFm NOTIFY fmChanged)
	Q_PROPERTY(uint am READ am WRITE setAm NOTIFY amChanged)
	Q_PROPERTY(uint programNum READ programNum WRITE setProgramNum NOTIFY programNumChanged)
	Q_PROPERTY(uint soundMode READ soundMode WRITE setSoundMode NOTIFY soundModeChanged)

	// tips
	Q_PROPERTY(WARNING_TIPS errType READ errType NOTIFY errTypeChanged)
	Q_PROPERTY(FUNCTION_EVENT functionTypes READ functionTypes NOTIFY functionTypesChanged)

	// fontname
	Q_PROPERTY(QString fontName READ fontName WRITE setFontName NOTIFY fontNameChanged)
public:    
	enum TipsEN{InitType, SystemErr, StopsystemErr, PowerErr, TyreleakErr, PleasetotyrepressErr, TemhighErr,
				VarysudoErr, CoolsystemErr, StopwatertoolowErr, MachineoillowErr, EpserroErr, PleasetestgeneratesystemErr, StoprubErr, OversetsudoErr, SafebagErr,
				CoolwatershortErr, AccnotstartErr, AccnotacctivatedErr, LdwfaultErr, ExhaustgasmonitorsystemErr, ChipErr,
				TyrepresstestfailErr, NightvisionfuncErr, AfsfaultErr, FunctionErr, FrontlightErr, OilErr, AutoErr, CamercoverErr, RadarcoverErr, BrandlightErr,
				FireonErr, UnknownkeyErr, ColumErr, AccclosedErr, BatterlowinkeyErr, SafememoryErr,
				BluetoothErr, BluetoothlineshortErr, ColumnbrakeErr, MeterErr, LdwclosedErr, AfsclosedErr,
				ActivehelpnotavaliableErr, AlarmsystemclosedErr, ActivehelpcloseErr, SafebeltErr,
				PleasetopErr, NoparkingErr, EnergylowErr, KeyincarErr, KeyincaseErr, PleaseturnonErr,
				LockedErr, ChargelowErr, StartmotorErr, PanelPNErr, Longpressonto4sErr, LightenstartErr};

	enum FUNCTION_EVENT { MIN_EVENT,
						  ABA_EVENT,						//主动制动辅助系统起作用界面 5s+
						  PDC_EVENT,						//PDC 显示界面 5s+
						  FCW_EVENT,						//前碰撞预警进入警戒状态或即将 *前碰撞预警进入警戒状态或即将发生碰撞的界面 5s+
						  LKPMORE_EVENT,					//驾驶员状态严重异常界面 5s+
						  DRIVEINFO_SHIFT2P_EVENT,          //请挂入 P 档!
						  DRIVEINFO_HIGHGRADIENT_EVENT,     //坡度过大,不宜停车!
						  DRIVEINFO_BRAKINGPOWERLOW_EVENT,  //制动力不足!
						  DRIVEINFO_KEYINCAR_EVENT,         //钥匙在车内!
						  DRIVEINFO_KEYINTRUNT_EVENT,       //钥匙在行李箱内!
						  DRIVEINFO_KEYSTATUS2OFF_EVENT,    //请置起动开关于‘OFF’!
						  DRIVEINFO_STEERCOLUMNLOCK_EVENT,  //转向柱锁未解除!
						  DRIVEINFO_BATLOWSTARTENGINE_EVENT,//蓄电池电量低,请起动发动机!
						  DRIVEINFO_STARTENGINESELF_EVENT,  //请手动起动发动机!
						  DRIVEINFO_SHIFT2PN_EVENT,         //踩下制动踏板并挂入 P/N 档,方可起动!
						  DRIVEINFO_LPRESS2START24S_EVENT,  //长按起动开关方可起动,请前往 4S 店检修!
						  DRIVEINFO_LAMPON_EVENT,           //照明已开启!
						  ACC_EVENT,						//ACC 显示界面 5s+
						  LKP_EVENT,						//驾驶员状态轻微异常界面 5s+
						  LDW_EVENT,						//LDW 报警界面 5s+
						  CCS_EVENT,						//定速巡航车速设置界面 5s+
						  MAX_EVENT,						//MAX NUM
						};

	enum WARNING_TIPS { NULL_ERR,
						SYS_N_ERR,				//系统出现 n(n≥3)个故障,按“CHECK”键查阅详情!
						BRAKESYS_ERR,			//制动系统严重故障!
						POWER_STEER_ERR,		//电液助力转向功能故障!
						TIREPRESSURE_LEAK_ERR,	//轮胎漏气!
						CHECK_TIREP_MORE_ERR,   //请检查轮胎压力! more
						ENGINE_CTRLSYS_ERR,		//发动机控制系统故障! Engine control unit fault!    empty
						GEARBOX_HOT_ERR,		//变速器温度过高! Gearbox temperature too high!
						GEAR_ERR,				//变速器故障! Gearbox fault!
						ACC_AUTO_OFF_ERR,		//ACC 自动解除!    empty
						ABA_ERR,				//主动制动辅助功能故障! Auto brake assistance fault!    empty
						FCW_ERR,				//前碰撞预警功能故障!    empty111
						ABS_ERR,				//ABS 故障!    empty
						HYDRAULICSYS_ERR,		//液压辅助真空助力器制动系统故障!    empty
						ESP_ERR,				//ESP 故障!    empty
						TCS_ERR,				//TCS 故障!    empty
						COOLSYS_ERR,			//冷却系统故障!
						FLUID_LOW_ERR,			//制动液液位过低!
						ENGINEOIL_LOW_ERR,		//机油压力过低!
						EPB_ERR,				//EPB 故障!
						AUTO_HOLD_ERR,			//AUTO HOLD 功能故障!    empty
						ACC_ERR,				//ACC 故障!    empty
						PDC_ERR,				//PDC 故障,无法启用!    empty
						CHECK_ALTERNATOR_ERR,	//请检查发电系统!
						CHANGE_BRAKEPAD_ERR,	//请更换制动摩擦片!
						OVER_SPEED_ERR,			//已超过设定车速!
						CHECK_TIREP_ERR,		//请检查轮胎压力!    empty
						AIRBAG_ERR,				//安全气囊系统故障!
						REFRIGERANT_LOW_ERR,	//制冷剂不足!
						ACC_ACTIVE_ERR,			//ACC 不能激活!
						SET_CCS_ERR,			//请按下‘SET-’设定巡航!    empty
						LDW_ERR,				//LDW 故障!
						EMISSIONSYS_ERR,		//废气监控系统故障!
						PASSIVEENTRYSYS_ERR,	//智能进入系统故障!
						TIREP_MONITOR_ERR,		//胎压监测功能失效!
						LFTURNLIGHT_ERR,		//左前转向灯故障
						RFTURNLIGHT_ERR,		//右前转向灯故障
						LRTURNLIGHT_ERR,		//左后转向灯故障
						RRTURNLIGHT_ERR,		//右后转向灯故障
						LRGROUPLIGHT_ERR,		//左后组合灯故障
						RRGROUPLIGHT_ERR,		//右后组合灯故障
						BACKUPLIGHT_ERR,		//倒车灯故障
						NIGHT_VIEW_ERR,			//夜视功能故障
						AFS_ERR,				//AFS 故障!
						STARTANDSTOPSYS_ERR,	//起停系统故障
						HEADLAMP_ADJUST_ERR,	//前照灯照明距离调节故障
						REFILL_FUEL_ERR,		//请加油
						AUTOLIGHTWIPER_ERR,		//自动行车灯/自动刮水功能故障!
						CAMERABLOCKED_ERR,		//摄像头被遮挡,请清洁风窗玻璃!
						RADERBLOCK_HOT_ERR,		//雷达被遮挡或雷达温度过高!
						LFLIGHT_ERR,			//左前照灯故障
						RFLIGHT_ERR,			//右前照灯故障
						LFPOSITIONLIGHT_ERR,	//左前位置灯故障
						RFPOSITIONLIGHT_ERR,	//右前位置灯故障
						LFFOGLIGHT_ERR,			//左前雾灯故障
						RFFOGLIGHT_ERR,			//右前雾灯故障
						LICENSELIGHT_ERR,		//牌照灯故障
						IGNITIONSWITCH_ERR,		//点火开关故障！
						UNKNOWNKEY_ERR,			//不能识别钥匙
						FOURWDSYS_ERR,			//四驱系统故障
						SCMSYS_ERR,				//转向柱电动可调系统故障！
						ACC_CLOSE_ERR,			//ACC 已关闭!
						KEYBAT_LOW_ERR,			//钥匙电池电量不足
						REFILLCLEANFLUID_ERR,	//请添加清洗液
						SEAT_ADJUST_ERR,		//座椅记忆（调整）功能故障
						XKMBEFOREMAINTENANCE,	//距保养还有××× km/请保养   empty
						BLUETOOTHMIC_ERR,		//麦克风短路或开路
						BLUETOOTHSWITCH_ERR,	//蓝牙开关短路或开路
						BLUETOOTHAUDIOLINE_ERR,	//蓝牙音频线短路
						STEERCOLUMNLOCK_ERR,	//转向柱锁功能故障
						INSTRUMENTCLUSTER_ERR,	//仪表故障！
						LDW_CLOSE_ERR,			//LDW 已关闭！
						AFS_CLOSE_ERR,			//AFS 已关闭！
						ESP_CLOSE_ERR,			//ESP 已关闭！
						ABA_ACTIVE_ERR,			//主动制动辅助功能不可用
						FCW_CLOSE_ERR,			//前碰撞预警功能已关闭!
						ABA_CLOSE_ERR,			//主动制动辅助功能已关闭!
						MAX_WARNING_TIPS
					  };

	explicit HqCarStatus(const QString &serialDev, QObject *parent = 0);
	explicit HqCarStatus(QObject *parent = 0);
	void setActive(bool);

	// MobileInfo
	uint nameLen()const { return m_nameLen; }
	QString name()const { return m_name; }
	uint numTypes()const { return m_numTypes; }
	uint numLen()const { return m_numLen; }
	QString number()const { return m_number; }

	// SettingsInfo
	bool commandReq()const { return m_commandReq; }
	bool closeReq()const { return m_closeReq; }
	bool tripClean()const { return m_tripClean; }
	bool averageSpeedClean()const { return m_averageSpeedClean; }
	bool averageFuelClean()const { return m_averageFuelClean; }
	bool engineerMode()const { return m_engineerMode; }
	uint dateTime()const { return m_dateTime; }

	// SpecialInfo
	bool brakeSysErr()const { return m_brakeSysErr; }
	bool powerSteerErr()const { return m_powerSteerErr; }
	bool fLTirePressLeak()const { return m_fLTirePressLeak; }
	bool fRTirePressLeak()const { return m_fRTirePressLeak; }
	bool rLTirePressLeak()const { return m_rLTirePressLeak; }
	bool rRTirePressLeak()const { return m_rRTirePressLeak; }
	bool fLTirePressMoreInfo()const { return m_fLTirePressMoreInfo; }
	bool fRTirePressMoreInfo()const { return m_fRTirePressMoreInfo; }
	bool rLTirePressMoreInfo()const { return m_rLTirePressMoreInfo; }
	bool rRTirePressMoreInfo()const { return m_rRTirePressMoreInfo; }
	bool engineControlErr()const { return m_engineControlErr; }
	bool gearboxToohot()const { return m_gearboxToohot; }
	bool gearboxErr()const { return m_gearboxErr; }
	bool accAutoOff()const { return m_accAutoOff; }
	bool abaErr()const { return m_abaErr; }
	bool fcwErr()const { return m_fcwErr; }
	bool absErr()const { return m_absErr; }
	bool hydraulicSysErr()const { return m_hydraulicSysErr; }
	bool espErr()const { return m_espErr; }
	bool tcsErr()const { return m_tcsErr; }
	bool coolSysErr()const { return m_coolSysErr; }
	bool fluidToolow()const { return m_fluidToolow; }
	bool engineOilErr()const { return m_engineOilErr; }
	bool epbErr()const { return m_epbErr; }
	bool autoHoldErr()const { return m_autoHoldErr; }
	bool accErr()const { return m_accErr; }
	bool pdcErr()const { return m_pdcErr; }
	bool checkAlternator()const { return m_checkAlternator; }
	bool changeBrakePads()const { return m_changeBrakePads; }
	bool overSpeedLimit()const { return m_overSpeedLimit; }
	bool fLTirePressInfo()const { return m_fLTirePressInfo; }
	bool fRTirePressInfo()const { return m_fRTirePressInfo; }
	bool rLTirePressInfo()const { return m_rLTirePressInfo; }
	bool rRTirePressInfo()const { return m_rRTirePressInfo; }
	bool airbagErr()const { return m_airbagErr; }
	bool refrigerantLow()const { return m_refrigerantLow; }
	bool accActiveErr()const { return m_accActiveErr; }
	bool setCruise()const { return m_setCruise; }
	bool ldwErr()const { return m_ldwErr; }
	bool emissionSysErr()const { return m_emissionSysErr; }
	bool passiveEntrySysErr()const { return m_passiveEntrySysErr; }
	bool fLTirePressMonitorErr()const { return m_fLTirePressMonitorErr; }
	bool fRTirePressMonitorErr()const { return m_fRTirePressMonitorErr; }
	bool rLTirePressMonitorErr()const { return m_rLTirePressMonitorErr; }
	bool rRTirePressMonitorErr()const { return m_rRTirePressMonitorErr; }
	bool lFTurnLightErr()const { return m_lFTurnLightErr; }
	bool rFTurnLightErr()const { return m_rFTurnLightErr; }
	bool lRTurnLightErr()const { return m_lRTurnLightErr; }
	bool rRTurnLightErr()const { return m_rRTurnLightErr; }
	bool lRGroupLightErr()const { return m_lRGroupLightErr; }
	bool rRGroupLightErr()const { return m_rRGroupLightErr; }
	bool backupLightErr()const { return m_backupLightErr; }
	bool nightVisionErr()const { return m_nightVisionErr; }
	bool afsErr()const { return m_afsErr; }
	bool startAndStopSysErr()const { return m_startAndStopSysErr; }
	bool headlampAdjustErr()const { return m_headlampAdjustErr; }
	bool refillFuel()const { return m_refillFuel; }
	bool autoLightsWiperErr()const { return m_autoLightsWiperErr; }
	bool cameraBlocked()const { return m_cameraBlocked; }
	bool raderBlockHotErr()const { return m_raderBlockHotErr; }
	bool lFLightErr()const { return m_lFLightErr; }
	bool rFLightErr()const { return m_rFLightErr; }
	bool lFPositionLightErr()const { return m_lFPositionLightErr; }
	bool rFPositionLightErr()const { return m_rFPositionLightErr; }
	bool lFFogLightErr()const { return m_lFFogLightErr; }
	bool rFFogLightErr()const { return m_rFFogLightErr; }
	bool licenseLightErr()const { return m_licenseLightErr; }
	bool ignitionSwitchErr()const { return m_ignitionSwitchErr; }
	bool unknownKey()const { return m_unknownKey; }
	bool fourWDSysErr()const { return m_fourWDSysErr; }
	bool scmSysErr()const { return m_scmSysErr; }
	bool accClose()const { return m_accClose; }
	bool keyBatLow()const { return m_keyBatLow; }
	bool refillCleanFluid()const { return m_refillCleanFluid; }
	bool seatAdjustErr()const { return m_seatAdjustErr; }
	bool xkmBeforeMaintenance()const { return m_xkmBeforeMaintenance; }
	bool bluetoothMicrophoneErr()const { return m_bluetoothMicrophoneErr; }
	bool bluetoothSwitchErr()const { return m_bluetoothSwitchErr; }
	bool bluetoothAudioLineErr()const { return m_bluetoothAudioLineErr; }
	bool steeringColumnLockErr()const { return m_steeringColumnLockErr; }
	bool instrumentClusterErr()const { return m_instrumentClusterErr; }
	bool ldwClose()const { return m_ldwClose; }
	bool afsClose()const { return m_afsClose; }
	bool espClose()const { return m_espClose; }
	bool abaActiveErr()const { return m_abaActiveErr; }
	bool fcwCloseErr()const { return m_fcwCloseErr; }
	bool abaCloseErr()const { return m_abaCloseErr; }
	bool abaIndicator()const { return m_abaIndicator; }
	bool avh()const { return m_avh; }
	uint stopAndGoIndicator()const { return m_stopAndGoIndicator; }
	bool parkingCarUi()const { return m_parkingCarUi; }
	bool rearRightRadarFlicker()const { return m_rearRightRadarFlicker; }
	bool rearCentreRRadarFlicker()const { return m_rearCentreRRadarFlicker; }
	bool rearCentreLRadarFlicker()const { return m_rearCentreLRadarFlicker; }
	bool rearLeftRadarFlicker()const { return m_rearLeftRadarFlicker; }
	bool frontRightRadarFlicker()const { return m_frontRightRadarFlicker; }
	bool frontCentreRRadarFlicker()const { return m_frontCentreRRadarFlicker; }
	bool frontCentreLRadarFlicker()const { return m_frontCentreLRadarFlicker; }
	bool frontLeftRadarFlicker()const { return m_frontLeftRadarFlicker; }
	uint frontLeftRadarLevel()const { return m_frontLeftRadarLevel; }
	uint frontCentreLRadarLevel()const { return m_frontCentreLRadarLevel; }
	uint frontCentreRRadarLevel()const { return m_frontCentreRRadarLevel; }
	uint frontRightRadarLevel()const { return m_frontRightRadarLevel; }
	uint rearRightRadarLevel()const { return m_rearRightRadarLevel; }
	uint rearCentreRRadarLevel()const { return m_rearCentreRRadarLevel; }
	uint rearCentreLRadarLevel()const { return m_rearCentreLRadarLevel; }
	uint rearLeftRadarLevel()const { return m_rearLeftRadarLevel; }
	bool fcwNotice()const { return m_fcwNotice; }
	bool fcwMoreNotice()const { return m_fcwMoreNotice; }
	bool lkpMoreRest()const { return m_lkpMoreRest; }
	bool lkpRest()const { return m_lkpRest; }
	bool shift2P()const { return m_shift2P; }
	bool slopeTooHigh()const { return m_slopeTooHigh; }
	bool brakingPowerLow()const { return m_brakingPowerLow; }
	bool keyInCar()const { return m_keyInCar; }
	bool keyInTrunk()const { return m_keyInTrunk; }
	bool keyStatus2Off()const { return m_keyStatus2Off; }
	bool steerColumnLock()const { return m_steerColumnLock; }
	bool batLowStartEngine()const { return m_batLowStartEngine; }
	bool startEngineSelf()const { return m_startEngineSelf; }
	bool shift2PN()const { return m_shift2PN; }
	bool lPress2Start24s()const { return m_lPress2Start24s; }
	bool lampON()const { return m_lampON; }
	bool accUI()const { return m_accUI; }
	uint accIndicator()const { return m_accIndicator; }
	bool accFlicker()const { return m_accFlicker; }
	uint frontCarDistanceLevel()const { return m_frontCarDistanceLevel; }
	bool frontCarFlicker()const { return m_frontCarFlicker; }
	uint frontCarSpeed()const { return m_frontCarSpeed; }
	bool accRecovery()const { return m_accRecovery; }
	uint frontCarStatus()const { return m_frontCarStatus; }
	bool ccsSet()const { return m_ccsSet; }
	uint ccsIndicator()const { return m_ccsIndicator; }
	uint ccsSpeed()const { return m_ccsSpeed; }
	bool ldwOn()const { return m_ldwOn; }
	uint ldwIndicator()const { return m_ldwIndicator; }
	bool ldwFlicker()const { return m_ldwFlicker; }
	uint ldwLeftIndicator()const { return m_ldwLeftIndicator; }
	uint ldwRightIndicator()const { return m_ldwRightIndicator; }
	uint bluetoothStatus()const { return m_bluetoothStatus; }
	uint batValue()const { return m_batValue; }
	uint mobileSingel()const { return m_mobileSingel; }
	bool highBeamLight()const { return m_highBeamLight; }
	bool positionLight()const { return m_positionLight; }
	bool frontFogLight()const { return m_frontFogLight; }
	bool rearFogLight()const { return m_rearFogLight; }
	bool engineOilLight()const { return m_engineOilLight; }
	bool nightVisionLight()const { return m_nightVisionLight; }
	bool sysBattErr()const { return m_sysBattErr; }
	bool mainErr()const { return m_mainErr; }
	bool espLightFlick()const { return m_espLightFlick; }
	uint fLTirePress()const { return m_fLTirePress; }
	uint fRTirePress()const { return m_fRTirePress; }
	uint rLTirePress()const { return m_rLTirePress; }
	uint rRTirePress()const { return m_rRTirePress; }
	uint fLTireTemp()const { return m_fLTireTemp; }
	uint fRTireTemp()const { return m_fRTireTemp; }
	uint rLTireTemp()const { return m_rLTireTemp; }
	uint rRTireTemp()const { return m_rRTireTemp; }
	uint fm()const { return m_fm; }
	uint am()const { return m_am; }
	uint programNum()const { return m_programNum; }
	uint soundMode()const { return m_soundMode; }

	QString fontName()const { return m_fontName; }
	WARNING_TIPS errType()const { return m_errType; }
	FUNCTION_EVENT functionTypes()const { return m_functionTypes; }

	Q_INVOKABLE void startTime();
	Q_INVOKABLE void stopTime();
	Q_INVOKABLE void showCheckErr();

	// MobileInfo
	void setNameLen(uint);
	void setName(QString);
	void setNumTypes(uint);
	void setNumLen(uint);
	void setNumber(QString);

	// SettingsInfo
	void setCommandReq(bool);
	void setCloseReq(bool);
	void setTripClean(bool);
	void setAverageSpeedClean(bool);
	void setAverageFuelClean(bool);
	void setEngineerMode(bool);
	void setDateTime(uint);

	// SpecialInfo
	void setBrakeSysErr(bool);
	void setPowerSteerErr(bool);
	void setFLTirePressLeak(bool);
	void setFRTirePressLeak(bool);
	void setRLTirePressLeak(bool);
	void setRRTirePressLeak(bool);
	void setFLTirePressMoreInfo(bool);
	void setFRTirePressMoreInfo(bool);
	void setRLTirePressMoreInfo(bool);
	void setRRTirePressMoreInfo(bool);
	void setEngineControlErr(bool);
	void setGearboxToohot(bool);
	void setGearboxErr(bool);
	void setAccAutoOff(bool);
	void setAbaErr(bool);
	void setFcwErr(bool);
	void setAbsErr(bool);
	void setHydraulicSysErr(bool);
	void setEspErr(bool);
	void setTcsErr(bool);
	void setCoolSysErr(bool);
	void setFluidToolow(bool);
	void setEngineOilErr(bool);
	void setEpbErr(bool);
	void setAutoHoldErr(bool);
	void setAccErr(bool);
	void setPdcErr(bool);
	void setCheckAlternator(bool);
	void setChangeBrakePads(bool);
	void setOverSpeedLimit(bool);
	void setFLTirePressInfo(bool);
	void setFRTirePressInfo(bool);
	void setRLTirePressInfo(bool);
	void setRRTirePressInfo(bool);
	void setAirbagErr(bool);
	void setRefrigerantLow(bool);
	void setAccActiveErr(bool);
	void setSetCruise(bool);
	void setLdwErr(bool);
	void setEmissionSysErr(bool);
	void setPassiveEntrySysErr(bool);
	void setFLTirePressMonitorErr(bool);
	void setFRTirePressMonitorErr(bool);
	void setRLTirePressMonitorErr(bool);
	void setRRTirePressMonitorErr(bool);
	void setLFTurnLightErr(bool);
	void setRFTurnLightErr(bool);
	void setLRTurnLightErr(bool);
	void setRRTurnLightErr(bool);
	void setLRGroupLightErr(bool);
	void setRRGroupLightErr(bool);
	void setBackupLightErr(bool);
	void setNightVisionErr(bool);
	void setAfsErr(bool);
	void setStartAndStopSysErr(bool);
	void setHeadlampAdjustErr(bool);
	void setRefillFuel(bool);
	void setAutoLightsWiperErr(bool);
	void setCameraBlocked(bool);
	void setRaderBlockHotErr(bool);
	void setLFLightErr(bool);
	void setRFLightErr(bool);
	void setLFPositionLightErr(bool);
	void setRFPositionLightErr(bool);
	void setLFFogLightErr(bool);
	void setRFFogLightErr(bool);
	void setLicenseLightErr(bool);
	void setIgnitionSwitchErr(bool);
	void setUnknownKey(bool);
	void setFourWDSysErr(bool);
	void setScmSysErr(bool);
	void setAccClose(bool);
	void setKeyBatLow(bool);
	void setRefillCleanFluid(bool);
	void setSeatAdjustErr(bool);
	void setXkmBeforeMaintenance(bool);
	void setBluetoothMicrophoneErr(bool);
	void setBluetoothSwitchErr(bool);
	void setBluetoothAudioLineErr(bool);
	void setSteeringColumnLockErr(bool);
	void setInstrumentClusterErr(bool);
	void setLdwClose(bool);
	void setAfsClose(bool);
	void setEspClose(bool);
	void setAbaActiveErr(bool);
	void setFcwCloseErr(bool);
	void setAbaCloseErr(bool);
	void setAbaIndicator(bool);
	void setAvh(bool);
	void setStopAndGoIndicator(uint);
	void setParkingCarUi(bool);
	void setRearRightRadarFlicker(bool);
	void setRearCentreRRadarFlicker(bool);
	void setRearCentreLRadarFlicker(bool);
	void setRearLeftRadarFlicker(bool);
	void setFrontRightRadarFlicker(bool);
	void setFrontCentreRRadarFlicker(bool);
	void setFrontCentreLRadarFlicker(bool);
	void setFrontLeftRadarFlicker(bool);
	void setFrontLeftRadarLevel(uint);
	void setFrontCentreLRadarLevel(uint);
	void setFrontCentreRRadarLevel(uint);
	void setFrontRightRadarLevel(uint);
	void setRearRightRadarLevel(uint);
	void setRearCentreRRadarLevel(uint);
	void setRearCentreLRadarLevel(uint);
	void setRearLeftRadarLevel(uint);
	void setFcwNotice(bool);
	void setFcwMoreNotice(bool);
	void setLkpMoreRest(bool);
	void setLkpRest(bool);
	void setShift2P(bool);
	void setSlopeTooHigh(bool);
	void setBrakingPowerLow(bool);
	void setKeyInCar(bool);
	void setKeyInTrunk(bool);
	void setKeyStatus2Off(bool);
	void setSteerColumnLock(bool);
	void setBatLowStartEngine(bool);
	void setStartEngineSelf(bool);
	void setShift2PN(bool);
	void setLPress2Start24s(bool);
	void setLampON(bool);
	void setAccUI(bool);
	void setAccIndicator(uint);
	void setAccFlicker(bool);
	void setFrontCarDistanceLevel(uint);
	void setFrontCarFlicker(bool);
	void setFrontCarSpeed(uint);
	void setAccRecovery(bool);
	void setFrontCarStatus(uint);
	void setCcsSet(bool);
	void setCcsIndicator(uint);
	void setCcsSpeed(uint);
	void setLdwOn(bool);
	void setLdwIndicator(uint);
	void setLdwFlicker(bool);
	void setLdwLeftIndicator(uint);
	void setLdwRightIndicator(uint);
	void setBluetoothStatus(uint);
	void setBatValue(uint);
	void setMobileSingel(uint);
	void setHighBeamLight(bool);
	void setPositionLight(bool);
	void setFrontFogLight(bool);
	void setRearFogLight(bool);
	void setEngineOilLight(bool);
	void setNightVisionLight(bool);
	void setSysBattErr(bool);
	void setMainErr(bool);
	void setEspLightFlick(bool);
	void setFLTirePress(uint);
	void setFRTirePress(uint);
	void setRLTirePress(uint);
	void setRRTirePress(uint);
	void setFLTireTemp(uint);
	void setFRTireTemp(uint);
	void setRLTireTemp(uint);
	void setRRTireTemp(uint);
	void setFm(uint);
	void setAm(uint);
	void setProgramNum(uint);
	void setSoundMode(uint);

	void setFontName(QString fontname) { m_fontName = fontname; emit fontNameChanged(m_fontName);}

#ifdef HONGQI_DEBUG
	Q_INVOKABLE void sendUpFrame();
#endif
	void setSerial(void);
protected:

#ifdef TIMER_FREQ
	void timerEvent(QTimerEvent *event);
#endif
signals:
	// MobileInfo
	void nameLenChanged(uint);
	void nameChanged(QString);
	void numTypesChanged(uint);
	void numLenChanged(uint);
	void numberChanged(QString);

	// SettingsInfo
	void commandReqChanged(bool);
	void closeReqChanged(bool);
	void tripCleanChanged(bool);
	void averageSpeedCleanChanged(bool);
	void averageFuelCleanChanged(bool);
	void engineerModeChanged(bool);
	void dateTimeChanged(uint);

	// SpecialInfo
	void brakeSysErrChanged(bool);
	void powerSteerErrChanged(bool);
	void fLTirePressLeakChanged(bool);
	void fRTirePressLeakChanged(bool);
	void rLTirePressLeakChanged(bool);
	void rRTirePressLeakChanged(bool);
	void fLTirePressMoreInfoChanged(bool);
	void fRTirePressMoreInfoChanged(bool);
	void rLTirePressMoreInfoChanged(bool);
	void rRTirePressMoreInfoChanged(bool);
	void engineControlErrChanged(bool);
	void gearboxToohotChanged(bool);
	void gearboxErrChanged(bool);
	void accAutoOffChanged(bool);
	void abaErrChanged(bool);
	void fcwErrChanged(bool);
	void absErrChanged(bool);
	void hydraulicSysErrChanged(bool);
	void espErrChanged(bool);
	void tcsErrChanged(bool);
	void coolSysErrChanged(bool);
	void fluidToolowChanged(bool);
	void engineOilErrChanged(bool);
	void epbErrChanged(bool);
	void autoHoldErrChanged(bool);
	void accErrChanged(bool);
	void pdcErrChanged(bool);
	void checkAlternatorChanged(bool);
	void changeBrakePadsChanged(bool);
	void overSpeedLimitChanged(bool);
	void fLTirePressInfoChanged(bool);
	void fRTirePressInfoChanged(bool);
	void rLTirePressInfoChanged(bool);
	void rRTirePressInfoChanged(bool);
	void airbagErrChanged(bool);
	void refrigerantLowChanged(bool);
	void accActiveErrChanged(bool);
	void setCruiseChanged(bool);
	void ldwErrChanged(bool);
	void emissionSysErrChanged(bool);
	void passiveEntrySysErrChanged(bool);
	void fLTirePressMonitorErrChanged(bool);
	void fRTirePressMonitorErrChanged(bool);
	void rLTirePressMonitorErrChanged(bool);
	void rRTirePressMonitorErrChanged(bool);
	void lFTurnLightErrChanged(bool);
	void rFTurnLightErrChanged(bool);
	void lRTurnLightErrChanged(bool);
	void rRTurnLightErrChanged(bool);
	void lRGroupLightErrChanged(bool);
	void rRGroupLightErrChanged(bool);
	void backupLightErrChanged(bool);
	void nightVisionErrChanged(bool);
	void afsErrChanged(bool);
	void startAndStopSysErrChanged(bool);
	void headlampAdjustErrChanged(bool);
	void refillFuelChanged(bool);
	void autoLightsWiperErrChanged(bool);
	void cameraBlockedChanged(bool);
	void raderBlockHotErrChanged(bool);
	void lFLightErrChanged(bool);
	void rFLightErrChanged(bool);
	void lFPositionLightErrChanged(bool);
	void rFPositionLightErrChanged(bool);
	void lFFogLightErrChanged(bool);
	void rFFogLightErrChanged(bool);
	void licenseLightErrChanged(bool);
	void ignitionSwitchErrChanged(bool);
	void unknownKeyChanged(bool);
	void fourWDSysErrChanged(bool);
	void scmSysErrChanged(bool);
	void accCloseChanged(bool);
	void keyBatLowChanged(bool);
	void refillCleanFluidChanged(bool);
	void seatAdjustErrChanged(bool);
	void xkmBeforeMaintenanceChanged(bool);
	void bluetoothMicrophoneErrChanged(bool);
	void bluetoothSwitchErrChanged(bool);
	void bluetoothAudioLineErrChanged(bool);
	void steeringColumnLockErrChanged(bool);
	void instrumentClusterErrChanged(bool);
	void ldwCloseChanged(bool);
	void afsCloseChanged(bool);
	void espCloseChanged(bool);
	void abaActiveErrChanged(bool);
	void fcwCloseErrChanged(bool);
	void abaCloseErrChanged(bool);
	void abaIndicatorChanged(bool);
	void avhChanged(bool);
	void stopAndGoIndicatorChanged(uint);
	void parkingCarUiChanged(bool);
	void rearRightRadarFlickerChanged(bool);
	void rearCentreRRadarFlickerChanged(bool);
	void rearCentreLRadarFlickerChanged(bool);
	void rearLeftRadarFlickerChanged(bool);
	void frontRightRadarFlickerChanged(bool);
	void frontCentreRRadarFlickerChanged(bool);
	void frontCentreLRadarFlickerChanged(bool);
	void frontLeftRadarFlickerChanged(bool);
	void frontLeftRadarLevelChanged(uint);
	void frontCentreLRadarLevelChanged(uint);
	void frontCentreRRadarLevelChanged(uint);
	void frontRightRadarLevelChanged(uint);
	void rearRightRadarLevelChanged(uint);
	void rearCentreRRadarLevelChanged(uint);
	void rearCentreLRadarLevelChanged(uint);
	void rearLeftRadarLevelChanged(uint);
	void fcwNoticeChanged(bool);
	void fcwMoreNoticeChanged(bool);
	void lkpMoreRestChanged(bool);
	void lkpRestChanged(bool);
	void shift2PChanged(bool);
	void slopeTooHighChanged(bool);
	void brakingPowerLowChanged(bool);
	void keyInCarChanged(bool);
	void keyInTrunkChanged(bool);
	void keyStatus2OffChanged(bool);
	void steerColumnLockChanged(bool);
	void batLowStartEngineChanged(bool);
	void startEngineSelfChanged(bool);
	void shift2PNChanged(bool);
	void lPress2Start24sChanged(bool);
	void lampONChanged(bool);
	void accUIChanged(bool);
	void accIndicatorChanged(uint);
	void accFlickerChanged(bool);
	void frontCarDistanceLevelChanged(uint);
	void frontCarFlickerChanged(bool);
	void frontCarSpeedChanged(uint);
	void accRecoveryChanged(bool);
	void frontCarStatusChanged(uint);
	void ccsSetChanged(bool);
	void ccsIndicatorChanged(uint);
	void ccsSpeedChanged(uint);
	void ldwOnChanged(bool);
	void ldwIndicatorChanged(uint);
	void ldwFlickerChanged(bool);
	void ldwLeftIndicatorChanged(uint);
	void ldwRightIndicatorChanged(uint);
	void bluetoothStatusChanged(uint);
	void batValueChanged(uint);
	void mobileSingelChanged(uint);
	void highBeamLightChanged(bool);
	void positionLightChanged(bool);
	void frontFogLightChanged(bool);
	void rearFogLightChanged(bool);
	void engineOilLightChanged(bool);
	void nightVisionLightChanged(bool);
	void sysBattErrChanged(bool);
	void mainErrChanged(bool);
	void espLightFlickChanged(bool);
	void fLTirePressChanged(uint);
	void fRTirePressChanged(uint);
	void rLTirePressChanged(uint);
	void rRTirePressChanged(uint);
	void fLTireTempChanged(uint);
	void fRTireTempChanged(uint);
	void rLTireTempChanged(uint);
	void rRTireTempChanged(uint);
	void fmChanged(uint);
	void amChanged(uint);
	void programNumChanged(uint);
	void soundModeChanged(uint);

	// tips
	void errTypeChanged(WARNING_TIPS);
	void functionTypesChanged(FUNCTION_EVENT);
	void fontNameChanged(QString);

private slots:
	void getGeneralSerial(GeneralInfo data);
	void getSpecialSerial(SpecialInfo data);
	void getMobileSerial(MobileInfo data);

	void updateERR();
	void updateFunction();
	void dealCheckKey();

private:
	void initValues();
	// MobileInfo
	uint m_nameLen;
	QString m_name;
	uint m_numTypes;
	uint m_numLen;
	QString m_number;

	// SettingsInfo
	bool m_commandReq;
	bool m_closeReq;
	bool m_tripClean;
	bool m_averageSpeedClean;
	bool m_averageFuelClean;
	bool m_engineerMode;
	uint m_dateTime;

	bool m_tripCleanFlag;


	// SpecialInfo
	bool m_brakeSysErr;
	bool m_powerSteerErr;
	bool m_fLTirePressLeak;
	bool m_fRTirePressLeak;
	bool m_rLTirePressLeak;
	bool m_rRTirePressLeak;
	bool m_fLTirePressMoreInfo;
	bool m_fRTirePressMoreInfo;
	bool m_rLTirePressMoreInfo;
	bool m_rRTirePressMoreInfo;
	bool m_engineControlErr;
	bool m_gearboxToohot;
	bool m_gearboxErr;
	bool m_accAutoOff;
	bool m_abaErr;
	bool m_fcwErr;
	bool m_absErr;
	bool m_hydraulicSysErr;
	bool m_espErr;
	bool m_tcsErr;
	bool m_coolSysErr;
	bool m_fluidToolow;
	bool m_engineOilErr;
	bool m_epbErr;
	bool m_autoHoldErr;
	bool m_accErr;
	bool m_pdcErr;
	bool m_checkAlternator;
	bool m_changeBrakePads;
	bool m_overSpeedLimit;
	bool m_fLTirePressInfo;
	bool m_fRTirePressInfo;
	bool m_rLTirePressInfo;
	bool m_rRTirePressInfo;
	bool m_airbagErr;
	bool m_refrigerantLow;
	bool m_accActiveErr;
	bool m_setCruise;
	bool m_ldwErr;
	bool m_emissionSysErr;
	bool m_passiveEntrySysErr;
	bool m_fLTirePressMonitorErr;
	bool m_fRTirePressMonitorErr;
	bool m_rLTirePressMonitorErr;
	bool m_rRTirePressMonitorErr;
	bool m_lFTurnLightErr;
	bool m_rFTurnLightErr;
	bool m_lRTurnLightErr;
	bool m_rRTurnLightErr;
	bool m_lRGroupLightErr;
	bool m_rRGroupLightErr;
	bool m_backupLightErr;
	bool m_nightVisionErr;
	bool m_afsErr;
	bool m_startAndStopSysErr;
	bool m_headlampAdjustErr;
	bool m_refillFuel;
	bool m_autoLightsWiperErr;
	bool m_cameraBlocked;
	bool m_raderBlockHotErr;
	bool m_lFLightErr;
	bool m_rFLightErr;
	bool m_lFPositionLightErr;
	bool m_rFPositionLightErr;
	bool m_lFFogLightErr;
	bool m_rFFogLightErr;
	bool m_licenseLightErr;
	bool m_ignitionSwitchErr;
	bool m_unknownKey;
	bool m_fourWDSysErr;
	bool m_scmSysErr;
	bool m_accClose;
	bool m_keyBatLow;
	bool m_refillCleanFluid;
	bool m_seatAdjustErr;
	bool m_xkmBeforeMaintenance;
	bool m_bluetoothMicrophoneErr;
	bool m_bluetoothSwitchErr;
	bool m_bluetoothAudioLineErr;
	bool m_steeringColumnLockErr;
	bool m_instrumentClusterErr;
	bool m_ldwClose;
	bool m_afsClose;
	bool m_espClose;
	bool m_abaActiveErr;
	bool m_fcwCloseErr;
	bool m_abaCloseErr;
	bool m_abaIndicator;
	bool m_avh;
	uint m_stopAndGoIndicator;
	bool m_parkingCarUi;
	bool m_rearRightRadarFlicker;
	bool m_rearCentreRRadarFlicker;
	bool m_rearCentreLRadarFlicker;
	bool m_rearLeftRadarFlicker;
	bool m_frontRightRadarFlicker;
	bool m_frontCentreRRadarFlicker;
	bool m_frontCentreLRadarFlicker;
	bool m_frontLeftRadarFlicker;
	uint m_frontLeftRadarLevel;
	uint m_frontCentreLRadarLevel;
	uint m_frontCentreRRadarLevel;
	uint m_frontRightRadarLevel;
	uint m_rearRightRadarLevel;
	uint m_rearCentreRRadarLevel;
	uint m_rearCentreLRadarLevel;
	uint m_rearLeftRadarLevel;
	bool m_fcwNotice;
	bool m_fcwMoreNotice;
	bool m_lkpMoreRest;
	bool m_lkpRest;
	bool m_shift2P;
	bool m_slopeTooHigh;
	bool m_brakingPowerLow;
	bool m_keyInCar;
	bool m_keyInTrunk;
	bool m_keyStatus2Off;
	bool m_steerColumnLock;
	bool m_batLowStartEngine;
	bool m_startEngineSelf;
	bool m_shift2PN;
	bool m_lPress2Start24s;
	bool m_lampON;
	bool m_accUI;
	uint m_accIndicator;
	bool m_accFlicker;
	uint m_frontCarDistanceLevel;
	bool m_frontCarFlicker;
	uint m_frontCarSpeed;
	bool m_accRecovery;
	uint m_frontCarStatus;
	bool m_ccsSet;
	uint m_ccsIndicator;
	uint m_ccsSpeed;
	bool m_ldwOn;
	uint m_ldwIndicator;
	bool m_ldwFlicker;
	uint m_ldwLeftIndicator;
	uint m_ldwRightIndicator;
	uint m_bluetoothStatus;
	uint m_batValue;
	uint m_mobileSingel;
	bool m_highBeamLight;
	bool m_positionLight;
	bool m_frontFogLight;
	bool m_rearFogLight;
	bool m_engineOilLight;
	bool m_nightVisionLight;
	bool m_sysBattErr;
	bool m_mainErr;
	bool m_espLightFlick;
	uint m_fLTirePress;
	uint m_fRTirePress;
	uint m_rLTirePress;
	uint m_rRTirePress;
	uint m_fLTireTemp;
	uint m_fRTireTemp;
	uint m_rLTireTemp;
	uint m_rRTireTemp;
	uint m_fm;
	uint m_am;
	uint m_programNum;
	uint m_soundMode;
	QString m_fontName;

	WARNING_TIPS m_errType;
	FUNCTION_EVENT m_functionTypes;

	void insertList(QList<uint> *list, uint idn);
	void removeList(QList<uint> *list, uint idn);
	uint popList(QList<uint> *list);

	void dealErrList(bool isInsert, WARNING_TIPS errType);
	void dealFunctionList(bool isInsert, FUNCTION_EVENT functionType);

	QList<uint>	m_functionList;
	QList<uint>	m_preTipList;
	QList<uint>	m_tipedList;
	bool m_isTipedList;

	QTimer *m_timer;
	QTimer *m_functionTimer;
	QTimer *m_checkTimer;
	int m_checkIndex;
};

#endif // HONGQICARSTATUS_H
