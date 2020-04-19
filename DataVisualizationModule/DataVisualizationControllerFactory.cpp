#include "DataVisualizationControllerFactory.h"

#ifdef _WIN32
#include "WindowsDataVisualizationController/WindowsDataVisualizationController.h"
#endif

#ifdef __linux__
#include "UnixDataVisualizationController/UnixDataVisualizationController.h"
#endif

DataVisualizationControllerFactory::DataVisualizationControllerFactory()
{
}

shared_ptr<AbstractDataVisualizationController> DataVisualizationControllerFactory::make()
{
#ifdef _WIN32
    return make_shared<WindowsDataVisualizationController>();
#endif
#ifdef __linux__
    return make_shared<UnixDataVisualizationController>();
#endif

}
