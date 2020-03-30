#include "WindowsMachineDetails.h"

WindowsMachineDetails::WindowsMachineDetails()
{
}

void WindowsMachineDetails::setMachineDetails()
{
    m_machineDetails.insert({"name","LAPTOP-6GVNEVHV"});
    m_machineDetails.insert({"model","VivoBook_ASUSLaptop X430FN_S430FN"});
    m_machineDetails.insert({"manufacturer","AsusTek Computer Inc."});
}

std::map<std::string, std::string> WindowsMachineDetails::getMachineDetails() const
{
    return m_machineDetails;
}
