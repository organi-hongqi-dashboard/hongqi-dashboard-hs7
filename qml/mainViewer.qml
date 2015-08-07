import QtQuick 2.2
import QtQuick.Window 2.2
import "content"

Window {
    id: main
    width: 1920
    height: 720
    color: "black"
    visible: true

    Rectangle {
        id: hongqi_hs7
        color: "black"

        MainPanel {
            id: mainPanel
        }
        Fps {
            id: fps
        }
    }
}
