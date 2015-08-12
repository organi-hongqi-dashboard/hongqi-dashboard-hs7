import QtQuick 2.4

Item {
    id: gearPanel
    x: 323
    y: 308

    focus: true
    Keys.onPressed: {
        switch(event.key) {
        case Qt.Key_1:
            if( gearValue == 4 )
                gearValue = 0;
            else
                gearValue++;
            getS();
            if( gearShow1.state == "" )
            {
                gearShow1.state = "Bigshow";
                gearShow2.state = "";
            }
            else
                if( gearShow2.state == "" )
                {
                    gearShow1.state = "";
                    gearShow2.state = "Bigshow";
                }
            break;
        }
    }
    property int gearValue: 0

    function getS() {
        switch (gearValue) {
        case 0 :
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearP.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearP.png"
            }
            break;
        case 1 :
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearD.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearD.png"
            }
            break;
        case 2 :
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearN.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearN.png"
            }
            break;
        case 3 :
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearS.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearS.png"
            }
            break;
        case 4 :
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearR.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearR.png"
            }
            break;
        default:
            if( gearShow1.state == "" )
            {
                gearshow1.source = "qrc:/gearPanel/images/gearPanel/gearP.png"
            }
            if( gearShow2.state == "" )
            {
                gearshow2.source = "qrc:/gearPanel/images/gearPanel/gearP.png"
            }
            break;
        }
    }

    Item {
        id: gearShow1
        width: parent.width
        height: parent.height

        Image {
            id: gearshow1
            opacity: 0
            source: "qrc:/gearPanel/images/gearPanel/gearP.png"
        }

        transform: Rotation {
            id: gearshowRot
            axis { x: 1; y: 0; z: 0 }
            angle: 90
            origin { x: 0; y: 100 }
        }
        states: [
            State {
                name: ""
            },
            State {
                name: "Bigshow"
            }
        ]
        transitions: [
            Transition {
                from: ""
                to: "Bigshow"
                ParallelAnimation {
                    NumberAnimation {target: gearshowRot; property: "angle"; from: 90; to: 0; duration: 800 }
                    NumberAnimation {target: gearshow1; property: "opacity"; from: 0; to: 1.0; duration: 800 }
                }
            },
            Transition {
                from: "Bigshow"
                to: ""
                SequentialAnimation {
                    NumberAnimation {target: gearshowRot; property: "angle"; from: 0; to: -90; duration: 800 }
                    NumberAnimation {target: gearshow1; property: "opacity"; from: 1.0; to: 0; duration: 800 }
                    NumberAnimation {target: gearshowRot; property: "angle"; from: -90; to: 90; duration: 100 }
                }
            }
        ]
    }
    Item {
        id: gearShow2
        width: parent.width
        height: parent.height

        Image {
            id: gearshow2
            opacity: 0
            source: "qrc:/gearPanel/images/gearPanel/gearP.png"
        }

        transform: Rotation {
            id: gearshowRot1
            axis { x: 1; y: 0; z: 0 }
            angle: 90
            origin { x: 0; y: 100 }
        }
        states: [
            State {
                name: ""
            },
            State {
                name: "Bigshow"
            }
        ]
        transitions: [
            Transition {
                from: ""
                to: "Bigshow"
                ParallelAnimation {
                    NumberAnimation {target: gearshowRot1; property: "angle"; from: 90; to: 0; duration: 800 }
                    NumberAnimation {target: gearshow2; property: "opacity"; from: 0; to: 1.0; duration: 800 }
                }
            },
            Transition {
                from: "Bigshow"
                to: ""
                SequentialAnimation {
                    NumberAnimation {target: gearshowRot1; property: "angle"; from: 0; to: -90; duration: 800 }
                    NumberAnimation {target: gearshow2; property: "opacity"; from: 1.0; to: 0; duration: 800 }
                    NumberAnimation {target: gearshowRot1; property: "angle"; from: -90; to: 90; duration: 100 }
                }
            }
        ]
    }

    Component.onCompleted: {
        gearShow1.state = "Bigshow";
        gearShow2.state = "";
    }
}
