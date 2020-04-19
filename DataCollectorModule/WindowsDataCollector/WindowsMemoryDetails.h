#ifndef WINDOWSMEMORYDETAILS_H
#define WINDOWSMEMORYDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractMemoryDetails.h"

using std::string;
using std::map;

class WindowsMemoryDetails : public AbstractMemoryDetails
{
public:
    WindowsMemoryDetails();

    void setMemoryDetails() override;
    const map<string, string>& getMemoryDetails() const override;


private:
    map<string, string> m_memoryDetails;
};

#endif // WINDOWSMEMORYDETAILS_H
