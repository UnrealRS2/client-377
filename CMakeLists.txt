cmake_minimum_required(VERSION 3.18)
project(client_377)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Grab all .h/.cpp files in src/ recursively
file(GLOB_RECURSE SOURCES
        "src/*.cpp"
        "src/*.h")

# Create shared library
add_library(client_377 SHARED ${SOURCES})

target_compile_definitions(client_377 PRIVATE CLIENT_API_EXPORTS)
target_include_directories(client_377 PRIVATE "C:/libs/boost_1_89_0")