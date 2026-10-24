cmake_minimum_required(VERSION 3.16)
project(StatLab C)

# Set C standard (optional, but recommended)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find the SDL3 package
# 'CONFIG' tells CMake to look for the config file provided by SDL3-devel
# 'REQUIRED' stops the build if SDL3 is not found
find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

# Add your executable
add_executable(statlab src/main.c
    src/utils.c
    src/utils.h)

# Link SDL3 to your target
# SDL3::SDL3 is the official imported target that includes all necessary flags
target_link_libraries(statlab PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)