import QtQuick 2.2

Rectangle {
	id: rightPanel

    SpeedDisk {
        id: speedDisk
	}

    RightInfo {
        id: rightInfo
    }

    OilBar {
        id: oilBar
	}

    WaterTempBar {
        id: waterTempBar
    }
}
