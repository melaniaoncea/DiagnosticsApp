#include "UnixMemoryDetails.h"

#include <sys/sysinfo.h>
#include <linux/types.h>

UnixMemoryDetails::UnixMemoryDetails()
{
}

void UnixMemoryDetails::setMemoryDetails()
{
    // empty the structure before using it
    m_memoryDetails.clear();

    // collect memory data
    struct sysinfo systemInformation;
    sysinfo(&systemInformation);

    const unsigned long gigabyte = 1024 * 1024 *1024;

    unsigned long totalMemory = systemInformation.totalram / gigabyte;
    unsigned long freeMemory = systemInformation.freeram / gigabyte;
    unsigned long usedMemory = (totalMemory - freeMemory);

    // save data into map
    m_memoryDetails.insert({"total", to_string(totalMemory)});
    m_memoryDetails.insert({"used", to_string(usedMemory)});
    m_memoryDetails.insert({"free", to_string(freeMemory)});
}

map<string, string> UnixMemoryDetails::getMemoryDetails() const
{
    return m_memoryDetails;
}
