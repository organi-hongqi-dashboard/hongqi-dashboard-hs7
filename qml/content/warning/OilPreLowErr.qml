import QtQuick 2.2

Item {
    id: oilPreLowErr

    // common
//    Image {
//        id: frameRec
//        x: 709
//        y: 253
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/frameRec.png"
//    }
//    Image {
//        id: picLight
//        x: 576
//        y: 414
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picLight.png"
//    }
//    Image {
//        id: picCar
//        x: 669
//        y: 390
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picCar.png"
//    }
//    Image {
//        id: picWarn
//        x: 869
//        y: 504
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picWarn.png"
//    }

   // private
    Image {
        id: picOilPressureIcon
        x: 889
        y: 211
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/picOilPressureIcon.png"
    }
    Image {
        id: textOilPressureLow
        x: 863
        y: 308
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/textOilPressureLow.png"
    }

//    ParallelAnimation {
//        running: true
//        SequentialAnimation {
//            NumberAnimation { target: picWarn; property: "opacity"; from: 1.0; to: 0; duration: 800 }
//            NumberAnimation { target: picWarn; property: "opacity"; from: 0; to: 1.0; duration: 800 }
//            loops:Animation.Infinite
//        }
//    }
    states: [
        State {
            name: ""
            PropertyChanges { target: oilPreLowErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: oilPreLowErr; opacity: 1.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: oilPreLowErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
