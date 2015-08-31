import QtQuick 2.2

Rectangle {
    id: oilBar
    x: 0
    opacity: 0.0

    property int valueOilMass: 10

    EnergyBar {
        id: bar
        x: 1021
        y: 553
        column: 0
        mirror: 0
        moving: 0
        sekuai: valueOilMass > 10 ?
                    "qrc:/common/bar/images/common/bar/greenCube.png" :
                    "qrc:/common/bar/images/common/bar/redCube.png"
        targetShade: "qrc:/common/bar/images/common/bar/barOutline.png"
        level: (valueOilMass / 100.0)
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Image {
        id: middleLine
        x: 1022
        y: 565
        source: "qrc:/common/bar/images/common/bar/middleLine.png"
    }

    Item {
        id: icon

        DigitValue {
            id: numOilShow
            anchors.right: iconPercentage.left
            anchors.rightMargin: -10
            y: 531
            spacing: -10
            icon0: "qrc:/common/bar/images/common/bar/0000.png"
            icon1: "qrc:/common/bar/images/common/bar/1111.png"
            icon2: "qrc:/common/bar/images/common/bar/2222.png"
            icon3: "qrc:/common/bar/images/common/bar/3333.png"
            icon4: "qrc:/common/bar/images/common/bar/4444.png"
            icon5: "qrc:/common/bar/images/common/bar/5555.png"
            icon6: "qrc:/common/bar/images/common/bar/6666.png"
            icon7: "qrc:/common/bar/images/common/bar/7777.png"
            icon8: "qrc:/common/bar/images/common/bar/8888.png"
            icon9: "qrc:/common/bar/images/common/bar/9999.png"
            value: valueOilMass
        }

        Image {
            id: iconPercentage
            x: 1130
            y: 533
            source: "qrc:/common/bar/images/common/bar/iconPercentage.png"
        }

        Image {
            id: iconOilMass
            x: 1236
            y: 550
            source: "qrc:/rightPanel/oilBar/images/rightPanel/oilBar/iconOilMass.png"
        }

    }

    states: [
        State {
            name: ""
            PropertyChanges { target: oilBar; opacity: 0.0; x: 0 }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: oilBar; opacity: 1.0; x: 0 }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: oilBar; opacity: 1.0; x: 190 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                PauseAnimation { duration: 4400 }
                NumberAnimation { target: oilBar; properties: "opacity,x"; duration: 500 }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                NumberAnimation { target: oilBar; properties: "opacity,x"; duration: 1000; easing.type: Easing.InBack }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                NumberAnimation { target: oilBar; properties: "opacity,x"; duration: 1000; easing.type: Easing.InBack }
            }
        }
    ]
}
