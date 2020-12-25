cmake_minimum_required(VERSION 3.10)

project(Simulator)

set(SIM_EXTERNAL_RPATH "" CACHE PATH
    "Path to external library directories to include in ELF"
)
set(SIM_RPATH "$ORIGIN/../lib:${SIM_EXTERNAL_RPATH}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(sim)
