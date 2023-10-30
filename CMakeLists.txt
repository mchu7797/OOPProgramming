cmake_minimum_required(VERSION 3.26)
project(OOPProgramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(12-1 12th/12-1.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/12th/student-info.txt ${CMAKE_CURRENT_BINARY_DIR}/student-info.txt COPYONLY)
add_executable(12-2 12th/12-2.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/12th/alphabet.txt ${CMAKE_CURRENT_BINARY_DIR}/alphabet.txt COPYONLY)
add_executable(12-3 12th/12-3.cpp)