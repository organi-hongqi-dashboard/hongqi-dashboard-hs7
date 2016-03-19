import QtQuick 2.2

Rectangle {
	id: speedDisk

	property real valueSpeed: CarStatus.speed
	property int valueOilMass: CarStatus.fuel
	Image {
		id: speed_disk
		x: 1221
		y: 31
		opacity: 0.0
		source: "qrc:/common/disk/images/common/disk/disk.png"
	}


	Item {
		id: speedNum
		opacity: 0.0

		Image {
			id: speed0
			x: 1337
			y: 498
			opacity: {
				if(valueSpeed >= 0 && valueSpeed < 20)
					return (1.0 - valueSpeed/50.0);
				else
					return (0.2 - valueSpeed/2400.0);
			}
			scale: {
				if(valueSpeed >= 0 && valueSpeed < 20)
					return (1.2 - valueSpeed/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed0.png"
		}
		Image {
			id: speed20
			x: 1295
			y: 414
			opacity: {
				if(valueSpeed >= 0 && valueSpeed < 40)
					return (1.0 - Math.abs(valueSpeed- 20)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 20)/2400.0);
			}
			scale: {
				if(valueSpeed > 0 && valueSpeed < 40)
					return (1.2 - Math.abs(valueSpeed - 20)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed20.png"
		}
		Image {
			id: speed40
			x: 1283
			y: 321
			opacity: {
				if(valueSpeed >= 20 && valueSpeed < 60)
					return (1.0 - Math.abs(valueSpeed- 40)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 40)/2400.0);
			}
			scale: {
				if(valueSpeed > 20 && valueSpeed < 60)
					return (1.2 - Math.abs(valueSpeed - 40)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed40.png"
		}
		Image {
			id: speed60
			x: 1308
			y: 236
			opacity: {
				if(valueSpeed >= 40 && valueSpeed < 80)
					return (1.0 - Math.abs(valueSpeed- 60)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 60)/2400.0);
			}
			scale: {
				if(valueSpeed > 40 && valueSpeed < 80)
					return (1.2 - Math.abs(valueSpeed - 60)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed60.png"
		}
		Image {
			id: speed80
			x: 1358
			y: 170
			opacity: {
				if(valueSpeed >= 60 && valueSpeed < 100)
					return (1.0 - Math.abs(valueSpeed- 80)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 80)/2400.0);
			}
			scale: {
				if(valueSpeed > 60 && valueSpeed < 100)
					return (1.2 - Math.abs(valueSpeed - 80)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed80.png"
		}
		Image {
			id: speed100
			x: 1416
			y: 123
			opacity: {
				if(valueSpeed >= 80 && valueSpeed < 120)
					return (1.0 - Math.abs(valueSpeed- 100)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 100)/2400.0);
			}
			scale: {
				if(valueSpeed > 80 && valueSpeed < 120)
					return (1.2 - Math.abs(valueSpeed - 100)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed100.png"
		}
		Image {
			id: speed120
			x: 1508
			y: 94
			opacity: {
				if(valueSpeed >= 100 && valueSpeed < 140)
					return (1.0 - Math.abs(valueSpeed- 120)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 120)/2400.0);
			}
			scale: {
				if(valueSpeed > 100 && valueSpeed < 140)
					return (1.2 - Math.abs(valueSpeed - 120)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed120.png"
		}
		Image {
			id: speed140
			x: 1590
			y: 119
			opacity: {
				if(valueSpeed >= 120 && valueSpeed < 160)
					return (1.0 - Math.abs(valueSpeed- 140)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 140)/2400.0);
			}
			scale: {
				if(valueSpeed > 120 && valueSpeed < 160)
					return (1.2 - Math.abs(valueSpeed - 140)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed140.png"
		}
		Image {
			id: speed160
			x: 1666
			y: 170
			opacity: {
				if(valueSpeed >= 140 && valueSpeed < 180)
					return (1.0 - Math.abs(valueSpeed- 160)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 160)/2400.0);
			}
			scale: {
				if(valueSpeed > 140 && valueSpeed < 180)
					return (1.2 - Math.abs(valueSpeed - 160)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed160.png"
		}
		Image {
			id: speed180
			x: 1713
			y: 236
			opacity: {
				if(valueSpeed >= 160 && valueSpeed < 200)
					return (1.0 - Math.abs(valueSpeed- 180)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 180)/2400.0);
			}
			scale: {
				if(valueSpeed > 160 && valueSpeed < 200)
					return (1.2 - Math.abs(valueSpeed - 180)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed180.png"
		}
		Image {
			id: speed200
			x: 1724
			y: 321
			opacity: {
				if(valueSpeed >= 180 && valueSpeed < 220)
					return (1.0 - Math.abs(valueSpeed- 200)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 200)/2400.0);
			}
			scale: {
				if(valueSpeed > 180 && valueSpeed < 220)
					return (1.2 - Math.abs(valueSpeed - 200)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed200.png"
		}
		Image {
			id: speed220
			x: 1719
			y: 413
			opacity: {
				if(valueSpeed >= 200 && valueSpeed < 240)
					return (1.0 - Math.abs(valueSpeed- 220)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 220)/2400.0);
			}
			scale: {
				if(valueSpeed > 200 && valueSpeed < 240)
					return (1.2 - Math.abs(valueSpeed - 220)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed220.png"
		}
		Image {
			id: speed240
			x: 1676
			y: 497
			opacity: {
				if(valueSpeed > 220 && valueSpeed <= 240)
					return (1.0 - Math.abs(valueSpeed- 240)/50.0);
				else
					return (0.2 - Math.abs(valueSpeed- 240)/2400.0);
			}
			scale: {
				if(valueSpeed > 220 && valueSpeed <= 240)
					return (1.2 - (240 - valueSpeed)/66.0);
				else
					return 0.9
			}
			Behavior on opacity { SpringAnimation{ spring: 1.2; damping: 0.2;} }
			Behavior on scale { SpringAnimation{ spring: 1.2; damping: 0.2;} }

			source: "qrc:/speedDisk/images/rightPanel/speedDisk/speed240.png"
		}
	}

	Item{
		id:speedScale
		opacity: 0.0
		Item{
			id:sScale
			Image {
				id: s24
				x: 1787
				y: 499
				opacity: 1.0
				width: 17
				height: 14
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s24.png"
			}
			Image {
				id: s23
				x: 1809
				y: 451
				opacity: 1.0
				width: 19
				height: 14
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s23.png"
			}
			Image {
				id: s22
				x: 1823
				y: 401
				opacity: 1.0
				width: 19
				height: 10
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s22.png"
			}
			Image {
				id: s21
				x: 1827
				y: 350
				opacity: 1.0
				width: 19
				height: 9
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s21.png"
			}
			Image {
				id: s20
				x: 1821
				y: 297
				opacity: 1.0
				width: 19
				height: 11
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s20.png"
			}
			Image {
				id: s19
				x: 1806
				y: 245
				opacity: 1.0
				width: 19
				height: 12
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s19.png"
			}
			Image {
				id: s18
				x: 1783
				y: 197
				opacity: 1.0
				width: 18
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s18.png"
			}
			Image {
				id: s17
				x: 1752
				y: 155
				opacity: 1.0
				width: 16
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s17.png"
			}
			Image {
				id: s16
				x: 1714
				y: 119
				opacity: 1.0
				width: 15
				height: 17
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s16.png"
			}
			Image {
				id: s15
				x: 1669
				y: 91
				opacity: 1.0
				width: 14
				height: 18
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s15.png"
			}
			Image {
				id: s14
				x: 1621
				y: 72
				opacity: 1.0
				width: 11
				height: 19
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s14.png"
			}
			Image {
				id: s13
				x: 1570
				y: 62
				opacity: 1.0
				width: 9
				height: 19
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s13.png"
			}
			Image {
				id: s12
				x: 1518
				y: 62
				opacity: 1.0
				width: 9
				height: 19
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s12.png"
			}
			Image {
				id: s11
				x: 1464
				y: 72
				opacity: 1.0
				width: 12
				height: 19
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s11.png"
			}
			Image {
				id: s10
				x: 1414
				y: 91
				opacity: 1.0
				width: 13
				height: 18
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s10.png"
			}
			Image {
				id: s9
				x: 1370
				y: 118
				opacity: 1.0
				width: 15
				height: 17
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s9.png"
			}
			Image {
				id: s8
				x: 1329
				y: 155
				opacity: 1.0
				width: 16
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s8.png"
			}
			Image {
				id: s7
				x: 1296
				y: 197
				opacity: 1.0
				width: 17
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s7.png"
			}
			Image {
				id: s6
				x: 1272
				y: 245
				opacity: 1.0
				width: 18
				height: 12
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s6.png"
			}
			Image {
				id: s5
				x: 1256
				y: 297
				opacity: 1.0
				width: 19
				height: 11
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s5.png"
			}
			Image {
				id: s4
				x: 1251
				y: 351
				opacity: 1.0
				width: 19
				height: 9
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s4.png"
			}
			Image {
				id: s3
				x: 1255
				y: 401
				opacity: 1.0
				width: 19
				height: 10
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s3.png"
			}
			Image {
				id: s2
				x: 1269
				y: 451
				opacity: 1.0
				width: 18
				height: 14
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s2.png"
			}
			Image {
				id: s1
				x: 1292
				y: 499
				opacity: 1.0
				width: 18
				height: 14
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/s1.png"
			}
		}

		Item{
			id:mScale
			Image {
				id: m12
				x: 1797
				y: 475
				opacity: 1.0
				width: 22
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m12.png"
			}
			Image {
				id: m11
				x: 1823
				y: 375
				opacity: 1.0
				width: 23
				height: 10
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m11.png"
			}
			Image {
				id: m10
				x: 1813
				y: 271
				opacity: 1.0
				width: 23
				height: 12
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m10.png"
			}
			Image {
				id: m9
				x: 1766
				y: 174
				opacity: 1.0
				width: 21
				height: 18
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m9.png"
			}
			Image {
				id: m8
				x: 1691
				y: 101
				opacity: 1.0
				width: 16
				height: 22
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m8.png"
			}
			Image {
				id: m7
				x: 1595
				y: 64
				opacity: 1.0
				width: 11
				height: 23
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m7.png"
			}
			Image {
				id: m6
				x: 1490
				y: 64
				opacity: 1.0
				width: 11
				height: 23
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m6.png"
			}
			Image {
				id: m5
				x: 1389
				y: 101
				opacity: 1.0
				width: 17
				height: 22
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m5.png"
			}
			Image {
				id: m4
				x: 1310
				y: 174
				opacity: 1.0
				width: 20
				height: 18
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m4.png"
			}
			Image {
				id: m3
				x: 1261
				y: 271
				opacity: 1.0
				width: 23
				height: 12
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m3.png"
			}
			Image {
				id: m2
				x: 1250
				y: 375
				opacity: 1.0
				width: 23
				height: 10
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m2.png"
			}
			Image {
				id: m1
				x: 1278
				y: 475
				opacity: 1.0
				width: 22
				height: 15
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/m1.png"
			}
		}

		Item{
			id:bScale
			Image {
				id: b13
				x: 1765
				y: 512
				opacity: 1.0
				width: 35
				height: 43
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b13.png"
			}
			Image {
				id: b12
				x: 1809
				y: 419
				opacity: 1.0
				width: 37
				height: 39
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b12.png"
			}
			Image {
				id: b11
				x: 1818
				y: 315
				opacity: 1.0
				width: 36
				height: 38
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b11.png"
			}
			Image {
				id: b10
				x: 1788
				y: 212
				opacity: 1.0
				width: 36
				height: 42
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b10.png"
			}
			Image {
				id: b9
				x: 1725
				y: 127
				opacity: 1.0
				width: 34
				height: 45
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b9.png"
			}
			Image {
				id: b8
				x: 1638
				y: 71
				opacity: 1.0
				width: 29
				height: 47
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b8.png"
			}
			Image {
				id: b7
				x: 1536
				y: 52
				opacity: 1.0
				width: 26
				height: 47
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b7.png"
			}
			Image {
				id: b6
				x: 1431
				y: 71
				opacity: 1.0
				width: 30
				height: 47
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b6.png"
			}
			Image {
				id: b5
				x: 1339
				y: 127
				opacity: 1.0
				width: 34
				height: 45
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b5.png"
			}
			Image {
				id: b4
				x: 1274
				y: 212
				opacity: 1.0
				width: 36
				height: 42
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b4.png"
			}
			Image {
				id: b3
				x: 1244
				y: 315
				opacity: 1.0
				width: 37
				height: 38
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b3.png"
			}
			Image {
				id: b2
				x: 1252
				y: 419
				opacity: 1.0
				width: 37
				height: 39
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b2.png"
			}
			Image {
				id: b1
				x: 1298
				y: 512
				opacity: 1.0
				width: 36
				height: 43
				source: "qrc:/speedDisk/images/rightPanel/speedDisk/b1.png"
			}
		}
	}


	Image {
		id: rightPointer
		x: 35 + 1221 - 43
		y: 303
		opacity: 0.0
		source: "qrc:/common/disk/images/common/disk/pointer.png"

		transform: Rotation {
			id: rightPointRotation
			origin.x: 370.5+ 1221 - 43- rightPointer.x;
			origin.y: 360 - rightPointer.y;
			angle: valueSpeed * 252.0 / 240.0
			Behavior on angle { SpringAnimation{ spring: 1.2; damping: 0.2; }}
		}
	}


	Image {
		id: speedUint
		x: 1519
		y: 491
		opacity: 0.2
		width: 59
		height: 21
		source: "qrc:/speedDisk/images/rightPanel/speedDisk/speedUint.png"
	}

	Item{
		id: powerBarMask
		x: 106 + 1221 - 43
		y: 92
		opacity: 0.9
		width: powerBarS.width/2
		height: powerBarS.height
		clip:true
		rotation: -153
		transformOrigin: Item.Right
		smooth: true
		Item{
			id: powerBar
			width: powerBarS.width/2
			height: powerBarS.height
			clip:true
			rotation: {
				if(valueOilMass >= 0 && valueOilMass <= 100)
					return 180-valueOilMass / 100 * 54;
				else
					return 180
			}
			// // 126 - 180
			transformOrigin: Item.Right
			smooth: true
			Behavior on rotation { SpringAnimation{ spring: 1.2; damping: 0.2;}}
			Rectangle{
				id:powerBarS
				width: 530
				height: width
				radius: width/2
				color: "transparent"
				border.color:{
					if(valueOilMass <20)
						return "red";
					else
						return "white"
				}
				border.width: 13
				smooth: true
			}
		}
	}

	Image {
		id: oilBar
		x: 1398
		y: 559
		opacity: 1.0
		width: 296
		height: 96
		source: "qrc:/speedDisk/images/rightPanel/speedDisk/oilBar.png"
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: speed_disk; opacity: 0.0 }
			PropertyChanges { target: rightPointer; opacity: 0.0 }
			PropertyChanges { target: speedNum; opacity: 0.0 }
			PropertyChanges { target: speedScale; opacity: 0.0 }
			PropertyChanges { target: speedUint; opacity: 0.0 }
			PropertyChanges { target: powerBarMask; opacity: 0.0 }
			PropertyChanges { target: oilBar; opacity: 0.0 }
		},
		State {
			name: "normalMode"
			PropertyChanges { target: speed_disk; opacity: 1.0 }
			PropertyChanges { target: rightPointer; opacity: 1.0 }
			PropertyChanges { target: speedNum; opacity: 1.0 }
			PropertyChanges { target: speedScale; opacity: 1.0 }
			PropertyChanges { target: speedUint; opacity: 0.2 }
			PropertyChanges { target: powerBarMask; opacity: 0.9 }
			PropertyChanges { target: oilBar; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "normalMode"
			ParallelAnimation {
				NumberAnimation { target: speed_disk; property: "opacity"; duration: 1000 }
				NumberAnimation { target: rightPointer; property: "opacity"; duration: 1000 }
				NumberAnimation { target: speedNum; property: "opacity"; duration: 1000 }
				NumberAnimation { target: speedScale; property: "opacity"; duration: 1000 }
				NumberAnimation { target: speedUint; property: "opacity"; duration: 1000 }
				NumberAnimation { target: powerBarMask; property: "opacity"; duration: 1000 }
				NumberAnimation { target: oilBar; property: "opacity"; duration: 1000 }
			}
		}
	]
}
