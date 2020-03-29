#ifndef ABSTRACTMEMORYDETAILS_H
#define ABSTRACTMEMORYDETAILS_H

#include<map>
#include<string>

class AbstractMemoryDetails
{
public:
    AbstractMemoryDetails() = default;
    virtual ~AbstractMemoryDetails() = default;

    virtual void setMemoryDetails() = 0;
    virtual std::map<std::string, std::string> getMemoryDetails() const = 0;
};

#endif // ABSTRACTMEMORYDETAILS_H
