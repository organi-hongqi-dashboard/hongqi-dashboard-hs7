import QtQuick 2.2

Rectangle {
    id: oilBar

    property int valueOilMass: 10

    EnergyBar {
        id: oilEnergyBar
        x: 1021
        y: 553
        opacity: 1.0
        column: 0
        mirror: 0
        moving: 0
        sekuai: valueOilMass > 10 ? "qrc:/common/images/common/greenCube.png" :
                                    "qrc:/common/images/common/redCube.png"
        targetShade: "qrc:/common/images/common/barOutline.png"
        level: (valueOilMass / 100.0)
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Text {
        id: justForNumOilShow
        text: ""
        x: 1145
    }

    DigitValue {
        id: numOilShow
//            anchors.centerIn: numSpeed
        anchors.right: justForNumOilShow.left
        y: 531
        spacing: -10
        icon0: "qrc:/centrePanel/images/oilMass/0000.png"
        icon1: "qrc:/centrePanel/images/oilMass/1111.png"
        icon2: "qrc:/centrePanel/images/oilMass/2222.png"
        icon3: "qrc:/centrePanel/images/oilMass/3333.png"
        icon4: "qrc:/centrePanel/images/oilMass/4444.png"
        icon5: "qrc:/centrePanel/images/oilMass/5555.png"
        icon6: "qrc:/centrePanel/images/oilMass/6666.png"
        icon7: "qrc:/centrePanel/images/oilMass/7777.png"
        icon8: "qrc:/centrePanel/images/oilMass/8888.png"
        icon9: "qrc:/centrePanel/images/oilMass/9999.png"
        value: valueOilMass
    }

    Image {
        id: iconPercentage
        x: 1135
        y: 533
        opacity: 1.0
        source: "qrc:/centrePanel/images/oilMass/iconPercentage.png"
    }


    Image {
        id: iconOilMass
        x: 1236
        y: 550
        opacity: 1.0
        source: "qrc:/centrePanel/images/oilMass/iconOilMass.png"
    }


    Image {
        id: bottomHighlight
        x: 1022
        y: 565
        opacity: 1.0
        source: "qrc:/centrePanel/images/oilMass/bottomHighlight.png"
    }
}
