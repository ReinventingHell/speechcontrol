file(GLOB_RECURSE SPCHCNTRL_SRCS "*.cpp")

include("${QT_USE_FILE}")
add_executable(speechcontrol ${SPCHCNTRL_SRCS})
target_link_libraries(speechcontrol ${QT_LIBRARIES})
