import QtQuick 2.4

Item {
	id: functionMenu
	opacity: 0.0

	Image {
		id: menuMainBg
		x: 613
		y: 95
		source: "qrc:/menuPanel/images/menuPanel/menuBg.png"
	}

	Image {
		id: menuLine
		x: 710
		y: 143
		opacity: 1.0
		width: 504
		height: 31
		source: "qrc:/menuPanel/images/menuPanel/menuLine.png"
	}

	ListModel {
		id: menuMainModel
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/car.png"
			nameText:qsTr("车辆信息")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/acc.png"
			nameText:qsTr("主动巡航")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/media.png"
			nameText:qsTr("多媒体")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/nav.png"
			nameText:qsTr("导航")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/nightView.png"
			nameText:qsTr("夜视")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/phone.png"
			nameText:qsTr("电话")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/warning.png"
			nameText:qsTr("报警")
		}
		ListElement {
			name: "qrc:/menuPanel/images/menuPanel/radio.png"
			nameText:qsTr("收音机")
		}
	}

	function getCurrentIndex() {
		return menuMainView.currentIndex;
	}

	function decrementCurrentIndex() {
		return menuMainView.decrementCurrentIndex();
	}

	function incrementCurrentIndex() {
		return menuMainView.incrementCurrentIndex();
	}

	PathView {
		id: menuMainView
		anchors.fill: menuMainBg

		delegate: menuMainDelegate
		model: menuMainModel
		path: Path {
			startX: menuMainBg.width*0.18
			startY: menuMainBg.height * 0.6
			PathAttribute { name: "itemScale"; value: 0.7; }
			PathAttribute { name: "itemOpacity"; value: 0.5; }
			PathLine { x: menuMainBg.width*0.21; y: menuMainBg.height * 0.6; }
			PathPercent { value: 0.2 }
			PathAttribute { name: "itemScale"; value: 0.7; }
			PathAttribute { name: "itemOpacity"; value: 0.5; }
			PathLine { x: menuMainBg.width*0.5; y: menuMainBg.height * 0.6; }
			PathAttribute { name: "itemScale"; value: 1.0; }
			PathAttribute { name: "itemOpacity"; value: 1.0; }
			PathLine { x: menuMainBg.width*0.8; y: menuMainBg.height * 0.6; }
			PathPercent { value: 0.8 }
			PathAttribute { name: "itemScale"; value: 0.7; }
			PathAttribute { name: "itemOpacity"; value: 0.5; }
			PathLine { x: menuMainBg.width*0.85; y: menuMainBg.height * 0.6; }
			PathAttribute { name: "itemScale"; value: 0.7; }
			PathAttribute { name: "itemOpacity"; value: 0.5; }
		}
		Keys.onLeftPressed: if (!moving) decrementCurrentIndex()
		Keys.onRightPressed: if (!moving) incrementCurrentIndex()
		focus: true
		pathItemCount: 5
		preferredHighlightBegin: 0.5
		preferredHighlightEnd: 0.5
	}
	Component {
		id: menuMainDelegate

		Item {
			id: wrapper
			opacity: PathView.itemOpacity
			scale: PathView.itemScale
			Text {
				anchors.horizontalCenter: parent.horizontalCenter
				anchors.bottom:img.top
				text: nameText
				color: "white"
				font.pixelSize: 25
				visible: wrapper.PathView.isCurrentItem
			}
			Image {
				id:img
				anchors.centerIn: parent
				source: name
			}
		}
	}

	Timer{
		id:hideTimer
		interval: 10000;
		running: true;
		onTriggered: {
			functionMenu.state = ""
		}
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: functionMenu; opacity: 0.0 }
		},
		State {
			name: "normalMode"
			PropertyChanges { target: functionMenu; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "normalMode"
			ParallelAnimation {
				NumberAnimation { target: functionMenu; property: "opacity"; duration: 1000 }
			}
		}
	]
}
