#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define GOLDEN_RATIO_PRIME_32 0x9e370001U
#define STR4_HASH(a,b,c,d)	(((a)<<24)|((b)<<16)|((c)<<8)|(d))*GOLDEN_RATIO_PRIME_32

#define MAGIC_UPDATE	STR4_HASH('U','P','D','T')
#define MAGIC_GENERAL	STR4_HASH('G','E','N','E')
#define MAGIC_SPECIAL	STR4_HASH('S','P','E','C')
#define MAGIC_SETTINGS	STR4_HASH('S','E','T','S')
#define MAGIC_MOBILE	STR4_HASH('M','O','B','L')
#define MAGIC_INVALID	STR4_HASH('I','N','V','A')

#define MAGIC_LEN	4


#if MAGIC_UPDATE== MAGIC_GENERAL || MAGIC_UPDATE== MAGIC_SPECIAL || MAGIC_UPDATE == MAGIC_SETTINGS || MAGIC_UPDATE == MAGIC_MOBILE || MAGIC_UPDATE == MAGIC_INVALID ||\
	MAGIC_GENERAL== MAGIC_SPECIAL || MAGIC_GENERAL == MAGIC_SETTINGS || MAGIC_GENERAL == MAGIC_MOBILE || MAGIC_GENERAL == MAGIC_INVALID ||\
	MAGIC_SPECIAL == MAGIC_SETTINGS || MAGIC_SPECIAL == MAGIC_MOBILE || MAGIC_SPECIAL == MAGIC_INVALID ||\
	MAGIC_SETTINGS == MAGIC_MOBILE || MAGIC_SETTINGS == MAGIC_INVALID ||\
	MAGIC_MOBILE == MAGIC_INVALID

#error "Magic hash conflicts"

#endif

/*
 * frame sent GeneralInfo by MCU
 */
typedef struct {
	uint8_t head;
	uint8_t length;
	uint16_t crc;
	uint32_t magic;
}__attribute__((packed)) MagicFrame;

/*
 * general car information
 */
typedef struct {
	uint16_t hwVer: 3,
		releaseVer: 5,
		betaVer: 8;
	uint16_t rpm;//转数
	uint32_t time;//日期时间
	uint8_t speed;//车速
	uint8_t  temprature;//水温表
	uint8_t  key0: 1,
		key1: 1,
		key2: 1,
		key3: 1,
		key4: 1,
		key5: 1,
		key6: 1,
		key7: 1;
	uint8_t gear: 4,//档位信息 P  1 2 3 4 5 6 7 N R
		gearMode: 2,//档位模式 D S M
		keyStatus: 2;//钥匙状态
	uint8_t leftFrontDoor: 1,//前左门状态
		rightFrontDoor: 1,//前右门状态
		leftRearDoor: 1,//后左门状态
		rightRearDoor: 1,//后右门状态
		hoodDoor: 1,//引擎盖状态
		trunkDoor: 1,//行李箱状态
		remain2: 2;
	uint32_t odo: 24,//总里程
		averageSpeed: 8;//平均车速
	uint8_t averageFuelUint: 1,//平均油耗Uint
		instantaneousFuelUint: 1,//瞬时油耗 Uint;
		remain3: 6;
	uint16_t remainMileage;//续航里程
	uint32_t trip1: 24,//小计里程1
		fuel: 8;//燃油量
	uint32_t trip2: 24,//续航里程
		soc: 8;//电量SOC
	uint16_t maintenanceMileage;//保养里程
	uint16_t outTemprature;//车外温度
	uint16_t averageFuel;//平均油耗
	uint16_t instantaneousFuel;//瞬时油耗
	uint16_t batteryCurrent;//动力电池电流
	uint16_t batteryVoltage;//动力电池电压
}__attribute__((packed)) GeneralInfo;

/*
 * special car information
 */
