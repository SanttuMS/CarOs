import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    ColumnLayout{
        anchors.centerIn: parent
        spacing: 16


        Label{
            text: vehicle.speed + " km/h"
            color: root.textColor
            font.pixelSize: 72
            Layout.alignment: Qt.AlignHCenter
        }

        Label{
            text: vehicle.batteryLevel + " %"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Label{
            text: vehicle.driveModeText
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter

        }

        Label{
            text: vehicle.temperature + " °C"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
