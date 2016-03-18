import QtQuick 2.3

Rectangle {
	id: rightPanel

    SpeedDisk {
        id: speedDisk
        state: ""
	}

    states: [
        State {
            name: ""
            PropertyChanges { target: speedDisk; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: speedDisk; visible: true; state: "normalMode" }
		}
    ]
}
