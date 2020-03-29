#ifndef MACHINEDETAILSFACTORY_H
#define MACHINEDETAILSFACTORY_H

#include "AbstractMachineDetailsFactory.h"
#include "AbstractMachineDetails.h"

#include<memory>

using namespace std;

class MachineDetailsFactory : public AbstractMachineDetailsFactory
{
public:
    MachineDetailsFactory() = default;

    shared_ptr<AbstractMachineDetails> make() override;

};

#endif // MACHINEDETAILSFACTORY_H