typedef struct {
	uint8_t	brakeSysErr: 1,//制动系统严重故障!
		powerSteerErr: 1,//电液助力转向功能故障!
		fLTirePressLeak: 1,//前左轮胎漏气
		fRTirePressLeak: 1,//前右轮胎漏气
		rLTirePressLeak: 1,//后左轮胎漏气
		rRTirePressLeak: 1,//后右轮胎漏气
		fLTirePressMoreInfo: 1,//前左轮胎压力提示信息,重度
		fRTirePressMoreInfo: 1;//前右轮胎压力提示信息,重度
	uint8_t	rLTirePressMoreInfo: 1,//后左轮胎压力提示信息,重度
		rRTirePressMoreInfo: 1,//后右轮胎压力提示信息,重度
		engineControlErr: 1,//发动机控制系统故障
		gearboxToohot: 1,//变速器温度过高
		gearboxErr: 1,//变速器故障
		accAutoOff: 1,//ACC 自动解除!
		abaErr: 1,//主动制动辅助功能故障!
		fcwErr: 1;//前碰撞预警功能故障!
	uint8_t	absErr: 1,//ABS 故障
		hydraulicSysErr: 1,//液压辅助真空助力器制动系统故障
		espErr: 1,//ESP 故障
		tcsErr: 1,//TCS 故障
		coolSysErr: 1,//冷却系统故障
		fluidToolow: 1,//制动液液位过低
		engineOilErr: 1,//机油压力故障
		epbErr: 1;//EPB 故障！
	uint8_t autoHoldErr: 1,//AUTO HOLD 功能故障
		accErr: 1,//ACC 故障!
		pdcErr: 1,//PDC 故障，无法启用
		checkAlternator: 1,//请检查发电系统
		changeBrakePads: 1,//请更换制动摩擦片
		overSpeedLimit: 1,//已超过设定车速
		fLTirePressInfo: 1,//前左轮胎压力提示信息,轻度
		fRTirePressInfo: 1;//前右轮胎压力提示信息,轻度
	uint8_t	rLTirePressInfo: 1,//后左轮胎压力提示信息,轻度
		rRTirePressInfo: 1,//后右轮胎压力提示信息,轻度
		airbagErr: 1,//安全气囊系统故障
		refrigerantLow: 1,//制冷剂不足
		accActiveErr: 1,//ACC 不能激活!
		setCruise: 1,//请按下‘SET-’设定巡航！
		ldwErr: 1,//LDW 故障！
		emissionSysErr: 1;//废气监控系统故障！
	uint8_t passiveEntrySysErr: 1,//智能进入系统故障！
		fLTirePressMonitorErr: 1,//前左胎压监测功能失效！
		fRTirePressMonitorErr: 1,//前右胎压监测功能失效！
		rLTirePressMonitorErr: 1,//后左胎压监测功能失效！
		rRTirePressMonitorErr: 1,//后右胎压监测功能失效！
		lFTurnLightErr: 1,//左前转向灯故障
		rFTurnLightErr: 1,//右前转向灯故障
		lRTurnLightErr: 1;//左后转向灯故障
	uint8_t	rRTurnLightErr: 1,//右后转向灯故障
		lRGroupLightErr: 1,//左后组合灯故障
		rRGroupLightErr: 1,//右后组合灯故障
		backupLightErr: 1,//倒车灯故障
		nightVisionErr: 1,//夜视功能故障！
		afsErr: 1,//AFS 故障！
		startAndStopSysErr: 1,//起停系统故障
		headlampAdjustErr: 1;//前照灯照明距离调节故障！
	uint8_t	refillFuel: 1,//请加油！
		autoLightsWiperErr: 1,//自动行车灯/自动刮水功能故障
		cameraBlocked: 1,//摄像头被遮挡，请清洁风窗玻璃！
		raderBlockHotErr: 1,//雷达被遮挡或雷达温度过高!
		lFLightErr: 1,//左前照灯故障
		rFLightErr: 1,//右前照灯故障
		lFPositionLightErr: 1,//左前位置灯故障
		rFPositionLightErr: 1;//右前位置灯故障
	uint8_t	lFFogLightErr: 1,//左前雾灯故障
		rFFogLightErr: 1,//右前雾灯故障
		licenseLightErr: 1,//牌照灯故障
		ignitionSwitchErr: 1,//点火开关故障！
		unknownKey: 1,//不能识别钥匙
		fourWDSysErr: 1,//四驱系统故障
		scmSysErr: 1,//转向柱电动可调系统故障！
		accClose: 1;//ACC 已关闭！
	uint8_t	keyBatLow: 1,//钥匙电池电量不足
		refillCleanFluid: 1,//请添加清洗液
		seatAdjustErr: 1,//座椅记忆（调整）功能故障
		xkmBeforeMaintenance: 1,//距保养还有××× km/请保养
		bluetoothMicrophoneErr: 1,//麦克风短路或开路
		bluetoothSwitchErr: 1,//蓝牙开关短路或开路
		bluetoothAudioLineErr: 1,//蓝牙音频线短路
		steeringColumnLockErr: 1;//转向柱锁功能故障
	uint8_t instrumentClusterErr: 1,//仪表故障！
		ldwClose: 1,//LDW 已关闭！
		afsClose: 1,//AFS 已关闭！
		espClose: 1,//ESP 已关闭！
		abaActiveErr: 1, //主动制动辅助功能不可用
		fcwCloseErr: 1,//前碰撞预警功能已关闭!
		abaCloseErr:1, //主动制动辅助功能已关闭!
		remain1:1;
	uint8_t abaIndicator: 1,//主动制动辅助报警信息符号显示
		avh: 1,//AVH 功能起作用
		stopAndGoIndicator: 2,//起停功能符号显示
		remain2: 4;
	uint16_t parkingCarUi: 1,//泊车系统界面
		rearRightRadarFlicker: 1,//后右雷达闪烁功能激活
		rearCentreRRadarFlicker: 1,//后中右雷达闪烁功能激活
		rearCentreLRadarFlicker: 1,//后中左雷达闪烁功能激活
		rearLeftRadarFlicker: 1,//后左雷达闪烁功能激活
		frontRightRadarFlicker: 1,//前右雷达闪烁功能激活
		frontCentreRRadarFlicker: 1,//前中右雷达闪烁功能激活
		frontCentreLRadarFlicker: 1,//前中左雷达闪烁功能激活
		frontLeftRadarFlicker: 1,//前左雷达闪烁功能激活
		remain3: 7;
	uint32_t frontLeftRadarLevel: 4,//前左雷达级别
		frontCentreLRadarLevel: 4,//前中左雷达级别
		frontCentreRRadarLevel: 4,//前中右雷达级别
		frontRightRadarLevel: 4,//后左雷达级别后左雷达级别
		rearRightRadarLevel: 4,//后右雷达级别
		rearCentreRRadarLevel: 4,//后中右雷达级别
		rearCentreLRadarLevel: 4,//后中左雷达级别
		rearLeftRadarLevel: 4;//后左雷达级别
	uint8_t fcwNotice: 1,//前碰撞预警进入警戒状态或即将发生碰撞的界面-碰撞等级为警戒状态(动画 0.4秒闪烁)
		fcwMoreNotice: 1,//前碰撞预警进入警戒状态或即将发生碰撞的界面-即将发生碰撞（动画 0.2S闪烁）
		lkpMoreRest: 1, //驾驶员状态严重异常界面
		lkpRest: 1, //驾驶员状态轻微异常界面
		shift2P: 1,//请挂入 P 档
		slopeTooHigh: 1,//坡度过大，不宜停车
		brakingPowerLow: 1,//制动力不足
		keyInCar: 1;//钥匙在车内
	uint8_t keyInTrunk: 1,//钥匙在行李箱内
		keyStatus2Off: 1,//请置起动开关于‘OFF"！
		steerColumnLock: 1,//转向柱锁未解除！
		batLowStartEngine: 1,//蓄电池电量低，请起动发动机
		startEngineSelf: 1,//请手动起动发动机
		shift2PN: 1,//踩下制动踏板并挂入 P/N 档，方可起动！
		lPress2Start24s: 1,//长按起动开关方可起动，请前往 4S 店检修！
		lampON: 1;//照明已开启
	uint8_t accUI: 1,//ACC 显示界面
		accIndicator: 2,//主动巡航指示符号
		accFlicker: 1,//主动巡航指示符号是否闪烁
		frontCarDistanceLevel: 3,//跟车距离级别
		frontCarFlicker: 1;//目标车速是否闪烁
	uint8_t frontCarSpeed;//目标车速
	uint8_t accRecovery: 1,//轻踩油门或按 RESUME 恢复巡航
		frontCarStatus: 2,//前方车辆状态
		remain4: 1,
		ccsSet: 1, //定速巡航车速设置界面
		ccsIndicator: 2, //定速巡航指示符号
		remain5: 1;
	uint8_t ccsSpeed; //定速巡航speed
	uint8_t ldwOn: 1, //LDW 报警界面
		ldwIndicator: 2,//LDW指示符号显示
		ldwFlicker: 1,//LDW指示符号闪烁
		ldwLeftIndicator: 2,//LDW左侧指示
		ldwRightIndicator: 2;//LDW右侧指示
	uint8_t bluetoothStatus: 4,//蓝牙通话状态
		batValue: 4;//手机电池电量
	uint8_t mobileSingel: 4,//手机信号级别
		remain6: 4;
	uint8_t highBeamLight: 1,//远光灯状态
		positionLight: 1,//位置灯状态
		frontFogLight: 1,//前雾灯
		rearFogLight: 1,//后雾灯
		engineOilLight: 1,//发动机机油压力故障指示灯
		nightVisionLight: 1,//主动夜视功能指示灯
		sysBattErr: 1,//充电故障指示灯
		mainErr: 1;//主报警指示灯
	uint8_t espLightFlick: 1,//espLightFlick
		remain7: 7;
	uint32_t fLTirePress: 8,//前左胎压
		fRTirePress: 8,//前右胎压
		rLTirePress: 8,//后左胎压
		rRTirePress: 8;//后右胎压
	uint32_t fLTireTemp: 8,//前左胎温
		fRTireTemp: 8,//前右胎温
		rLTireTemp: 8,//后左胎温
		rRTireTemp: 8;//后右胎温
	uint32_t fm: 8,//FM
		am: 8,//AM
		programNum: 10,//节目编号
		soundMode: 4,//声音模式
		remain8: 2;
}__attribute__((packed)) SpecialInfo;

