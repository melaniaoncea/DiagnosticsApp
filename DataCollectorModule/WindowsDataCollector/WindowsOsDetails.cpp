#include "WindowsOsDetails.h"
#include "windows.h"

WindowsOsDetails::WindowsOsDetails()
{

}

void WindowsOsDetails::setOsDetails()
{
    m_osDetails.clear();

    // Os version can be retrieved using
    // a function like VerifyVersionInfoA. Might
    // not give the actual version for te Os
    // see https://docs.microsoft.com/en-us/windows/
    // win32/api/winbase/nf-winbase-verifyversioninfoa
    // GetProductInfo might be an alternative
    m_osDetails.insert({"osName", "Windows"});
    m_osDetails.insert({"osVersion", "10.0"});
}

std::map<std::string, std::string> WindowsOsDetails::getOsDetails() const
{
    return m_osDetails;
}
