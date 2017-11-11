cmake_minimum_required(VERSION 3.0)

add_subdirectory(clog ${CMAKE_SOURCE_DIR}/clog/build)

add_subdirectory(UniversalUI ${CMAKE_SOURCE_DIR}/UniversalUI/build)

# modules to use
add_subdirectory(UniversalUI/uui_modules/FLTKUI UniversalUI/uui_modules/FLTKUI/build)
add_subdirectory(UniversalUI/uui_modules/CharacterUI UniversalUI/uui_modules/CharacterUI/build)

#main application
add_subdirectory(app app/build)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
