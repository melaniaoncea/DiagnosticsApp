cmake_minimum_required(VERSION 3.5)

# Create list of all source files from current module
set(MODULES_DATA_COLLECTOR_MODULE
    AbstractMachineDetails.h
    AbstractMachineDetails.cpp
    AbstractMachineDetailsFactory.h
    AbstractMachineDetailsFactory.cpp
    AbstractMemoryDetails.h
    AbstractMemoryDetails.cpp
    AbstractMemoryDetailsFactory.h
    AbstractMemoryDetailsFactory.cpp
    AbstractOsDetails.h
    AbstractOsDetails.cpp
    AbstractOsDetailsFactory.h
    AbstractOsDetailsFactory.cpp
    AbstractProcessesList.h
    AbstractProcessesList.cpp
    AbstractProcessesListFactory.h
    AbstractProcessesListFactory.cpp
    MachineDetailsFactory.h
    MachineDetailsFactory.cpp
    MemoryDetailsFactory.h
    MemoryDetailsFactory.cpp
    OsDetailsFactory.h
    OsDetailsFactory.cpp
    ProcessesListFactory.h
    ProcessesListFactory.cpp  
)

add_library(Data_Collection_Library_static STATIC ${MODULES_DATA_COLLECTOR_MODULE})

# Add subdirectories
if(WIN32)
add_subdirectory(Windows/)
target_link_libraries(Data_Collection_Library_static Windows_Data_Collection_Library_static)
endif(WIN32)

if(UNIX AND NOT APPLE)
add_subdirectory(Unix/)
target_link_libraries(Data_Collection_Library_static Unix_Data_Collection_Library_static)
endif(UNIX AND NOT APPLE)
