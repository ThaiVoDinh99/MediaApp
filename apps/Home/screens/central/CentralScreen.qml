import QtQuick
import QtQuick.Controls
import Home.Cores

Window {
    id: rootItem
    width: 1280
    height: 540
    visible: true

    // onClosing: (close) => {
    //     close.accepted = false
    //     console.warn("This is a warning!")
    // }

    Repeater {
        id: layers
        model: LayerManager
        delegate: Loader {
            id: loaderDelegate
            source: model.layerSource
            active: true
            anchors.fill: parent
        }
    }
}
