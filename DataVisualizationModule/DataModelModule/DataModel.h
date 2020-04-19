#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "AbstractDataModel.h"

#include<map>
#include<list>
#include<string>

using std::string;
using std::list;
using std::map;

class DataModel : public AbstractDataModel
{
public:
    DataModel() = default;

    const map<string, string>& getSystemDetails(SystemDetailsType detailsType) const override;
    const list<std::string>& getCurrentRunningProcesses() const override;
    void setSystemDetails(SystemDetailsType detailsType, const map<string, string>& systemDetails) override;
    void setCurrentRunningProcesses(const list<string>& currentRunningProcesses) override;

private:
    const map<std::string, std::string>& getOsDetails() const;
    const map<string, string>& getMachineDetails() const;
    const map<string, string>& getMemoryDetails() const;

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
