#ifndef ABSTRACTPROCESSESLIST_H
#define ABSTRACTPROCESSESLIST_H

#include<list>
#include<string>

class AbstractProcessesList
{
public:
    AbstractProcessesList() = default;
    virtual ~AbstractProcessesList() = default;

    virtual void setProcessesList() = 0;
    virtual std::list<std::string> getRunningProcessesList() const = 0;
};

#endif // ABSTRACTPROCESSESLIST_H
