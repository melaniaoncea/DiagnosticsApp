cmake_minimum_required(VERSION 3.12)

project(DiagnosticsApp VERSION 1.0.0 LANGUAGES CXX)

#include(ctest)

include(CheckIncludeFileCXX)

# Useful CMake options
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

# Check for platform specific libraries for OS communication
check_include_file_cxx (Windows.h HAVE_WINDOWS_H)
check_include_file_cxx (sys/utsname.h HAVE_UTSNAME_H)

# Generate config file
configure_file (
    "${PROJECT_SOURCE_DIR}/init/config.h"
    "${PROJECT_BINARY_DIR}/config.h"
)

# Specify the output directory as an include directory
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

# Add the list of subdirectories
add_subdirectory(DataCollectorModule/)
add_subdirectory(DataVisualizationModule/)

set(SOURCES main.cpp)

# Create executable with all necessary source files
set(MyProjectBin_src ${PROJECT_SOURCE_DIR}/main.cpp)
add_executable(DiagnosticsApp ${MyProjectBin_src})

# Find the libraries
#find_library(DATA_COLLECTOR_LIB DataCollectorModule Data_Collection_Library_static NO_DEFAULT_PATH )
#find_library(DATA_MODEL_LIB DataModelModule Data_Model_Library_static NO_DEFAULT_PATH)
#find_library(DATA_VISUALIZATION_LIB DataVisualizationModule Data_Visualization_Library_static NO_DEFAULT_PATH)

target_link_libraries(DiagnosticsApp PUBLIC
    Data_Collection_Library_static
    Data_Visualization_Library_static)
