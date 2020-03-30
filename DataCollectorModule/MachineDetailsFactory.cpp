#include "MachineDetailsFactory.h"
#include "AbstractMachineDetails.h"

#ifdef  _WIN32
#include "DataCollectorModule/WindowsDataCollector/WindowsMachineDetails.h"
#endif

#ifdef __linux__ && !__ANDROID__
#include "DataCollectorModule/UnixDataCollector/UnixMachineDetails.h"
#include<memory>
#endif

shared_ptr<AbstractMachineDetails> MachineDetailsFactory::make()
{
#ifdef  _WIN32
    return make_shared<WindowsMachineDetails>();
#endif

#ifdef __linux__ && !__ANDROID__
    return make_shared<UnixMachineDetails>();
#endif
}
