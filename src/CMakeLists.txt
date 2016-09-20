cmake_minimum_required(VERSION 2.8.11)

project(dgp2016)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5core)
find_package(Qt5Widgets)
find_package(Qt5Svg)

set(FORMS_DIR ${PROJECT_SOURCE_DIR}/../forms)
set(ASSETS_DIR ${PROJECT_SOURCE_DIR}/../assets)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

add_definitions(-DNOMINMAX -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_USE_MATH_DEFINES)

#add current dir to include search path
include_directories(${PROJECT_SOURCE_DIR})

#library list
set(LIB_LIST Qt5::Core Qt5::Widgets Qt5::Svg)

add_subdirectory(io)
set(LIB_LIST ${LIB_LIST} io)

add_subdirectory(util)
set(LIB_LIST ${LIB_LIST} util)

add_subdirectory(core)
set(LIB_LIST ${LIB_LIST} core)

add_subdirectory(wrl)
set(LIB_LIST ${LIB_LIST} wrl)

add_subdirectory(gui)
set(LIB_LIST ${LIB_LIST} gui)

