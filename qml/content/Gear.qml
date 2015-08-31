import QtQuick 2.2

Item {
    id: gear

    property bool animationStarting: false

    transform: Rotation {
        id: gearRot
        axis { x: 1; y: 0; z: 0 }
        angle: 90
        origin { x: 50; y: 100 }
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: gearRot; angle: 90 }
            PropertyChanges { target: gear; opacity: 0.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: gearRot; angle: 0 }
            PropertyChanges { target: gear; opacity: 1.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
                ScriptAction {
                    script: {
                        gear.animationStarting = true;
                    }
                }
                ParallelAnimation {
                    NumberAnimation {target: gearRot; property: "angle"; from: 90; to: 0; duration: 800 }
                    NumberAnimation {target: gear; property: "opacity"; from: 0; to: 1.0; duration: 800 }
                }
                ScriptAction {
                    script: {
                        gear.animationStarting = false;
                    }
                }
            }
        },
        Transition {
            from: "show"
            to: ""
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation {target: gearRot; property: "angle"; from: 0; to: -90; duration: 800 }
                    SequentialAnimation {
                        PauseAnimation { duration: 500 }
                        NumberAnimation {target: gear; property: "opacity"; from: 1.0; to: 0; duration: 300 }
                    }
                }
                NumberAnimation {target: gearRot; property: "angle"; from: -90; to: 90; duration: 0 }
            }
        }
    ]
}
