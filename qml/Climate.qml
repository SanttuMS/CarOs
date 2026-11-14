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

    }
}