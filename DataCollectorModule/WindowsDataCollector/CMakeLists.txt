cmake_minimum_required(VERSION 3.10)

# Create list of all source files from current module
set(WINDOWS_DATA_COLLECTOR_MODULE
    WindowsMachineDetails.h
    WindowsMachineDetails.cpp
    WindowsMemoryDetails.h
    WindowsMemoryDetails.cpp
    WindowsOsDetails.h
    WindowsOsDetails.cpp
    WindowsProcessesList.h
    WindowsProcessesList.cpp
)

# Pack module into a static library
add_library(Windows_Data_Collection_Library_static STATIC
    ${WINDOWS_DATA_COLLECTOR_MODULE}
    )



