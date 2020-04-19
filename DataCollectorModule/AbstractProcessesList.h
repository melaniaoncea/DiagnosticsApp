#ifndef ABSTRACTPROCESSESLIST_H
#define ABSTRACTPROCESSESLIST_H

#include<list>
#include<string>

using namespace std;

class AbstractProcessesList
{
public:
    AbstractProcessesList() = default;
    virtual ~AbstractProcessesList() = default;

    virtual void setProcessesList() = 0;
    virtual const list<string>& getRunningProcessesList() const = 0;
};

#endif // ABSTRACTPROCESSESLIST_H
