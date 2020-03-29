#ifndef ABSTRACTOSDETAILS_H
#define ABSTRACTOSDETAILS_H

#include<map>
#include<string>

class AbstractOsDetails
{
public:
    AbstractOsDetails() = default;
    virtual ~AbstractOsDetails() = default;

    virtual void setOsDetails() = 0;
    virtual std::map<std::string, std::string> getOsDetails() const = 0;
};

#endif // ABSTRACTOSDETAILS_H
