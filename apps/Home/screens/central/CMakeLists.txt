qt6_add_qml_module(CentralResources
    URI "screens.central"
    RESOURCE_PREFIX "/"
    QML_FILES
        main.qml
        CentralScreen.qml
)

install(FILES main.qml
    DESTINATION "executable/apps/Home"
)
