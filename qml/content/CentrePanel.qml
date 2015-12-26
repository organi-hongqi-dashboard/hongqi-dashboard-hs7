import QtQuick 2.2

Rectangle {
    id: centrePanel

    property string valueTime: CarStatus.time
    property string valueDate: CarStatus.date
    property int valueOdo: CarStatus.odo
	property real valueTrip: CarStatus.trip1
	property real valueTrip2: CarStatus.trip2
	property real valueOutsideTemp: CarStatus.outTemp * 0.1 - 40

    property int getAverageFuel: CarStatus.avgFuel
    property real getInstantaneousFuel: CarStatus.instantaneousFuel * 0.1
    property bool getAverageFuelUint: CarStatus.avgFuelUnit
    property bool getInstantaneousFuelUint: CarStatus.instantaneousFuelUnit
    property int getRemainMileage: CarStatus.remainMileage
	property int tripAB: CarStatus.tripAB;

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
        id: bg
        x: 448
        y: 252
        opacity: 0.0
        source: "qrc:/centrePanel/images/centrePanel/bg.png"
    }

    Item {
        id: functionLine
        opacity: 0.0

        Image {
            id: functionUpLine
            x: 324
            y: 34
            source: "qrc:/centrePanel/images/centrePanel/functionUpLine.png"
        }

        Image {
            id: functionDownLine
            x: 324
            y: 586
            source: "qrc:/centrePanel/images/centrePanel/functionDownLine.png"
        }
    }

    Item {
        id: normalLine
        opacity: 0.0

        Image {
            id: normalDownLine
            x: 71
            y: 576
            source: "qrc:/centrePanel/images/centrePanel/normalDownLine.png"
        }
        Image {
            id: normalUpLine
            x: 71
            y: 14
            source: "qrc:/centrePanel/images/centrePanel/normalUpLine.png"
        }
    }

    Image {
        id: runningInfo
        x: 717
        y: 254
        opacity: 0.0
        source: "qrc:/centrePanel/images/centrePanel/runningInfo.png"

        Item {
            id: avgFuel
            anchors.left: runningInfo.left
            anchors.leftMargin: 380
            y: 40
            Image {
                id: avgFuelUnit_100km
                opacity: 0.5
                visible: getAverageFuelUint
                source: "qrc:/centrePanel/images/centrePanel/100km.png"
            }

            Image {
                id: avgFuelUnit_h
                opacity: 0.5
                visible: !getAverageFuelUint
                source: "qrc:/centrePanel/images/centrePanel/h.png"
            }
            Text {
                id: averageFuelV
                anchors.right: avgFuel.left
                anchors.rightMargin: 35
                y: -12
                font.family: fontName.fontCurrent
                font.pixelSize: 28
                font.italic: true
                color: "#ffe5c1"
                text: (centrePanel.getAverageFuel >= 0 && centrePanel.getAverageFuel <= 300) ? (centrePanel.getAverageFuel*0.1).toFixed(1) : qsTr("--.-")
            }
        }

        Item {
            id: instantaneousFuelUnit
            anchors.left: runningInfo.left
            anchors.leftMargin: 380
            y: 111
            Image {
                id: instantaneousFuelUnit_100km
                opacity: 0.5
                visible: getInstantaneousFuelUint
                source: "qrc:/centrePanel/images/centrePanel/100km.png"
            }

            Image {
                id: instantaneousFuelUnit_h
                opacity: 0.5
                visible: !getInstantaneousFuelUint
                source: "qrc:/centrePanel/images/centrePanel/h.png"
            }
            Text {
                id: instantaneousFuel
                anchors.right: instantaneousFuelUnit.left
                anchors.rightMargin: 35
                y: -12
                font.family: fontName.fontCurrent
                font.pixelSize: 28
                font.italic: true
                color: "#ffe5c1"
                text: (centrePanel.getInstantaneousFuel >= 0 && centrePanel.getInstantaneousFuel <= 45) ? centrePanel.getInstantaneousFuel.toFixed(1) : qsTr("--.-")
            }
        }

        Item {
            id: remainMileage
            anchors.left: runningInfo.left
            anchors.leftMargin: 380
            y: 111 + 69

            Text {
                id: remainMileageV
                anchors.right: remainMileage.left
                anchors.rightMargin: 35
                y: -12
                font.family: fontName.fontCurrent
                font.pixelSize: 28
                font.italic: true
                color: "#ffe5c1"
                text: (centrePanel.getRemainMileage >= 0 && centrePanel.getRemainMileage <= 999) ? centrePanel.getRemainMileage : qsTr("---")
            }
        }
    }

    Item {
        id: dateTime

        Text {
            id: numTime
            x: 910
            y: 5
            font.pixelSize: 36
            font.family: fontName.fontCurrent
            font.bold: true
            color: "white"
            text: valueTime
        }

        Text {
            id: numDate
            x: 892
            y: 47
            font.pixelSize: 24
            font.family: fontName.fontCurrent
            color: "white"
            text: valueDate
        }
    }

    Item {
        id: bottomText

        Image {
            id: baseline
            x: 601
            y: 646
            opacity: 1.0
            source: "qrc:/centrePanel/images/centrePanel/baseline.png"
        }

        Item {
            id: temp

            Image {
                id: tempIcon
                x: 1151
                y: 609
                opacity: 1.0
                source: "qrc:/centrePanel/images/centrePanel/tempIcon.png"
            }

            Image {
                id: cTempIcon
                x: 1251
                y: 611
                opacity: 1.0
                width: 20
                height: 19
                source: "qrc:/centrePanel/images/centrePanel/cTempIcon.png"
            }

            Text {
                id: tempV
                text: (valueOutsideTemp >= -40 && valueOutsideTemp <= 165) ? valueOutsideTemp.toFixed(0) : qsTr("---")
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "white"
                y: 597
                font.letterSpacing: 1
                // font.bold: true
                anchors.right: cTempIcon.left
                anchors.rightMargin: 5
            }
        }

        Item {
            id: odo

            Image {
                id: odoIcon
                x: 645
                y: 609
                opacity: 1.0
                source: "qrc:/centrePanel/images/centrePanel/odoIcon.png"
            }

            Image {
                id: odoKmIcon
                x: 840
                y: 611
                opacity: 1.0
                width: 30
                height: 19
                source: "qrc:/centrePanel/images/centrePanel/kmIcon.png"
            }

            Text {
                id: odoV
                text: ""
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "white"
                y: 597
                font.letterSpacing: 1
                // font.bold: true
                anchors.right: odoKmIcon.left
                anchors.rightMargin: 5
            }

            Text {
                id: odoZero
                text: "000000"
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "gray"
                y: 597
                font.letterSpacing: 1
                // font.bold: true
                anchors.right: odoV.left
                anchors.rightMargin: 1
            }
        }

        Item {
            id: trip

            Image {
                id: tripAIcon
                x: 922
                y: 609
                opacity: 0.5
				source: (centrePanel.tripAB == 1) ? "qrc:/centrePanel/images/centrePanel/tripBIcon.png"
						: "qrc:/centrePanel/images/centrePanel/tripAIcon.png"
            }

            Image {
                id: tripKmIcon
                x: 1068
                y: 611
                opacity: 1.0
                width: 30
                height: 19
                source: "qrc:/centrePanel/images/centrePanel/kmIcon.png"
            }

            Text {
                id: tripV
                text: ""
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "white"
                y: 597
                font.letterSpacing: 1
                // font.bold: true
                anchors.right: tripKmIcon.left
                anchors.rightMargin: 5
            }

            Text {
                id: tripZero
                text: "0000.0"
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "gray"
                y: 597
                font.letterSpacing: 1
                // font.bold: true
                anchors.right: tripV.left
                anchors.rightMargin: 1
            }
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
                centrePanel.state = "normalMode";
            } else {
                centrePanel.state = "warningMode";
            }
        }
    }

    property string ssssSource: CarStatus.warningTipSrc
    onSsssSourceChanged: {
        centreWarning.warningSource = CarStatus.warningTipSrc
    }


    states: [
        State {
            name: ""
            PropertyChanges { target: bg; opacity: 0.0 }
            PropertyChanges { target: functionLine; opacity: 0.0 }
            PropertyChanges { target: normalLine; opacity: 0.0 }
            PropertyChanges { target: runningInfo; opacity: 0.0 }
            PropertyChanges { target: centreWarning; opacity: 0.0 }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: bg; opacity: 1.0 }
            PropertyChanges { target: functionLine; opacity: 0.0 }
            PropertyChanges { target: normalLine; opacity: 1.0 }
            PropertyChanges { target: runningInfo; opacity: 1.0 }
            PropertyChanges { target: centreWarning; opacity: 0.0 }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: bg; opacity: 1.0 }
            PropertyChanges { target: functionLine; opacity: 1.0 }
            PropertyChanges { target: normalLine; opacity: 0.0 }
            PropertyChanges { target: runningInfo; opacity: 0.0 }
            PropertyChanges { target: centreWarning; opacity: 0.0 }
        },
        State {
            name: "warningMode"
            PropertyChanges { target: bg; opacity: 1.0 }
            PropertyChanges { target: functionLine; opacity: 0.0 }
            PropertyChanges { target: normalLine; opacity: 1.0 }
            PropertyChanges { target: runningInfo; opacity: 0.0 }
            PropertyChanges { target: centreWarning; opacity: 1.0 }
        }
    ]
    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                PauseAnimation { duration: 4400 }
                ParallelAnimation {
                    NumberAnimation { target: bg; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: functionLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: normalLine; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                    NumberAnimation { target: runningInfo; property: "opacity"; duration: 1000; easing.type: Easing.InBack }
                }
            }
        }
    ]

    //    CarFunction {
    //        id: carFunction
    //    }

    //    CarInfo {
    //        id: carInfo
    //    }

	focus: true
	Keys.onPressed: {
		switch(event.key) {
		case Qt.Key_1:

			buttonShort();
			break;
		case Qt.Key_2:
			buttonLong();

			break;
		}
	}
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
			CarStatus.tripClear = true;
		else
			CarStatus.tripClean2 = true;
	}

	Component.onCompleted: {
		CarStatus.okButtonShort.connect(buttonShort);
		CarStatus.okButtonLong.connect(buttonLong);
	}
}
