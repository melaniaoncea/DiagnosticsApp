#ifndef UNIXMACHINEDETAILS_H
#define UNIXMACHINEDETAILS_H

#include<string>
#include<map>

#include "DataCollectorModule/AbstractMachineDetails.h"

class UnixMachineDetails : public AbstractMachineDetails
{
public:
    UnixMachineDetails();

    void setMachineDetails() override;
    std::map<std::string, std::string>getMachineDetails() const override;

private:
    std::map<std::string, std::string> m_machineDetails;


};

#endif // UNIXMACHINEDETAILS_H
