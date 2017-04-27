
cmake_minimum_required (VERSION 2.6)
project (POO)
find_package(SDL REQUIRED)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set (PROJECT_SOURCE_DIR src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories ("${PROJECT_SOURCE_DIR}/")
include_directories (${SDL_INCLUDE_DIR})

FILE(
  GLOB_RECURSE
  file_prj
  src/*
  )

add_executable(test.bin ${file_prj})

target_link_libraries(test.bin "X11")
target_link_libraries(test.bin ${SDL_LIBRARY})


