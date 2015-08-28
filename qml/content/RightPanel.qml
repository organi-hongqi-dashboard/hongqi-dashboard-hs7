import QtQuick 2.2

Rectangle {
	id: rightPanel

    SpeedDisk {
        id: speedDisk
        state: ""
	}

//    RightInfo {
//        id: rightInfo
//    }

//    OilBar {
//        id: oilBar
//	}

//    WaterTempBar {
//        id: waterTempBar
//    }

    states: [
        State {
            name: ""
            PropertyChanges { target: speedDisk; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: speedDisk; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: speedDisk; visible: true; state: "functionMode" }
        }
    ]
}
