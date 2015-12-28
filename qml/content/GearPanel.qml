import QtQuick 2.2

Item {
    id: gearPanel
    opacity: 0.0

    property bool isAnimation: false
    property int setGear: 0
    property int setGearIndex: 0
    property int gear: CarStatus.gear
    property int gearMode: CarStatus.gearMode

    function setGearV() {
        switch( gear ) {
        case 0: // P
            setGear = 0;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
		case 7:
		case 8:
			setGearIndex = gear - 1;
            switch( gearMode ) {
            case 1: //D
                setGear = 3;
                break;
            case 2: //S
                setGear = 4;
                break;
            case 3: //M
                setGear = 5;
                break;
            default:
                setGear = 0;
                break;
            }
            break;
        case 0x0e: //N
            setGear = 1;
            break;
        case 0x0f: //R
            setGear = 2;
            break;
        default:
            setGear = 0;
            break;
        }

        if( isAnimation == true )
            return;
        if( gear1.state == "" ) {
            if( gearBox2.getGearValue != gearPanel.setGear ) {
                gearBox1.getGearValue = setGear;
                gearBox1.getGearIndex = setGearIndex;
                gear2.state = "";
                gear1.state = "show";
            }
            else
                gearBox2.getGearIndex = setGearIndex;
        } else {
            if( gearBox1.getGearValue != gearPanel.setGear ) {
                gearBox2.getGearValue = setGear;
                gearBox2.getGearIndex = setGearIndex;
                gear1.state = "";
                gear2.state = "show";
            }
            else
                gearBox1.getGearIndex = setGearIndex;
        }
    }

    onGearChanged: {
        setGearV();
    }

    onGearModeChanged: {
        setGearV();
    }

    Gear {
        id: gear1
        x: 260
        y: 308

        GearBox {
            id: gearBox1
            getGearValue: 0
            getGearIndex: 0
        }
        state: "show"

        onAnimationStartingChanged: {
            if( animationStarting == true )
                isAnimation = true;
            else {
                isAnimation = false;
                if( gearBox1.getGearValue != gearPanel.setGear )
                    setGearV();}
        }
    }

    Gear {
        id: gear2
        x: 260
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
                if( gearBox2.getGearValue != gearPanel.setGear )
                    setGearV();
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
                PauseAnimation { duration: 4400 }
                NumberAnimation { target: gearPanel; property: "opacity"; duration: 500 }
            }
        },
        Transition {
            from: "normalMode"
            to: "functionMode"
            SequentialAnimation {
                NumberAnimation { target: gearPanel; properties: "scale,x,y"; duration: 1000; easing.type: Easing.InBack }
            }
        },
        Transition {
            from: "functionMode"
            to: "normalMode"
            SequentialAnimation {
                NumberAnimation { target: gearPanel; properties: "scale,x,y"; duration: 1000;easing.type: Easing.InBack }
            }
        }
    ]
}
