#include "OsDetailsFactory.h"
#include "AbstractOsDetails.h"

#ifdef _WIN32
#include "DataCollectorModule/WindowsDataCollector/WindowsOsDetails.h"
#endif

#ifdef __linux__
#include "DataCollectorModule/UnixDataCollector/UnixOsDetails.h"
#include<memory> // needed for recognizing shared_ptr in Unix
#endif

shared_ptr<AbstractOsDetails> OsDetailsFactory::make()
{
#ifdef  _WIN32
    return make_shared<WindowsOsDetails>();
#endif

#ifdef __linux__
    return make_shared<UnixOsDetails>();
#endif
}
