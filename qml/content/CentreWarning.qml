import QtQuick 2.2

Rectangle {
    id: centreWarning
	property string warningSource: ""
	onWarningSourceChanged: {
		warning.setSource(centreWarning.warningSource);
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
			PropertyChanges { target: warning; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: warning; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation {
				NumberAnimation{ target: warning; property: "opacity"; duration: 500 }
			}
		},
		Transition {
			from: "show"
			to: ""
			SequentialAnimation {
				NumberAnimation{ target: warning; property: "opacity"; duration: 500 }
			}
		}
	]
}
