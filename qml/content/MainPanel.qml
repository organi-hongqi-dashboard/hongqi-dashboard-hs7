import QtQuick 2.2

Rectangle {
    id: mainPanel

    //    CentrePanel {
    //        id: centrePanel
    //    }
    //    RightPanel {
    //        id: rightPanel
    //    }
    LeftPanel {
        id: leftPanel
        visible: false
        state: ""
    }


    states: [
        State {
            name: ""
            PropertyChanges { target: leftPanel; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: leftPanel; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: leftPanel; visible: true; state: "functionMode" }
        }
    ]
}
