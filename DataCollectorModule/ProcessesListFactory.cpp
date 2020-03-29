#include "ProcessesListFactory.h"
#include "AbstractProcessesList.h"

#include<config.h>
#include<memory> // include this library for the Unix platform

#ifdef  HAVE_WINDOWS_H
    #include "DataCollectorModule/Windows/WindowsProcessesList.h"
#endif

#ifdef HAVE_SYS_MOUNT_H
    #include "DataCollectorModule/Unix/UnixProcessesList.h"
#endif

shared_ptr<AbstractProcessesList> ProcessesListFactory::make()
{
#ifdef  HAVE_WINDOWS_H
    return make_shared<WindowsProcessesList>();
#endif

#ifdef HAVE_SYS_MOUNT_H
    return make_shared<UnixProcessesList>();
#endif
}
