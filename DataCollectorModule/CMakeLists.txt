cmake_minimum_required(VERSION 3.10)

# Create list of all source files from current module
set(DATA_COLLECTOR_MODULE
    AbstractMachineDetails.h
    AbstractMachineDetailsFactory.h
    AbstractMemoryDetails.h
    AbstractMemoryDetailsFactory.h
    AbstractOsDetails.h
    AbstractOsDetailsFactory.h
    AbstractProcessesList.h
    AbstractProcessesListFactory.h
    MachineDetailsFactory.h
    MachineDetailsFactory.cpp
    MemoryDetailsFactory.h
    MemoryDetailsFactory.cpp
    OsDetailsFactory.h
    OsDetailsFactory.cpp
    ProcessesListFactory.h
    ProcessesListFactory.cpp  
)

# Pack them into a static library
add_library(Data_Collection_Library_static STATIC ${DATA_COLLECTOR_MODULE})

# Add subdirectories and link platform specific libraries that current module is dependent on
if(WIN32)
add_subdirectory(WindowsDataCollector/)
target_link_libraries(Data_Collection_Library_static Windows_Data_Collection_Library_static)
endif(WIN32)

if(UNIX AND NOT APPLE)
add_subdirectory(UnixDataCollector/)
target_link_libraries(Data_Collection_Library_static Unix_Data_Collection_Library_static)
endif(UNIX AND NOT APPLE)
