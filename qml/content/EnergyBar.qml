import QtQuick 2.2

Item {
	property real   column
	property string sekuai
	property string targetShade

	property alias level:  energyBarEffect.level
	property alias mirror: energyBarEffect.mirror
	property alias moving: energyBarEffect.moving

	id: energyBar
	width: mTargetShade.width
	height: mTargetShade.height

	Image {
		id: mSeKuai
		visible: false
		source: sekuai
	}

	Image {
		id: mTargetShade
		visible: false
		source: targetShade
	}

	ShaderEffect {
		property real level: 0
		property real wave:  0
		property int mirror: 0
		property int moving: 0

		property real column :         energyBar.column
		property variant sekuai :      mSeKuai
		property variant targetShade : mTargetShade

		id: energyBarEffect
		width: energyBar.width
		height: energyBar.height

		NumberAnimation on wave {
			from: 0.0; to: 1.0; loops: Animation.Infinite; duration: 2000
		}

		fragmentShader: "
			//precision mediump float;
			varying highp vec2 qt_TexCoord0;
			uniform sampler2D sekuai;
			uniform sampler2D targetShade;
			uniform int mirror;
			uniform int moving;
			uniform lowp float column;
			uniform lowp float level;
			uniform lowp float wave;

			void main() {
				vec2 coord = qt_TexCoord0;
				vec2 coordSeKuai = vec2(column, level);

				if (mirror == 1)
				coord.x = 1.0 - coord.x;
				if (coord.x < level) {
					vec4 colorSeKuai = texture2D(sekuai, coordSeKuai);
					vec4 colorTargetShade = texture2D(targetShade, coord);
					colorTargetShade = colorSeKuai * colorTargetShade* 3.0;
					if (moving != 0) {
						if (1.0 - coord.x > wave - 0.05 &&
							1.0 - coord.x < wave + 0.05)
						colorTargetShade = colorTargetShade * (1.4 - 0.4 * cos(6.28 / 0.1 * (1.0 - coord.x - (wave - 0.05))));
					}
					gl_FragColor = colorTargetShade;
				}
				else
				gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
			}"
	}
}
