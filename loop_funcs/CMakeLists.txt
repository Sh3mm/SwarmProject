cmake_minimum_required(VERSION 2.8.12)
project(SwarmProject)
set(CMAKE_CXX_STANDARD 11)
# Deactivate RPATH for MacOSX
set(CMAKE_MACOSX_RPATH 0)

# Find the ARGoS package
find_package(PkgConfig REQUIRED)
find_package(ARGoS REQUIRED)
include_directories(${ARGOS_INCLUDE_DIRS})
link_directories(${ARGOS_LIBRARY_DIR})
link_libraries(${ARGOS_LDFLAGS})
string(REPLACE "/lib/argos3" "" ARGOS_PREFIX "${ARGOS_LIBRARY_DIR}")
set(CMAKE_INSTALL_PREFIX ${ARGOS_PREFIX} CACHE STRING "Install path prefix, prepended onto install directories." FORCE)


# Find the Buzz package
find_package(PkgConfig)
pkg_check_modules(BUZZ REQUIRED buzz)

include_directories(${CMAKE_SOURCE_DIR} ${ARGOS_INCLUDE_DIRS} ${BUZZ_INCLUDE_DIR})

# Set ARGoS link dir
link_directories(${ARGOS_LIBRARY_DIRS} ${BUZZ_LIBRARY_DIRS})

# Compile target
file(GLOB SRC "*.h" "*.cpp")

add_library(SwarmProject SHARED
        ${SRC}
)

target_link_libraries(SwarmProject
      buzz
      argos3core_simulator
      argos3plugin_simulator_dynamics2d
      argos3plugin_simulator_entities
      argos3plugin_simulator_footbot
      argos3plugin_simulator_genericrobot
      argos3plugin_simulator_media
      argos3plugin_simulator_buzz
  )

# Install stuff
# install(TARGETS SwarmProject DESTINATION ${ARGOS_PREFIX}/lib/argos3)

