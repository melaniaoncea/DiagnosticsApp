cmake_minimum_required(VERSION 3.12)

# Create list of all source files from current module
set(UNIX_DATA_COLLECTOR_MODULE
    UnixMachineDetails.h
    UnixMachineDetails.cpp
    UnixMemoryDetails.h
    UnixMemoryDetails.cpp
    UnixOsDetails.h
    UnixOsDetails.cpp
    UnixProcessesList.h
    UnixProcessesList.cpp
)

# Pack current module into a static library
add_library(Unix_Data_Collection_Library_static STATIC
    ${UNIX_DATA_COLLECTOR_MODULE}
    )