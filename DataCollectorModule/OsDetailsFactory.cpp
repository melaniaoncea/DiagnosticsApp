#include "OsDetailsFactory.h"
#include "AbstractOsDetails.h"

#include<config.h>
#include<memory>

#ifdef  HAVE_WINDOWS_H
    #include "DataCollectorModule/Windows/WindowsOsDetails.h"
#endif

#ifdef HAVE_SYS_MOUNT_H
    #include "DataCollectorModule/Unix/UnixOsDetails.h"
#endif

shared_ptr<AbstractOsDetails> OsDetailsFactory::make()
{
#ifdef  HAVE_WINDOWS_H
    return make_shared<WindowsOsDetails>();
#endif

#ifdef HAVE_SYS_MOUNT_H
    return make_shared<UnixOsDetails>();
#endif
}
