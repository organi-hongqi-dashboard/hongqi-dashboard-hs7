import QtQuick 2.3

Rectangle {
	id: rightPanel

    SpeedDisk {
        id: speedDisk
        state: ""
	}

    OilBar {
        id: oilBar
        state: ""
    }

    //    RightInfo {
    //        id: rightInfo
    //    }

    states: [
        State {
            name: ""
            PropertyChanges { target: speedDisk; visible: false; state: "" }
            PropertyChanges { target: oilBar; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: speedDisk; visible: true; state: "normalMode" }
            PropertyChanges { target: oilBar; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: speedDisk; visible: true; state: "functionMode" }
            PropertyChanges { target: oilBar; visible: true; state: "functionMode" }
        }
    ]
}
