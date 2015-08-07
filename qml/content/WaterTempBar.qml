import QtQuick 2.2

Rectangle {
    id: waterTempBar

    property int valueCoolantTemp: 60

    EnergyBar {
        id: coolantEnergyBar
        x: 1453
        y: 597
        opacity: 1.0
        column: 0
        mirror: 0
        moving: 0
        sekuai: (valueCoolantTemp - 50) / 80.0 > 10 ?
                    "qrc:/common/images/common/greenCube.png" :
                    "qrc:/common/images/common/redCube.png"
        targetShade: "qrc:/common/images/common/barOutline.png"
        level: ((valueCoolantTemp - 50) / 80.0)
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Image {
        id: iconTemp
        x: 1539
        y: 560
        opacity: 1.0
        source: "qrc:/rightPanel/images/coolantTemp/iconTemp.png"
    }

    Image {
        id: coolant50
        x: 1414
        y: 602
        opacity: 1.0
        source: "qrc:/rightPanel/images/coolantTemp/coolant50.png"
    }
    Image {
        id: coolant130
        x: 1660
        y: 602
        opacity: 1.0
        source: "qrc:/rightPanel/images/coolantTemp/coolant130.png"
    }
    Image {
        id: coolant90
        x: 1545
        y: 639
        opacity: 1.0
        source: "qrc:/rightPanel/images/coolantTemp/coolant90.png"
    }

    // module 刻度___2
    Image {
        id: bottomHighlight_2
        x: 1454
        y: 609
        opacity: 1.0
        source: "qrc:/rightPanel/images/coolantTemp/bottomHighlight_2.png"
    }
}
