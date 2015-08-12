import QtQuick 2.2

Rectangle {
	id: leftPanel

    RpmDisk {
        id: rpmPanel
    }

    LeftInfo {
        id: leftInfo
    }

    SocBar {
        id: socBar
    }

    PowerKwBar {
        id: powerKwBar
    }
    VoltagePanel {
        id:voltagePanel
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rpmPanel; state: "" }
            PropertyChanges { target: leftInfo; state: "" }
        },
        State {
            name: "Bigshow"
            PropertyChanges { target: rpmPanel; state: "Bigshow" }
            PropertyChanges { target: leftInfo; state: "Bigshow" }
        },
        State {
            name: "Smallshow"
            PropertyChanges { target: rpmPanel; state: "Smallshow" }
        }
    ]
    Component.onCompleted: {
        leftPanel.state = "Bigshow"
    }
}
