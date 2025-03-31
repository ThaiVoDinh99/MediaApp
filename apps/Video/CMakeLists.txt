cmake_minimum_required(VERSION 3.10)
project(Video)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS REQUIRED
    Quick
    Core
    Gui
    AppManMainPrivate
    AppManManagerPrivate
)

file(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/controllers/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/cores/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/models/*.cpp"
)

set(INCLUDE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/controllers/"
    "${CMAKE_CURRENT_SOURCE_DIR}/cores/"
    "${CMAKE_CURRENT_SOURCE_DIR}/models/"
)

qt6_add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::AppManMainPrivate
    Qt6::AppManManagerPrivate
    UICommon
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_FILES})

install(TARGETS ${PROJECT_NAME}
    DESTINATION "executable/apps/Video"
)

install(FILES info.yaml video.png
    DESTINATION "executable/apps/Video"
)
