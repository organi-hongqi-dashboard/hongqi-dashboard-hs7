import QtQuick 2.2

Item {
    id: gearShiftTemHighErr

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
        id: gearWhiteBg
        x: 871
        y: 339
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/gearShiftTemHighErr/gearWhiteBg.png"
    }
    Image {
        id: gearRedBg
        x: 781
        y: 241
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/gearShiftTemHighErr/gearRedBg.png"
    }
    Image {
        id: temBg
        x: 881
        y: 394
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/gearShiftTemHighErr/temBg.png"
    }
    Image {
        id: gearShiftTemHighText
        x: 867
        y: 258
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/gearShiftTemHighErr/gearShiftTemHighText.png"
    }

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: gearRedBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            PauseAnimation { duration: 300 }
            NumberAnimation { target: gearRedBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
    states: [
        State {
            name: ""
            PropertyChanges { target: gearShiftTemHighErr; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: gearShiftTemHighErr; opacity: 1.0 }

        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                NumberAnimation{ target: gearShiftTemHighErr; property: "opacity"; duration: 500 }
            }
        }
    ]
    Component.onCompleted: {
        state = "show"
    }
}
