#ifndef ABSTRACTMACHINEDETAILS_H
#define ABSTRACTMACHINEDETAILS_H

#include<map>
#include<string>

using namespace std;

class AbstractMachineDetails
{
public:
    AbstractMachineDetails() = default;
    virtual ~AbstractMachineDetails() = default;

    virtual void setMachineDetails() = 0;
    virtual const map<string, string>& getMachineDetails() const = 0;
};

#endif // ABSTRACTMACHINEDETAILS_H
