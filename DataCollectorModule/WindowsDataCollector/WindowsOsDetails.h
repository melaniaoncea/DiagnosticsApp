#ifndef WINDOWSOSDETAILS_H
#define WINDOWSOSDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractOsDetails.h"

class WindowsOsDetails : public AbstractOsDetails
{
public:
    WindowsOsDetails();

    void setOsDetails() override;
    std::map<std::string, std::string> getOsDetails() const override;


private:
    std::map<std::string, std::string> m_osDetails;
};

#endif // WINDOWSOSDETAILS_H
