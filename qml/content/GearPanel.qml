import QtQuick 2.2

Item {
    id: gearPanel
    opacity: 0.0

    property bool isAnimation: false
    property int getGear: 0

//    focus: true
//    Keys.onPressed: {
//        switch(event.key) {
//        case Qt.Key_1:

//            if( getGear == 5 )
//                getGear = 0;
//            else
//                getGear++;
//            break;
//        case Qt.Key_2:
//            if( getGear == 0 )
//                getGear = 5;
//            else
//                getGear--;
//            break;
//        }
//    }

    function setGear() {
        if( isAnimation == true || getGear < 0 || getGear > 5 )
            return;
        if( gear1.state == "" ) {
            gearBox1.getGearValue = getGear;
            gear2.state = "";
            gear1.state = "show";
        } else {
            gearBox2.getGearValue = getGear;
            gear1.state = "";
            gear2.state = "show";
        }
    }

    onGetGearChanged: {
        setGear();
    }

    Gear {
        id: gear1
        x: 260
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
