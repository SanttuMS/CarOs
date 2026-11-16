import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic

Item {
    id: root

    property color textColor: "white"

    property string currentTime: ""
    property string currentDate: ""

    function updateDateTime() {
        const now = new Date()

        root.currentTime = Qt.formatTime(now, "HH:mm:ss")
        root.currentDate = Qt.formatDate(now, "dd.MM.yyyy")
    }

    Timer {
        interval: 1000
        running: true
        repeat: true

        onTriggered: root.updateDateTime()
    }

    Component.onCompleted: root.updateDateTime()


    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 24
        spacing: 20


        // TOP BAR
        RowLayout {
            Layout.fillWidth: true

            Label {
                text: "CarOS"
                color: root.textColor
                font.pixelSize: 26
                font.bold: true
            }

            Item {
                Layout.fillWidth: true
            }

            ColumnLayout {
                spacing: 2

                Label {
                    text: root.currentTime
                    color: root.textColor
                    font.pixelSize: 26
                    Layout.alignment: Qt.AlignRight
                }

                Label {
                    text: root.currentDate
                    color: root.textColor
                    font.pixelSize: 16
                    opacity: 0.7
                    Layout.alignment: Qt.AlignRight
                }
            }
        }


        // MAIN DASHBOARD AREA
        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 30


            // LEFT INFORMATION PANEL
            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 18



                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100

                    radius: 12
                    color: "#2f2f2f"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14

                        Label {
                            text: "BATTERY"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                        }

                        Label {
                            text: vehicle.batteryLevel + "%"
                            color: root.textColor
                            font.pixelSize: 30
                            font.bold: true
                            visible: vehicle.isPoweredOn
                        }
                    }
                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100

                    radius: 12
                    color: "#2f2f2f"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14

                        Label {
                            text: "MOTOR TEMPERATURE"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                        }

                        Label {
                            text: vehicle.motorTemperature + " °C"
                            color: root.textColor
                            font.pixelSize: 30
                            font.bold: true
                            visible: vehicle.isPoweredOn
                        }
                    }
                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 110

                    radius: 12
                    color: "#2f2f2f"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14

                        Label {
                            text: "MEDIA"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                        }

                        Label {
                            text: media.artist + " - " + media.currentTrack
                            color: root.textColor
                            font.pixelSize: 20
                            font.bold: true
                            visible: vehicle.isPoweredOn
                        }

                        Label {
                            text: media.mediaModeText
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                            visible: vehicle.isPoweredOn
                        }
                    }
                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 110

                    radius: 12
                    color: "#2f2f2f"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14

                        Label {
                            text: "CLIMATE"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                        }

                        Label {
                            text: climate.cabinTemperature + " °C"
                            color: root.textColor
                            font.pixelSize: 20
                            font.bold: true
                            visible: vehicle.isPoweredOn
                        }

                        Label {
                            text: climate.isClimateOn
                                  ? climate.climateModeText
                                  : "OFF"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                            visible: vehicle.isPoweredOn
                        }
                    }
                }


                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 110

                    radius: 12
                    color: "#2f2f2f"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 14

                        Label {
                            text: "NAVIGATION"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                        }

                        Label {
                            text: navigation.destination === ""
                                  ? "No destination"
                                  : navigation.destination
                            color: root.textColor
                            font.pixelSize: 20
                            font.bold: true
                            visible: vehicle.isPoweredOn
                        }

                        Label {
                            text: navigation.isNavActive
                                  ? "ETA: " + navigation.etaTarget + " min"
                                  : "Navigation inactive"
                            color: root.textColor
                            font.pixelSize: 14
                            opacity: 0.7
                            visible: vehicle.isPoweredOn
                        }
                    }
                }
            }


            // CENTER VEHICLE AREA
            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 18

                Button {
                    text: vehicle.isPoweredOn ? "Power OFF" : "Power ON"
                    onClicked: vehicle.togglePower()
                    Layout.alignment: Qt.AlignCenter
                    background: Rectangle {
                        radius: 8
                    color: vehicle.isPoweredOn ? "Power OFF" : "Power ON"
                           ? "#2196f3"
                           : "#444444"
                    }
                }


                Item {
                    Layout.fillHeight: true
                }


                Label {
                    text: vehicle.speed
                    color: root.textColor
                    font.pixelSize: 100
                    font.bold: true
                    Layout.alignment: Qt.AlignHCenter
                }

                Label {
                    text: "km/h"
                    color: root.textColor
                    font.pixelSize: 24
                    opacity: 0.7
                    Layout.alignment: Qt.AlignHCenter
                }


                Label {
                    text: vehicle.driveModeText
                    color: root.textColor
                    font.pixelSize: 24
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
                            radius: 8

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


                Item {
                    Layout.fillHeight: true
                }


            }
        }
    }
}