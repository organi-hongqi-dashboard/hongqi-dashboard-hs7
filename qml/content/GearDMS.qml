import QtQuick 2.2

Rectangle {
    id: gearDMSPanel
    y: 80

    property string getIcon1: ""
    property string getIcon2: ""
    property string getIcon3: ""
    property string getIcon4: ""
    property string getIcon5: ""
    property string getIcon6: ""
    property string getIcon7: ""
    //property string getIcon8: ""
    property int getIndex: 0

    ListModel {
        id: appModel
    }

    Component.onCompleted: {
        appModel.append({"icon": gearDMSPanel.getIcon1});
        appModel.append({"icon": gearDMSPanel.getIcon2});
        appModel.append({"icon": gearDMSPanel.getIcon3});
        appModel.append({"icon": gearDMSPanel.getIcon4});
        appModel.append({"icon": gearDMSPanel.getIcon5});
        appModel.append({"icon": gearDMSPanel.getIcon6});
        appModel.append({"icon": gearDMSPanel.getIcon7});
        //appModel.append({"icon": gearDMSPanel.getIcon8});
    }

    Component {
        id: appDelegate

        Item {
            id: wrapp
            z: PathView.iconZ
            scale: PathView.iconScale
            opacity: PathView.iconOpacity

            Image {
                id: myIcon
                y: 20;
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter:  parent.verticalCenter
                source: icon
                smooth: true
            }
        }
    }

    PathView {
        id: view
        pathItemCount: 3
        anchors.fill: parent
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        focus: false
        model: appModel
        delegate: appDelegate
        currentIndex: getIndex
        path: Path {
            startX: -100
            startY: 0
            PathAttribute { name: "iconScale"; value: 0.2 }
            PathAttribute { name: "iconOpacity"; value: 0.1 }
            PathAttribute { name: "iconZ"; value: 4 }

            PathLine { x: 130; y: 10 }
            PathAttribute { name: "iconScale"; value: 1.0 }
            PathAttribute { name: "iconOpacity"; value: 1.0 }
            PathAttribute { name: "iconZ"; value: 0 }

            PathLine { x: 310; y: 0 }
            PathAttribute { name: "iconScale"; value: 0.2 }
            PathAttribute { name: "iconOpacity"; value: 0.1 }
            PathAttribute { name: "iconZ"; value: 4 }
        }
    }

    states: [
        State {
            name: ""
        },
        State {
            name: "show"
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            SequentialAnimation {
            }
        },
        Transition {
            from: "show"
            to: ""
            SequentialAnimation {
            }
        }
    ]
}
