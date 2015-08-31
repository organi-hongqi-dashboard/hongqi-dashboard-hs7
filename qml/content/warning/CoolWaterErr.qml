import QtQuick 2.2

Item {
    id: coolWaterErr

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
    Image {
        id: coolWaterBg
        x: 819
        y: 247
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/coolWaterErr/coolWaterBg.png"
    }
    Image {
        id: coolWaterText
        x: 853
        y: 259
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/coolWaterErr/coolWaterText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: coolWaterBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: coolWaterBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
    states: [
        State {
            name: ""
            PropertyChanges { target: coolWaterErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: coolWaterErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: coolWaterErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
