#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define GOLDEN_RATIO_PRIME_32 0x9e370001U
#define STR4_HASH(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))*GOLDEN_RATIO_PRIME_32

#define MAGIC_UPDATE_UP     STR4_HASH('U','P','U','P')
#define MAGIC_UPDATE_DOWN   STR4_HASH('D','O','U','P')
#define MAGIC_GENERAL_UP    STR4_HASH('U','P','G','E')
#define MAGIC_GENERAL_DOWN  STR4_HASH('D','O','G','E')
#define MAGIC_SPECIAL_UP    STR4_HASH('U','P','S','P')
#define MAGIC_SPECIAL_DOWN  STR4_HASH('D','O','S','P')
#define MAGIC_OTHER_UP      STR4_HASH('U','P','O','T')
#define MAGIC_OTHER_DOWN    STR4_HASH('D','O','O','T')

#define MAGIC_LEN   4

#if ((MAGIC_UPDATE_UP == MAGIC_UPDATE_DOWN)       \
	|| (MAGIC_UPDATE_UP == MAGIC_GENERAL_UP)      \
	|| (MAGIC_UPDATE_UP == MAGIC_GENERAL_DOWN)    \
	|| (MAGIC_UPDATE_UP == MAGIC_SPECIAL_UP)      \
	|| (MAGIC_UPDATE_UP == MAGIC_SPECIAL_DOWN)    \
	|| (MAGIC_UPDATE_UP== MAGIC_OTHER_UP)         \
	|| (MAGIC_UPDATE_UP == MAGIC_OTHER_DOWN)      \
	|| (MAGIC_UPDATE_DOWN == MAGIC_GENERAL_UP)    \
	|| (MAGIC_UPDATE_DOWN == MAGIC_GENERAL_DOWN)  \
	|| (MAGIC_UPDATE_DOWN == MAGIC_SPECIAL_UP)    \
	|| (MAGIC_UPDATE_DOWN == MAGIC_SPECIAL_DOWN)  \
	|| (MAGIC_UPDATE_DOWN == MAGIC_OTHER_UP)      \
	|| (MAGIC_UPDATE_DOWN == MAGIC_OTHER_DOWN)    \
	|| (MAGIC_GENERAL_UP == MAGIC_GENERAL_DOWN)   \
	|| (MAGIC_GENERAL_UP == MAGIC_SPECIAL_UP)     \
	|| (MAGIC_GENERAL_UP == MAGIC_SPECIAL_DOWN)   \
	|| (MAGIC_GENERAL_UP == MAGIC_OTHER_UP)       \
	|| (MAGIC_GENERAL_UP == MAGIC_OTHER_DOWN)     \
	|| (MAGIC_GENERAL_DOWN == MAGIC_SPECIAL_UP)   \
	|| (MAGIC_GENERAL_DOWN == MAGIC_SPECIAL_DOWN) \
	|| (MAGIC_GENERAL_DOWN == MAGIC_OTHER_UP)     \
	|| (MAGIC_GENERAL_DOWN == MAGIC_OTHER_DOWN)   \
	|| (MAGIC_SPECIAL_UP == MAGIC_SPECIAL_DOWN)   \
	|| (MAGIC_SPECIAL_UP == MAGIC_OTHER_UP)       \
	|| (MAGIC_SPECIAL_UP == MAGIC_OTHER_DOWN)     \
	|| (MAGIC_SPECIAL_DOWN == MAGIC_OTHER_UP)     \
	|| (MAGIC_SPECIAL_DOWN == MAGIC_OTHER_DOWN)   \
	|| (MAGIC_OTHER_UP == MAGIC_OTHER_DOWN))

#error "Magic hash conflicts"
#endif

