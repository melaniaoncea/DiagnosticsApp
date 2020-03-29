#ifndef ABSTRACTOSDETAILSFACTORY_H
#define ABSTRACTOSDETAILSFACTORY_H

#include "AbstractOsDetails.h"

using namespace std;

class AbstractOsDetailsFactory
{
public:
    AbstractOsDetailsFactory() = default;
    virtual ~AbstractOsDetailsFactory() = default;

    virtual shared_ptr<AbstractOsDetails> make() = 0;
};

#endif // ABSTRACTOSDETAILSFACTORY_H
