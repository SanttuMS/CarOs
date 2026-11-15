import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 16

        Text{
            text: "Climate"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignCenter
        }

        Text{
            text: "Target temperature: " + climate.cabinTemperature
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignCenter

        }

        RowLayout{
            Layout.alignment: Qt.AlignCenter
            spacing: 12

            Button{
                text: climate.isClimateOn ? "On" : "Off"
                onClicked: climate.toggleClimate()
            }

            Text{
                text: "Fan speed: " + climate.fanSpeed
                color: root.textColor
                font.pixelSize: 12
                Layout.alignment: Qt.AlignCenter

            }

            Slider {
                from: 0
                to: 10
                value: climate.fanSpeed

                Layout.preferredWidth: 300
                Layout.alignment: Qt.AlignHCenter

                onMoved: climate.fanSpeed = Math.round(value)
            }

        }

        RowLayout{
            Layout.alignment: Qt.AlignCenter
            spacing: 12

            Button{
                id: autoButton
                text: "AUTO"
                onClicked: climate.setAuto()
                background: Rectangle {
                    // corners
                    radius: 8
                    // button highligting - condition ? valueIfTrue : valueIfFalse
                    color: climate.isClimateOn &&
                            climate.climateModeText === "AUTO"
                            ? "#4caf50"
                            : "#444444"
                }

            }

            Button{
                id: manualButton
                text: "MANUAL"
                onClicked: climate.setManual()
                background: Rectangle {
                    // corners
                    radius: 8
                    // button highligting - condition ? valueIfTrue : valueIfFalse
                    color: climate.isClimateOn &&
                            climate.climateModeText === "MANUAL"
                            ? "#4caf50"
                            : "#444444"
                }

            }

            Button{
                id: defrostButton
                text: "DEFROST"
                onClicked: climate.setDefrost()
                background: Rectangle {
                    // corners
                    radius: 8
                    // button highligting - condition ? valueIfTrue : valueIfFalse
                    color: climate.isClimateOn &&
                            climate.climateModeText === "DEFROST"
                            ? "#4caf50"
                            : "#444444"
                }


            }
        }

    }
}