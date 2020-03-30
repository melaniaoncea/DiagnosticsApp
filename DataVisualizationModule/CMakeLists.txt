cmake_minimum_required(VERSION 3.12)

# Create list of all source files from current module
set(DATA_VISUALIZATION_MODULE
    AbstractDataVisualizationController.h
    AbstractDataVisualizationController.cpp
    AbstractDataVisualizationControllerFactory.h
    AbstractDataVisualizationControllerFactory.cpp
    DataVisualizationControllerFactory.h
    DataVisualizationControllerFactory.cpp
)

# Pack module in a static library
add_library(Data_Visualization_Library_static STATIC
    ${DATA_VISUALIZATION_MODULE})

# Add subdirectories and link with needed libraries
add_subdirectory(DataModelModule/)

target_link_libraries(Data_Visualization_Library_static Data_Model_Library_static)

# Add platform specific libraries
if(WIN32)
add_subdirectory(WindowsDataVisualizationController/)
target_link_libraries(Data_Visualization_Library_static Windows_Data_Visualization_Library_static)
endif(WIN32)

if(UNIX AND NOT APPLE)
add_subdirectory(UnixDataVisualizationController/)
target_link_libraries(Data_Visualization_Library_static Unix_Data_Visualization_Library_static)
endif(UNIX AND NOT APPLE)
