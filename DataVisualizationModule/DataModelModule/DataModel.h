#ifndef DATAMODEL_H
#define DATAMODEL_H

#include<map>
#include<list>
#include<string>

#include "AbstractDataModel.h"

class DataModel : public AbstractDataModel
{
public:
    DataModel() = default;

    std::map<std::string, std::string> getSystemDetails(SystemDetailsType detailsType) const override;
    std::list<std::string> getCurrentRunningProcesses() const override;
    void setSystemDetails(SystemDetailsType detailsType, std::map<std::string, std::string> systemDetails) override;
    void setCurrentRunningProcesses(std::list<std::string> currentRunningProcesses) override;

private:
    std::map<std::string, std::string> getOsDetails() const;
    std::map<std::string, std::string> getMachineDetails() const;
    std::map<std::string, std::string> getMemoryDetails() const;

    void setOsDetails(std::map<std::string, std::string> osDetails);
    void setMachineDetails(std::map<std::string, std::string> machineDetails);
    void setMemoryDetails(std::map<std::string, std::string> memoryDetails);

private:
    std::map<std::string, std::string> m_osDetails;
    std::map<std::string, std::string> m_machineDetails;
    std::map<std::string, std::string> m_memoryDetails;
    std::list<std::string> m_currentRunningProcesses;

};

#endif // DATAMODEL_H
