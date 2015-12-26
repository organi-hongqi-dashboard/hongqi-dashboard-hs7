#ifndef CARNATION_SPE_PROTOCOL_H
#define CARNATION_SPE_PROTOCOL_H

#include <stdint.h>

/*
 * carnation special information
 */
typedef struct {
    uint8_t
        leftHandDrive       : 1,    // byte0: 0
        rightHandDrive      : 1,    // byte0: 1
        highBeam            : 1,    // byte0: 2
        dippedBeam          : 1,    // byte0: 3
        positionLight       : 1,    // byte0: 4
        frontFogLight       : 1,    // byte0: 5
        rearFogLight        : 1,    // byte0: 6
        auxiliaryHighBeam   : 1;    // byte0: 7
    uint8_t
        safetyBeltLight     : 1,    // byte1: 0
        airBagLight         : 1,    // byte1: 1
        engineFaultLight    : 1,    // byte1: 2
        absFault            : 1,    // byte1: 3
        oilPressureLow      : 1,    // byte1: 4
        batteryFaultLight   : 1,    // byte1: 5
        brakeSystemFailure  : 1,    // byte1: 6
        parkingLight        : 1;    // byte1: 7
    uint8_t
        oilLowLight         : 1,    // byte2: 0
        coolantLowLight     : 1,    // byte2: 1
		espLight            : 2,    // byte2: 2 - 3
        afsOffLight         : 1,    // byte2: 4
        milLight            : 1,    // byte2: 5
		gearboxErrLight     : 1,    // byte2: 6
		changeBrakePadsLight: 1;    // byte2: 7
    uint8_t
		electronicParkingLight: 1,    // byte3: 0
		remain2             : 7;    // byte3: 1-7
    uint8_t
        breakSystemPic      : 1,    // byte3: 0
        brakeFluidPic       : 1,    // byte3: 1
        addOilPic           : 1,    // byte3: 2
        batteryFaultPic     : 1,    // byte3: 3
        oilPressureLowPic   : 1,    // byte3: 4
        coolantSystemErrPic : 1,    // byte3: 5
        absFaultPic         : 1,    // byte3: 6
        epbFaultPic         : 1;    // byte3: 7
    uint8_t
        engineCtlFaultPic   : 1,    // byte4: 0
        exhaustEmissionPic  : 1,    // byte4: 1
        espFaultPic         : 1,    // byte4: 2
        airBagFaultPic      : 1,    // byte4: 3
        speedChangerErrPic  : 1,    // byte4: 4
        speedChaTempHighPic : 1,    // byte4: 5    // speed changer temperature high
        coolantHighTempPic  : 1,// byte4: 6
        tcsErrPic             : 1;    // byte4: 7
    uint8_t
        changeBrakeFrontPic    : 1,
        changeBrakeRearPic     :1,
        remain4             : 6;    // byte4: 6 - 7
}__attribute__((packed)) SpecialInfo;

/*
 * special frame sent by MCU
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
 * special settings information
 */
typedef struct {

}__attribute__((packed)) SpecSettingsInfo;

/*
 * special settings frame sent by CORE
 */
typedef struct {
    uint8_t head;
    uint8_t length;
    uint16_t crc;
    uint32_t magic;
    SpecSettingsInfo specSettingsInfo;
    uint8_t tail;
}__attribute__((packed)) SpecSettingsFrame;

/*
 * byte length for frame
 */
#define SPECIAL_INFO_LEN       (const int)(sizeof(SpecialInfo))
#define SPECIAL_FRAME_LEN      (const int)(sizeof(SpecialFrame))
#define SPECSETTINGS_INFO_LEN  (const int)(sizeof(SpecSettingsInfo))
#define SPECSETTINGS_FRAME_LEN (const int)(sizeof(SpecSettingsFrame))

/*
 * app version
 */
#define CARNATION_APP_VERSION   "1.0.0"

#endif // CARNATION_SPE_PROTOCOL_H
