#ifndef ABSTRACTMEMORYDETAILSFACTORY_H
#define ABSTRACTMEMORYDETAILSFACTORY_H

#include "AbstractMemoryDetails.h"

#include<memory>

using namespace std;

class AbstractMemoryDetailsFactory
{
public:
    AbstractMemoryDetailsFactory() = default;
    virtual ~AbstractMemoryDetailsFactory() = default;

    virtual shared_ptr<AbstractMemoryDetails> make() = 0;

};

#endif // ABSTRACTMEMORYDETAILSFACTORY_H
