import QtQuick 2.2

Rectangle {
	id: centreWarning
	opacity: 0.0
	property string warningSource: ""
	onWarningSourceChanged: {
		warning.setSource(centreWarning.warningSource);
	}

	// common
	Image {
		id: frameRec
		x: 709
		y: 253
		opacity: 1.0
		source: "qrc:/warningPic/images/warningPic/frameRec.png"
	}
	Image {
		id: picLight
		x: 576
		y: 414
		opacity: 1.0
		source: "qrc:/warningPic/images/warningPic/picLight.png"
	}
	Image {
		id: picCar
		x: 669
		y: 390
		opacity: 1.0
		source: "qrc:/warningPic/images/warningPic/picCar.png"
	}
	Image {
		id: picWarn
		x: 869
		y: 504
		opacity: 1.0
		source: "qrc:/warningPic/images/warningPic/picWarn.png"
	}

	Loader {
		id: warning
		active: true
		asynchronous: true
		source: ""
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: centreWarning; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: centreWarning; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
				NumberAnimation{ target: centreWarning; property: "opacity"; duration: 100 }
			}
			ParallelAnimation {
				running: true
				SequentialAnimation {
					NumberAnimation { target: picWarn; property: "opacity"; from: 1.0; to: 0; duration: 800 }
					NumberAnimation { target: picWarn; property: "opacity"; from: 0; to: 1.0; duration: 800 }
					loops:Animation.Infinite
				}
			}
		},
		Transition {
			from: "show"
			to: ""
			SequentialAnimation {
				NumberAnimation{ target: centreWarning; property: "opacity"; duration: 500 }
			}
		}
	]
}
