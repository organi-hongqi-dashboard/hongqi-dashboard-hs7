import QtQuick 2.0

Row {
	id: digitValue

	property int value: 0
	property int num6: 0
	property int num5: 0
	property int num4: 0
	property int num3: 0
	property int num2: 0
	property int num1: 0
	property int showNum: 1

	property bool completed: false

	property var imageSource: new Array

	onValueChanged: {
		num6 = value / 100000;
		num5 = (value % 100000) / 10000;
		num4 = (value % 10000) / 1000;
		num3 = (value % 1000) / 100;
		num2 = (value % 100) / 10;
		num1 = value % 10;
	}

	Image {
		id: num6Image
		visible: showNum == 6 ? true :
								((num6 == 0) ? false : true)
		source: completed ? digitValue.imageSource[num6] : ""
	}
	Image {
		id: num5Image
		visible: showNum >= 5 ? true :
								((num6 == 0 && num5 ==0) ? false : true)
		source: completed ? digitValue.imageSource[num5] : ""
	}
	Image {
		id: num4Image
		visible: showNum >= 4 ? true :
								((num6 == 0 && num5 ==0 && num4 ==0) ? false : true)
		source: completed ? digitValue.imageSource[num4] : ""
	}

	Image {
		id: num3Image
		visible: showNum >= 3 ? true :
								((num6 == 0 && num5 ==0 && num4 ==0 && num3 ==0) ? false : true)
		source: completed ? digitValue.imageSource[num3] : ""
	}
	Image {
		id: num2Image
		visible: showNum >= 2 ? true :
								(num6 == 0 && num5 ==0 && num4 ==0 && num3 ==0 && num2 ==0) ? false : true
		source: completed ? digitValue.imageSource[num2] : ""
	}
	Image {
		id: num1Image
		source: completed ? digitValue.imageSource[num1] : ""
	}

	Component.onCompleted: {
		if (!completed) {
			imageSource[0] = "qrc:/common/images/common/0.png";
			imageSource[1] = "qrc:/common/images/common/1.png";
			imageSource[2] = "qrc:/common/images/common/2.png";
			imageSource[3] = "qrc:/common/images/common/3.png";
			imageSource[4] = "qrc:/common/images/common/4.png";
			imageSource[5] = "qrc:/common/images/common/5.png";
			imageSource[6] = "qrc:/common/images/common/6.png";
			imageSource[7] = "qrc:/common/images/common/7.png";
			imageSource[8] = "qrc:/common/images/common/8.png";
			imageSource[9] = "qrc:/common/images/common/9.png";
			completed = true;
		}
	}
}
