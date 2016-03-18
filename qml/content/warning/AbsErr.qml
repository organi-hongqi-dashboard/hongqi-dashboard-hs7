import QtQuick 2.2

Item {
    id: absErr

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
        id: picAbs
        x: 910
        y: 200
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/picAbs.png"
    }
    Image {
        id: textABSFault
        x: 889
        y: 308
        opacity: 1.0
        source: "qrc:/warningPic/images/warningPic/textABSFault.png"
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
			PropertyChanges { target: absErr; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: absErr; opacity: 1.0 }

		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
				NumberAnimation{ target: absErr; property: "opacity"; duration: 500 }
			}
		}
	]
	Component.onCompleted: {
	   state = "show"
	}
}
