#include "MachineDetailsFactory.h"
#include "AbstractMachineDetails.h"

#include<config.h>

#ifdef  HAVE_WINDOWS_H
    #include "DataCollectorModule/Windows/WindowsMachineDetails.h"
#endif

#ifdef HAVE_SYS_MOUNT_H
    #include "DataCollectorModule/Unix/UnixMachineDetails.h"
#endif

shared_ptr<AbstractMachineDetails> MachineDetailsFactory::make()
{
#ifdef  HAVE_WINDOWS_H
    return make_shared<WindowsMachineDetails>();
#endif

#ifdef HAVE_SYS_MOUNT_H
    return make_shared<UnixMachineDetails>();
#endif
}
