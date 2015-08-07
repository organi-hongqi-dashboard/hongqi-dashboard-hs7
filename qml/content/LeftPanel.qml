import QtQuick 2.2

Rectangle {
	id: leftPanel

    RpmDisk {
        id: rpmDisk
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
}
