import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    visible: true
    width: screen.width/3.5
    height: screen.height/1.3
    title: qsTr("test C++")
    color: "blue"

    Rectangle{
        id:root
        width: parent.width/1.4
        height: parent.height/1.4
        anchors.centerIn: parent
        color: "white"
        radius: 20

        ListView{
            anchors.fill: root
            model: myModel
            spacing:10
            delegate: Rectangle{
                id:rect
                width: root.width
                height: root.height/8
                color: "green"
                Text {
                    text: "number"
                    anchors.verticalCenter: rect.verticalCenter
                }
                Text {
                    text: modelData
                    color: "white"
                    anchors{
                        verticalCenter:rect.verticalCenter
                        right: rect.right
                    }
                }
            }
        }


    }
    Button{
        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
        text: "  GO"


    }

}


