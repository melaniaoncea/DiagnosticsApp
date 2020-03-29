#ifndef ABSTRACTMACHINEDETAILSFACTORY_H
#define ABSTRACTMACHINEDETAILSFACTORY_H

#include "AbstractMachineDetails.h"

using namespace std;

class AbstractMachineDetailsFactory
{
public:
    AbstractMachineDetailsFactory() = default;
    virtual ~AbstractMachineDetailsFactory() = default;

    virtual shared_ptr<AbstractMachineDetails> make() = 0;

};

#endif // ABSTRACTMACHINEDETAILSFACTORY_H
