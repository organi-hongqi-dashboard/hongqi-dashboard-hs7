import QtQuick 2.2
import QtQuick.Window 2.2
import "content"
import "content/warning"

Window {
	id: main
	width: 1920
	height: 720
	color: "black"
	visible: true

	Rectangle {
		id: carnation

		SplashPanel {
			id: splashPanel
			state: ""

			onAnimationFinishedChanged: {
				if( animationFinished === true ) {
					mainPanel.state = "normalMode";
					splashPanel.state = "";
				}
			}
		}

		MainPanel {
			id: mainPanel
			state: ""
		}

		Component.onCompleted: {
			splashPanel.state = "show"
		}
	}
}
