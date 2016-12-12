cmake_minimum_required(VERSION 2.8)



#project(test CXX)
# set(CMAKE_CXX_COMPILER /usr/bin/g++)
#FILE(
#  GLOB_RECURSE
#  src_compo_test
#  src/compo/*
#  )

# add_executable(compoTest ${src_compo_test} test/compo.cpp)

set(ARDUINO_SDK_d /usr/share/arduino)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(BOARD_SUB 8MHzatmega328)
set(nano.build.mcu  "atmega328p")
set( nano.upload.maximum_size 30720)
set( nano.upload.maximum_data_size 2048) 
set( nano.upload.speed 57600)
set( nano.bootloader.low_fuses 0xFF)
set( nano.bootloader.high_fuses 0xDE)
set( nano.bootloader.extended_fuses 0x05)
set( nano.bootloader.file optiboot/optiboot_atmega328.hex)
set (CMAKE_CXX_STANDARD 11)

#set(ARDUINO_PLATFORMS avr)

project(Gant C CXX)

message("________")
print_board_list()
message("________")
print_programmer_list()
message("________")

include_directories(lib/avr-stl/include/)

link_directories(${ARDUINO_SDK_d}/libraries)
link_directories(${ARDUINO_SDK}/libraries)
link_directories(${ARDUINO_SDK_d}/hardware/arduino/avr/cores/arduino/)

FILE(
  GLOB_RECURSE
  srcGANT
  src/*
  )

generate_arduino_firmware(Gant
  SRCS  ${srcGANT}
  PORT /dev/ttyUSB0
  BOARD nano)

