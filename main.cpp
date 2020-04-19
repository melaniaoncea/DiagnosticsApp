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

using std::map;
using std::string;

int main()
{
    // create the objects that collect the data
    unique_ptr<AbstractMachineDetailsFactory> machineDetailsFactory = make_unique<MachineDetailsFactory>();
    shared_ptr<AbstractMachineDetails> machineDetails = machineDetailsFactory->make();

    unique_ptr<AbstractMemoryDetailsFactory> memoryDetailsFactory = make_unique<MemoryDetailsFactory>();
    shared_ptr<AbstractMemoryDetails> memoryDetails = memoryDetailsFactory->make();

    unique_ptr<AbstractOsDetailsFactory> osDetailsFactory = make_unique<OsDetailsFactory>();
    shared_ptr<AbstractOsDetails> osDetails = osDetailsFactory->make();

    unique_ptr<AbstractProcessesListFactory> processesListFactory = make_unique<ProcessesListFactory>();
    shared_ptr<AbstractProcessesList> processesList = processesListFactory->make();

    // collect system information
    machineDetails->setMachineDetails();
    memoryDetails->setMemoryDetails();
    osDetails->setOsDetails();
    processesList->setProcessesList();

    // create data model
    shared_ptr<AbstractDataModel> dataModel = make_shared<DataModel>();

    // populate data model
    map<string, string> machineDetailsInfo = machineDetails->getMachineDetails();
    dataModel->setSystemDetails(SystemDetailsType::MachineDetails, machineDetailsInfo);

    map<string, string> memoryDetailsInfo = memoryDetails->getMemoryDetails();
    dataModel->setSystemDetails(SystemDetailsType::MemoryDetails, memoryDetailsInfo);

    map<string, string> osDetailsInfo = osDetails->getOsDetails();
    dataModel->setSystemDetails(SystemDetailsType::OsDetails, osDetailsInfo);

    list<string> processesListInfo = processesList->getRunningProcessesList();
    dataModel->setCurrentRunningProcesses(processesListInfo);

    // create display controller
    unique_ptr<AbstractDataVisualizationControllerFactory> dataVisualizationControllerFactory = make_unique<DataVisualizationControllerFactory>();
    shared_ptr<AbstractDataVisualizationController> dataVisualizationController = dataVisualizationControllerFactory->make();

    // display ui menu
    dataVisualizationController->initialize(dataModel);
    dataVisualizationController->displayUiMenu();
    return 0;
}