/*
 * magic frame sent by MCU
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
	uint16_t tmpVersion: 8,      // byte0: 0 ~ 7
		relVersion: 5,           // byte0: 8 ~ 12
		hwVersion: 3;            // byte1: 13 ~ 15
	uint16_t rpm;                // byte2: 0 ~ 15
	uint32_t dateTime;           // byte4: 0 ~ 31
	uint8_t speed;               // byte8: 0 ~ 7
	uint8_t waterTemp;           // byte9: 0 ~ 7
	uint8_t key1: 1,             // byte10: 0
		key2: 1,                 // byte10: 1
		key3: 1,                 // byte10: 2
		key4: 1,                 // byte10: 3
		remain1: 3,              // byte10: 4 ~ 6
		igOn: 1;                 // byte10: 7
	uint8_t gear: 4,             // byte11: 0 ~ 3
		gearMode: 2,             // byte11: 4 ~ 5
		keyStatus: 2;            // byte11: 6 ~ 7
	uint8_t lfDoor: 1,           // byte12: 0
		rfDoor: 1,               // byte12: 1
		lrDoor: 1,               // byte12: 2
		rrDoor: 1,               // byte12: 3
		hoodDoor: 1,             // byte12: 4
		trunkDoor: 1,            // byte12: 5
		remain2: 2;              // byte12: 6 ~ 7
	uint32_t odo: 24,            // byte13: 0 ~ 23
		avgSpeed: 8;             // byte16: 24 ~ 31
	uint8_t avgFuelUnit: 1,      // byte17: 0
		instantaneousFuelUnit: 1,// byte17: 1
		remain3: 6;              // byte17: 2 ~ 7
	uint16_t remainMileage;      // byte18: 0 ~ 15
	uint32_t trip1: 24,          // byte20: 0 ~ 23
		fuel: 8;                 // byte23: 24 ~ 31
	uint32_t trip2: 24,          // byte24: 0 ~ 23
		soc: 8;                  // byte27: 24 ~ 31
	uint16_t maintenanceMileage; // byte28: 0 ~ 15
	uint16_t outTemp;            // byte30: 0 ~ 15
	uint16_t avgFuel;            // byte32: 0 ~ 15
	uint16_t instantaneousFuel;  // byte34: 0 ~ 15
	uint16_t batteryCurrent;     // byte36: 0 ~ 15
	uint16_t batteryVoltage;     // byte38: 0 ~ 15
}__attribute__((packed)) GeneralInfo;

/*
 * general frame sent by MCU
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
 * general settings information
 */
typedef struct {
	uint8_t commandReq: 1,      // byte0: 0
		closeReq: 1,            // byte0: 1
		tripClean: 1,           // byte0: 2
		avgSpeedClean: 1,       // byte0: 3
		avgFuelClean: 1,        // byte0: 4
		tripClean2: 1,			// byte0: 5
		remain1: 1,             // byte0: 6
		projectMode: 1;         // byte0: 7
	uint8_t alarmInterface;     // byte1: 0 ~ 7
	uint8_t interfaceSoundSync; // byte2: 0 ~ 7
	uint8_t remain2;            // byte3: 0 ~ 7
	uint32_t dateTimeSet;       // byte4: 0 ~ 31
}__attribute__((packed)) SettingsInfo;

/*
 * general settings frame sent by CORE
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
 * byte length for frame
 */
#define MAGIC_FRAME_LEN     (const int)(sizeof(MagicFrame))
#define GENERAL_INFO_LEN    (const int)(sizeof(GeneralInfo))
#define GENERAL_FRAME_LEN   (const int)(sizeof(GeneralFrame))
#define SETTINGS_INFO_LEN   (const int)(sizeof(SettingsInfo))
#define SETTINGS_FRAME_LEN  (const int)(sizeof(SettingsFrame))

/*
 * update frequency for settings frame
 */
#define SETTINGSFTRAME_FREQ 100

/*
 * baud rate for serial
 */
#define SERIAL_BAUD_RATE QSerialPort::Baud115200

/*
 * crc16 check
 */
uint16_t crc16Check(uint8_t *ptr,uint8_t len);

#endif // PROTOCOL_H
