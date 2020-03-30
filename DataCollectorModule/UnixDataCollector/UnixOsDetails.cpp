#include "UnixOsDetails.h"

UnixOsDetails::UnixOsDetails()
{
}

void UnixOsDetails::setOsDetails()
{
    m_osDetails.clear();

    m_osDetails.insert({"osName", "Ubuntu"});
    m_osDetails.insert({"osVersion", "16.04"});
}

map<string, string> UnixOsDetails::getOsDetails() const
{
    return m_osDetails;
}
