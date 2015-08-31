import QtQuick 2.2

Item {
    id: afsErr

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
        id: afsLightBg
        x: 645
        y: 324
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/afsErr/afsLightBg.png"
    }
    Image {
        id: afsCarBg
        x: 875
        y: 326
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanelafsErr/afsCarBg.png"
    }
    Image {
        id: afsCloseText
        x: 888
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/afsErr/afsCloseText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: afsLightBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: afsLightBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
    states: [
        State {
            name: ""
            PropertyChanges { target: afsErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: afsErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: afsErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
