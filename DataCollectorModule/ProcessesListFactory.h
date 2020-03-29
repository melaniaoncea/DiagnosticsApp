#ifndef PROCESSESLISTFACTORY_H
#define PROCESSESLISTFACTORY_H

#include "AbstractProcessesListFactory.h"
#include "AbstractProcessesList.h"

using namespace std;

class ProcessesListFactory : public AbstractProcessesListFactory
{
public:
    ProcessesListFactory() = default;

    shared_ptr<AbstractProcessesList> make() override;
};

#endif // PROCESSESLISTFACTORY_H
