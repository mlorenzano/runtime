import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: main_window
    visible: true
    width: 640
    height: 480
    title: "Runtime"

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            spacing: 2
            ToolButton {
                iconSource: "qrc:/load.png"
                onClicked: file_dialog.open()
            }
            ToolButton {
                iconSource: "qrc:/exit.png"
                onClicked: Qt.quit()
            }

            Item {
                Layout.fillWidth: true
            }
        }
    }

    GridView {
        model: digital_inputs
        width: parent.width
        height: parent.height

        anchors {
            fill: parent
            margins: 20
        }

        delegate: Item {
            width: 100
            height: width
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                width: parent.width * 0.9
                height: parent.height * 0.9
                MouseArea {
                    anchors.fill: parent
                    onClicked: console.log("clicked" + index)
                }
                color: value ? "green" : "red"
                Text {
                    anchors.centerIn: parent
                    text: name
                }

            }
        }
    }

    statusBar: StatusBar {
        RowLayout {
            Label {
                text: menu.filename
                font {
                    pixelSize: 15
                    bold: true
                }
            }

            Item {
                Layout.fillWidth: true
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
