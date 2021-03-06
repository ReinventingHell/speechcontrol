# Testing configuration for SpeechControl.
# Designed for CTest, but Experiri can handle this as well.

set(CTEST_PROJECT_NAME "SpeechControl")
set(CTEST_NIGHTLY_START_TIME "06:00:00 UTC")

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "cdash.thesii.org")
set(CTEST_DROP_LOCATION "/submit.php?project=SpeechControl")
set(CTEST_DROP_SITE_CDASH TRUE)


set(CTEST_OUTPUT_ON_FAILURE TRUE)
set(CTEST_SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CTEST_BINARY_DIRECTORY "${CMAKE_BINARY_DIR}")

