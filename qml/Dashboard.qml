import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    property string currentTime: ""
    property string currentDate: ""

    // To show time and date in dashboard.
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
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 5
        spacing: 16


        Label {
            text: root.currentTime
            color: root.textColor
            font.pixelSize: 28
            Layout.alignment: Qt.AlignRight
        }

        Label {
            text: root.currentDate
            color: root.textColor
            font.pixelSize: 20
            Layout.alignment: Qt.AlignRight

        }

        Label{
            text: "Song: " + media.currentTrack
            color: root.textColor
            font.pixelSize: 20
            Layout.alignment: Qt.AlignRight
        }

        Label{
            text: "Climate: " + climate.cabinTemperature
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Label{
            text: "Navigation: " + navigation.destination + navigation.etaTarget
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }
    }


    ColumnLayout {
        anchors.centerIn: parent
        spacing: 16


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
                id: ecoButton
                text: "ECO"
                onClicked: vehicle.setEcoMode()

                background: Rectangle {
                    // corners
                    radius: 8
                    // button highligting - condition ? valueIfTrue : valueIfFalse
                    color: vehicle.driveModeText === "ECO"
                           ? "#4caf50"
                           : "#444444"
                }
            }

            Button {
                id: normalButton
                text: "NORMAL"
                onClicked: vehicle.setNormalMode()

                background: Rectangle {
                    radius: 8
                    color: vehicle.driveModeText === "NORMAL"
                           ? "#2196f3"
                           : "#444444"
                }
            }

            Button {
                id: sportButton
                text: "SPORT"
                onClicked: vehicle.setSportMode()

                background: Rectangle {
                    radius: 8
                    color: vehicle.driveModeText === "SPORT"
                           ? "#f44336"
                           : "#444444"
                }
            }
        }
    }
}