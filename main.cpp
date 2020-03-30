#include "DataVisualizationModule/AbstractDataVisualizationControllerFactory.h"
#include "DataVisualizationModule/AbstractDataVisualizationController.h"
#include "DataVisualizationModule/DataVisualizationControllerFactory.h"

#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"
#include "DataVisualizationModule/DataModelModule/DataModel.h"

#include "DataCollectorModule/AbstractMachineDetailsFactory.h"
#include "DataCollectorModule/AbstractMachineDetails.h"
#include "DataCollectorModule/MachineDetailsFactory.h"

#include "DataCollectorModule/AbstractMemoryDetailsFactory.h"
#include "DataCollectorModule/AbstractMemoryDetails.h"
#include "DataCollectorModule/MemoryDetailsFactory.h"

#include "DataCollectorModule/AbstractOsDetailsFactory.h"
#include "DataCollectorModule/AbstractOsDetails.h"
#include "DataCollectorModule/OsDetailsFactory.h"

#include "DataCollectorModule/AbstractProcessesListFactory.h"
#include "DataCollectorModule/AbstractProcessesList.h"
#include "DataCollectorModule/ProcessesListFactory.h"

#include<iostream>
#include<map>
#include<list>
#include<string>
#include<memory>

using namespace std;

int main()
{
    // create the objects that collect the data
    AbstractMachineDetailsFactory* machineDetailsFactory = new MachineDetailsFactory();
    shared_ptr<AbstractMachineDetails> machineDetails = machineDetailsFactory->make();

    AbstractMemoryDetailsFactory* memoryDetailsFactory = new MemoryDetailsFactory();
    shared_ptr<AbstractMemoryDetails> memoryDetails = memoryDetailsFactory->make();

    AbstractOsDetailsFactory* osDetailsFactory = new OsDetailsFactory();
    shared_ptr<AbstractOsDetails> osDetails = osDetailsFactory->make();

    AbstractProcessesListFactory* processesListFactory = new ProcessesListFactory();
    shared_ptr<AbstractProcessesList> processesList = processesListFactory->make();

    // collect system information
    machineDetails->setMachineDetails();
    memoryDetails->setMemoryDetails();
    osDetails->setOsDetails();
    processesList->setProcessesList();

    // create data model
    AbstractDataModel* dataModel = new DataModel();

    // populate data model
    std::map<std::string, std::string> machineDetailsInfo = machineDetails->getMachineDetails();
    dataModel->setSystemDetails(SystemDetailsType::MachineDetails, machineDetailsInfo);

    std::map<std::string, std::string> memoryDetailsInfo = memoryDetails->getMemoryDetails();
    dataModel->setSystemDetails(SystemDetailsType::MemoryDetails, memoryDetailsInfo);

    std::map<std::string, std::string> osDetailsInfo = osDetails->getOsDetails();
    dataModel->setSystemDetails(SystemDetailsType::OsDetails, osDetailsInfo);

    std::list<std::string> processesListInfo = processesList->getRunningProcessesList();
    dataModel->setCurrentRunningProcesses(processesListInfo);

    // create display controller
    AbstractDataVisualizationControllerFactory* dataVisualizationControllerFactory = new DataVisualizationControllerFactory();
    shared_ptr<AbstractDataVisualizationController> dataVisualizationController = dataVisualizationControllerFactory->make();

    // display ui menu
    dataVisualizationController->initialize(*dataModel);
    dataVisualizationController->displayUiMenu();
    return 0;
}
