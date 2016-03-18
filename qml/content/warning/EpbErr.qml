import QtQuick 2.2

Item {
    id: epbErr

    // private
    Image {
        id: picParkingSysIcon
        x: 905
        y: 203
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/picParkingSysIcon.png"
    }
    Image {
        id: textParkingFault
        x: 863
        y: 308
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/textParkingFault.png"
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: epbErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: epbErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: epbErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
