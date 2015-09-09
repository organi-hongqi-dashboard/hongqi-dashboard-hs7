import QtQuick 2.2
import "functionMode"
import "warning"

Rectangle {
    id: carFunction

    FunctionMenu {
        id: functionMenu
        opacity: 0
    }

    //    AbsErr {
    //        id: absErr
    //        visible: false
    //    }

    //    AfsErr {
    //        id: afsErr
    //        visible: false
    //    }

    //    ChargingSysErr {
    //        id: chargingSysErr
    //        visible: false
    //    }

    //    CoolWaterErr {
    //        id: coolWaterErr
    //        visible: false
    //    }

    //    EngineErr {
    //        id: engineErr
    //        visible: false
    //    }

    //    GearShiftTemHighErr {
    //        id: gearShiftTemHighErr
    //        visible: false
    //    }

    //    OilPreLowErr {
    //        id: oilPreLowErr
    //        visible: false
    //    }

    //    OilShortErr {
    //        id: oilShortErr
    //        visible: false
    //    }

    //    SafeErr {
    //        id: safeErr
    //        visible: false
    //    }

    //    BrakingErr {
    //        id: brakingErr
    //        visible: false
    //    }

    //    EpbErr {
    //        id: epbErr
    //        visible: false
    //    }

    //    property int cycle: 0

    //    Timer {
    //        id: timer
    //        interval: 7000
    //        running: true
    //        repeat: true
    //        onTriggered: {
    //            switch (cycle) {
    //            case 0:
    //                absErr.visible = true;
    //                epbErr.visible = false;
    //                break;
    //            case 1:
    //                chargingSysErr.visible = true;
    //                absErr.visible = false;
    //                break;
    //            case 2:
    //                coolWaterErr.visible = true;
    //                chargingSysErr.visible = false;
    //                break;
    //            case 3:
    //                engineErr.visible = true;
    //                coolWaterErr.visible = false;
    //                break;
    //            case 4:
    //                gearShiftTemHighErr.visible = true;
    //                engineErr.visible = false;
    //                break;
    //            case 5:
    //                oilPreLowErr.visible = true;
    //                gearShiftTemHighErr.visible = false;
    //                break;
    //            case 6:
    //                oilShortErr.visible = true;
    //                oilPreLowErr.visible = false;
    //                break;
    //            case 7:
    //                safeErr.visible = true;
    //                oilShortErr.visible = false;
    //                break;
    //            case 8:
    //                afsErr.visible = true;
    //                safeErr.visible = false;
    //                break;
    //            case 9:
    //                brakingErr.visible = true;
    //                afsErr.visible = false;
    //                break;
    //            case 10:
    //                epbErr.visible = true;
    //                brakingErr.visible = false;
    //                break;
    //            }
    //            if (cycle == 10)
    //                cycle = 0;
    //            else
    //                ++cycle;
    //        }
    // }
}
