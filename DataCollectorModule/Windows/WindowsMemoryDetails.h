#ifndef WINDOWSMEMORYDETAILS_H
#define WINDOWSMEMORYDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractMemoryDetails.h"

class WindowsMemoryDetails : public AbstractMemoryDetails
{
public:
    WindowsMemoryDetails();

    void setMemoryDetails() override;
    std::map<std::string, std::string> getMemoryDetails() const override;


private:
    std::map<std::string, std::string> m_memoryDetails;
};

#endif // WINDOWSMEMORYDETAILS_H
