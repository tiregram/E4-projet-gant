
cmake_minimum_required (VERSION 2.6)
project (POO)
find_package(LibSSH REQUIRED)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set (PROJECT_SOURCE_DIR src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories ("${PROJECT_SOURCE_DIR}/")
include_directories (${LIBSSH_INCLUDE_DIRS})


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

add_library(launcher_shared SHARED ${file_lib})
add_library(launcher_static STATIC ${file_lib})

# mise en place des tests #####################################################
foreach(loop_var ${file_test})

  # get name
  string(FIND ${loop_var} "test" pos REVERSE)
  string(SUBSTRING ${loop_var} ${pos} -1 name)

  # add executable
  add_executable(${name}.bin ${loop_var})

  # link
  target_link_libraries(${name}.bin ${LIBSSH_LIBRARIES})
  target_link_libraries(${name}.bin launcher_shared)
endforeach(loop_var)



