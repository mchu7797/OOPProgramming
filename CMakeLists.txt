cmake_minimum_required(VERSION 3.27)
project(OOPProgramming)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(5-0 5th/5-0.cpp)
add_executable(5-1 5th/5-1.cpp)
add_executable(5-2 5th/5-2.cpp)
add_executable(5-3 5th/5-3.cpp)
add_executable(5-4 5th/5-4.cpp)
add_executable(5-5 5th/5-5.cpp)
add_executable(5-10 5th/5-10.cpp)

add_executable(q5-4 5th/q5-4.cpp)
add_executable(q5-5 5th/q5-4.cpp)
add_executable(q5-7 5th/q5-7.cpp)

add_executable(6-1 6th/6-1.cpp)
add_executable(6-2 6th/6-2.cpp)

add_executable(7-1 7th/7-1.cpp)
add_executable(7-2 7th/7-2.cpp)

add_executable(8-1 8th/8-1.cpp)

add_executable(9-1 9th/9-1.cpp)
add_executable(9-2 9th/9-2.cpp)
add_executable(9-3 9th/9-3.cpp)

add_executable(10-1 10th/10-1.cpp)
add_executable(10-2 10th/10-2.cpp)
add_executable(10-3 10th/10-3.cpp)

add_executable(12-1 12th/12-1.cpp)
add_executable(12-2 12th/12-2.cpp)
add_executable(12-3 12th/12-3.cpp)

add_executable(Playfair end-project/playfair.cpp)

configure_file(end-project/enc.txt enc.txt COPYONLY)
configure_file(12th/alphabet.txt alphabet.txt COPYONLY)
configure_file(12th/student-info.txt student-info.txt COPYONLY)