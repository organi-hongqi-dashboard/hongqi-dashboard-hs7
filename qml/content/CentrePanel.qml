import QtQuick 2.2

Rectangle {
	id: centrePanel

    property string valueTime: "10:25"
    property string valueDate: "2015-01-09"
    property int valueOdo: 6589
    property double valueTrip: 641.5
    property int valueOutsideTemp: -29

    // module 底图
    Image {
        id: outlinelittle
        x: 324
        y: 34
        opacity: 0.0
        source: "qrc:/common/images/common/outlinelittle.png"
    }
    Image {
        id: outlineBig
        x: 71
        y: 14
        opacity: 1.0
        transformOrigin: Item.Center
        source: "qrc:/common/images/common/outlineBig.png"
    }

    // module 日期时间
    Item {
        id: dateTime

        Text {
            id: numTime
//            x: 913
            x: 915
            y: 16
            font.pixelSize: 33
            font.family: fontName.fontCurrent
            font.bold: true
            color: "white"
            text: valueTime
        }


        Text {
            id: numDate
//            x: 901
            x: 897
            y: 53
            font.pixelSize: 22
            font.family: fontName.fontCurrent
            color: "white"
            text: valueDate
        }
    }

    // module 下栏文字
    Item {
        id: bottomText

        Image {
            id: baseline
            x: 601
            y: 646
            opacity: 1.0
            source: "qrc:/common/images/common/baseline.png"
        }
        Image {
            id: iconKMTemp
            x: 840
            y: 611
            opacity: 1.0
            source: "qrc:/common/images/common/iconKMTemp.png"
        }

        /* group outside temperature */
        Item {
            id: groupTemp

            Image {
                id: charTemp
                x: 1157
                y: 609
                opacity: 1.0
                source: "qrc:/common/images/common/charTemp.png"
            }

            Text {
                id: numOutsideTemp
                text: valueOutsideTemp
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "white"
//                y: 609
                y: 600
//                font.letterSpacing: 3
                font.bold: true
                anchors.left: charTemp.right
//                anchors.leftMargin: 5
            }
        }

        /* group odo */
        Item {
            id: groupOdo

            Image {
                id: charOdo
                x: 645
                y: 609
                opacity: 1.0
                source: "qrc:/common/images/common/charOdo.png"
            }
            Text {
                id: backOfOdo
                text: "000000"
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                color: "gray"
                //                y: 609
                y: 600
                font.letterSpacing: 3
                font.bold: true
                anchors.left: charOdo.right
            }
            Rectangle {
                id: shadeForOdo
                anchors.right: backOfOdo.right
                y: backOfOdo.y
                width: numOdo.width
                height: numOdo.height
                color: "black"
            }
            Text {
                id: numOdo
                anchors.right: backOfOdo.right
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                //                y: 609
                y: 600
                font.letterSpacing: 3
                font.bold: true
                color: "white"
                text: valueOdo
            }
        }

        /* group trip */
        Item {
            id: groupTrip

            Image {
                id: iconTripA
                x: 922
                y: 609
                opacity: 0.498039215686
                source: "qrc:/common/images/common/iconTripA.png"
            }
            Text {
                id: backOfTrip
                text: "0000.0"
                color: "gray"
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                font.letterSpacing: 3
                font.bold: true
//                y: 609
                y: 600
                anchors.left: iconTripA.right
                anchors.leftMargin: 10
            }
            Rectangle {
                id: shadeForTrip
                anchors.right: backOfTrip.right
                y: 600
                width: numTripA.width
                height: numTripA.height
                color: "black"
            }
            Text {
                id: numTripA
                anchors.right: backOfTrip.right
                font.pixelSize: 32
                font.family: fontName.fontCurrent
                font.bold: true
//                font.weight:Font.ExtraBold
                font.letterSpacing: 3
//                y: 609
                y: 600
                color: "white"
                text: valueTrip
            }
        }
    }

    CarFunction {
        id: carFunction
    }

    CarInfo {
        id: carInfo
    }
}
