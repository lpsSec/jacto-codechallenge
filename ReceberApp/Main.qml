import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: appWindow
    width: 800
    height: 600
    visible: true
    title: qsTr("Receber")

    Column {
        width: parent.width
        spacing: 15
        padding: 10

        Row {
            Text {
                id: textTopic
                text: qsTr("Tópico")
                font.bold: true
            }
            TextField {
                id: textTopicContent
                text: receiver.topic
                width: 250
                enabled: false
                background: Rectangle {
                    color: "#ffffff"
                    border.color: "#888888"
                    border.width: 1
                }
            }
        }

        Row {
            Text {
                id: textContent
                text: qsTr("Contúdo")
                font.bold: true
            }
            TextArea{
                id: textAreaContent
                width: 450
                height: 450
                text: receiver.content
                leftPadding: 10
                readOnly: true
                wrapMode: Text.Wrap
                background: Rectangle {
                        color: "#ffffff"
                        border.color: "#888888"
                        border.width: 1
                    }
            }
        }
        Row {
            Button {
                text: "Limpar"
                onClicked: {
                    textTopicContent.text = ""
                    textAreaContent.text = ""
                }
            }
        }
    }
}
