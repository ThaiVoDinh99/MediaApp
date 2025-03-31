cmake_minimum_required(VERSION 3.10)
project(MediaApp)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

add_subdirectory(libs)
add_subdirectory(apps)

install(FILES am-config.yaml
    DESTINATION "executable/apps/Home"
)
