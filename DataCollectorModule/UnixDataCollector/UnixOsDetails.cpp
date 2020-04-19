#include "UnixOsDetails.h"
#include <sys/utsname.h>

UnixOsDetails::UnixOsDetails()
{
}

void UnixOsDetails::setOsDetails()
{
    m_osDetails.clear();

    // get os details from utsname.h
    struct utsname uts;
    uname(&uts);
    string osName = uts.sysname;
    string version = uts.version;

    // remove unnecessary data
    string osVersion = version.substr(4, 14);

    // populate map with formatted data
    m_osDetails.insert({"osName", osName});
    m_osDetails.insert({"osVersion", osVersion});
}

const map<string, string>& UnixOsDetails::getOsDetails() const
{
    return m_osDetails;
}

string UnixOsDetails::getOsDetails()
{

}
