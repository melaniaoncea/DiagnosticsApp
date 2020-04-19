#include "ProcessesListFactory.h"
#include "AbstractProcessesList.h"

#ifdef _WIN32
#include "DataCollectorModule/WindowsDataCollector/WindowsProcessesList.h"
#endif

#ifdef __linux__
#include "DataCollectorModule/UnixDataCollector/UnixProcessesList.h"
#include<memory> // include this library for the Unix platform
#endif

shared_ptr<AbstractProcessesList> ProcessesListFactory::make()
{
#ifdef _WIN32
    return make_shared<WindowsProcessesList>();
#endif

#ifdef __linux__
    return make_shared<UnixProcessesList>();
#endif
}
