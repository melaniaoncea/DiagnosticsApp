#include "UnixMemoryDetails.h"

UnixMemoryDetails::UnixMemoryDetails()
{
}

void UnixMemoryDetails::setMemoryDetails()
{
    m_memoryDetails.clear();

    m_memoryDetails.insert({"total", "16,235"});
    m_memoryDetails.insert({"used", "10,000"});
    m_memoryDetails.insert({"free", "6,235"});
}

map<string, string> UnixMemoryDetails::getMemoryDetails() const
{
    return m_memoryDetails;
}
