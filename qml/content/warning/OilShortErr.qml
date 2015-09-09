import QtQuick 2.2

Item {
    id: oilShortErr

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
        id: oilFallBg
        x: 799
        y: 406
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilShortErr/oilFallBg.png"
    }
    Image {
        id: oilGunBg
        x: 806
        y: 334
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilShortErr/oilGunBg.png"
    }
    Image {
        id: oilShortText
        x: 910
        y: 259
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilShortErr/oilShortText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: oilFallBg; property: "y"; from: 406; to: 456; duration: 800 }
            NumberAnimation { target: oilFallBg; property: "opacity"; from: 1.0; to: 0; duration: 0 }
            NumberAnimation { target: oilFallBg; property: "y"; from: 456; to: 406; duration: 800 }
            NumberAnimation { target: oilFallBg; property: "opacity"; from: 0; to: 1.0; duration: 0 }
            loops:Animation.Infinite
        }
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
