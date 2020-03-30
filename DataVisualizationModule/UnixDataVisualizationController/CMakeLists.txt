cmake_minimum_required(VERSION 3.12)

# Create list of all source files from current module
set(UNIX_DATA_VISUALIZATION_CONTROLLER_MODULE
    UnixDataVisualizationController.h
    UnixDataVisualizationController.cpp
)

# make a static library
add_library(Unix_Data_Visualization_Library_static STATIC
    ${UNIX_DATA_VISUALIZATION_CONTROLLER_MODULE}
    )