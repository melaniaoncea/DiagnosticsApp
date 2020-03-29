#ifndef WINDOWSMACHINEDETAILS_H
#define WINDOWSMACHINEDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractMachineDetails.h"

class WindowsMachineDetails : public AbstractMachineDetails
{
public:
    WindowsMachineDetails();

    void setMachineDetails() override;
    std::map<std::string, std::string>getMachineDetails() const override;

private:
    std::map<std::string, std::string> m_machineDetails;
};

#endif // WINDOWSMACHINEDETAILS_H
