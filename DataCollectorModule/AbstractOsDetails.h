#ifndef ABSTRACTOSDETAILS_H
#define ABSTRACTOSDETAILS_H

#include<map>
#include<string>

using namespace std;

class AbstractOsDetails
{
public:
    AbstractOsDetails() = default;
    virtual ~AbstractOsDetails() = default;

    virtual void setOsDetails() = 0;
    virtual map<string, string> getOsDetails() const = 0;
};

#endif // ABSTRACTOSDETAILS_H
