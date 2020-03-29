cmake_minimum_required(VERSION 3.12)

# Create list of all source files from current module
set(MODULES_WINDOWS_DATA_COLLECTOR_MODULE
    WindowsMachineDetails.h
    WindowsMachineDetails.cpp
    WindowsMemoryDetails.h
    WindowsMemoryDetails.cpp
    WindowsOsDetails.h
    WindowsOsDetails.cpp
    WindowsProcessesList.h
    WindowsProcessesList.cpp
)

add_library(Windows_Data_Collection_Library_static STATIC
    ${MODULES_WINDOWS_DATA_COLLECTOR_MODULE}
    )
target_link_libraries(Windows_Data_Collection_Library_static)


