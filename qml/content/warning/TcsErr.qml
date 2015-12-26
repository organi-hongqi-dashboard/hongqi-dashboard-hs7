import QtQuick 2.2

Item {
	id: brakingMoreErr

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
        id: absWhiteBg
        x: 761
        y: 354
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/absErr/absWhiteBg.png"
    }
    Image {
        id: absRedBg
        x: 725
        y: 328
        opacity: 1.0
        source: "qrc:/centralPanel/images/centralPanel/absErr/absRedBg.png"
    }

	Text {
		x: 910
		y: 258
		anchors.centerIn: textRec
		color: "white"
		font.pixelSize: 32
		font.family: fontName.fontCurrent
		opacity: 1.0
        text: qsTr("TCS故障!")
	}

    ParallelAnimation {
        running: true
        SequentialAnimation {
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 1.0; to: 0; duration: 300 }
            NumberAnimation { target: warningSymbol; property: "opacity"; from: 0; to: 1.0; duration: 300 }
            loops: 2
        }
        SequentialAnimation {
            NumberAnimation { target: absRedBg; property: "opacity"; from: 1.0; to: 0; duration: 800 }
            NumberAnimation { target: absRedBg; property: "opacity"; from: 0; to: 1.0; duration: 800 }
            loops:Animation.Infinite
        }
    }
	states: [
		State {
			name: ""
			PropertyChanges { target: brakingMoreErr; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: brakingMoreErr; opacity: 1.0 }

		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
				NumberAnimation{ target: brakingMoreErr; property: "opacity"; duration: 500 }
			}
		}
	]
	Component.onCompleted: {
	   state = "show"
	}
}
