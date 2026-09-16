import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    property string currentTime: ""
    property string currentDate: ""

    Timer {
        interval: 1000
        running: true
        repeat: true

        onTriggered: {
            const now = new Date()

            root.currentTime = Qt.formatTime(now, "HH:mm:ss")
            root.currentDate = Qt.formatDate(now, "dd.MM.yyyy")
        }
    }

    Component.onCompleted: {
        const now = new Date()

        currentTime = Qt.formatTime(now, "HH:mm:ss")
        currentDate = Qt.formatDate(now, "dd.MM.yyyy")
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 16


        Label {
            text: root.currentTime
            color: root.textColor
            font.pixelSize: 28
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: root.currentDate
            color: root.textColor
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: vehicle.speed + " km/h"
            color: root.textColor
            font.pixelSize: 72
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: vehicle.batteryLevel + "%"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: vehicle.driveModeText
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: vehicle.temperature + " °C"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 12

            Button {
                text: "ECO"
                onClicked: vehicle.driveMode = Vehicle.Eco
            }

            Button {
                text: "NORMAL"
                onClicked: vehicle.driveMode = Vehicle.Normal
            }

            Button {
                text: "SPORT"
                onClicked: vehicle.driveMode = Vehicle.Sport
            }
        }
    }
}
