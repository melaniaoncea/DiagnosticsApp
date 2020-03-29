cmake_minimum_required(VERSION 3.12)

# Create list of all source files from current module
set(MODULES_DATA_VISUALIZATION_MODULE
    DataVisualizationController.h
    DataVisualizationController.cpp
)

add_library(Data_Visualization_Library_static STATIC
    ${MODULES_DATA_VISUALIZATION_MODULE})

add_subdirectory(DataModelModule/)

target_link_libraries(Data_Visualization_Library_static Data_Model_Library_static)
