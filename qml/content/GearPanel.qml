import QtQuick 2.2

Item {
	id: gearPanel
	opacity: 1.0

	property int setGear: 0
	property int setGearIndex: 0
	property int gear: CarStatus.gear
	property int gearMode: CarStatus.gearMode

	function setGearV() {
		switch( gear ) {
		case 0: // P
			gearShow.source = "qrc:/centrePanel/images/centrePanel/gearP.png"
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			switch( gearMode ) {
			case 1: //D
				gearShow.source = "qrc:/centrePanel/images/centrePanel/gearD" + gear + ".png"
				break;
			case 2: //S
				gearShow.source = "qrc:/centrePanel/images/centrePanel/gearS" + gear + ".png"
				break;
			case 3: //M
				gearShow.source = "qrc:/centrePanel/images/centrePanel/gearM" + gear + ".png"
				break;
			default:
				gearShow.source = "qrc:/centrePanel/images/centrePanel/gearN.png"
				break;
			}
			break;
		case 0x0e: //N
			gearShow.source = "qrc:/centrePanel/images/centrePanel/gearN.png"
			break;
		case 0x0f: //R
			gearShow.source = "qrc:/centrePanel/images/centrePanel/gearR.png"
			break;
		default:
			gearShow.source = "qrc:/centrePanel/images/centrePanel/gearN.png"
			break;
		}
	}

	onGearChanged: {
		setGearV();
	}

	onGearModeChanged: {
		setGearV();
	}

	Image {
		id: gearShow
		x: 1200
		y: 591
		opacity: 1.0
		width: 87
		height: 59
		source: "qrc:/centrePanel/images/centrePanel/gearN.png"
	}
}
