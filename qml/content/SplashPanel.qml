import QtQuick 2.2

Rectangle {
    id: splashPanel
    property bool animationFinished: false

    Image {
        id: splash
        source: "qrc:/splash/images/splash/splash.png"
        visible: false
        opacity: 0.0
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: splash; visible: false }
        },
        State {
            name: "show"
            PropertyChanges { target: splash; visible: true }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                ScriptAction { script: { animationFinished = false; } }
                NumberAnimation {target: splash; property: "opacity"; from: 0.0; to: 1.0; duration: 500 }
                PauseAnimation { duration: 500 }
                NumberAnimation {target: splash; property: "opacity"; from: 1.0; to: 0.0; duration: 500 }
                ScriptAction { script: { animationFinished = true; } }
            }
        }
    ]
}
