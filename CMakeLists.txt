project(SpeechControl)
cmake_minimum_required(VERSION 2.8)

# Incorporate our custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

# Special options to include in the build.
option(WITH_KDE "Provides support with KDE." OFF)

## Required packages
find_package(PkgConfig 0.2 REQUIRED)
find_package(Qt4 4.7 COMPONENTS
  QtCore
  QtDBus
  REQUIRED)

include(SpeechControlDefaults)
include(SpeechControlMacros)
include(CTestMacroExtras)

## Variables for SpeechControl.
set(PROJECT_VERSION "0.1")
set(SPCHCNTRL_BUILDING ON)
set(SPCHCNTRL_CMAKE_SDIR "${PROJECT_SOURCE_DIR}/cmake")
set(SPCHCNTRL_INCLUDE_DIRS ${QT_INCLUDE_DIR}
    ${QT_QTCORE_INCLUDE_DIR} ${QT_QTDBUS_INCLUDE_DIR})
set(SPCHCNTRL_BUILD_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_BINARY_DIR}/src")
set(SPCHCNTRL_LIBRARIES ${QT_QTCORE_LIBRARY} ${QT_QTDBUS_LIBRARY} ${QT_QTDBUS_LIB_DEPENDENCIES})

## The subdirectories, order's vital here.
add_subdirectory(cmake)
add_subdirectory(res)
add_subdirectory(src)
add_subdirectory(doc)