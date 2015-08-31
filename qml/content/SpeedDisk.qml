import QtQuick 2.2

Rectangle {
    id: rightSpeed
    x: 0
    y: 0
    scale: 1.0

    property int valueSpeed: 0

    Image {
        id: speed_disk
        x: 1204
        y: 3
        opacity: 0.0
        source: "qrc:/common/disk/images/common/disk/disk.png"
        transform: Rotation {
            id: disk_Rota
            angle: 90
            origin.x: 0
            origin.y: 694
            axis { x: 0; y: 1; z: 0 }
            Behavior on angle {  // for animation
                PropertyAnimation { duration: 300; easing.type : Easing.OutElastic; easing.amplitude: 0.5; easing.period: 0.5 }
            }
        }
    }

    Item {
        id: speed_scale
        opacity: 0.0

        Image {
            id: graduationRight2
            x: 1248
            y: 47
            opacity: 0.0 // small to 0.0
            source: "qrc:/rightPanel/images/rightDisk/graduationRight2.png"
        }
        Image {
            id: graduationRight1
            x: 1248
            y: 47
            source: "qrc:/rightPanel/images/rightDisk/graduationRight1.png"
        }
    }

    Item {
        id: speedNumIndicator
        property int numCtrl: 260 //arange 0.0 - 260.0
        opacity: 0.0

        Image {
            id: num0
            x: 1363
            y: 536
            opacity: speedNumIndicator.numCtrl > 10
            source: "qrc:/rightPanel/images/rightDisk/num0.png"
        }
        Image {
            id: num20
            x: 1305
            y: 448
            opacity: speedNumIndicator.numCtrl > 30
            source: "qrc:/rightPanel/images/rightDisk/num20.png"
        }
        Image {
            id: num40
            x: 1285
            y: 345
            opacity: speedNumIndicator.numCtrl > 50
            source: "qrc:/rightPanel/images/rightDisk/num40.png"
        }
        Image {
            id: num60
            x: 1299
            y: 249
            opacity: speedNumIndicator.numCtrl > 70
            source: "qrc:/rightPanel/images/rightDisk/num60.png"
        }
        Image {
            id: num80
            x: 1356
            y: 162
            opacity: speedNumIndicator.numCtrl > 90
            source: "qrc:/rightPanel/images/rightDisk/num80.png"
        }
        Image {
            id: num100
            x: 1433
            y: 104
            opacity: speedNumIndicator.numCtrl > 110
            source: "qrc:/rightPanel/images/rightDisk/num100.png"
        }
        Image {
            id: num120
            x: 1526
            y: 84
            opacity: speedNumIndicator.numCtrl > 130
            source: "qrc:/rightPanel/images/rightDisk/num120.png"
        }
        Image {
            id: num140
            x: 1610
            y: 105
            opacity: speedNumIndicator.numCtrl > 150
            source: "qrc:/rightPanel/images/rightDisk/num140.png"
        }
        Image {
            id: num160
            x: 1692
            y: 160
            opacity: speedNumIndicator.numCtrl > 170
            source: "qrc:/rightPanel/images/rightDisk/num160.png"
        }
        Image {
            id: num180
            x: 1753
            y: 243
            opacity: speedNumIndicator.numCtrl > 190
            source: "qrc:/rightPanel/images/rightDisk/num180.png"
        }
        Image {
            id: num200
            x: 1755
            y: 344
            opacity: speedNumIndicator.numCtrl > 210
            source: "qrc:/rightPanel/images/rightDisk/num200.png"
        }
        Image {
            id: num220
            x: 1739
            y: 443
            opacity: speedNumIndicator.numCtrl > 230
            source: "qrc:/rightPanel/images/rightDisk/num220.png"
        }
        Image {
            id: num240
            x: 1681
            y: 528
            opacity: speedNumIndicator.numCtrl > 250
            source: "qrc:/rightPanel/images/rightDisk/num240.png"
        }
    }

    Image {
        id: iconKmPerHBig
        x: 1333
        y: 493
        opacity: 0.0
        source: "qrc:/rightPanel/images/rightDisk/iconKmPerHBig.png"
    }

    Image {
        id: rightPointer
        x: 1255
        y: 430
        opacity: 0.0
        source: "qrc:/common/disk/images/common/disk/pointer.png"

        transform: Rotation {
            id: rightPointRotation
            origin.x: 1560 - rightPointer.x;
            origin.y: 360 - rightPointer.y;
            angle: valueSpeed * 270 / 240
            Behavior on angle { SpringAnimation{ spring: 1.2; damping: 0.2;}
            }
        }
    }



    Item {
        id: numSpeed
        opacity: 0.0
        x: 1419
        y: 318
        width: 280
        height: 160

        DigitValue {
            id: numSpeedShow
            anchors.centerIn: numSpeed
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

    CoolantTempBar {
        id: coolantTempBar
        state: ""
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rightSpeed; x: 0; y: 0; scale: 1.0 }
            PropertyChanges { target: disk_Rota; angle: 90 }
            PropertyChanges { target: speed_disk; opacity: 0.0 }
            PropertyChanges { target: speed_scale; opacity: 0.0; scale: 0.0 }
            PropertyChanges { target: speedNumIndicator; opacity: 0.0; numCtrl: 0.0 }
            PropertyChanges { target: rightPointer; opacity: 0.0; }
            PropertyChanges { target: iconKmPerHBig; opacity: 0.0; x: 1333; y: 493; scale: 1.0 }
            PropertyChanges { target: numSpeed; opacity: 0.0 }
            PropertyChanges { target: graduationRight2; opacity: 0.0 }
            PropertyChanges { target: coolantTempBar; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: rightSpeed; x: 0; y: 0; scale: 1.0 }
            PropertyChanges { target: disk_Rota; angle: 0 }
            PropertyChanges { target: speed_disk; opacity: 1.0 }
            PropertyChanges { target: speed_scale; opacity: 1.0; scale: 1.0 }
            PropertyChanges { target: speedNumIndicator; opacity: 1.0; numCtrl: 260.0 }
            PropertyChanges { target: rightPointer; opacity: 1.0; }
            PropertyChanges { target: iconKmPerHBig; opacity: 1.0; x: 1333; y: 493; scale: 1.0 }
            PropertyChanges { target: numSpeed; opacity: 1.0 }
            PropertyChanges { target: graduationRight2; opacity: 1.0 }
            PropertyChanges { target: coolantTempBar; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: rightSpeed; x: 795; y: 289; scale: 0.56 }
            PropertyChanges { target: disk_Rota; angle: 0 }
            PropertyChanges { target: speed_disk; opacity: 1.0 }
            PropertyChanges { target: speed_scale; opacity: 1.0; scale: 1.0 }
            PropertyChanges { target: speedNumIndicator; opacity: 0.0; numCtrl: 0.0 }
            PropertyChanges { target: rightPointer; opacity: 1.0; }
            PropertyChanges { target: iconKmPerHBig; opacity: 1.0; x: 1526; y: 597; scale: 1.2 }
            PropertyChanges { target: numSpeed; opacity: 1.0 }
            PropertyChanges { target: graduationRight2; opacity: 0.0 }
            PropertyChanges { target: coolantTempBar; visible: true; state: "functionMode" }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                NumberAnimation { target: speed_disk; property: "opacity"; duration: 500 }
                ParallelAnimation {
                    SequentialAnimation {
                        NumberAnimation { target: disk_Rota; property: "angle"; from: 90; to: 0; duration: 1000 }
                        PauseAnimation { duration: 400 }
                    }
                    SequentialAnimation {
                        PauseAnimation { duration: 600}
                        ParallelAnimation {
                        NumberAnimation { target: speed_scale; property: "opacity"; duration: 800 }
                        NumberAnimation { target: graduationRight2; property: "scale"; from: 0; to: 1.0; duration: 800 }
                        NumberAnimation { target: graduationRight1; property: "scale"; from: 0; to: 1.0; duration: 800 }
                        }
                    }
                    SequentialAnimation {
                        PauseAnimation { duration: 600}
                        ParallelAnimation {
                            NumberAnimation { target: speedNumIndicator; property: "opacity"; duration: 800 }
                            NumberAnimation { target: speedNumIndicator; property: "numCtrl"; duration: 800 }
                        }
                    }
                }
                NumberAnimation { target: iconKmPerHBig; property: "opacity"; duration: 500 }
                NumberAnimation { target: rightPointer; property: "opacity"; duration: 400 }
                NumberAnimation { target: rightPointRotation; property: "angle"; from: 0; to: 270; duration: 800 }
                NumberAnimation { target: rightPointRotation; property: "angle"; from: 270; to: 0; duration: 800 }
                NumberAnimation { target: numSpeed; property: "opacity"; duration: 500 }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            ParallelAnimation {
                NumberAnimation { target: rightSpeed; properties: "scale,x,y"; duration: 1000;easing.type: Easing.InBack}
                NumberAnimation { target: iconKmPerHBig; properties: "x,y,scale"; duration: 1000 ;easing.type: Easing.InBack}
                NumberAnimation { target: speedNumIndicator; properties: "opacity, numCtrl"; duration: 1000 ;easing.type: Easing.InBack}
                NumberAnimation { target: graduationRight2; property: "opacity"; duration: 1000 ;easing.type: Easing.InBack}

            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            ParallelAnimation {
                NumberAnimation { target: rightSpeed; properties: "scale,x,y"; duration: 1000; easing.type: Easing.InBack}
                NumberAnimation { target: iconKmPerHBig; properties: "x,y,scale"; duration: 1000 ;easing.type: Easing.InBack}
                NumberAnimation { target: speedNumIndicator; properties: "opacity, numCtrl"; duration: 1000 ;easing.type: Easing.InBack}
                NumberAnimation { target: graduationRight2; property: "opacity"; duration: 1000 ;easing.type: Easing.InBack}

            }
        }
    ]
}
