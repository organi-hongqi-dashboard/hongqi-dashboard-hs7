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
        brakeSystemFailure  : 1,    // byte0: 2
        chargeFault         : 1,    // byte0: 3
        oilPressureLow      : 1,    // byte0: 4
        absFault            : 1,    // byte0: 5
        epbFault            : 1,    // byte0: 6
        engineFault         : 1;    // byte0: 7
    uint8_t
        milFault            : 1,    // byte1: 0
        espFault            : 1,    // byte1: 1
        srsFault            : 1,    // byte1: 2
        gearBoxFault        : 1,    // byte1: 3
        remain1             : 4;    // byte1: 4 ~ 7
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

#endif // CARNATION_SPE_PROTOCOL_H
