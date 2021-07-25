# Set the name and the supported language of the project
project(c-play C)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.9)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

# Add sources
set(SOURCES
    src/main.c
    src/map.c
    src/log.c
    src/ini.c
)

# Add an executable 
add_executable(cplay ${SOURCES})

# for the log
# set_property(TARGET cplay PROPERTY C_STANDARD 99)

# Link the target to the GTK+ libraries
target_link_libraries(cplay ${GTK3_LIBRARIES})

target_include_directories(cplay
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
find_package (SQLite3)
if (SQLITE3_FOUND)
  include_directories(${SQLITE3_INCLUDE_DIRS})
  # target_link_libraries (cplay ${SQLITE3_LIBRARIES})
  target_link_libraries (cplay sqlite3)
endif (SQLITE3_FOUND)