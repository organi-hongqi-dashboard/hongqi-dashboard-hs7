import QtQuick 2.2

Item {
    id: leftPanel

    RpmDisk {
        id: rpmDisk
        state: ""
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: rpmDisk; visible: false; state: "" }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: rpmDisk; visible: true; state: "normalMode" }
		}
    ]
}
