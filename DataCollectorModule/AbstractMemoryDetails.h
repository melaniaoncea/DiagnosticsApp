#ifndef ABSTRACTMEMORYDETAILS_H
#define ABSTRACTMEMORYDETAILS_H

#include<map>
#include<string>

using namespace std;

class AbstractMemoryDetails
{
public:
    AbstractMemoryDetails() = default;
    virtual ~AbstractMemoryDetails() = default;

    virtual void setMemoryDetails() = 0;
    virtual const map<string, string>& getMemoryDetails() const = 0;
};

#endif // ABSTRACTMEMORYDETAILS_H
