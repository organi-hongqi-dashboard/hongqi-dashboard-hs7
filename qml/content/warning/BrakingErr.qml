import QtQuick 2.2

Item {
    id: brakingErr

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
        id: displayBG
        x: 830
        y: 238
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/brakingErr/displayBG.png"
    }
    Image {
        id: triBG
        x: 1100
        y: 437
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/brakingErr/triBG.png"
    }
    Image {
        id: brakeLevelLowText
        x: 852
        y: 259
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/brakingErr/brakeLevelLowText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: triBG; property: "opacity"; from: 0; to: 1.0; duration: 0 }
            NumberAnimation { target: triBG; property: "x"; from: 1100; to: 1020; duration: 400 }
            NumberAnimation { target: triBG; property: "opacity"; from: 1.0; to: 0; duration: 400 }
            NumberAnimation { target: triBG; property: "opacity"; from: 0; to: 1.0; duration: 400 }
            NumberAnimation { target: triBG; property: "opacity"; from: 1.0; to: 0; duration: 400 }
            NumberAnimation { target: triBG; property: "opacity"; from: 0; to: 1.0; duration: 400 }
            NumberAnimation { target: triBG; property: "opacity"; from: 1.0; to: 0; duration: 400 }
            NumberAnimation { target: triBG; property: "x"; from: 1020; to: 1080; duration: 0 }
            loops:Animation.Infinite
        }
    }
    states: [
        State {
            name: ""
            PropertyChanges { target: brakingErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: brakingErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: brakingErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
