import QtQuick 2.2

Item {
    id: epbErr

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
        id: epbBg
        x: 755
        y: 246
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/epbErr/epbBg.png"
    }
    Image {
        id: cautionBg
        x: 907
        y: 442
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/epbErr/cautionBg.png"
    }
    Image {
        id: epbErrText
        x: 897
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/epbErr/epbErrText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: cautionBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: cautionBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
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
