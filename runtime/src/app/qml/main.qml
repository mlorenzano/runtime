import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: main_window
    visible: true
    width: 640
    height: 480
    title: "Runtime"

    header: Item {
        id: menu_bar
        Button {
            id: load_file
            anchors {
                left: parent.left
                leftMargin: 10
            }
            width: 32
            height: width
            background: Rectangle {
                color: "lightgray"
                border {
                    width: 1
                    color: "black"
                }
                radius: 5
            }

            Image {
                source: "qrc:/load.png"
                opacity: parent.pressed ? 0.5 : 1
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }

            onClicked: file_dialog.open()
        }

        Button {
            id: exit
            anchors {
                left: load_file.right
                leftMargin: 10
            }
            width: 32
            height: width
            background: Rectangle {
                color: "lightgray"
                border {
                    width: 1
                    color: "black"
                }
                radius: 5
            }

            Image {
                source: "qrc:/exit.png"
                opacity: parent.pressed ? 0.5 : 1
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }

            onClicked: Qt.quit()
        }
    }

    footer: Text {
        text: menu.filename
        font {
            pixelSize: 15
            bold: true
        }
    }

    ListView {
        model: digital_inputs
        spacing: 20
        width: parent.width
        height: parent.height
        delegate: Button {
            width: 50
            height: 50
            text: name
            background: Rectangle {
                color: value ? "green" : "red"
            }
        }
    }

    FileDialog {
        id: file_dialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            menu.load(file_dialog.fileUrls)
            close()
        }

        onRejected: close()
    }
}
