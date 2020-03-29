#ifndef UNIXOSDETAILS_H
#define UNIXOSDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractOsDetails.h"

class UnixOsDetails : public AbstractOsDetails
{
public:
    UnixOsDetails();

    void setOsDetails() override;
    std::map<std::string, std::string> getOsDetails() const override;


private:
    std::map<std::string, std::string> m_osDetails;
};

#endif // UNIXOSDETAILS_H