#define NAMELEN_MAX 8
#define NUMBERLEN_MAX 16
/*
 * special car information
 */
typedef struct {
	uint8_t nameLen;//来电人名字长度
	uint8_t name[NAMELEN_MAX];//来电人名字
	uint8_t numTypes: 3,//来电号码类型
		numLen: 5;//来电号码长度
	uint8_t number[NUMBERLEN_MAX];//来电号码数据
}__attribute__((packed)) MobileInfo;

/*
 * frame sent GeneralInfo by MCU
 */
typedef struct {
	uint8_t head;
	uint8_t length;
	uint16_t crc;
	uint32_t magic;
	GeneralInfo generalInfo;
	uint8_t tail;
}__attribute__((packed)) GeneralFrame;

/*
 * frame sent SpecialInfo by MCU
 */
typedef struct {
	uint8_t head;
	uint8_t length;
	uint16_t crc;
	uint32_t magic;
	SpecialInfo specialInfo;
	uint8_t tail;
}__attribute__((packed)) SpecialFrame;


/*
 * frame sent MobileInfo by MCU
 */
typedef struct {
	uint8_t head;
	uint8_t length;
	uint16_t crc;
	uint32_t magic;
	MobileInfo mobileInfo;
	uint8_t tail;
}__attribute__((packed)) MobileFrame;

