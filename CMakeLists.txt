# Set the name and the supported language of the project
project(c-play C)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.9)


# Add sources
set(SOURCES
    src/main.c
    src/map.c
    src/log.c
    src/ini.c
    src/core.c
    src/d_field.c
    src/d_fields.c
    src/d_table.c
    src/d_record.c
    src/test/sqlite_hello.c
    src/test/ini_hello.c
    src/test/log_hello.c
    src/test/map_hello.c
    src/test/core_hello.c
    src/test/data_hello.c
)

# Add an executable 
add_executable(cplay ${SOURCES})

# for the log
# set_property(TARGET cplay PROPERTY C_STANDARD 99)


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