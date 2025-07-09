cmake_minimum_required(VERSION 3.8)
project(libserial_script1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)



add_executable(serial_port_read
    src/serial_port_read.cpp )
target_link_libraries(serial_port_read PRIVATE
"${SERIAL_LDFLAGS}")

add_executable(0_arduino_to_raspberrypi
    src/0_arduino_to_raspberrypi.cpp )
target_link_libraries(0_arduino_to_raspberrypi PRIVATE
"${SERIAL_LDFLAGS}")


add_executable(serial_port_write
    src/serial_port_write.cpp )
target_link_libraries(serial_port_write PRIVATE
"${SERIAL_LDFLAGS}")


add_executable(1_raspberrypi_to_arduino
    src/1_raspberrypi_to_arduino.cpp )
target_link_libraries(1_raspberrypi_to_arduino PRIVATE
"${SERIAL_LDFLAGS}")

add_executable(2_bidirectional
    src/2_bidirectional.cpp )
target_link_libraries(2_bidirectional PRIVATE
"${SERIAL_LDFLAGS}")



