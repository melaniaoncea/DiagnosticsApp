cmake_minimum_required(VERSION 3.5)

# Create list of all source files from current module
set(MODULES_UNIX_DATA_COLLECTOR_MODULE
    UnixMachineDetails.h
    UnixMachineDetails.cpp
    UnixMemoryDetails.h
    UnixMemoryDetails.cpp
    UnixOsDetails.h
    UnixOsDetails.cpp
    UnixProcessesList.h
    UnixProcessesList.cpp
)

add_library(Unix_Data_Collection_Library_static STATIC
    ${MODULES_UNIX_DATA_COLLECTOR_MODULE}
    )