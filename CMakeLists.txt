cmake_minimum_required(VERSION 3.13.4)
project(chess)

# C++ standard version 17
set(CMAKE_CXX_STANDARD 17)

# Build configuration
set(CMAKE_BUILD_TYPE DEBUG)

# Cmake directories
message(STATUS "CMake build directory: ${CMAKE_BINARY_DIR}")
message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")

# Add all .hpp files under include/ directory
file(GLOB HEADERS_HPP "headers/*.hpp")
# Add all .cpp files under src/ directory
file(GLOB SOURCES_CPP "src/*.cpp")

# Displaying the source code
set(SOURCES ${HEADERS_HPP} ${SOURCES_CPP})
message(STATUS "HEADER FILES: ${HEADERS_HPP}\n-- SOURCE FILES: ${SOURCES_CPP}\n-- ALL: ${SOURCES}")

# Setting executable file and configuring the path for the binary output
add_executable(${PROJECT_NAME} src/main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

# SFML configuration
set(SFML_DIR "libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS audio graphics system window)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio sfml-graphics sfml-system sfml-window)

# Included directories 
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC headers)
target_include_directories(${PROJECT_NAME} PUBLIC libraries/SFML-2.5.1/include/SFML)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /Wall)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
endif()
