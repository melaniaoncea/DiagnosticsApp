#ifndef WINDOWSOSDETAILS_H
#define WINDOWSOSDETAILS_H

#include<map>
#include<string>

#include "DataCollectorModule/AbstractOsDetails.h"

using std::map;
using std::string;

class WindowsOsDetails : public AbstractOsDetails
{
public:
    WindowsOsDetails();

    void setOsDetails() override;
    const map<string, string>& getOsDetails() const override;


private:
    map<string, string> m_osDetails;
};

#endif // WINDOWSOSDETAILS_H
