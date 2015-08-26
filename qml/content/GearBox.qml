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
        source: "qrc:/gearPanel/images/gearPanel/gearP.png"
    }

    Image {
        id: gearN
        visible: false
        source: "qrc:/gearPanel/images/gearPanel/gearN.png"
    }

    Image {
        id: gearD
        visible: false
        source: "qrc:/gearPanel/images/gearPanel/gearD.png"
    }

    Image {
        id: gearR
        visible: false
        source: "qrc:/gearPanel/images/gearPanel/gearR.png"
    }
}
