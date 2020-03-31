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

    // gathers Os details and save them in the map structure
    void setOsDetails() override;

    // provides osDetails data
    map<string, string> getOsDetails() const override;

private:
    std::string getOsDetails();


private:
    map<string, string> m_osDetails;
};

#endif // UNIXOSDETAILS_H
