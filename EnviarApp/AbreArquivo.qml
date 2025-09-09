import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Item {
    id: abrirArquivoItem

    Row {
        width: parent.width
        spacing: 10
        padding: 10

        FileDialog {
            id: fileDialog
            title: "Selecione um arquivo"
            nameFilters: ["Text files (*.txt)"]
            // currentFolder: Qt.resolvedUrl(".")
            onAccepted: {
                let path = fileDialog.currentFile
                textArea.text = CarregarArquivo.readFile(path)
            }
        }

        Button {
            text: "Selecionar"
            onClicked: {
                fileDialog.open()
            }
        }

        Button {
            text: "Voltar"
            onClicked: stackView.pop()
        }
        }

    TextArea {
        id: textArea
        anchors.left: parent.left
        anchors.right: parent.right
        // anchors.top: parent.top + 40
        // anchors.bottom: parent.bottom +20
        y: 50
        height: parent.height - 60
        readOnly: true
        wrapMode: Text.Wrap
        background: Rectangle {
                color: "#ffffff"
                border.color: "#888888"
                border.width: 1
            }
    }
}
