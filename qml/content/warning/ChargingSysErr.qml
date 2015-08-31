import QtQuick 2.2

Item {
    id: chargingSysErr

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
        id: batterBg
        x: 906
        y: 323
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/chargingSysErr/batterBg.png"
    }
    Image {
        id: chargingSysErrText
        x: 881
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/chargingSysErr/chargingSysErrText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: batterBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: batterBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
    states: [
        State {
            name: ""
            PropertyChanges { target: chargingSysErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: chargingSysErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: chargingSysErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
