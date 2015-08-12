import QtQuick 2.2

Rectangle {
    id: socBar

    property int valueSocMass: 58

    EnergyBar {
        id: socEnergyBar
        x: 685
        y: 553
        opacity: 1.0
        column: 0
        mirror: 0
        moving: 0
        sekuai: valueSocMass > 10 ? "qrc:/common/images/common/greenCube.png" :
                                    "qrc:/common/images/common/redCube.png"
        targetShade: "qrc:/common/images/common/barOutline.png"
        level: (valueSocMass / 100.0)
        Behavior on level { SpringAnimation { spring: 2; damping: 0.2 } }
    }

    Text {
        id: justForNumSocShow
        text: ""
        x: 810
    }

    DigitValue {
        id: numSocShow
        anchors.right: justForNumSocShow.left
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
        value: valueSocMass
    }

    Image {
        id: soc_unit
        x: 653
        y: 548
        opacity: 1.0
        source: "qrc:/socBar/images/soc/soc_unit.png"
    }
    Image {
        id: soc_percentage
        x: 798
        y: 533
        opacity: 1.0
        source: "qrc:/socBar/images/soc/soc_%.png"
    }
    Image {
        id: soc_scale
        x: 692
        y: 564
        opacity: 1.0
        source: "qrc:/socBar/images/soc/soc_scale.png"
    }
}
