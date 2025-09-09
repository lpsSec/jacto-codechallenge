import QtQuick
import QtQuick.Controls

Item {
    id: transmitirComandoItem

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
                text: ""
                width: 250

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
                text: ""
                leftPadding: 10
                wrapMode: Text.Wrap
                background: Rectangle {
                        color: "#ffffff"
                        border.color: "#888888"
                        border.width: 1
                    }
            }
        }
        Row {
            spacing: 10
            Button {
                text: "Enviar"
                onClicked: {
                    var topicText = textTopicContent.text
                    var contentText = textAreaContent.text
                    EnviarComando.sendMessage(topicText, contentText)
                }
            }
            Button {
                text: "Voltar"
                onClicked: stackView.pop()
            }
        }
    }
}
