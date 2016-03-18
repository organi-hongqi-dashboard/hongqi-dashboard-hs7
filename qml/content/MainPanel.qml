import QtQuick 2.2

Rectangle {
    id: mainPanel

    CentrePanel {
        id: centrePanel
        visible: false
        state: ""
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

    CarTipsIcon {
        id: carTipsIcon
		visible: false
		state: ""
    }

	FunctionMenu{
		id:functionMenu
		visible: false
		state: ""
	}

    states: [
        State {
            name: ""
            PropertyChanges { target: centrePanel; visible: false; state: "" }
            PropertyChanges { target: rightPanel; visible: false; state: "" }
			PropertyChanges { target: leftPanel; visible: false; state: "" }
			PropertyChanges { target: functionMenu; visible: false; state: "" }
			PropertyChanges { target: carTipsIcon; visible: false; state: "" }
		},
        State {
            name: "normalMode"
            PropertyChanges { target: centrePanel; visible: true; state: "normalMode" }
            PropertyChanges { target: rightPanel; visible: true; state: "normalMode" }
			PropertyChanges { target: leftPanel; visible: true; state: "normalMode" }
			PropertyChanges { target: functionMenu; visible: true; state: "normalMode" }
			PropertyChanges { target: carTipsIcon; visible: true; state: "normalMode" }
		}
    ]
}
