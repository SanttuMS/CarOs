import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic


ApplicationWindow {
    id: window
    width: 640
    height: 480
    minimumWidth: 400
    minimumHeight: 300
    visible: true
    title: qsTr("CarOs")

    property bool lightMode: Application.styleHints.colorScheme === Qt.Light
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

            Dashboard{
                Layout.fillWidth: true
                Layout.fillHeight: true

                textColor: window.lightmode
                            ?window.dark
                            :window.light

            }

            Button {
                id: button1

                text: window.lightMode
                      ? qsTr("\u263D  Dark mode")
                      : qsTr("\u263C  Light mode")

                Layout.alignment: Qt.AlignHCenter

                onClicked: window.lightMode = !window.lightMode
            }
        }
    }
}