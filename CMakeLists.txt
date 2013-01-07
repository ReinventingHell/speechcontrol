cmake_minimum_required(VERSION 2.8)
project(SpeechControl)

find_package(Qt4 REQUIRED
    QtCore QtGui)
find_package(QtGStreamer REQUIRED)

add_subdirectory(src)
