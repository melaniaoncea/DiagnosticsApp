#include "WindowsMachineDetails.h"

// header that helps in obtaining info from the system
// could also be written <windows.h>, some compilers take
// one form over the other
#include <Windows.h>

WindowsMachineDetails::WindowsMachineDetails()
{
}

void WindowsMachineDetails::setMachineDetails()
{
    // get computer name in Windows
    char buffer[256] = "";
    uint32_t size = sizeof(buffer);
    if (GetComputerName(buffer, &size))
    {
        m_machineDetails.insert({"name", to_string(buffer)});
    }

    // for these following details I saw tha working with WMI could be an option
    // as well as writing your own code
    m_machineDetails.insert({"model","VivoBook_ASUSLaptop X430FN_S430FN"});
    m_machineDetails.insert({"manufacturer","AsusTek Computer Inc."});
}

std::map<std::string, std::string> WindowsMachineDetails::getMachineDetails() const
{
    return m_machineDetails;
}
