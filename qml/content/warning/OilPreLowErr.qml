import QtQuick 2.2

Item {
    id: oilPreLowErr

    // common
    Image {
        id: textRec
        x: 697
        y: 233
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/textRec.png"
    }
    Image {
        id: warningSymbol
        x: 775
        y: 251
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/warningSymbol.png"
    }

    // private
    Image {
        id: oilLowText
        x: 866
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/oilLowText.png"
    }

    Image {
        id: pressLow
        x: 894
        y: 338
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/pressLow.png"
    }

    Image {
        id: pointer
        x: 969
        y: 451
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/pointer.png"

        transform: Rotation {
            id: pointerRotation
            origin.x: 34
            origin.y: 10
            angle: 0
            Behavior on angle { NumberAnimation{ duration: 300 } }
        }
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: pointerRotation; property: "angle"; from: 0; to: 60; duration: 400 }
            NumberAnimation { target: pointerRotation; property: "angle"; from: 60; to: 0; duration: 400 }
            loops:Animation.Infinite
        }
    }
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
