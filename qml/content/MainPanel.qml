import QtQuick 2.2

Rectangle {
    id: mainPanel

    Image {
        id: bg
        x: 78
        y: 342
        source: "qrc:/common/images/common/bg.png"
    }

    CentrePanel {
        id: centrePanel
    }

    RightPanel {
        id: rightPanel
        visible: false
        state: ""
    }
    LeftPanel {
        id: leftPanel
        visible: false
        state: ""
    }


    states: [
        State {
            name: ""
            PropertyChanges { target: rightPanel; visible: false; state: "" }
            PropertyChanges { target: leftPanel; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: rightPanel; visible: true; state: "normalMode" }
            PropertyChanges { target: leftPanel; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: rightPanel; visible: true; state: "functionMode" }
            PropertyChanges { target: leftPanel; visible: true; state: "functionMode" }
        }
    ]
}
