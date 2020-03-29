#ifndef MEMORYDETAILSFACTORY_H
#define MEMORYDETAILSFACTORY_H

#include "AbstractMemoryDetailsFactory.h"
#include "AbstractMemoryDetails.h"

#include<memory>

using namespace std;

class MemoryDetailsFactory : public AbstractMemoryDetailsFactory
{
public:
    MemoryDetailsFactory() = default;

    shared_ptr<AbstractMemoryDetails> make() override;

};

#endif // MEMORYDETAILSFACTORY_H
