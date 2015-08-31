import QtQuick 2.2

Item {
    id: safeErr

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
        id: seatBg
        x: 875
        y: 341
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/safeErr/seatBg.png"
    }
    Image {
        id: safeBg
        x: 914
        y: 279
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/safeErr/safeBg.png"
    }
    Image {
        id: safeBagErrText
        x: 871
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/safeErr/safeBagErrText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: safeBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: safeBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
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
