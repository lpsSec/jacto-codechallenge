import QtQuick
import QtQuick.Controls

Item {
    id: principalItem

    Column {
        anchors.centerIn: parent
        spacing: 20

        Button {
            text: "Abrir Arquivo"
            onClicked: stackView.push("qrc:/AbreArquivo.qml")
        }
        Button {
            text: "Transmitir Comando"
            onClicked: stackView.push("qrc:/TransmitirComando.qml")
        }

        Button {
            text: "Sair"
            onClicked: Qt.quit()
        }
    }
}
