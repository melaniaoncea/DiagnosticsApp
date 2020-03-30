cmake_minimum_required(VERSION 3.10)

# Project name, version, language
project(DiagnosticsApp VERSION 1.0.0 LANGUAGES CXX)

# Include library for tests
#include(ctest)

# Useful CMake options
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run some settings automatically if needed
if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the output directory as an include directory
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

# Add the list of subdirectories
add_subdirectory(DataCollectorModule/)
add_subdirectory(DataVisualizationModule/)

set(SOURCES main.cpp)

# Create executable
set(MyProjectBin_src ${PROJECT_SOURCE_DIR}/main.cpp)
add_executable(DiagnosticsApp ${MyProjectBin_src})

# Link libraries the main app is dependent on
target_link_libraries(DiagnosticsApp PUBLIC
    Data_Collection_Library_static
    Data_Visualization_Library_static)
