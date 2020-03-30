cmake_minimum_required(VERSION 3.10)

# Create list of all source files from current module
set(MODULES_DATA_MODEL_MODULE
    AbstractDataModel.h
    AbstractDataModel.cpp
    DataModel.h
    DataModel.cpp
)

add_library(Data_Model_Library_static STATIC
    ${MODULES_DATA_MODEL_MODULE}
    )
target_link_libraries(Data_Model_Library_static)
