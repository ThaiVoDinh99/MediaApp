cmake_minimum_required(VERSION 3.10)
project(Home)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS REQUIRED
    Quick
    Core
    Qml
    AppManMainPrivate
    AppManManagerPrivate
)

file(GLOB_RECURSE SOURCE_RESOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/cores/*cpp"
)

set(INCLUDE_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/."
    "${CMAKE_CURRENT_SOURCE_DIR}/cores"
    "${CMAKE_CURRENT_SOURCE_DIR}/controllers"
)

add_subdirectory(screens)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_RESOURCES} screens/central/CentralResources.qrc)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    Qt6::AppManMainPrivate
    Qt6::AppManManagerPrivate
    CentralResources
    HomeLayerResources
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

install(TARGETS ${PROJECT_NAME}
    DESTINATION "executable/apps/Home"
)