/*
 * setting information
 */
typedef struct {
	uint16_t commandReq: 1,
		closeReq: 1,
		tripClean: 1,
		averageSpeedClean: 1,
		averageFuelClean: 1,
		remain1: 1,
		remain2: 1,
		engineerMode: 1,
		remain3: 8;
	uint8_t remain4;
	uint8_t remain5;
	uint32_t dateTime;
}__attribute__((packed)) SettingsInfo;

/*
 * frame sent by ARM
 */
typedef struct {
	uint8_t head;
	uint8_t length;
	uint16_t crc;
	uint32_t magic;
	SettingsInfo settingsInfo;
	uint8_t tail;
}__attribute__((packed)) SettingsFrame;

/*
 * Hongqi version
 */
#define HONGQI_VERSION "V 1.0.0"

/*
 * byte length for frame
 */
#define MAGIC_FRAME_LEN		(const int)(sizeof(MagicFrame))

#define GENERAL_FRAME_LEN	(const int)(sizeof(GeneralFrame))
#define SPECIAL_FRAME_LEN	(const int)(sizeof(SpecialFrame))
#define MOBILE_FRAME_LEN	(const int)(sizeof(MobileFrame))
#define SETTINGS_FRAME_LEN	(const int)(sizeof(SettingsFrame))
#define GENERAL_INFO_LEN	(const int)(sizeof(GeneralInfo))
#define SPECIAL_INFO_LEN	(const int)(sizeof(SpecialInfo))
#define MOBILE_INFO_LEN		(const int)(sizeof(MobileInfo))
#define SETTINGS_INFO_LEN	(const int)(sizeof(SettingsInfo))
/*
 * update frequency for up and down frame
 */
#define SETTINGSFTRAME_FREQ 500
#define DOWNFRAME_FREQ 100

/*
 * baud rate for serial
 */
#define BAUD_RATE QSerialPort::Baud115200
/*
 * crc16 check
 */
uint16_t crc16Check(uint8_t *ptr,uint8_t len);

#endif // PROTOCOL_H
