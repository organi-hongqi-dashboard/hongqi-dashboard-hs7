import QtQuick 2.4

Item {
    id: menuPanel
    x: 0
    y: 0
    width: 1920
    height: 780

    Image {
        id: rect_1
        x: 472
        y: 339
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/rect_1.png"
    }
    Image {
        id: ellipse_18
        x: 385
        y: 253
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/ellipse_18.png"
    }
    Image {
        id: rect_1_copy
        x: 1359
        y: 338
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/rect_1_copy.png"
    }
    Image {
        id: yellow_copy
        x: 753
        y: 112
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/yellow_copy.png"
    }
    Image {
        id: ellipse_14
        x: 607
        y: 341
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/ellipse_14.png"
    }
    Image {
        id: ellipse_14_copy
        x: 631
        y: 363
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/ellipse_14_copy.png"
    }
    Image {
        id: menu
        x: 924
        y: 142
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/menu.png"
    }
    Image {
        id: layer_177_copy_2
        x: 719
        y: 131
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/layer_177_copy_2.png"
    }
    Image {
        id: layer_177_copy_3
        x: 719
        y: 186
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/layer_177_copy_3.png"
    }

    Image {
        id: layer_180
        x: 796
        y: 264
        opacity: 1.0
        source: "qrc:/menuPanel/images/menuPanel/layer_180.png"
    }

    ListModel {
        id: appModel
        ListElement { name: "主题风格"; icon: "qrc:/menuPanel/images/menuPanel/themeStyle.png"; icon2: "qrc:/menuPanel/images/menuPanel/themeStyleY.png" }
        ListElement { name: "单位设置"; icon: "qrc:/menuPanel/images/menuPanel/unitSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/unitSettingY.png" }
        ListElement { name: "通话设置"; icon: "qrc:/menuPanel/images/menuPanel/contactSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/contactSettingY.png" }
        ListElement { name: "网络配置"; icon: "qrc:/menuPanel/images/menuPanel/7812512.png"; icon2: "qrc:/menuPanel/images/menuPanel/7812512Y.png" }
        ListElement { name: "胎压信息"; icon: "qrc:/menuPanel/images/menuPanel/TPMSInfo.png"; icon2: "qrc:/menuPanel/images/menuPanel/TPMSInfoY.png" }
        ListElement { name: "电子信箱"; icon: "qrc:/menuPanel/images/menuPanel/7984524512.png"; icon2: "qrc:/menuPanel/images/menuPanel/7984524512Y.png" }
        ListElement { name: "行车信息"; icon: "qrc:/menuPanel/images/menuPanel/drivInfo.png"; icon2: "qrc:/menuPanel/images/menuPanel/drivInfoY.png" }
        ListElement { name: "时间设置"; icon: "qrc:/menuPanel/images/menuPanel/timeSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/timeSettingY.png" }
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
                source: wrapp.PathView.isCurrentItem ? icon2:icon
                smooth: true
                visible: parent.scale > 0.3 ? true: false
            }
            Text {
                anchors { top: myIcon.bottom; horizontalCenter: parent.horizontalCenter }
                text: name
                smooth: true
                scale: wrapp.PathView.isCurrentItem ? 1.5 : 1.0
                color: wrapp.PathView.isCurrentItem ? "#d7a263" : "white"
                visible: parent.scale > 0.4 ? true: false
            }
        }
    }

    PathView {
        id: view
        anchors.fill: parent
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        focus: true
        model: appModel
        delegate: appDelegate
        path: Path {
            startX: 960
            startY: 340
            PathAttribute { name: "iconScale"; value: 0 }
            PathAttribute { name: "iconOpacity"; value: 0 }
            PathAttribute { name: "iconZ"; value: 4 }

            PathQuad { x: 640; y: 390; controlX: 730; controlY: 340 }
            PathAttribute { name: "iconScale"; value: 0.7 }
            PathAttribute { name: "iconOpacity"; value: 0.5 }
            PathAttribute { name: "iconZ"; value: 2 }

            PathQuad { x: 970; y: 460; controlX: 705; controlY: 470 }
            PathAttribute { name: "iconScale"; value: 1.0 }
            PathAttribute { name: "iconOpacity"; value: 1.0 }
            PathAttribute { name: "iconZ"; value: 0 }

            PathQuad { x: 1285; y: 390; controlX: 1190; controlY: 470 }
            PathAttribute { name: "iconScale"; value: 0.7 }
            PathAttribute { name: "iconOpacity"; value: 0.5 }
            PathAttribute { name: "iconZ"; value: 2 }

            PathQuad { x: 960; y: 340; controlX: 1185; controlY: 341 }
            PathAttribute { name: "iconScale"; value: 0 }
            PathAttribute { name: "iconOpacity"; value: 0 }
            PathAttribute { name: "iconZ"; value: 4 }
        }

        Keys.onLeftPressed: if (!moving) decrementCurrentIndex()
        Keys.onRightPressed: if (!moving) incrementCurrentIndex()
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
