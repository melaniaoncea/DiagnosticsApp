#ifndef ABSTRACTDATAMODEL_H
#define ABSTRACTDATAMODEL_H

#include<map>
#include<list>
#include<string>

enum SystemDetailsType {
    OsDetails = 1,
    MachineDetails = 2,
    MemoryDetails = 3
};

class AbstractDataModel
{
public:
    AbstractDataModel() = default;
    virtual ~AbstractDataModel() = default;

    virtual std::map<std::string, std::string> getSystemDetails(SystemDetailsType detailsType) const = 0;
    virtual std::list<std::string> getCurrentRunningProcesses() const = 0;
    virtual void setSystemDetails(SystemDetailsType detailsType, std::map<std::string, std::string> systemDetails) = 0;
    virtual void setCurrentRunningProcesses(std::list<std::string> currentRunningProcesses) = 0;

};

#endif // ABSTRACTDATAMODEL_H
