cmake_minimum_required(VERSION 3.10)

project(tenelles.personal.sdPlugin VERSION 1.0)

# set the C++ standard to C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)
if (MSVC)
  add_definitions("/Zc:__cplusplus" -DUNICODE=1)
endif()
include_directories("${CMAKE_SOURCE_DIR}")

add_subdirectory(StreamDockCPPSDK/Vendor)
add_subdirectory(StreamDockCPPSDK/StreamDockSDK)

set(
  SOURCES
  "BrightnessAction.cpp"
  "PersonalPlugin.cpp"
  main.cpp
)
add_executable(
  tenellesPersonalPlugin
  ${SOURCES}
)

target_link_libraries(tenellesPersonalPlugin StreamDockSDK)
