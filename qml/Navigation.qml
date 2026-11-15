import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 16

        Text {
            text: "NAVIGATION"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: navigation.isNavActive
                  ? "Navigation active"
                  : "Navigation inactive"
            color: root.textColor
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: navigation.destination === ""
                  ? "Destination: Not set"
                  : "Destination: " + navigation.destination
            color: root.textColor
            font.pixelSize: 24
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: "ETA: " + navigation.etaTarget + " min"
            color: root.textColor
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 12

            Text {
                text: "Latitude: " + navigation.vehicleLatitude
                color: root.textColor
                font.pixelSize: 16
            }

            Text {
                text: "Longitude: " + navigation.vehicleLongitude
                color: root.textColor
                font.pixelSize: 16
            }
        }

        Rectangle {
            Layout.preferredWidth: 500
            Layout.preferredHeight: 220
            Layout.alignment: Qt.AlignHCenter

            radius: 12
            color: "#2f2f2f"
            border.color: "#555555"
            border.width: 1

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 12

                Text {
                    text: "Map placeholder"
                    color: "white"
                    font.pixelSize: 22
                    Layout.alignment: Qt.AlignHCenter
                }

                Text {
                    text: "Vehicle position"
                    color: "#cccccc"
                    font.pixelSize: 16
                    Layout.alignment: Qt.AlignHCenter
                }

                Text {
                    text: navigation.vehicleLatitude
                          + ", "
                          + navigation.vehicleLongitude
                    color: "#cccccc"
                    font.pixelSize: 14
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 12

            Button {
                text: "Helsinki"

                onClicked: {
                    navigation.destination = "Helsinki"
                    navigation.etaTarget = 25
                }
            }

            Button {
                text: "Tampere"

                onClicked: {
                    navigation.destination = "Tampere"
                    navigation.etaTarget = 95
                }
            }

            Button {
                text: navigation.isNavActive
                      ? "Stop navigation"
                      : "Start navigation"

                onClicked: navigation.toggleNavigation()
            }
        }
    }
}