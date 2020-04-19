#ifndef ABSTRACTDATAMODEL_H
#define ABSTRACTDATAMODEL_H

#include<map>
#include<list>
#include<string>

using std::string;
using std::list;
using std::map;

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

    virtual const map<string, string>& getSystemDetails(SystemDetailsType detailsType) const = 0;
    virtual const list<string>& getCurrentRunningProcesses() const = 0;
    virtual void setSystemDetails(SystemDetailsType detailsType, const map<string, string>& systemDetails) = 0;
    virtual void setCurrentRunningProcesses(const list<string>& currentRunningProcesses) = 0;

};

#endif // ABSTRACTDATAMODEL_H
