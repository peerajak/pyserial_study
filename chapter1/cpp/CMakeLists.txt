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


add_executable(serial_port_write
    src/serial_port_write.cpp )
target_link_libraries(serial_port_write PRIVATE
"${SERIAL_LDFLAGS}")

add_executable(bidirectional
    src/bidirectional.cpp )
target_link_libraries(bidirectional PRIVATE
"${SERIAL_LDFLAGS}")



