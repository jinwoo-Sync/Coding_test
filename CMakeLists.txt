cmake_minimum_required(VERSION 3.0.0)

project(GPS_TEST VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS -no-pie )
set(CMAKE_CXX_FLAGS "-fPIC -std=c++14 -fopenmp")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

##################################### INTERNAL #####################################
set(INCLUDE_LIST 
    ${INCLUDE_LIST}
    ./src
    ./include
)
file(GLOB EXECUTABLE_LIST
    ${EXECUTABLE_LIST} 
    ./src/*.cpp
    ./include/*.cpp
)
set(LINK_LIST 
    ${LINK_LIST}
)

##################################### EXTERNAL #####################################

include_directories(
    ${INCLUDE_LIST}
)

add_executable(
    ${PROJECT_NAME}
    ${EXECUTABLE_LIST}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${LINK_LIST}
)