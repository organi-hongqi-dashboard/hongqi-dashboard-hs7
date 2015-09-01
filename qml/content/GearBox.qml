import QtQuick 2.2


Item {
    id: gearBox

    property int getGearValue: 0
    property int getGearIndex: 0

    onGetGearValueChanged: {
        switch( getGearValue ) {
        case 0:
            gearP.visible = true;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false;
            gearM.visible = false;
            gearS.visible = false;
            break;
        case 1:
            gearP.visible = false;
            gearN.visible = true;
            gearR.visible = false;
            gearD.visible = false;
            gearM.visible = false;
            gearS.visible = false;
            break;
        case 2:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = true;
            gearD.visible = false;
            gearM.visible = false;
            gearS.visible = false;
            break;
        case 3:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = true;
            gearM.visible = false;
            gearS.visible = false;
            break;
        case 4:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false;
            gearM.visible = true;
            gearS.visible = false;
            break;
        case 5:
            gearP.visible = false;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false;
            gearM.visible = false;
            gearS.visible = true;
            break;
        default:
            gearP.visible = true;
            gearN.visible = false;
            gearR.visible = false;
            gearD.visible = false
            gearM.visible = false;
            gearS.visible = false;;
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

    GearDMS {
        id: gearD
        x: -20
        visible: false
        getIndex: getGearIndex
        getIcon1: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD1.png";
        getIcon2: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD2.png";
        getIcon3: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD3.png";
        getIcon4: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD4.png";
        getIcon5: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD5.png";
        getIcon6: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD6.png";
        getIcon7: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD7.png";
        //getIcon8: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearD8.png";
    }

    GearDMS {
        id: gearS
        x: -20
        visible: false
        getIndex: getGearIndex
        getIcon1: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS1.png";
        getIcon2: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS2.png";
        getIcon3: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS3.png";
        getIcon4: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS4.png";
        getIcon5: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS5.png";
        getIcon6: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS6.png";
        getIcon7: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS7.png";
        //getIcon8: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearS8.png";
    }

    GearDMS {
        id: gearM
        x: -20
        visible: false
        getIndex: getGearIndex
        getIcon1: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM1.png";
        getIcon2: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM2.png";
        getIcon3: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM3.png";
        getIcon4: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM4.png";
        getIcon5: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM5.png";
        getIcon6: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM6.png";
        getIcon7: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM7.png";
        //getIcon8: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearM8.png";
    }

    Image {
        id: gearR
        visible: false
        source: "qrc:/letfPanel/gearPanel/images/letfPanel/gearPanel/gearR.png"
    }
}
