#ifndef ABSTRACTDATAVISUALIZATIONCONTROLLERFACTORY_H
#define ABSTRACTDATAVISUALIZATIONCONTROLLERFACTORY_H

#include "AbstractDataVisualizationController.h"

#include<memory.h>

using namespace std;

class AbstractDataVisualizationControllerFactory
{
public:
    AbstractDataVisualizationControllerFactory() = default;
    virtual ~AbstractDataVisualizationControllerFactory() = default;

    virtual shared_ptr<AbstractDataVisualizationController> make() = 0;
};

#endif // ABSTRACTDATAVISUALIZATIONCONTROLLERFACTORY_H
