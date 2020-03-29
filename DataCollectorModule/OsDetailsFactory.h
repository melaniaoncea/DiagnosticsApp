#ifndef OSDETAILSFACTORY_H
#define OSDETAILSFACTORY_H

#include "AbstractOsDetailsFactory.h"
#include "AbstractOsDetails.h"

using namespace std;

class OsDetailsFactory : public AbstractOsDetailsFactory
{
public:
    OsDetailsFactory() = default;

    shared_ptr<AbstractOsDetails> make() override;
};

#endif // OSDETAILSFACTORY_H
