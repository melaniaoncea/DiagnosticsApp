#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "AbstractDataModel.h"

#include<map>
#include<list>
#include<string>

using namespace std;

class DataModel : public AbstractDataModel
{
public:
    DataModel() = default;

    map<string, string> getSystemDetails(SystemDetailsType detailsType) const override;
    list<string> getCurrentRunningProcesses() const override;
    void setSystemDetails(SystemDetailsType detailsType, map<string, string> systemDetails) override;
    void setCurrentRunningProcesses(list<string> currentRunningProcesses) override;

private:
    map<string, string> getOsDetails() const;
    map<string, string> getMachineDetails() const;
    map<string, string> getMemoryDetails() const;

    void setOsDetails(map<string, string> osDetails);
    void setMachineDetails(map<string, string> machineDetails);
    void setMemoryDetails(map<string, string> memoryDetails);

private:
    map<string, string> m_osDetails;
    map<string, string> m_machineDetails;
    map<string, string> m_memoryDetails;
    list<string> m_currentRunningProcesses;

};

#endif // DATAMODEL_H
