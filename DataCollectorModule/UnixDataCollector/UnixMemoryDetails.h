#ifndef UNIXMEMORYDETAILS_H
#define UNIXMEMORYDETAILS_H

#include "DataCollectorModule/AbstractMemoryDetails.h"

#include<map>
#include<string>

using namespace std;

class UnixMemoryDetails : public AbstractMemoryDetails
{
public:
    UnixMemoryDetails();

    // gathers memory details and save them in the map structure
    void setMemoryDetails() override;

    // provides memory details
    const map<string, string>& getMemoryDetails() const override;


private:
    map<string, string> m_memoryDetails;
};

#endif // UNIXMEMORYDETAILS_H
