qt6_add_library(HomeLayerResources STATIC)
qt6_add_resources(HomeLayerResources "HomeLayerResources"
    PREFIX "/"
    FILES
        DesktopLayer.qml
        PopupLayer.qml
)
