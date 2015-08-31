import QtQuick 2.2

Item {
    id: rpmDisk
    x: 0
    y: 0
    scale: 1.0

    Image {
        id: rpm_disk
        x: 2
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

    Image {
        id: rpm_scale
        x: 45
        y: 47
        opacity: 0.0
        source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm_scale.png"
    }

    Item {
        id:rpm_number
        property real numCtrl: 0.0 //arange 0.0 - 8.0
        opacity: 0.0

        Image {
            id: rpm0
            x: 164
            y: 524
            opacity: rpm_number.numCtrl > 0.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm0.png"
        }
        Image {
            id: rpm1
            x: 94
            y: 372
            opacity: rpm_number.numCtrl > 1.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm1.png"
        }
        Image {
            id: rpm2
            x: 132
            y: 204
            opacity: rpm_number.numCtrl > 2.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm2.png"
        }
        Image {
            id: rpm3
            x: 261
            y: 105
            opacity: rpm_number.numCtrl > 3.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm3.png"
        }
        Image {
            id: rpm4
            x: 414
            y: 104
            opacity: rpm_number.numCtrl > 4.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm4.png"
        }
        Image {
            id: rpm5
            x: 551
            y: 201
            opacity: rpm_number.numCtrl > 5.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm5.png"
        }
        Image {
            id: rpm6
            x: 589
            y: 371
            opacity: rpm_number.numCtrl > 6.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm6.png"
        }
        Image {
            id: rpm7
            x: 526
            y: 524
            opacity: rpm_number.numCtrl > 7.5
            source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm7.png"
        }
    }

    Image {
        id: unit
        x: 103
        y: 451
        opacity: 0.0
        source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/unit.png"
    }

    Image {
        id: rpm_pointer
        x: 51.5
        y: 432
        opacity: 0.0
        source: "qrc:/common/disk/images/common/disk/pointer.png"

        transform: Rotation {
            id: pointerRotation
            origin.x: 308
            origin.y: -73
            angle: 0/*38.5 * 7*/
            Behavior on angle { SpringAnimation{ spring: 2; damping: 0.2} }
        }
    }

    PowerKwBar {
        id: powerKwBar
        state: ""
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rpmDisk; x: 0; y: 0; scale: 1.0 }
            PropertyChanges { target: disk_Rota; angle: 90 }
            PropertyChanges { target: rpm_disk; opacity: 0.0 }
            PropertyChanges { target: rpm_scale; opacity: 0.0 }
            PropertyChanges { target: rpm_number; opacity: 0.0; numCtrl: 0.0 }
            PropertyChanges { target: rpm_pointer; opacity: 0.0; }
            PropertyChanges { target: unit; opacity: 0.0; x: 103; y: 451; scale: 1.0 }
            PropertyChanges { target: powerKwBar; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: rpmDisk; x: 0; y: 0; scale: 1.0 }
            PropertyChanges { target: disk_Rota; angle: 0 }
            PropertyChanges { target: rpm_disk; opacity: 1.0 }
            PropertyChanges { target: rpm_scale; opacity: 1.0 }
            PropertyChanges { target: rpm_number; opacity: 1.0; numCtrl: 8.0 }
            PropertyChanges { target: rpm_pointer; opacity: 1.0; }
            PropertyChanges { target: unit; opacity: 1.0; x: 103; y: 451; scale: 1.0 }
            PropertyChanges { target: powerKwBar; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: rpmDisk; x: 54; y: 290; scale: 0.56 }
            PropertyChanges { target: disk_Rota; angle: 0 }
            PropertyChanges { target: rpm_disk; opacity: 1.0 }
            PropertyChanges { target: rpm_scale; opacity: 1.0 }
            PropertyChanges { target: rpm_number; opacity: 1.0; numCtrl: 8.0 }
            PropertyChanges { target: rpm_pointer; opacity: 1.0; }
            PropertyChanges { target: unit; opacity: 1.0; x: 310; y: 580; scale: 1.2 }
            PropertyChanges { target: powerKwBar; visible: true; state: "functionMode" }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                NumberAnimation { target: rpm_disk; property: "opacity"; duration: 500 }
                ParallelAnimation {
                    SequentialAnimation {
                        NumberAnimation { target: disk_Rota; property: "angle"; from: 90; to: 0; duration: 1000 }
                        PauseAnimation { duration: 400 }
                    }
                    SequentialAnimation {
                        PauseAnimation { duration: 600}
                        ParallelAnimation {
                            NumberAnimation { target: rpm_scale; property: "opacity"; duration: 800 }
                            NumberAnimation { target: rpm_scale; property: "scale"; from: 0; to: 1.0; duration: 800 }
                        }
                    }
                    SequentialAnimation {
                        PauseAnimation { duration: 600}
                        ParallelAnimation {
                            NumberAnimation { target: rpm_number; property: "opacity"; duration: 800 }
                            NumberAnimation { target: rpm_number; property: "numCtrl"; duration: 800 }
                        }
                    }
                }
                NumberAnimation { target: unit; property: "opacity"; duration: 500 }
                NumberAnimation { target: rpm_pointer; property: "opacity"; duration: 400 }
                NumberAnimation { target: pointerRotation; property: "angle"; from: 0; to: 269.5; duration: 800 }
                NumberAnimation { target: pointerRotation; property: "angle"; from: 269.5; to: 0; duration: 800 }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            ParallelAnimation {
                NumberAnimation { target: rpmDisk; properties: "scale,x,y"; duration: 1000 ;easing.type: Easing.InBack}
                NumberAnimation { target: unit; properties: "x,y,scale"; duration: 1000 ;easing.type: Easing.InBack}
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            ParallelAnimation {
                NumberAnimation { target: rpmDisk; properties: "scale,x,y"; duration: 1000; easing.type: Easing.InBack}
                NumberAnimation { target: unit; properties: "x,y,scale"; duration: 1000 ;easing.type: Easing.InBack}
            }
        }
    ]
}

