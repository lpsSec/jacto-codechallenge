import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: appWindow
    width: 800
    height: 600
    visible: true
    title: qsTr("Enviar")

    StackView {
            id: stackView
            anchors.fill: parent
            initialItem: "qrc:/Principal.qml"
        }
}
