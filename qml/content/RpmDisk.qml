import QtQuick 2.2

import QtQuick 2.4

Item {
    id: rpmPanel
    x: 0
    y: 0

    //    property real number: 1.0
    //    property real xscale: number
    //    property real yscale: number
    //    transform: Scale { origin.x: 355; origin.y: 360; xScale: xscale; yScale: xscale }
    //    transform: Rotation { origin.x: 355; origin.y: 360;  }

    Image {
        id: rpm_disk
        x: 2
        y: 3
        opacity: 0
        source: "qrc:/rpmPanel/images/rpmPanel/rpm_disk.png"

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
        opacity: 0
        source: "qrc:/rpmPanel/images/rpmPanel/rpm_scale.png"
        scale: 0
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
            source: "qrc:/rpmPanel/images/rpmPanel/rpm0.png"
        }
        Image {
            id: rpm1
            x: 94
            y: 372
            opacity: rpm_number.numCtrl > 1.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm1.png"
        }
        Image {
            id: rpm2
            x: 132
            y: 204
            opacity: rpm_number.numCtrl > 2.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm2.png"
        }
        Image {
            id: rpm3
            x: 261
            y: 105
            opacity: rpm_number.numCtrl > 3.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm3.png"
        }
        Image {
            id: rpm4
            x: 414
            y: 104
            opacity: rpm_number.numCtrl > 4.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm4.png"
        }
        Image {
            id: rpm5
            x: 551
            y: 201
            opacity: rpm_number.numCtrl > 5.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm5.png"
        }
        Image {
            id: rpm6
            x: 589
            y: 371
            opacity: rpm_number.numCtrl > 6.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm6.png"
        }
        Image {
            id: rpm7
            x: 526
            y: 524
            opacity: rpm_number.numCtrl > 7.5
            source: "qrc:/rpmPanel/images/rpmPanel/rpm7.png"
        }
    }

    Image {
        id: rpm_pointer
        x: 51.5
        y: 432
        opacity: 0
        source: "qrc:/rpmPanel/images/rpmPanel/rpm_pointer.png"

        transform: Rotation {
            //            property real pointerAngle: 90
            id: pointerRotation
            origin.x: 308
            origin.y: -73
            angle: 38.5 * 0        //pointerAngle
            Behavior on angle { SpringAnimation{ spring: 2; damping: 0.2} }
        }
    }
    Image {
        id: unit_up
        x: 103
        y: 451
        opacity: 0
        source: "qrc:/rpmPanel/images/rpmPanel/unit_up.png"
    }
    Image {
        id: unit_down
        x: 223
        y: 607
        opacity: 0
        source: "qrc:/rpmPanel/images/rpmPanel/unit_down.png"
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rpmPanel; x: 0 }
            PropertyChanges { target: rpmPanel; y: 0 }
            PropertyChanges { target: rpmPanel; scale: 0 }
            PropertyChanges { target: rpm_disk; opacity: 0 }
            PropertyChanges { target: rpm_scale; opacity: 0 }
            PropertyChanges { target: rpm_number; opacity: 0; numCtrl: 0.0  }
            PropertyChanges { target: rpm_pointer; opacity: 0; }
            PropertyChanges { target: unit_up; opacity: 0; }
            PropertyChanges { target: unit_down; opacity: 0; }
        },
        State {
            name: "Bigshow"
            PropertyChanges { target: rpmPanel; x: 0 }
            PropertyChanges { target: rpmPanel; y: 0 }
            PropertyChanges { target: rpmPanel; scale: 1.0 }
            PropertyChanges { target: rpm_disk; opacity: 1.0 }
            PropertyChanges { target: rpm_scale; opacity: 1.0 }
            PropertyChanges { target: rpm_number; opacity: 1.0; numCtrl: 8.0 }
            PropertyChanges { target: rpm_pointer; opacity: 1.0 }
            PropertyChanges { target: unit_up; opacity: 1.0; }
            PropertyChanges { target: unit_down; opacity: 0; }
        },
        State {
            name: "Smallshow"
            PropertyChanges { target: rpmPanel; x: 54 }
            PropertyChanges { target: rpmPanel; y: 290 }
            PropertyChanges { target: rpmPanel; scale: 0.56 }
            PropertyChanges { target: unit_up; opacity: 0; }
            PropertyChanges { target: unit_down; opacity: 1.0; }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "Bigshow"
            SequentialAnimation {
                NumberAnimation { target: rpm_disk; property: "opacity"; duration: 500 }
                ParallelAnimation {
                    NumberAnimation { target: disk_Rota; property: "angle"; from: 90; to: 0; duration: 1000 }
                    SequentialAnimation {
                        PauseAnimation { duration: 600}
                        ParallelAnimation {
                            NumberAnimation { target: rpm_scale; property: "opacity"; duration: 800 }
                            NumberAnimation { target: rpm_scale; property: "scale"; from: 0; to: 1.0; duration: 800 }
                        }
                    }
                    SequentialAnimation {
                        PauseAnimation { duration: 800}
                        ParallelAnimation {
                            NumberAnimation { target: rpm_number; property: "opacity"; duration: 800 }
                            NumberAnimation { target: rpm_number; property: "numCtrl"; duration: 1500 }
                        }
                    }
                }
                NumberAnimation { target: unit_up; property: "opacity"; duration: 500 }
                NumberAnimation { target: rpm_pointer; property: "opacity"; duration: 400 }
                NumberAnimation { target: pointerRotation; property: "angle"; from: 0; to: 270; duration: 800 }
                NumberAnimation { target: pointerRotation; property: "angle"; from: 270; to: 0; duration: 800 }
            }
        },
        Transition {
            from: "Bigshow"
            to: "Smallshow"
            SequentialAnimation {
                NumberAnimation { target: unit_up; property: "opacity"; to: 0; duration: 500 }
                ParallelAnimation {
                    NumberAnimation { target: unit_up; property: "opacity"; to: 0; duration: 500 }
                    NumberAnimation { target: rpmPanel; property: "x"; to: 54; duration: 800 }
                    NumberAnimation { target: rpmPanel; property: "y"; to:290; duration: 800 }
                    NumberAnimation { target: rpmPanel; property: "scale"; to: 0.56; duration: 800 }
                    NumberAnimation { target: unit_down; property: "opacity"; duration: 300 }
                }
            }
        },
        Transition {
            from: "Smallshow"
            to: "Bigshow"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: unit_up; property: "opacity"; duration: 500 }
                    NumberAnimation { target: rpmPanel; property: "x"; duration: 800 }
                    NumberAnimation { target: rpmPanel; property: "y"; duration: 800 }
                    NumberAnimation { target: rpmPanel; property: "scale"; to: 0.56; duration: 800 }
                }
                NumberAnimation { target: unit_down; property: "opacity"; duration: 300 }
            }
        },
        Transition {
            from: "Bigshow"
            to: ""
            SequentialAnimation {
            }
        },
        Transition {
            from: "Smallshow"
            to: ""
            SequentialAnimation {
            }
        }
    ]
}

