cmake_minimum_required(VERSION 3.15)
project(prac_4)

set(CMAKE_CXX_STANDARD 17)


include_directories("inc/")

add_executable("${PROJECT_NAME}" prac_4.cpp)
file(COPY Device.txt DESTINATION /)