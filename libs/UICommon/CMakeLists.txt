cmake_minimum_required(VERSION 3.10)
project(UICommon)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS REQUIRED
    Core
    Qml
    AppManMainPrivate
    AppManManagerPrivate
    AppManLauncherPrivate
)

file(GLOB_RECURSE SOURCE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Cores/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/System/*.cpp"
)

set(INCLUDE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/."
    "${CMAKE_CURRENT_SOURCE_DIR}/Cores/"
    "${CMAKE_CURRENT_SOURCE_DIR}/Components/"
    "${CMAKE_CURRENT_SOURCE_DIR}/System/"
)

qt6_add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Core Qt6::AppManMainPrivate Qt6::AppManManagerPrivate Qt6::AppManLauncherPrivate)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_FILES})
