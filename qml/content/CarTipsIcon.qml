import QtQuick 2.2

Rectangle {
	id: carTipsIcon

	property bool leftHandDriveValue: CarStatus.leftHandDrive
	property bool rightHandDriveValue: CarStatus.rightHandDrive
	property bool highBeamValue: CarStatus.highBeam
	property bool dippedBeamValue: CarStatus.dippedBeam
	property bool positionLightValue: CarStatus.positionLight
	property bool frontFogLightValue: CarStatus.frontFogLight
	property bool rearFogLightValue: CarStatus.rearFogLight
	property bool auxiliaryHighBeamValue: CarStatus.auxiliaryHighBeam

	property bool safetyBeltLightValue: CarStatus.safetyBeltLight
	property bool airBagLightValue: CarStatus.airBagLight
	property bool engineFaultLightValue: CarStatus.engineFaultLight
	property bool absFaultValue: CarStatus.absFault
	property bool oilPressureLowValue: CarStatus.oilPressureLow
	property bool batteryFaultLightValue: CarStatus.batteryFaultLight
	property bool brakeSystemFailureValue: CarStatus.brakeSystemFailure
	property bool parkingLightValue: CarStatus.parkingLight

	property bool oilLowLightValue: CarStatus.oilLowLight
	property bool coolantLowLightValue: CarStatus.coolantLowLight
	property int espLightValue: CarStatus.espLight
	//property bool espOffLightValue: CarStatus.espOffLight
	property bool afsOffLightValue: CarStatus.afsOffLight
	property bool milLightValue: CarStatus.milLight
	property bool gearboxErrLightValue: CarStatus.gearboxErrLight
	property bool changeBrakePadsLightValue: CarStatus.changeBrakePadsLight

	property bool electronicParkingLightValue: CarStatus.electronicParkingLight

	property bool breakSystemPicValue: CarStatus.breakSystemPic
	property bool brakeFluidPicValue: CarStatus.brakeFluidPic
	property bool addOilPicValue: CarStatus.addOilPic
	property bool batteryFaultPicValue: CarStatus.batteryFaultPic
	property bool oilPressureLowPicValue: CarStatus.oilPressureLowPic
	property bool coolantSystemErrPicValue: CarStatus.coolantSystemErrPic
	property bool absFaultPicValue: CarStatus.absFaultPic
	property bool epbFaultPicValue: CarStatus.epbFaultPic

	property bool engineCtlFaultPicValue: CarStatus.engineCtlFaultPic
	property bool exhaustEmissionPicValue: CarStatus.exhaustEmissionPic
	property bool espFaultPicValue: CarStatus.espFaultPic
	property bool airBagFaultPicValue: CarStatus.airBagFaultPic
	property bool speedChangerErrPicValue: CarStatus.speedChangerErrPic
	property bool speedChaTempHighPicValue: CarStatus.speedChaTempHighPic

	Image {
		id: leftHandDrive
		x: 570
		y: 20
		opacity: true == leftHandDriveValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/leftHandDrive.png"
	}
	Image {
		id: rightHandDrive
		x: 1298
		y: 20
		opacity: true == rightHandDriveValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/rightHandDrive.png"
	}

	Image {
		id: airbagErrLight
		//        x: 829
		//        y: 662
		x: 1815
		y: 61
		opacity: true == airBagLightValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/airbagErrLight.png"
	}

	Image {
		id: engineErrLight
		//        x: 1084
		//        y: 667
		x: 1126 - 10
		y: 12 + 5
		opacity: (true == engineFaultLightValue || true == milLightValue) ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/engineErrLight.png"
	}
	Image {
		id: absErrLight
		x: 1859
		y: 24
		opacity: true == absFaultValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/absErrLight.png"
	}

	Image {
		id: engineOilLight
		x: 1787
		y: 676
		opacity: oilPressureLowValue ? 1.0 : 0.0
		width: 56
		height: 22
		source: "qrc:/carTipsIcon/images/carTipsIcon/engineOilLight.png"
	}

	Image {
		id: sysBattErr
		x: 1852
		y: 671
		opacity: batteryFaultLightValue ? 1.0 : 0.0
		width: 48
		height: 30
		source: "qrc:/carTipsIcon/images/carTipsIcon/sysBattErr.png"
	}

	Image {
		id: breakSysErrLight
		//        x: 1018
		//        y: 663
		x: 1765
		y: 25
		opacity: true == brakeSystemFailureValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/breakSysErrLight.png"
	}

	Image {
		id: epbErrLight
		x: 1852
		y: 622
		opacity: parkingLightValue ? 1.0 : 0.0
		width: 48
		height: 33
		source: "qrc:/carTipsIcon/images/carTipsIcon/epbErrLight.png"
	}

	onEspLightValueChanged: {
		switch( espLightValue ) {
		case 1:
			espErrLightBlink.running = false;
			espErrLight.visible = true;
			break;
		case 2:
			espErrLightBlink.running = true;
			espErrLight.visible = true;
			break;
		default:
			espErrLightBlink.running = false;
			espErrLight.visible = false;
			break;
		}
	}

	Timer {
		id: espErrLightBlink
		interval: 500;
		running: false;
		repeat: true
		onTriggered: {
			espErrLight.visible = !espErrLight.visible;
		}
	}

	Image {
		id: espErrLight
		//        x: 769
		//        y: 662
		x: 1866
		y: 105
		visible: false
		source: "qrc:/carTipsIcon/images/carTipsIcon/espErrLight.png"
	}

	Image {
		id: gearboxLight
		//        x: 1245
		//        y: 660
		x: 1176
		y: 12
		opacity: gearboxErrLightValue ? 1.0 : 0.0
		width: 49
		height: 48
		source: "qrc:/carTipsIcon/images/carTipsIcon/gearboxLight.png"
	}

	Image {
		id: changeBrakePadsLight
		//		x: 1178
		//		y: 664
		x: 636
		y: 25
		opacity: true == changeBrakePadsLightValue ? 1.0 : 0.0
		width: 51
		height: 39
		source: "qrc:/carTipsIcon/images/carTipsIcon/changeBrakePadsLight.png"
	}

	Image {
		id: breakSys
		x: 758
		y: 23
		opacity: true == electronicParkingLightValue ? 1.0 : 0.0
		source: "qrc:/carTipsIcon/images/carTipsIcon/breakSys.png"
	}


	//    Image {
	//        id: powerSteerErrLight
	//        x: 563
	//        y: 666
	//        opacity: 1.0
	//        width: 48
	//        height: 37
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/powerSteerErrLight.png"
	//    }
	//    Image {
	//        id: abaErrLight
	//        x: 1048
	//        y: 657
	//        opacity: 1.0
	//        width: 54
	//        height: 51
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/abaErrLight.png"
	//    }
	//	Image {
	//		id: refrigerantLowLight
	//		x: 1176
	//		y: 12
	//		opacity: 1.0
	//		width: 34
	//		height: 46
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/refrigerantLowLight.png"
	//	}
	//	Image {
	//		id: bluetoothLight
	//		x: 1126
	//		y: 12
	//		opacity: 1.0
	//		width: 31
	//		height: 48
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/bluetoothLight.png"
	//	}
	//    Image {
	//        id: afsOff
	//        x: 1060
	//        y: 19
	//		opacity: 1//afsOffLightValue ? 1.0 : 0.0
	//        width: 49
	//        height: 42
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/afsOff.png"
	//    }
	//    Image {
	//        id: autoLightsWiperErrLight
	//        x: 148
	//        y: 24
	//        opacity: 1.0
	//        width: 54
	//        height: 31
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/autoLightsWiperErrLight.png"
	//    }
	//    Image {
	//        id: lightErrLight
	//        x: 82
	//        y: 15
	//        opacity: 1.0
	//        width: 53
	//        height: 48
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/lightErrLight.png"
	//    }
	//    Image {
	//        id: headlampAdjustErrLight
	//        x: 17
	//        y: 10
	//        opacity: 1.0
	//        width: 48
	//        height: 51
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/headlampAdjustErrLight.png"
	//    }
	//    Image {
	//        id: nightVisionLight
	//        x: 16
	//        y: 596
	//        opacity: 1.0
	//        width: 47
	//        height: 51
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/nightVisionLight.png"
	//    }

	//	Image {
	//		id: mainErrLight
	//		x: 19
	//		y: 664
	//		opacity: 1.0
	//		width: 48
	//		height: 42
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/mainErrLight.png"
	//	}
	//	Image {
	//		id: passiveEntrySysErrLight
	//		x: 82
	//		y: 677
	//		opacity: 1.0
	//		width: 54
	//		height: 24
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/passiveEntrySysErrLight.png"
	//	}
	//	Image {
	//		id: unknownKeyLight
	//		x: 1859
	//		y: 24
	//		opacity: 1.0
	//		width: 51
	//		height: 43
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/unknownKeyLight.png"
	//	}
	//	Image {
	//		id: keyBatLowLight
	//		x: 1765
	//		y: 25
	//		opacity: 1.0
	//		width: 55
	//		height: 39
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/keyBatLowLight.png"
	//	}
	//	Image {
	//		id: ignitionSwitchErrLight
	//		x: 1815
	//		y: 61
	//		opacity: 1.0
	//		width: 51
	//		height: 51
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/ignitionSwitchErrLight.png"
	//	}
	//	Image {
	//		id: steeringColumnLockErrLight
	//		x: 1866
	//		y: 105
	//		opacity: 1.0
	//		width: 39
	//		height: 54
	//		source: "qrc:/carTipsIcon/images/carTipsIcon/steeringColumnLockErrLight.png"
	//	}

	//    Image {
	//        id: ldwGreen
	//        x: 867
	//        y: 658
	//        opacity: 1.0
	//        width: 39
	//        height: 50
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/ldwGreen.png"
	//    }
	//    Image {
	//        id: ldwYellow
	//        x: 867
	//        y: 658
	//        opacity: 1.0
	//        width: 39
	//        height: 50
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/ldwYellow.png"
	//    }
	//    Image {
	//        id: ldwRed
	//        x: 867
	//        y: 658
	//        opacity: 1.0
	//        width: 39
	//        height: 50
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/ldwRed.png"
	//    }
	//    Image {
	//        id: tirePressWarning
	//        x: 1310
	//        y: 660
	//        opacity: 1.0
	//        width: 45
	//        height: 45
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/tirePressWarning.png"
	//    }
	//    Image {
	//        id: tirePressRed
	//        x: 1310
	//        y: 660
	//        opacity: 1.0
	//        width: 45
	//        height: 45
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/tirePressRed.png"
	//    }
	//    Image {
	//        id: accYellow
	//        x: 982
	//        y: 661
	//        opacity: 1.0
	//        width: 48
	//        height: 42
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/accYellow.png"
	//    }
	//    Image {
	//        id: accRed
	//        x: 982
	//        y: 661
	//        opacity: 1.0
	//        width: 48
	//        height: 42
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/accRed.png"
	//    }
	//    Image {
	//        id: accGreen
	//        x: 983
	//        y: 666
	//        opacity: 1.0
	//        width: 53
	//        height: 36
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/accGreen.png"
	//    }
	//    Image {
	//        id: ccsGreen
	//        x: 1113
	//        y: 660
	//        opacity: 1.0
	//        width: 51
	//        height: 45
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/ccsGreen.png"
	//    }
	//    Image {
	//        id: ccsYellow
	//        x: 1113
	//        y: 660
	//        opacity: 1.0
	//        width: 51
	//        height: 45
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/ccsYellow.png"
	//    }
	//    Image {
	//        id: autoHoldErrLight
	//        x: 624
	//        y: 666
	//        opacity: 1.0
	//        width: 55
	//        height: 37
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/autoHoldErrLight.png"
	//    }
	//    Image {
	//        id: scmSysErrLight
	//        x: 753
	//        y: 657
	//        opacity: 1.0
	//        width: 42
	//        height: 54
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/scmSysErrLight.png"
	//    }
	//    Image {
	//        id: fourWD
	//        x: 808
	//        y: 660
	//        opacity: 1.0
	//        width: 45
	//        height: 46
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/fourWD.png"
	//    }
	//    Image {
	//        id: fcwCloseErrLight
	//        x: 918
	//        y: 663
	//        opacity: 1.0
	//        width: 55
	//        height: 42
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/fcwCloseErrLight.png"
	//    }
	//    Image {
	//        id: stopAndGoGreen
	//        x: 692
	//        y: 658
	//        opacity: 1.0
	//        width: 45
	//        height: 48
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/stopAndGoGreen.png"
	//    }
	//    Image {
	//        id: stopAndGoYellow
	//        x: 692
	//        y: 658
	//        opacity: 1.0
	//        width: 45
	//        height: 48
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/stopAndGoYellow.png"
	//    }
	//    Image {
	//        id: stopAndGoWhite
	//        x: 694
	//        y: 660
	//        opacity: 1.0
	//        width: 42
	//        height: 45
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/stopAndGoWhite.png"
	//    }
	//    Image {
	//        id: fcwErrLight
	//        x: 920
	//        y: 663
	//        opacity: 1.0
	//        width: 51
	//        height: 42
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/fcwErrLight.png"
	//    }
	//    Image {
	//        id: fcwNoticeLight
	//        x: 1051
	//        y: 660
	//        opacity: 1.0
	//        width: 50
	//        height: 46
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/fcwNoticeLight.png"
	//    }
	//    Image {
	//        id: abaCloseLight
	//        x: 1051
	//        y: 660
	//        opacity: 1.0
	//        width: 50
	//        height: 46
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/abaCloseLight.png"
	//    }
	//    Image {
	//        id: highBeamLight
	//        x: 636
	//        y: 25
	//		opacity: 1//highBeamValue ? 1.0 : 0.0
	//        width: 51
	//        height: 33
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/highBeamLight.png"
	//    }
	//    Image {
	//        id: rearFogLight1
	//        x: 696
	//        y: 22
	//		opacity: 1//rearFogLightValue ? 1.0 : 0.0
	//        width: 51
	//        height: 39
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/rearFogLight.png"
	//    }
	//    Image {
	//        id: frontFogLight1
	//        x: 758
	//        y: 23
	//		opacity: 1//frontFogLightValue ? 1.0 : 0.0
	//        width: 48
	//        height: 38
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/frontFogLight.png"
	//    }
	//    Image {
	//        id: positionLight1
	//        x: 814
	//        y: 27
	//		opacity: 1//positionLightValue ? 1.0 : 0.0
	//        width: 55
	//        height: 30
	//        source: "qrc:/carTipsIcon/images/carTipsIcon/positionLight.png"
	//    }
}
