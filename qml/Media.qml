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
            text: "MEDIA"
            color: root.textColor
            font.pixelSize: 32
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: "Now playing: " + media.artist + " - " + media.currentTrack
            color: root.textColor
            font.pixelSize: 24
            Layout.alignment: Qt.AlignHCenter
        }


        RowLayout{
            Layout.alignment: Qt.AlignHCenter
        Button{
            text: "Next track: " + media.nextTrack
            onClicked: media.nextTrack()
        }
        Button {
            text: media.isPlaying ? "Pause" : "Play"
            Layout.alignment: Qt.AlignHCenter

            onClicked: media.playPause()
        }
        Button{
            text: "Previous track: " + media.previousTrack
            onClicked: media.previousTrack()
        }
    }
        Text {
            text: "Volume: " + media.volume
            color: root.textColor
            font.pixelSize: 18
            Layout.alignment: Qt.AlignHCenter
        }

        Slider {
            from: 0
            to: 100
            value: media.volume

            Layout.preferredWidth: 300
            Layout.alignment: Qt.AlignHCenter

            onMoved: media.volume = Math.round(value)
        }


    RowLayout {
        Layout.alignment: Qt.AlignHCenter
        spacing: 12

        Button {
            id: tunerButton
            text: "Tuner"
            onClicked: media.setTuner()

            background: Rectangle {
                // corners
                radius: 8
                // button highligting - condition ? valueIfTrue : valueIfFalse
                color: media.mediaModeText === "TUNER"
                       ? "#4caf50"
                       : "#444444"
            }
        }

        Button {
            id: spotifyButton
            text: "Spotify"
            onClicked: media.setSpotify()

            background: Rectangle {
                radius: 8
                color: media.mediaModeText === "SPOTIFY"
                       ? "#2196f3"
                       : "#444444"
            }
        }

        Button {
            id: bluetoothButton
            text: "Bluetooth"
            onClicked: media.setBluetooth()

            background: Rectangle {
                radius: 8
                color: media.mediaModeText === "BLUETOOTH"
                       ? "#f44336"
                       : "#444444"
                    }
        }
    }
    }
}


