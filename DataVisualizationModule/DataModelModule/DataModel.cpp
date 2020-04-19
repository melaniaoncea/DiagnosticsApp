#include "DataModel.h"

#include<map>
#include<list>
#include<string>

const map<string, string>& DataModel::getSystemDetails(SystemDetailsType detailsType) const
{
    switch (detailsType) {
        case SystemDetailsType::OsDetails: return getOsDetails();
            break;
        case SystemDetailsType::MachineDetails: return getMachineDetails();
            break;
        case SystemDetailsType::MemoryDetails: return getMemoryDetails();
    }
}

const list<string>& DataModel::getCurrentRunningProcesses() const
{
    return m_currentRunningProcesses;
}

void DataModel::setSystemDetails(SystemDetailsType detailsType, const map<string, string>& systemDetails)
{
    switch (detailsType) {
        case SystemDetailsType::OsDetails: setOsDetails(systemDetails);
            break;
        case SystemDetailsType::MachineDetails: setMachineDetails(systemDetails);
            break;
        case SystemDetailsType::MemoryDetails: setMemoryDetails(systemDetails);
    }
}

void DataModel::setCurrentRunningProcesses(const list<string> &currentRunningProcesses)
{
    m_currentRunningProcesses.clear();
    m_currentRunningProcesses = currentRunningProcesses;
}

const map<string, string>& DataModel::getOsDetails() const
{
    return m_osDetails;
}

const map<string, string>& DataModel::getMachineDetails() const
{
    return  m_machineDetails;
}

const map<string, string>& DataModel::getMemoryDetails() const
{
    return m_memoryDetails;
}

void DataModel::setOsDetails(map<string, string> osDetails)
{
    m_osDetails.clear();
    m_osDetails = osDetails;
}

void DataModel::setMachineDetails(map<string, string> machineDetails)
{
    m_memoryDetails.clear();
    m_machineDetails = machineDetails;
}

void DataModel::setMemoryDetails(map<string, string> memoryDetails)
{
    m_memoryDetails.clear();
    m_memoryDetails = memoryDetails;
}
