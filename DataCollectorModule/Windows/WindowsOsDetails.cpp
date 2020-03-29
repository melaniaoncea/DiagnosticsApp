#include "WindowsOsDetails.h"
#include "Windows.h"

WindowsOsDetails::WindowsOsDetails()
{

}

void WindowsOsDetails::setOsDetails()
{
    m_osDetails.clear();

    m_osDetails.insert({"osName", "Windows"});
    m_osDetails.insert({"osVersion", "10.0"});
//    OSVERSIONINFOEXA info;
//    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
//    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
//    DWORD dwTypeMask = 0x0000002 + 0x0000001 + 0x0000008;
//    DWORDLONG dwlConditionMask;

//    ULONGLONG conditionMask = 0;
//    DWORD typeMask = 0x0000002;
//    BYTE condition= 1;

//    dwlConditionMask = VerSetConditionMask(conditionMask, typeMask, condition);

//    VerifyVersionInfoA(&info, dwTypeMask, dwlConditionMask);
    //    m_OSVersion = info.dwMajorVersion + info.dwMinorVersion;
}

std::map<std::string, std::string> WindowsOsDetails::getOsDetails() const
{
    return m_osDetails;
}
