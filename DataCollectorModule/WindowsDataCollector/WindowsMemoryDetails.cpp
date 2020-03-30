#include "WindowsMemoryDetails.h"

WindowsMemoryDetails::WindowsMemoryDetails()
{
}

void WindowsMemoryDetails::setMemoryDetails()
{
    m_memoryDetails.clear();

    m_memoryDetails.insert({"total", "16,235"});
    m_memoryDetails.insert({"used", "10,000"});
    m_memoryDetails.insert({"free", "6,235"});
}

std::map<std::string, std::string> WindowsMemoryDetails::getMemoryDetails() const
{
    return m_memoryDetails;
}
