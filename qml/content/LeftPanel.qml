import QtQuick 2.2

Item {
    id: leftPanel

    RpmDisk {
        id: rpmDisk
        state: ""
    }

    GearPanel {
        id: gearPanel
        state: ""
    }

//    LeftInfo {
//        id: leftInfo
//    }

//    SocBar {
//        id: socBar
//    }

//    PowerKwBar {
//        id: powerKwBar
//    }
//    VoltagePanel {
//        id:voltagePanel
//    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rpmDisk; visible: false; state: "" }
            PropertyChanges { target: gearPanel; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: rpmDisk; visible: true; state: "normalMode" }
            PropertyChanges { target: gearPanel; visible: true; state: "normalMode" }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: rpmDisk; visible: true; state: "functionMode" }
            PropertyChanges { target: gearPanel; visible: true; state: "functionMode" }
        }
    ]
}
