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

        focus: true
        Keys.onPressed: {
            switch(event.key) {
            case Qt.Key_1:

                mainPanel.state = "functionMode"
                break;
            case Qt.Key_2:
                mainPanel.state = "normalMode"

                break;
            }
        }

        //        Fps {
        //            id: fps
        //        }

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

		WasteGasMonitoringSysErr {
			state: "show"
		}


        Component.onCompleted: {
            splashPanel.state = "show"
        }
    }
}
