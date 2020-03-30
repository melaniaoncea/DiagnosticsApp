#ifndef DATAVISUALIZATIONCONTROLLERFACTORY_H
#define DATAVISUALIZATIONCONTROLLERFACTORY_H

#include "AbstractDataVisualizationControllerFactory.h"
#include "AbstractDataVisualizationController.h"

#include<memory.h>

using namespace std;

class DataVisualizationControllerFactory : public AbstractDataVisualizationControllerFactory
{
public:
    DataVisualizationControllerFactory();

    shared_ptr<AbstractDataVisualizationController> make() override;
};

#endif // DATAVISUALIZATIONCONTROLLERFACTORY_H
