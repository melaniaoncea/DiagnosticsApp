#include "UnixMachineDetails.h"


UnixMachineDetails::UnixMachineDetails()
{
}

void UnixMachineDetails::setMachineDetails()
{

    m_machineDetails.insert({"name","LAPTOP-6GVNEVHV"});
    m_machineDetails.insert({"model","VivoBook_ASUSLaptop X430FN_S430FN"});
    m_machineDetails.insert({"manufacturer","AsusTek Computer Inc."});
}

const map<string, string>& UnixMachineDetails::getMachineDetails() const
{
    return m_machineDetails;
}

