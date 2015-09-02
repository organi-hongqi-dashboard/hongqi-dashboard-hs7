import QtQuick 2.2

Rectangle {
    id: coolantTempBar
    y: -20
    opacity: 0.0
    property int valueCoolantTemp: carStatus.waterTemp

    EnergyBar {
        id: bar
        x: 1453
        y: 597
        column: 0
        mirror: 0
        moving: 0
        sekuai: (valueCoolantTemp - 50) / 80.0 > 10 ?
                    "qrc:/common/bar/images/common/bar/greenCube.png" :
                    "qrc:/common/bar/images/common/bar/redCube.png"
        targetShade: "qrc:/common/bar/images/common/bar/barOutline.png"
        level: 0.0
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Image {
        id: middleLine
        x: 1454
        y: 609
        source: "qrc:/common/bar/images/common/bar/middleLine.png"
    }

    Item {
        id: icon

        Image {
            id: iconTemp
            x: 1539
            y: 560
            source: "qrc:/rightPanel/coolantTemp/images/rightPanel/coolantTemp/iconTemp.png"
        }
        Image {
            id: coolant50
            x: 1414
            y: 602
            source: "qrc:/rightPanel/coolantTemp/images/rightPanel/coolantTemp/coolant50.png"
        }
        Image {
            id: coolant130
            x: 1660
            y: 602
            source: "qrc:/rightPanel/coolantTemp/images/rightPanel/coolantTemp/coolant130.png"
        }
        Image {
            id: coolant90
            x: 1545
            y: 639
            source: "qrc:/rightPanel/coolantTemp/images/rightPanel/coolantTemp/coolant90.png"
        }
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: coolantTempBar; opacity: 0.0 }
            PropertyChanges { target: bar; level: 0.0 }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: coolantTempBar; opacity: 1.0 }
            PropertyChanges { target: bar; level: ((valueCoolantTemp - 50) / 80.0) }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: coolantTempBar; opacity: 0.0 }
            PropertyChanges { target: bar; level: 0.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                PauseAnimation { duration: 4400 }
                ParallelAnimation {
                    NumberAnimation { target: coolantTempBar; property: "opacity"; duration: 500 }
                    NumberAnimation { target: bar; property: "level"; duration: 500 }
                }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: coolantTempBar; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: bar; property: "level"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: coolantTempBar; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: bar; property: "level"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        }
    ]
}
