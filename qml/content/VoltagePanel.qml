import QtQuick 2.2

Rectangle {
    id: voltagePanel

    property int valueVoltageBar: 60

    EnergyBar {
        id: voltageBar
        x: 255
        y: 597
        opacity: 1.0
        column: 0
        mirror: 0
        moving: 0
        sekuai: valueVoltageBar > 10 ?
                    "qrc:/common/images/common/greenCube.png" :
                    "qrc:/common/images/common/redCube.png"
        targetShade: "qrc:/common/images/common/barOutline.png"
        level: (valueVoltageBar / 100.0)
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Image {
            id: voltage_unit
            x: 342
            y: 570
            opacity: 1.0
            source: "qrc:/voltage/images/voltage/voltage_unit.png"
        }
        Image {
            id: voltage_percentage
            x: 217
            y: 602
            opacity: 1.0
            source: "qrc:/voltage/images/voltage/voltage_0%.png"
        }
        Image {
            id: voltage_100
            x: 462
            y: 602
            opacity: 1.0
            source: "qrc:/voltage/images/voltage/voltage_100.png"
        }
        Image {
            id: voltage_scale
            x: 262
            y: 609
            opacity: 1.0
            source: "qrc:/voltage/images/voltage/voltage_scale.png"
        }

}
