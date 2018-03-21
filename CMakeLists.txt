cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
add_subdirectory(clog ${CMAKE_SOURCE_DIR}/build/clog)

add_subdirectory(Node ${CMAKE_SOURCE_DIR}/build/Node)

add_subdirectory(UniversalUI ${CMAKE_SOURCE_DIR}/build/UniversalUI)

# modules to use
add_subdirectory(UniversalUI/uui_modules/FLTKUI ${CMAKE_SOURCE_DIR}/build/FLTKUI)
add_subdirectory(UniversalUI/uui_modules/CharacterUI ${CMAKE_SOURCE_DIR}/build/CharacterUI)

#main application
add_subdirectory(app ${CMAKE_SOURCE_DIR}/build/app)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
