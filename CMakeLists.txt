cmake_minimum_required(VERSION 3.27)
project(NuclearLoad)

set(SRC "${CMAKE_SOURCE_DIR}/src")
include_directories(${SRC}) 

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(wxWidgets REQUIRED)

file(GLOB SRC_FILES "${SRC}/*.cpp" "${SRC}/*.hpp")
add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRC_FILES}) 

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME} PRIVATE wxWidgets::wxWidgets)
