import QtQuick 2.2

Item {
    id: changeBrakeFront

	// common
	Image {
		id: textRec
		x: 697
		y: 233
		opacity: 1.0
		source: "qrc:/centralPanel/images/centralPanel/textRec.png"
	}
	Image {
		id: warningSymbol
		x: 775
		y: 251
		opacity: 1.0
		source: "qrc:/centralPanel/images/centralPanel/warningSymbol.png"
	}

	// private
    Image {
        id: brake
        x: 853
        y: 337
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/changebreak/brake.png"
    }
    Image {
        id: brakeRed
        x: 836
        y: 317
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/changebreak/brakeRed.png"
    }

	Text {
		anchors.centerIn: textRec
		color: "white"
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		opacity: 1.0
        text: qsTr("请更换前制动摩擦片!")
	}

	ParallelAnimation {
		running: true
		SequentialAnimation {
			NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
			NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
			loops: 2
		}
		SequentialAnimation {
            NumberAnimation { target: brakeRed; property: "opacity"; from: 1.0; to: 0; duration: 800 }
			PauseAnimation { duration: 300 }
            NumberAnimation { target: brakeRed; property: "opacity"; from: 0; to: 1.0; duration: 800 }
			loops:Animation.Infinite
		}
	}
	states: [
		State {
			name: ""
            PropertyChanges { target: changeBrakeFront; opacity: 0.0 }
		},
		State {
			name: "show"
            PropertyChanges { target: changeBrakeFront; opacity: 1.0 }

		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
                NumberAnimation{ target: changeBrakeFront; property: "opacity"; duration: 500 }
			}
		}
	]
	Component.onCompleted: {
		state = "show"
	}
}
