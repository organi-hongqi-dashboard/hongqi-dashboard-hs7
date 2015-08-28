import QtQuick 2.2

Item {
    id: gearBox

    property int getGearValue: 0

    onGetGearValueChanged: {
        switch( getGearValue ) {
        case 0:
            gearP.visible = true;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false;
            break;
        case 1:
            gearP.visible = false;
            gearN.visible = true;
            gearR.visible = false;
            gearD.visible = false;
            break;
        case 2:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = true;
            gearD.visible = false;
            break;
        case 3:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = true;
            break;
        default:
            gearP.visible = true;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false;
            break;
        }
    }

    Image {
        id: gearP
        visible: true
        source: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearP.png"
    }

    Image {
        id: gearN
        visible: false
        source: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearN.png"
    }

    Image {
        id: gearD
        visible: false
        source: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD.png"
    }

    Image {
        id: gearR
        visible: false
        source: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearR.png"
    }
}
