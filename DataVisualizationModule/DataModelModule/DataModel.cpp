#include "DataModel.h"

#include<map>
#include<list>
#include<string>

std::map<std::string, std::string> DataModel::getSystemDetails(SystemDetailsType detailsType) const
{
    std::map<std::string, std::string> result;
    switch (detailsType) {
        case SystemDetailsType::OsDetails: result = getOsDetails();
            break;
        case SystemDetailsType::MachineDetails: result = getMachineDetails();
            break;
        case SystemDetailsType::MemoryDetails: result = getMemoryDetails();
    }
    return result;
}

std::list<std::string> DataModel::getCurrentRunningProcesses() const
{
    return m_currentRunningProcesses;
}

void DataModel::setSystemDetails(SystemDetailsType detailsType, std::map<std::string, std::string> systemDetails)
{
    switch (detailsType) {
        case SystemDetailsType::OsDetails: setOsDetails(systemDetails);
            break;
        case SystemDetailsType::MachineDetails: setMachineDetails(systemDetails);
            break;
        case SystemDetailsType::MemoryDetails: setMemoryDetails(systemDetails);
    }
}

void DataModel::setCurrentRunningProcesses(std::list<std::string> currentRunningProcesses)
{
    m_currentRunningProcesses.clear();
    m_currentRunningProcesses = currentRunningProcesses;
}

std::map<std::string, std::string> DataModel::getOsDetails() const
{
    return m_osDetails;
}

std::map<std::string, std::string> DataModel::getMachineDetails() const
{
    return  m_machineDetails;
}

std::map<std::string, std::string> DataModel::getMemoryDetails() const
{
    return m_memoryDetails;
}

void DataModel::setOsDetails(std::map<std::string, std::string> osDetails)
{
    m_osDetails.clear();
    m_osDetails = osDetails;
}

void DataModel::setMachineDetails(std::map<std::string, std::string> machineDetails)
{
    m_memoryDetails.clear();
    m_machineDetails = machineDetails;
}

void DataModel::setMemoryDetails(std::map<std::string, std::string> memoryDetails)
{
    m_memoryDetails.clear();
    m_memoryDetails = memoryDetails;
}
