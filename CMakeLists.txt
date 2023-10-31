cmake_minimum_required(VERSION 3.26)
project(OOPProgramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(5-0 5th/5-0.cpp)
add_executable(5-1 5th/5-1.cpp)
add_executable(5-2 5th/5-2.cpp)
add_executable(5-3 5th/5-3.cpp)
add_executable(5-4 5th/5-4.cpp)
add_executable(5-5 5th/5-5.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/12th/alphabet.txt ${CMAKE_CURRENT_BINARY_DIR}/alphabet.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/12th/student-info.txt ${CMAKE_CURRENT_BINARY_DIR}/student-info.txt COPYONLY)
add_executable(12-1 12th/12-1.cpp)
add_executable(12-2 12th/12-2.cpp)
add_executable(12-3 12th/12-3.cpp)