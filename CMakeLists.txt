cmake_minimum_required(VERSION 3.13.4)
project(CHESS)

# use C++ standard version 17
set(CMAKE_CXX_STANDARD 17)
# produce non-optimized code with debug symbols
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "CMake build directory: ${CMAKE_BINARY_DIR}")
message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")

# Add all .hpp files under include/ directory
file(GLOB HEADERS_HPP "headers/*.hpp")
# Add all .cpp files under src/ directory
file(GLOB SOURCES_CPP "src/*.cpp")

set(SOURCES ${HEADERS_HPP} ${SOURCES_CPP})
message(STATUS "HEADER FILES: ${HEADERS_HPP}\n-- SOURCE FILES: ${SOURCES_CPP}\n-- ALL: ${SOURCES}")

add_executable(${PROJECT_NAME} src/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

set (SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics system window)
target_link_libraries(CHESS PRIVATE sfml-audio sfml-graphics sfml-system sfml-window)

target_sources(CHESS PUBLIC ${SOURCES})
target_include_directories(CHESS PUBLIC src)
target_include_directories(CHESS PUBLIC headers)
target_include_directories(CHESS PUBLIC libraries)

if(MSVC)
    target_compile_options(CHESS PRIVATE /Wall)
else()
    target_compile_options(CHESS PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
endif()
