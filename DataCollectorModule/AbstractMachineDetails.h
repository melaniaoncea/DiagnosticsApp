#ifndef ABSTRACTMACHINEDETAILS_H
#define ABSTRACTMACHINEDETAILS_H

#include<map>
#include<string>

class AbstractMachineDetails
{
public:
    AbstractMachineDetails() = default;
    virtual ~AbstractMachineDetails() = default;

    virtual void setMachineDetails() = 0;
    virtual std::map<std::string, std::string>getMachineDetails() const = 0;
};

#endif // ABSTRACTMACHINEDETAILS_H
