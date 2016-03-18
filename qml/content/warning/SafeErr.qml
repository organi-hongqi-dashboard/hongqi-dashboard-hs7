import QtQuick 2.2

Item {
    id: safeErr

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
        id: picAirBag
        x: 916
        y: 195
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/picAirBag.png"
    }
    Image {
        id: textAirbag
        x: 833
        y: 308
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/textAirbag.png"
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
            PropertyChanges { target: safeErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: safeErr; opacity: 1.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: safeErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
