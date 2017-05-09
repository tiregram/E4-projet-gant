
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
  file_lib
  src/*
  )


FILE(
  GLOB_RECURSE
  file_test
  src/test*
  )

list(REMOVE_ITEM file_lib ${file_test})

add_library(wmlib_static STATIC ${file_lib})
add_library(wmlib_shared SHARED ${file_lib})

foreach(loop_var ${file_test})

  string(FIND ${loop_var} "test" pos REVERSE)
  string(SUBSTRING ${loop_var} ${pos} -1 name)

  add_executable(${name}.bin ${loop_var})
  target_link_libraries(${name}.bin "X11")
  target_link_libraries(${name}.bin wmlib_shared)
  target_link_libraries(${name}.bin ${SDL_LIBRARY})
endforeach(loop_var)





