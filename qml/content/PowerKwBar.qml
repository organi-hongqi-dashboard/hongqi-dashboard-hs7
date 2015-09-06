import QtQuick 2.2

Rectangle {
    id: powerKwBar
    y: -20

    opacity: 0.0
    property int valuePowerKwBar: 90

    EnergyBar {
        id: bar
        x: 255
        y: 597
        column: 0
        mirror: 0
        moving: 0
        sekuai: valuePowerKwBar > 10 ?
                    "qrc:/common/bar/images/common/bar/greenCube.png" :
                    "qrc:/common/bar/images/common/bar/redCube.png"
        targetShade: "qrc:/common/bar/images/common/bar/barOutline.png"
        level: 0.0
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Image {
        id: middleLine
        x: 256
        y: 609
        source: "qrc:/common/bar/images/common/bar/middleLine.png"
    }

    Item {
        id: icon

        Image {
            id: voltage_unit
            x: 342
            y: 570
            source: "qrc:/letfPanel/powerKwBar/images/letfPanel/powerKwBar/voltage_unit.png"
        }
        Image {
            id: voltage_percentage
            x: 217
            y: 602
            opacity: 1.0
            source: "qrc:/letfPanel/powerKwBar/images/letfPanel/powerKwBar/voltage_0%.png"
        }
        Image {
            id: voltage_100
            x: 462
            y: 602
            opacity: 1.0
            source: "qrc:/letfPanel/powerKwBar/images/letfPanel/powerKwBar/voltage_100.png"
        }

    }

    states: [
        State {
            name: ""
            PropertyChanges { target: powerKwBar; opacity: 0.0 }
            PropertyChanges { target: bar; level: 0.0 }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: powerKwBar; opacity: 1.0 }
            PropertyChanges { target: bar; level: (valuePowerKwBar / 100.0) }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: powerKwBar; opacity: 0.0 }
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
                    NumberAnimation { target: powerKwBar; property: "opacity"; duration: 500; }
                    NumberAnimation { target: bar; property: "level"; duration: 500; }
                }

            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: powerKwBar; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: bar; property: "level"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: powerKwBar; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: bar; property: "level"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        }
    ]
}
