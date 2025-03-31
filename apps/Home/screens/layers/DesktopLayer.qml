import QtQuick
import Home.Cores
import QtQuick.Controls

Item {
    id: rootItem

    Rectangle {
        id: headerBar
        width: 1280
        height: 80
        color: "black"
    }

    Rectangle {
        id: mainLayer
        width: 1280
        height: 540 - headerBar.height
        anchors.top: headerBar.bottom
        color: "blue"

        SwipeView {
            id: mainView
            currentIndex: 0
            width: mainLayer.width/2
            height: mainLayer.height

            Repeater {
                id: repeaterLayout
                model: ApplicationManager
                delegate: Page {
                    id: boderView
                    width: mainLayer.width/2
                    height: mainLayer.height
                    background: Rectangle { color: "red" }

                    Rectangle {
                        width: parent.width - 40
                        height: parent.height - 60
                        anchors {
                            horizontalCenter: parent.horizontalCenter
                            top: parent.top
                            topMargin: 20
                        }

                        color: "gray"
                        Text {
                            id: appName
                            text: model.Name
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        Image {
                            id: imageDelegate
                            width: 100
                            height: 100
                            anchors.centerIn: parent
                            source: model.Icon
                        }
                    }
                }
            }
        }

        PageIndicator {
            id: indicator
            count: mainView.count - 1
            currentIndex: mainView.currentIndex
            anchors.bottom: mainView.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            delegate: Rectangle {
                width: 50
                height: 10
                color: index === indicator.currentIndex ? "yellow" : "gray"
            }
        }
    }
}


