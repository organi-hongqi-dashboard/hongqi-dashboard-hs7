import QtQuick 2.2

Rectangle {
	id: rightSpeed

    property int valueSpeed: 190

    Image {
        id: bgRightBig
        x: 1225
        y: 25
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/bgRightBig.png"
    }
    Image {
        id: roundRightBig2
        x: 1204
        y: 3
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/roundRightBig2.png"
    }
    Image {
        id: roundRightBig1
        x: 1243
        y: 42
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/roundRightBig1.png"
    }
    Image {
        id: iconKmPerHBig
        x: 1333
        y: 493
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/iconKmPerHBig.png"
    }

    Item {
        id: numSpeed
        opacity: 1.0
        x: 1419
        y: 318
        width: 280
        height: 160

        DigitValue {
            id: numSpeedShow
            anchors.centerIn: numSpeed
//                spacing: -20
            icon0: "qrc:/rightPanel/images/rightDisk/00.png"
            icon1: "qrc:/rightPanel/images/rightDisk/01.png"
            icon2: "qrc:/rightPanel/images/rightDisk/02.png"
            icon3: "qrc:/rightPanel/images/rightDisk/03.png"
            icon4: "qrc:/rightPanel/images/rightDisk/04.png"
            icon5: "qrc:/rightPanel/images/rightDisk/05.png"
            icon6: "qrc:/rightPanel/images/rightDisk/06.png"
            icon7: "qrc:/rightPanel/images/rightDisk/07.png"
            icon8: "qrc:/rightPanel/images/rightDisk/08.png"
            icon9: "qrc:/rightPanel/images/rightDisk/09.png"
            value: valueSpeed
        }
    }

    Image {
        id: graduationRight2
        x: 1248
        y: 47
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/graduationRight2.png"
    }
    Image {
        id: graduationRight1
        x: 1248
        y: 47
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/graduationRight1.png"
    }
    Item {
        id: speedNumIndicator

        Image {
            id: num0
            x: 1363
            y: 536
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num0.png"
        }
        Image {
            id: num20
            x: 1305
            y: 448
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num20.png"
        }
        Image {
            id: num40
            x: 1285
            y: 345
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num40.png"
        }
        Image {
            id: num60
            x: 1299
            y: 249
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num60.png"
        }
        Image {
            id: num80
            x: 1356
            y: 162
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num80.png"
        }
        Image {
            id: num100
            x: 1433
            y: 104
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num100.png"
        }
        Image {
            id: num120
            x: 1526
            y: 84
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num120.png"
        }
        Image {
            id: num140
            x: 1610
            y: 105
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num140.png"
        }
        Image {
            id: num160
            x: 1692
            y: 160
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num160.png"
        }
        Image {
            id: num180
            x: 1753
            y: 243
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num180.png"
        }
        Image {
            id: num200
            x: 1755
            y: 344
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num200.png"
        }
        Image {
            id: num220
            x: 1739
            y: 443
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num220.png"
        }
        Image {
            id: num240
            x: 1681
            y: 528
            opacity: 1.0
            source: "qrc:/rightPanel/images/rightDisk/num240.png"
        }
    }

    Image {
        id: rightPointer
        x: 1261
        y: 427
        opacity: 1.0
        source: "qrc:/rightPanel/images/rightDisk/rightPoint.png"

        transform: Rotation {
            id: rightPointRotation
            origin.x: 1560 - rightPointer.x;
            origin.y: 360 - rightPointer.y;
            angle: valueSpeed * 269.7 / 240
            Behavior on angle { SpringAnimation{ spring: 1.2; damping: 0.2;}
            }
        }
    }

//    transitions: [
//        Transition {
//            from: ""
//            to: "show"
//            SequentialAnimation {
//                /* speed disk pointer move circle */
//                ParallelAnimation {
//                    NumberAnimation { target: rightPointRotation; property: "angle"; from:0; to: 270; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "valueSpeed"; from:0; to: 240; duration: 1000 }
//                }
//                ParallelAnimation {
//                    NumberAnimation { target: rightPointRotation; property: "angle"; from:270; to: 0; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "valueSpeed"; from:240; to: 0; duration: 1000 }
//                }

//                PauseAnimation { duration: 3000 }

//                /* speed disk transform from big to small animation */
//                ParallelAnimation {
//                    NumberAnimation { target: rightSpeed; property: "x"; to: 795; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "y"; to: 289; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "scale"; to: 0.56; duration: 1000 }
//                    NumberAnimation { target: speedNumIndicator; property: "opacity"; to: 0.0; duration: 1000 }
//                    NumberAnimation { target: graduationRight2; property: "opacity"; to: 0.0; duration: 1000 }
//                    NumberAnimation { target: iconKmPerHBig; property: "x"; to: 1526; duration: 1000 }
//                    NumberAnimation { target: iconKmPerHBig; property: "y"; to: 597; duration: 1000 }
//                    NumberAnimation { target: iconKmPerHBig; property: "scale"; to: 1.2; duration: 1000 }
////                    NumberAnimation { target: outlineBig; property: "opacity"; to: 0.0; duration: 1000 }
////                    NumberAnimation { target: outlineBig; property: "width"; to: 2220; duration: 1000 }
////                    NumberAnimation { target: outlineBig; property: "x"; to: -100; duration: 1000 }
//                }
////                NumberAnimation { target: outlinelittle; property: "opacity"; to: 1.0; duration: 500 }

//                /* speed disk pointer move circle */
//                ParallelAnimation {
//                    NumberAnimation { target: rightPointRotation; property: "angle"; from:0; to: 270; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "valueSpeed"; from:0; to: 240; duration: 1000 }
//                }
//                ParallelAnimation {
//                    NumberAnimation { target: rightPointRotation; property: "angle"; from:270; to: 0; duration: 1000 }
//                    NumberAnimation { target: rightSpeed; property: "valueSpeed"; from:240; to: 0; duration: 1000 }
//                }
//            }
//        },
//        Transition {
//            from: "show"
//            to: ""
//            SequentialAnimation {
//            }
//        }
//    ]
}
