import QtQuick 2.2

Item {
	id: rpmDisk

	property int valueRpm: CarStatus.rpm
	property int valueCoolantTemp: CarStatus.waterTemp
	Image {
		id: rpm_disk
		x: 43
		y: 31
		opacity: 0.0
		source: "qrc:/common/disk/images/common/disk/disk.png"
	}


	Item{
		id:warning
		opacity: 0.0
		Image {
			id: warningBar
			x: 615
			y: 359
			opacity: 1.0
			width: 82
			height: 194
			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/warningBar.png"
		}
		Image {
			id: warningLine1
			x: 673
			y: 355
			opacity: 1.0
			width: 25
			height: 7
			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/warningLine1.png"
		}
		Image {
			id: warningLine2
			x: 612
			y: 535
			opacity: 1.0
			width: 23
			height: 21
			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/warningLine2.png"
		}
	}

	Item {
		id:rpm_number
		opacity: 0.0

		Image {
			id: rpm0
			x: 157
			y: 492
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - valueRpm/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm >= 0 && valueRpm < 1000)
					return (1.5 - (valueRpm)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm0.png"
		}
		Image {
			id: rpm1
			x: 107
			y: 343
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 1000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 0 && valueRpm < 2000)
					return (1.5 - Math.abs(valueRpm - 1000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm1.png"
		}
		Image {
			id: rpm2
			x: 156
			y: 200
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 2000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 1000 && valueRpm < 3000)
					return (1.5 - Math.abs(valueRpm - 2000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm2.png"
		}
		Image {
			id: rpm3
			x: 279
			y: 111
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 3000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 2000 && valueRpm < 4000)
					return (1.5 - Math.abs(valueRpm - 3000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm3.png"
		}
		Image {
			id: rpm4
			x: 428
			y: 110
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 4000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 3000 && valueRpm < 5000)
					return (1.5 - Math.abs(valueRpm - 4000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm4.png"
		}
		Image {
			id: rpm5
			x: 547
			y: 200
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 5000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 4000 && valueRpm < 6000)
					return (1.5 - Math.abs(valueRpm - 5000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm5.png"
		}
		Image {
			id: rpm6
			x: 599
			y: 346
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 6000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 5000 && valueRpm < 7000)
					return (1.5 - Math.abs(valueRpm - 6000)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm6.png"
		}
		Image {
			id: rpm7
			x: 548
			y: 504
			opacity: {
				if(valueRpm >= 0 && valueRpm <= 7000)
					return (1.0 - Math.abs(valueRpm - 7000)/8000.0);
				else
					return 0.1
			}
			scale: {
				if(valueRpm > 6000 && valueRpm <= 7000)
					return (1.5 - (7000 - valueRpm)/2000.0);
				else
					return 1.0
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpm7.png"
		}
	}


	Item {
		id: rpm_scale
		opacity: 0.0
		Item{
			id:smallScale
			Image {
				id: scales1
				x: 110
				y: 492
				opacity: 1.0
				width: 18
				height: 14
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales1.png"
			}
			Image {
				id: scales2
				x: 95
				y: 460
				opacity: 1.0
				width: 18
				height: 12
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales2.png"
			}
			Image {
				id: scales3
				x: 83
				y: 426
				opacity: 1.0
				width: 19
				height: 11
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales3.png"
			}
			Image {
				id: scales4
				x: 77
				y: 392
				opacity: 1.0
				width: 18
				height: 9
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales4.png"
			}
			Image {
				id: scales5
				x: 77
				y: 319
				opacity: 1.0
				width: 18
				height: 11
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales5.png"
			}
			Image {
				id: scales6
				x: 83
				y: 282
				opacity: 1.0
				width: 19
				height: 12
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales6.png"
			}
			Image {
				id: scales7
				x: 95
				y: 247
				opacity: 1.0
				width: 18
				height: 13
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales7.png"
			}
			Image {
				id: scales8
				x: 110
				y: 213
				opacity: 1.0
				width: 18
				height: 14
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales8.png"
			}
			Image {
				id: scales9
				x: 153
				y: 155
				opacity: 1.0
				width: 17
				height: 16
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales9.png"
			}
			Image {
				id: scales10
				x: 180
				y: 130
				opacity: 1.0
				width: 15
				height: 17
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales10.png"
			}
			Image {
				id: scales11
				x: 210
				y: 107
				opacity: 1.0
				width: 14
				height: 18
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales11.png"
			}
			Image {
				id: scales12
				x: 242
				y: 90
				opacity: 1.0
				width: 13
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales12.png"
			}
			Image {
				id: scales13
				x: 312
				y: 68
				opacity: 1.0
				width: 10
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales13.png"
			}
			Image {
				id: scales14
				x: 348
				y: 63
				opacity: 1.0
				width: 9
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales14.png"
			}
			Image {
				id: scales15
				x: 385
				y: 63
				opacity: 1.0
				width: 10
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales15.png"
			}
			Image {
				id: scales16
				x: 420
				y: 68
				opacity: 1.0
				width: 11
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales16.png"
			}
			Image {
				id: scales17
				x: 487
				y: 90
				opacity: 1.0
				width: 14
				height: 19
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales17.png"
			}
			Image {
				id: scales18
				x: 518
				y: 107
				opacity: 1.0
				width: 15
				height: 18
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales18.png"
			}
			Image {
				id: scales19
				x: 547
				y: 130
				opacity: 1.0
				width: 16
				height: 17
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales19.png"
			}
			Image {
				id: scales20
				x: 573
				y: 155
				opacity: 1.0
				width: 16
				height: 16
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales20.png"
			}
			Image {
				id: scales21
				x: 614
				y: 213
				opacity: 1.0
				width: 19
				height: 14
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales21.png"
			}
			Image {
				id: scales22
				x: 629
				y: 247
				opacity: 1.0
				width: 19
				height: 13
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales22.png"
			}
			Image {
				id: scales23
				x: 641
				y: 282
				opacity: 1.0
				width: 18
				height: 12
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales23.png"
			}
			Image {
				id: scales24
				x: 647
				y: 319
				opacity: 1.0
				width: 19
				height: 11
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales24.png"
			}
			Image {
				id: scales25
				x: 647
				y: 392
				opacity: 1.0
				width: 19
				height: 9
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales25.png"
			}
			Image {
				id: scales26
				x: 641
				y: 426
				opacity: 1.0
				width: 18
				height: 11
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales26.png"
			}
			Image {
				id: scales27
				x: 629
				y: 460
				opacity: 1.0
				width: 19
				height: 13
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales27.png"
			}
			Image {
				id: scales28
				x: 614
				y: 492
				opacity: 1.0
				width: 19
				height: 14
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scales28.png"
			}
		}
		Item{
			id:bigScale
			Image {
				id: scale1
				x: 121
				y: 511
				opacity: 1.0
				width: 35
				height: 44
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale1.png"
			}
			Image {
				id: scale2
				x: 65
				y: 345
				opacity: 1.0
				width: 37
				height: 37
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale2.png"
			}
			Image {
				id: scale3
				x: 121
				y: 173
				opacity: 1.0
				width: 35
				height: 43
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale3.png"
			}
			Image {
				id: scale4
				x: 268
				y: 66
				opacity: 1.0
				width: 29
				height: 47
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale4.png"
			}
			Image {
				id: scale5
				x: 446
				y: 66
				opacity: 1.0
				width: 29
				height: 47
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale5.png"
			}
			Image {
				id: scale6
				x: 586
				y: 173
				opacity: 1.0
				width: 36
				height: 43
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale6.png"
			}
			Image {
				id: scale7
				x: 641
				y: 345
				opacity: 1.0
				width: 37
				height: 37
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale7.png"
			}
			Image {
				id: scale8
				x: 586
				y: 511
				opacity: 1.0
				width: 36
				height: 44
				source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/scale8.png"
			}
		}

	}

	Image {
		id: rpm_pointer
		x: 35
		y: 303
		opacity: 0.0
		source: "qrc:/common/disk/images/common/disk/pointer.png"
		transform: Rotation {
			id: pointerRotation
			origin.x: 370.5 - rpm_pointer.x
			origin.y: 360- rpm_pointer.y
			angle: valueRpm * 252.0 / 7000.0
			Behavior on angle { SpringAnimation{ spring: 1.2; damping: 0.2;} }
		}
	}

	Image {
		id: rpmUint
		x: 300
		y: 491
		opacity: 0.0//0.2
		source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/rpmUint.png"
	}

	Item{
		id: powerBarMask
		x: 106
		y: 92
		opacity: 0.0//0.9
		width: powerBarS.width/2
		height: powerBarS.height
		clip:true
		rotation: -153
		transformOrigin: Item.Right
		Item{
			id: powerBar
			width: powerBarS.width/2
			height: powerBarS.height
			clip:true
			rotation: {
				if(valueCoolantTemp >= 50 && valueCoolantTemp <= 130)
					return 180-(valueCoolantTemp - 50) / 80 * 54;
				else
					return 180
			}
			transformOrigin: Item.Right
			Behavior on rotation { SpringAnimation{ spring: 1.2; damping: 0.2;}}
			Rectangle{
				id:powerBarS
				width: 530
				height: width
				radius: width/2
				color: "transparent"
				border.color: {
					if(valueCoolantTemp > 110)
						return "red"
					else
						return "white"
				}
				border.width: 13
				smooth: true
			}
		}
	}

	Image {
		id: coolantTemp
		x: 213
		y: 556
		opacity: 0.0
		width: 319
		height: 98
		source: "qrc:/rpmDisk/images/letfPanel/rpmDisk/coolantTemp.png"
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: rpm_disk; opacity: 0.0 }
			PropertyChanges { target: rpm_pointer; opacity: 0.0 }
			PropertyChanges { target: warning; opacity: 0.0 }
			PropertyChanges { target: rpm_number; opacity: 0.0 }
			PropertyChanges { target: rpm_scale; opacity: 0.0 }
			PropertyChanges { target: rpmUint; opacity: 0.0 }
			PropertyChanges { target: powerBarMask; opacity: 0.0 }
			PropertyChanges { target: coolantTemp; opacity: 0.0 }
		},
		State {
			name: "normalMode"
			PropertyChanges { target: rpm_disk; opacity: 1.0 }
			PropertyChanges { target: rpm_pointer; opacity: 1.0 }
			PropertyChanges { target: warning; opacity: 1.0 }
			PropertyChanges { target: rpm_number; opacity: 1.0 }
			PropertyChanges { target: rpm_scale; opacity: 1.0 }
			PropertyChanges { target: rpmUint; opacity: 0.2 }
			PropertyChanges { target: powerBarMask; opacity: 0.9 }
			PropertyChanges { target: coolantTemp; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "normalMode"
			ParallelAnimation {
				NumberAnimation { target: rpm_disk; property: "opacity"; duration: 1000 }
				NumberAnimation { target: rpm_pointer; property: "opacity"; duration: 1000 }
				NumberAnimation { target: warning; property: "opacity"; duration: 1000 }
				NumberAnimation { target: rpm_number; property: "opacity"; duration: 1000 }
				NumberAnimation { target: rpm_scale; property: "opacity"; duration: 1000 }
				NumberAnimation { target: rpmUint; property: "opacity"; duration: 1000 }
				NumberAnimation { target: powerBarMask; property: "opacity"; duration: 1000 }
				NumberAnimation { target: coolantTemp; property: "opacity"; duration: 1000 }
			}
		}
	]
}

