import QtQuick 2.2

Item {
    id: gearPanel
    opacity: 0.0

    property bool isAnimation: false
    property int getGear: 0

    function setGear() {
        if( isAnimation == true )
            return;
        switch( getGear ) {
        case 0:
            if( gear1.state == "" ) {
                gearBox1.getGearValue = getGear;
                gear2.state = "";
                gear1.state = "show";
            } else {
                gearBox2.getGearValue = getGear;
                gear1.state = "";
                gear2.state = "show";
            }
            break;
        case 1:
            if( gear1.state == "" ) {
                gearBox1.getGearValue = getGear;
                gear2.state = "";
                gear1.state = "show";
            } else {
                gearBox2.getGearValue = getGear;
                gear1.state = "";
                gear2.state = "show";
            }
            break;
        case 2:
            if( gear1.state == "" ) {
                gearBox1.getGearValue = getGear;
                gear2.state = "";
                gear1.state = "show";
            } else {
                gearBox2.getGearValue = getGear;
                gear1.state = "";
                gear2.state = "show";
            }
            break;
        case 3:
            if( gear1.state == "" ) {
                gearBox1.getGearValue = getGear;
                gear2.state = "";
                gear1.state = "show";
            } else {
                gearBox2.getGearValue = getGear;
                gear1.state = "";
                gear2.state = "show";
            }
            break;
        default:
            break;
        }
    }

    onGetGearChanged: {
        setGear();
    }

    Gear {
        id: gear1
        x: 323
        y: 308

        GearBox {
            id: gearBox1
            getGearValue: 0
        }
        state: "show"

        onAnimationStartingChanged: {
            if( animationStarting == true )
                isAnimation = true;
            else {
                isAnimation = false;
                if( gearBox1.getGearValue != gearPanel.getGear )
                    setGear();
            }
        }
    }

    Gear {
        id: gear2
        x: 323
        y: 308

        GearBox {
            id: gearBox2
            getGearValue: 0
        }
        state: ""

        onAnimationStartingChanged: {
            if( animationStarting == true )
                isAnimation = true;
            else {
                isAnimation = false;
                if( gearBox2.getGearValue != gearPanel.getGear )
                    setGear();
            }
        }
    }

    states: [
        State {
            name: ""
            PropertyChanges { target: gearPanel; x: 0; y: 0; scale: 1.0; opacity: 0.0 }
        },
        State {
            name: "normalMode"
            PropertyChanges { target: gearPanel; x: 0; y: 0; scale: 1.0; opacity: 1.0 }
        },
        State {
            name: "functionMode"
            PropertyChanges { target: gearPanel; x: 54; y: 290; scale: 0.56; opacity: 1.0 }
        }
    ]
    transitions: [
        Transition {
            from: ""
            to: "normalMode"
            SequentialAnimation {
                PauseAnimation { duration: 4000 }
                NumberAnimation { target: gearPanel; property: "opacity"; duration: 500 }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                NumberAnimation { target: gearPanel; properties: "scale,x,y"; duration: 500 }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                NumberAnimation { target: gearPanel; properties: "scale,x,y"; duration: 500 }
            }
        }
    ]
}
