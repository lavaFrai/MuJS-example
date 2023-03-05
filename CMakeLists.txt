cmake_minimum_required(VERSION 3.24)
project(MuJS)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")

include_directories(mujs)
include_directories(openssl/include)

file(GLOB_RECURSE mujs_lib RELATIVE ${CMAKE_SOURCE_DIR} "mujs/*.c")
file(GLOB_RECURSE mujs_headers RELATIVE ${CMAKE_SOURCE_DIR} "mujs/*.h")
set(SOURCE_FILES ${SOURCE_FILES} ${mujs_lib} ${mujs_headers} js_stdlib.h exec.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
add_executable(MuJS ${SOURCE_FILES} main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.js ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# add_executable(MuJS main.cpp)