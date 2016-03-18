import QtQuick 2.2

Rectangle {
	id: centrePanel

	property string valueTime: CarStatus.time
	property string valueDate: CarStatus.date
	property int valueOdo: CarStatus.odo
	property real valueTrip: CarStatus.trip1
	property real valueTrip2: CarStatus.trip2
	property real valueOutsideTemp: CarStatus.outTemp * 0.1 - 40

	property int getAvgSpeed: CarStatus.avgSpeed
	property int getAverageFuel: CarStatus.avgFuel
	property real getInstantaneousFuel: CarStatus.instantaneousFuel * 0.1
	property bool getAverageFuelUint: CarStatus.avgFuelUnit
	property bool getInstantaneousFuelUint: CarStatus.instantaneousFuelUnit
	property int getRemainMileage: CarStatus.remainMileage
	property int tripAB: CarStatus.tripAB;

	Image {
		id: bg
		x: 159
		y: 183
		opacity: 1.0
		width: 1597
		height: 536
		source: "qrc:/centrePanel/images/centrePanel/bg.png"
	}
	Image {
		id: lineBg
		x: 527
		y: 66
		opacity: 1.0
		width: 864
		height: 8
		source: "qrc:/centrePanel/images/centrePanel/lineBg.png"
	}

	Text {
		id: numTime
		x: 526
		y: 16
		font.pixelSize: 36
		font.family: fontName.fontCurrent
		color: "white"
		text: valueTime
	}

	Text {
		id: temputure
		anchors.right: temputureUint.left
		y: 16
		font.pixelSize: 36
		font.family: fontName.fontCurrent
		color: "white"
		text: "--"
	}
	Image {
		id: temputureUint
		x: 1368
		y: 27
		opacity: 1.0
		width: 23
		height: 22
		source: "qrc:/centrePanel/images/centrePanel/temputureUint.png"
	}


	property int zeroTripNum: 0
	property int iTrip: 0
	onValueTripChanged: {
		if( tripAB == 1 )
			return;
		zeroTripNum = 0;
		iTrip = valueTrip;
		while( iTrip != 0 ){
			zeroTripNum++;
			iTrip /= 10;
		}

		zeroTripNum = 5 - zeroTripNum;
		switch(zeroTripNum) {
		case 0:
			tripZero.text = "";
			break;
		case 1:
			tripZero.text = "0";
			break;
		case 2:
			tripZero.text = "00";
			break;
		case 3:
			tripZero.text = "000";
			break;
		case 4:
			tripZero.text = "000";
			break;
		default:
			tripZero.text = "0000.0";
			break;
		}

		if( valueTrip == 0 || valueTrip > 99999 )
			tripV.text = "";
		else
			tripV.text = (valueTrip * 0.1).toFixed(1);
	}

	property int zeroTripNum2: 0
	property int iTrip2: 0
	onValueTrip2Changed: {
		if( tripAB == 0 )
			return;
		zeroTripNum2 = 0;
		iTrip2 = valueTrip2;
		while( iTrip2 != 0 ){
			zeroTripNum2++;
			iTrip2 /= 10;
		}

		zeroTripNum2 = 5 - zeroTripNum2;
		switch(zeroTripNum2) {
		case 0:
			tripZero.text = "";
			break;
		case 1:
			tripZero.text = "0";
			break;
		case 2:
			tripZero.text = "00";
			break;
		case 3:
			tripZero.text = "000";
			break;
		case 4:
			tripZero.text = "000";
			break;
		default:
			tripZero.text = "0000.0";
			break;
		}

		if( valueTrip2 == 0 || valueTrip2 > 99999 )
			tripV.text = "";
		else
			tripV.text = (valueTrip2 * 0.1).toFixed(1);
	}

	Image {
		id: tripAIcon
		x: 1709
		y: 673
		opacity: 1.0
		width: 24
		height: 24
		source: (tripAB == 1) ? "qrc:/centrePanel/images/centrePanel/tripBIcon.png"
							  : "qrc:/centrePanel/images/centrePanel/tripAIcon.png"
	}

	Text {
		id: tripV
		text: ""
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		color: "white"
		y: 664
		font.letterSpacing: 1
		anchors.right: tripUint.left
		anchors.leftMargin: 5
	}

	Text {
		id: tripZero
		text: "0000.0"
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		color: "gray"
		y: 664
		anchors.right: tripV.left
	}

	Image {
		id: tripUint
		x: 1844
		y: 677
		opacity: 1.0
		width: 34
		height: 21
		source: "qrc:/centrePanel/images/centrePanel/tripUint.png"
	}

	property int zeroOdoNum: 0
	property int iOdo: 0
	onValueOdoChanged: {
		zeroOdoNum = 0;
		iOdo = valueOdo;
		while( iOdo != 0 ){
			zeroOdoNum++;
			iOdo /= 10;
		}

		zeroOdoNum = 6 - zeroOdoNum;
		switch(zeroOdoNum) {
		case 0:
			odoZero.text = "";
			break;
		case 1:
			odoZero.text = "0";
			break;
		case 2:
			odoZero.text = "00";
			break;
		case 3:
			odoZero.text = "000";
			break;
		case 4:
			odoZero.text = "0000";
			break;
		case 5:
			odoZero.text = "00000";
			break;
		default:
			odoZero.text = "000000";
			break;
		}

		if( valueOdo == 0 || valueOdo > 999999 )
			odoV.text = "";
		else
			odoV.text = valueOdo;
	}

	Image {
		id: odoUint
		x: 157
		y: 677
		opacity: 1.0
		width: 33
		height: 21
		source: "qrc:/centrePanel/images/centrePanel/odoUint.png"
	}

	Text {
		id: odoV
		text: ""
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		color: "white"
		y: 664
		anchors.right: odoUint.left
		anchors.rightMargin: 5
	}

	Text {
		id: odoZero
		text: "000000"
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		color: "gray"
		y: 664
		anchors.right: odoV.left
	}


	GearPanel {
		id:gearPanel
	}


	Item{
		id: runningInfo
		visible: true
		Image {
			id: runningInfoTemp
			x: 764
			y: 265
			opacity: 1.0
			width: 404
			height: 261
			source: "qrc:/common/images/common/runningInfoTemp.png"
		}



		DigitValue {
			id: averageSpeed
			anchors.right: runningInfoTemp.right
			anchors.rightMargin: 180 +10
			y:313
			icon0: "qrc:/common/images/common/num0.png"
			icon1: "qrc:/common/images/common/num1.png"
			icon2: "qrc:/common/images/common/num2.png"
			icon3: "qrc:/common/images/common/num3.png"
			icon4: "qrc:/common/images/common/num4.png"
			icon5: "qrc:/common/images/common/num5.png"
			icon6: "qrc:/common/images/common/num6.png"
			icon7: "qrc:/common/images/common/num7.png"
			icon8: "qrc:/common/images/common/num8.png"
			icon9: "qrc:/common/images/common/num9.png"
			value: getAvgSpeed
		}

		DigitValue {
			id: avgFuel_shiShu
			anchors.right: runningInfoTemp.right
			anchors.rightMargin: 180 + 60 +10
			y:313 + 165
			icon0: "qrc:/common/images/common/num0.png"
			icon1: "qrc:/common/images/common/num1.png"
			icon2: "qrc:/common/images/common/num2.png"
			icon3: "qrc:/common/images/common/num3.png"
			icon4: "qrc:/common/images/common/num4.png"
			icon5: "qrc:/common/images/common/num5.png"
			icon6: "qrc:/common/images/common/num6.png"
			icon7: "qrc:/common/images/common/num7.png"
			icon8: "qrc:/common/images/common/num8.png"
			icon9: "qrc:/common/images/common/num9.png"
			value: getAverageFuel / 10
		}

		DigitValue {
			id: avgFuel_xiaoShu
			anchors.right: runningInfoTemp.right
			anchors.rightMargin: 180 +10
			y:313 + 165
			icon0: "qrc:/common/images/common/num0.png"
			icon1: "qrc:/common/images/common/num1.png"
			icon2: "qrc:/common/images/common/num2.png"
			icon3: "qrc:/common/images/common/num3.png"
			icon4: "qrc:/common/images/common/num4.png"
			icon5: "qrc:/common/images/common/num5.png"
			icon6: "qrc:/common/images/common/num6.png"
			icon7: "qrc:/common/images/common/num7.png"
			icon8: "qrc:/common/images/common/num8.png"
			icon9: "qrc:/common/images/common/num9.png"
			value: getAverageFuel % 10
		}

		Image {
			id: avgFuelUint
			anchors.left: avgFuel_xiaoShu.right
			anchors.leftMargin: 10
			y:505
			source: getAverageFuelUint ? "qrc:/common/images/common/l100km.png" : "qrc:/common/images/common/lh.png"
		}

	}



	// tips
	//    centreWarning.warningSource = CarStatus.warningTipSrc

	CentreWarning {
		id: centreWarning
		state: ""
		onWarningSourceChanged: {
			//            centreWarning.warningSource = CarStatus.warningTipSrc
			if( centreWarning.warningSource == "" ) {
				centreWarning.state = "";
				runningInfo.visible = true;
			} else {
				centreWarning.state = "show";
				runningInfo.visible = false;
			}
		}
	}

	property string ssssSource: CarStatus.warningTipSrc
	onSsssSourceChanged: {
		centreWarning.warningSource = CarStatus.warningTipSrc
	}


	//    states: [
	//        State {
	//            name: ""
	//            PropertyChanges { target: bg; opacity: 0.0 }
	//            PropertyChanges { target: functionLine; opacity: 0.0 }
	//            PropertyChanges { target: normalLine; opacity: 0.0 }
	//            PropertyChanges { target: runningInfo; opacity: 0.0 }
	//            PropertyChanges { target: centreWarning; opacity: 0.0 }
	//        },
	//        State {
	//            name: "normalMode"
	//            PropertyChanges { target: bg; opacity: 1.0 }
	//            PropertyChanges { target: functionLine; opacity: 0.0 }
	//            PropertyChanges { target: normalLine; opacity: 1.0 }
	//            PropertyChanges { target: runningInfo; opacity: 1.0 }
	//            PropertyChanges { target: centreWarning; opacity: 0.0 }
	//        },
	//        State {
	//            name: "functionMode"
	//            PropertyChanges { target: bg; opacity: 1.0 }
	//            PropertyChanges { target: functionLine; opacity: 1.0 }
	//            PropertyChanges { target: normalLine; opacity: 0.0 }
	//            PropertyChanges { target: runningInfo; opacity: 0.0 }
	//            PropertyChanges { target: centreWarning; opacity: 0.0 }
	//        },
	//        State {
	//            name: "warningMode"
	//            PropertyChanges { target: bg; opacity: 1.0 }
	//            PropertyChanges { target: functionLine; opacity: 0.0 }
	//            PropertyChanges { target: normalLine; opacity: 1.0 }
	//            PropertyChanges { target: runningInfo; opacity: 0.0 }
	//            PropertyChanges { target: centreWarning; opacity: 1.0 }
	//        }
	//    ]
	//    transitions: [
	//        Transition {
	//            from: ""
	//            to: "normalMode"
	//            SequentialAnimation {
	//                PauseAnimation { duration: 4400 }
	//                ParallelAnimation {
	//                    NumberAnimation { target: bg; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                }
	//            }
	//        },
	//        Transition {
	//            from: "normalMode"
	//            to: "functionMode"
	//            SequentialAnimation {
	//                ParallelAnimation {
	//                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                }
	//            }
	//        },
	//        Transition {
	//            from: "functionMode"
	//            to: "normalMode"
	//            SequentialAnimation {
	//                ParallelAnimation {
	//                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
	//                }
	//            }
	//        }
	//    ]


	//	focus: true
	//	Keys.onPressed: {
	//		switch(event.key) {
	//		case Qt.Key_1:

	//			buttonShort();
	//			break;
	//		case Qt.Key_2:
	//			buttonLong();

	//			break;
	//		}
	//	}
	function buttonShort() {
		if( tripAB == 0) {
			tripAB = 1;
			zeroTripNum2 = 0;
			iTrip2 = valueTrip2;
			while( iTrip2 != 0 ){
				zeroTripNum2++;
				iTrip2 /= 10;
			}

			zeroTripNum2 = 5 - zeroTripNum2;
			switch(zeroTripNum2) {
			case 0:
				tripZero.text = "";
				break;
			case 1:
				tripZero.text = "0";
				break;
			case 2:
				tripZero.text = "00";
				break;
			case 3:
				tripZero.text = "000";
				break;
			case 4:
				tripZero.text = "000";
				break;
			default:
				tripZero.text = "0000.0";
				break;
			}

			if( valueTrip2 == 0 || valueTrip2 > 99999 )
				tripV.text = "";
			else
				tripV.text = (valueTrip2 * 0.1).toFixed(1);
		}
		else {
			tripAB = 0;
			zeroTripNum = 0;
			iTrip = valueTrip;
			while( iTrip != 0 ){
				zeroTripNum++;
				iTrip /= 10;
			}

			zeroTripNum = 5 - zeroTripNum;
			switch(zeroTripNum) {
			case 0:
				tripZero.text = "";
				break;
			case 1:
				tripZero.text = "0";
				break;
			case 2:
				tripZero.text = "00";
				break;
			case 3:
				tripZero.text = "000";
				break;
			case 4:
				tripZero.text = "000";
				break;
			default:
				tripZero.text = "0000.0";
				break;
			}

			if( valueTrip == 0 || valueTrip > 99999 )
				tripV.text = "";
			else
				tripV.text = (valueTrip * 0.1).toFixed(1);
		}
	}

	function buttonLong() {
		if( tripAB == 0 )
			CarStatus.tripClean = true;
		else
			CarStatus.tripClean2 = true;
	}

	Component.onCompleted: {
		CarStatus.okButtonShort.connect(buttonShort);
		CarStatus.okButtonLong.connect(buttonLong);
	}
}
