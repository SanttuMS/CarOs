import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: window
    width: 1240
    height: 780
    minimumWidth: 400
    minimumHeight: 300
    visible: true
    title: qsTr("CarOs")

    property bool lightMode: Application.styleHints.colorScheme === Qt.Light
    property string currentView: "Dashboard"
    property color reallyDark: "#1f1f1f"
    property color dark: "#262626"
    property color reallyLight: "#e7e7e7"
    property color light: "#e0e0e0"

    Rectangle {
        anchors.fill: parent
        color: window.lightMode ? window.reallyLight : window.reallyDark

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 24
            spacing: 16

            StackLayout {
                id: stack
                Layout.fillWidth: true
                Layout.fillHeight: true
                currentIndex: 0

                Dashboard {
                    textColor: window.lightMode
                               ? window.dark
                               : window.light
                }

                Media {
                textColor: window.lightMode
                                ? window.dark
                                : window.light
                }

                Navigation {
                textColor: window.lightMode
                                ? window.dark
                                : window.light
                }

                Climate {
                textColor: window.lightMode
                                ? window.dark
                                : window.light


                }
            }
        }

        RowLayout{
                Layout.alignment: Qt.AlignHCenter
                spacing: 12


            Button{
                id: button1

                text: ("Dashboard")

                onClicked: stack.currentIndex = 0
                visible: vehicle.isPoweredOn

            }

            Button{
                id: button2

                text: ("Media")

                onClicked: stack.currentIndex = 1
                visible: vehicle.isPoweredOn

            }

            Button{
                id: button3

                text: ("Navigation")

                onClicked: stack.currentIndex = 2
                visible: vehicle.isPoweredOn

            }

            Button{
                id: button4

                text: ("Climate")

                onClicked: stack.currentIndex = 3
                visible: vehicle.isPoweredOn
            }
        }
    }

}

