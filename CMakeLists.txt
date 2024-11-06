cmake_minimum_required(VERSION 3.25)
project(studFailuApdorojimas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(Include)
file(GLOB SOURCES "src/*.cpp")
add_executable(studFailuApdorojimas ${SOURCES})