#ifndef UNIXOSDETAILS_H
#define UNIXOSDETAILS_H

#include "DataCollectorModule/AbstractOsDetails.h"

#include<map>
#include<string>

using namespace std;

class UnixOsDetails : public AbstractOsDetails
{
public:
    UnixOsDetails();

    void setOsDetails() override;
    map<string, string> getOsDetails() const override;


private:
    map<string, string> m_osDetails;
};

#endif // UNIXOSDETAILS_H
