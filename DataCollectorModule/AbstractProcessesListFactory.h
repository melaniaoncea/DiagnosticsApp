#ifndef ABSTRACTPROCESSESLISTFACTORY_H
#define ABSTRACTPROCESSESLISTFACTORY_H

#include "AbstractProcessesList.h"

#include<memory>

using namespace std;

class AbstractProcessesListFactory
{
public:
    AbstractProcessesListFactory() = default;
    virtual ~AbstractProcessesListFactory() = default;

    virtual shared_ptr<AbstractProcessesList> make() = 0;
};

#endif // ABSTRACTPROCESSESLISTFACTORY_H
