import QtQuick 2.2

Item {
	id: gearShiftTemHighErr

    // common
//    Image {
//        id: frameRec
//        x: 709
//        y: 253
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/frameRec.png"
//    }
//    Image {
//        id: picLight
//        x: 576
//        y: 414
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picLight.png"
//    }
//    Image {
//        id: picCar
//        x: 669
//        y: 390
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picCar.png"
//    }
//    Image {
//        id: picWarn
//        x: 869
//        y: 504
//        opacity: 1.0
//        source: "qrc:/warningPic/images/warningPic/picWarn.png"
//    }

   // private
    Image {
        id: picMotorIcon
        x: 907
        y: 200
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/picMotorIcon.png"
    }
    Image {
        id: textGasOver
        x: 759
        y: 308
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/textGasOver.png"
    }

//    ParallelAnimation {
//        running: true
//        SequentialAnimation {
//            NumberAnimation { target: picWarn; property: "opacity"; from: 1.0; to: 0; duration: 800 }
//            NumberAnimation { target: picWarn; property: "opacity"; from: 0; to: 1.0; duration: 800 }
//            loops:Animation.Infinite
//        }
//    }
	states: [
		State {
			name: ""
			PropertyChanges { target: gearShiftTemHighErr; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: gearShiftTemHighErr; opacity: 1.0 }

		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
				NumberAnimation{ target: gearShiftTemHighErr; property: "opacity"; duration: 500 }
			}
		}
	]
	Component.onCompleted: {
		state = "show"
	}
}
