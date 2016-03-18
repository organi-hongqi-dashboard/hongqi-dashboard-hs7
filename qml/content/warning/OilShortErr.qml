import QtQuick 2.2

Item {
    id: oilShortErr

    Image {
       id: textAddOil
       x: 911
       y: 308
       opacity: 1.0
       source: "qrc:/warningPic/images/warningPic/textAddOil.png"
   }
    states: [
        State {
            name: ""
            PropertyChanges { target: oilShortErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: oilShortErr; opacity: 1.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: oilShortErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
