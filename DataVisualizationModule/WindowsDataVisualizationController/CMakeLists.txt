cmake_minimum_required(VERSION 3.10)

# Create list of all source files from current module
set(WINDOWS_DATA_VISUALIZATION_MODULE
    WindowsDataVisualizationController.h
    WindowsDataVisualizationController.cpp
)

# pack module in a static library
add_library(Windows_Data_Visualization_Library_static STATIC
    ${WINDOWS_DATA_VISUALIZATION_MODULE}
    )


