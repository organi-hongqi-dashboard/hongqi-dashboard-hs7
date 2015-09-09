import QtQuick 2.4

Item {
    property bool igOn: true
    property int firstIndex: -1
    property int secondIndex: 0
    property bool secondShowFlag: false
    property bool anyButton: false

    id: menuPanel
    x: 0
    y: 0
    width: 1920
    height: 780
    opacity: 0
    Behavior on opacity { NumberAnimation { duration: 500 } }

    onAnyButtonChanged: {
        if (!anyButton) {
            timer30s.running = true;
        }
        else {
            timer30s.running = false;
        }
    }

    onIgOnChanged: {
        if (!igOn) {
            menuPanel.firstIndex = -1;
            menuPanel.secondIndex = 0;
            menuPanel.secondShowFlag = false;
            view.currentIndex = 0;
            Theme.opacity = 0.0;
            UnitSet.opacity = 0.0;
            Phone.opacity = 0.0;
            NetSet.opacity = 0.0;
            Tire.opacity = 0.0;
            Mail.opacity = 0.0;
            Message.opacity = 0.0;
            Time.opacity = 0.0;
            menuPanel.opacity = 0.0;
        }
    }

    function leftBtnClicked() {
        if (menuPanel.opacity == 0)
            return;
        if (!secondShowFlag) {
            if (menuPanel.firstIndex <= 0)
                menuPanel.firstIndex = 7;
            else
                menuPanel.firstIndex--;
            view.currentIndex = menuPanel.firstIndex;
        }
        else {
            switch (firstIndex) {
            case 0: // Theme
                break;
            case 1: // UnitSet
                if (menuPanel.secondIndex == 0)
                    menuPanel.secondIndex = 7;
                else
                    menuPanel.secondIndex -= 1;
                break;
            case 2: // Phone
                if (menuPanel.secondIndex == 1) {
                    menuPanel.secondIndex = 0;
//                    if (openAndClose.x == 710) {
//                        blueToothConnectBtn.visible = false;
//                        blueToothDisconnectBtn.visible = true;
//                        openAndClose.x = 667;
//                        openAndClose.text = qsTr("Close");
//                    }
//                    else {
//                        blueToothConnectBtn.visible = true;
//                        blueToothDisconnectBtn.visible = false;
//                        openAndClose.x = 710;
//                        openAndClose.text = qsTr("open");
//                    }
                }
                else {
                    menuPanel.secondIndex  += 1;
//                    blueToothShake1.start();
//                    blueToothShake2.start();
                }
                break;
            case 3: // NetSet
                break;
            case 4: // Tire
                break;
            case 5: // Mail
                break;
            case 6: // Message
                break;
            case 7: // Time
                break;
            default:
                break;
            }
        }
    }

    function rightBtnClicked() {
        if (menuPanel.opacity == 0)
            return;
        if (!menuPanel.secondShowFlag) {
            if (menuPanel.firstIndex == 7)
                menuPanel.firstIndex = 0;
            else if (menuPanel.firstIndex == -1)
                menuPanel.firstIndex = 1;
            else
                menuPanel.firstIndex++;
            view.currentIndex = menuPanel.firstIndex;
        }
        else {
            switch (firstIndex) {
            case 0: // Date&Time
                break;
            case 1: // Message
                if (menuPanel.secondIndex == 7)
                    menuPanel.secondIndex = 0;
                else
                    menuPanel.secondIndex += 1;
                break;
            case 2: // BlueTooth
                if (menuPanel.secondIndex == 1) {
                    menuPanel.secondIndex = 0;
//                    if (openAndClose.x == 710) {
//                        blueToothConnectBtn.visible = false;
//                        blueToothDisconnectBtn.visible = true;
//                        openAndClose.x = 667;
//                        openAndClose.text = qsTr("Close");
//                    }
//                    else {
//                        blueToothConnectBtn.visible = true;
//                        blueToothDisconnectBtn.visible = false;
//                        openAndClose.x = 710;
//                        openAndClose.text = qsTr("open");
//                    }
                }
                else {
                    menuPanel.secondIndex  += 1;
//                    blueToothShake1.start();
//                    blueToothShake2.start();
                }
                break;
            case 3: // NetSet
                break;
            case 4: // Tire
                break;
            case 5: // Mail
                break;
            case 6: // Message
                break;
            case 7: // Time
                break;
            default:
                break;
            }
        }
    }

    function okBtnClicked() {
        if (menuPanel.opacity == 0 && menuPanel.firstIndex == -1) {
            menuPanel.firstIndex = 0;
            view.currentIndex = 0;
            menuPanel.secondShowFlag = false;
            return;
        }
        if (!menuPanel.secondShowFlag) {
            switch (menuPanel.firstIndex) {
            case 0: // Theme
                theme.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 1: // UnitSet
                UnitSet.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 2: // Phone
                phone.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 3: // NetSet
                NetSet.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 4: // Tire
                Tire.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 5: // Mail
                Mail.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 6: // Message
                Message.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 7: // Time
                Time.opacity = 1.0;
                menuPanel.secondShowFlag = true;
                break;
            case 8: // Back
                menuPanel.firstIndex = -1;
                menuPanel.secondShowFlag = false;
                menuPanel.opacity = 0;
                break;
            case -1:
                menuPanel.firstIndex = 0;
                view.currentIndex = 0;
                menuPanel.secondShowFlag = false;
                break;
            default:
                break;
            }
        }
        else {
            switch (menuPanel.firstIndex) {
            case 0: // Theme
                theme.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 1: // UnitSet
                UnitSet.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 2: // Phone
                phone.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 3: // NetSet
                NetSet.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 4: // Tire
                tire.opacity = 0.0;
                view.opacity = 1.0;
                carModel.opacity = 1.0;
                menuPanel.secondShowFlag = false;
                break;
            case 5: // Mail
                Mail.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 6: // Message
                Message.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            case 7: // Time
                Time.opacity = 0.0;
                menuPanel.secondShowFlag = false;
                break;
            default:
                break;
            }
        }
    }

    Item {
        id: carModel

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
    }

    ListModel {
        id: appModel
        ListElement { name: "Theme"; icon: "qrc:/menuPanel/images/menuPanel/themeStyle.png"; icon2: "qrc:/menuPanel/images/menuPanel/themeStyleY.png" }
        ListElement { name: "UnitSet"; icon: "qrc:/menuPanel/images/menuPanel/unitSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/unitSettingY.png" }
        ListElement { name: "Phone"; icon: "qrc:/menuPanel/images/menuPanel/contactSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/contactSettingY.png" }
        ListElement { name: "NetSet"; icon: "qrc:/menuPanel/images/menuPanel/7812512.png"; icon2: "qrc:/menuPanel/images/menuPanel/7812512Y.png" }
        ListElement { name: "Tire"; icon: "qrc:/menuPanel/images/menuPanel/TPMSInfo.png"; icon2: "qrc:/menuPanel/images/menuPanel/TPMSInfoY.png" }
        ListElement { name: "Mail"; icon: "qrc:/menuPanel/images/menuPanel/7984524512.png"; icon2: "qrc:/menuPanel/images/menuPanel/7984524512Y.png" }
        ListElement { name: "Message"; icon: "qrc:/menuPanel/images/menuPanel/drivInfo.png"; icon2: "qrc:/menuPanel/images/menuPanel/drivInfoY.png" }
        ListElement { name: "Time"; icon: "qrc:/menuPanel/images/menuPanel/timeSetting.png"; icon2: "qrc:/menuPanel/images/menuPanel/timeSettingY.png" }
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
        focus: false
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

        Keys.onLeftPressed: leftBtnClicked()
        Keys.onRightPressed: rightBtnClicked()
        Keys.onUpPressed: okBtnClicked()
    }

    Item {
        id: phone
        opacity: 0.0
        Behavior on opacity { NumberAnimation { duration: 200; easing.type: Easing.InQuint } }

        Image {
            id: phonel
            x: 431
            y: 60
            opacity: 1.0
            source: "qrc:/centrePanel/images/centrePanel/phone.png"
        }
    }

    Item {
        id: theme
        opacity: 0.0
        Behavior on opacity { NumberAnimation { duration: 200; easing.type: Easing.InQuint } }

        Image {
            id: themel
            x: 431
            y: 98
            opacity: 1.0
            source: "qrc:/centrePanel/images/centrePanel/theme.png"
        }
    }
}
