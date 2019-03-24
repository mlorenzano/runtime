import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    //title: "Runtime"
    //flags: Qt.SplashScreen

    header: Item {

        Button {
            id: load_file
            anchors {
                left: parent.left
                leftMargin: 10
            }
            width: 48
            height: width
            background: Rectangle {
                color: "transparent"
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
            anchors {
                left: load_file.right
                leftMargin: 10
            }
            width: 32
            height: 32
        }
    }

    FileDialog {
        id: file_dialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + file_dialog.fileUrls)
            menu.load(file_dialog.fileUrls)
            close()
        }
        onRejected: {
            console.log("Canceled")
            close()
        }
    }
}
