#ifndef UNIXMACHINEDETAILS_H
#define UNIXMACHINEDETAILS_H

#include "DataCollectorModule/AbstractMachineDetails.h"

#include<string>
#include<map>

using namespace std;

class UnixMachineDetails : public AbstractMachineDetails
{
public:
    UnixMachineDetails();

    void setMachineDetails() override;
    map<string, string>getMachineDetails() const override;

private:
    map<string, string> m_machineDetails;


};

#endif // UNIXMACHINEDETAILS_H
