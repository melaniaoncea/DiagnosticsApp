#include "MemoryDetailsFactory.h"
#include "AbstractMemoryDetails.h"

#include<config.h>

#ifdef  HAVE_WINDOWS_H
    #include "DataCollectorModule/Windows/WindowsMemoryDetails.h"
#endif

#ifdef HAVE_SYS_MOUNT_H
    #include "DataCollectorModule/Unix/UnixMemoryDetails.h"
#endif

shared_ptr<AbstractMemoryDetails> MemoryDetailsFactory::make()
{
#ifdef  HAVE_WINDOWS_H
    return make_shared<WindowsMemoryDetails>();
#endif

#ifdef HAVE_SYS_MOUNT_H
    return make_shared<UnixMemoryDetails>();
#endif
}
