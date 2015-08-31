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
        id: oilYellow
        x: 894
        y: 338
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/oilYellow.png"
    }
    Image {
        id: oilLowBg
        x: 939
        y: 406
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/oilLowBg.png"
    }
    Image {
        id: oilLowText
        x: 866
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/oilPreLowErr/oilLowText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: oilLowBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: oilLowBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
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
