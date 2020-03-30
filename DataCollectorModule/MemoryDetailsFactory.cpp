#include "MemoryDetailsFactory.h"
#include "AbstractMemoryDetails.h"

#ifdef _WIN32
#include "DataCollectorModule/WindowsDataCollector/WindowsMemoryDetails.h"
#endif

#ifdef __linux__ && !__ANDROID__
#include "DataCollectorModule/UnixDataCollector/UnixMemoryDetails.h"
#include<memory>
#endif

shared_ptr<AbstractMemoryDetails> MemoryDetailsFactory::make()
{
#ifdef _WIN32
    return make_shared<WindowsMemoryDetails>();
#endif

#ifdef __linux__ && !__ANDROID__
    return make_shared<UnixMemoryDetails>();
#endif
}
