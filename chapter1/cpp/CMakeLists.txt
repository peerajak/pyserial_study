cmake_minimum_required(VERSION 3.8)
project(libserial_script1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)



add_executable(libserial_script1
    src/libserial_script1.cpp )



#target_include_directories(libserial_script1 PUBLIC
#"${SERIAL_INCLUDE_DIRS}"
#)

target_link_libraries(libserial_script1 PRIVATE
"${SERIAL_LDFLAGS}")



