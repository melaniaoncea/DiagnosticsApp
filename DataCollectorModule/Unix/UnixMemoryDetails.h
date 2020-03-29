#ifndef UNIXMEMORYDETAILS_H
#define UNIXMEMORYDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractMemoryDetails.h"


class UnixMemoryDetails : public AbstractMemoryDetails
{
public:
    UnixMemoryDetails();

    void setMemoryDetails() override;
    std::map<std::string, std::string> getMemoryDetails() const override;


private:
    std::map<std::string, std::string> m_memoryDetails;
};

#endif // UNIXMEMORYDETAILS_H
