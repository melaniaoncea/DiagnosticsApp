#ifndef ABSTRACTDATAMODEL_H
#define ABSTRACTDATAMODEL_H

#include<map>
#include<list>
#include<string>

using namespace std;

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

    virtual map<string, string> getSystemDetails(SystemDetailsType detailsType) const = 0;
    virtual list<string> getCurrentRunningProcesses() const = 0;
    virtual void setSystemDetails(SystemDetailsType detailsType, map<string, string> systemDetails) = 0;
    virtual void setCurrentRunningProcesses(list<string> currentRunningProcesses) = 0;

};

#endif // ABSTRACTDATAMODEL_H
