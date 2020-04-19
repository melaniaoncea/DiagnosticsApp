#ifndef WINDOWSMACHINEDETAILS_H
#define WINDOWSMACHINEDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractMachineDetails.h"

using std::map;
using std::string;

class WindowsMachineDetails : public AbstractMachineDetails
{
public:
    WindowsMachineDetails();

    void setMachineDetails() override;
    const map<string, string>& getMachineDetails() const override;

private:
    map<string, string> m_machineDetails;
};

#endif // WINDOWSMACHINEDETAILS_H
