#include "DataVisualizationController.h"

#include<map>
#include<string>
#include<list>
#include<stdio.h>

#include "DataModelModule/AbstractDataModel.h"

using namespace std;

DataVisualizationController::DataVisualizationController(AbstractDataModel& dataModel):
    m_dataModel(dataModel)
{

}

void DataVisualizationController::displayUiMenu()
{
    // display the ui menu
    printf("Menu: \n  1 - Press 1 for operating system details \n 2 - Press 2 for machine details \n  3 - Press 3 for memory details \n  4 - Press 4 for the list of current running processes \n 5 - Press 5 for exiting the application \n");
    getUserResponse();
}

int DataVisualizationController::getUserResponse()
{
    // get the response from the user
    int* userResponse(0);

    while(scanf("%d", userResponse))
    {
        // verify user response
        // if exit -> return
        if (*userResponse == 5){
            break;
        } else if (isUserAskingForInfo(*userResponse)) {
            // if asking for info,process request
            processUserResponse(*userResponse);
        }  else {
            // if response not valid, promt the user to choose another option
            printf("Please pick a valid option from the menu below:\n");
            displayUiMenu();
        }
    }
    return 0;
}

void DataVisualizationController::processUserResponse(int userResponse)
{
        // process response based on response type and display requested info
        if (userResponse < 4) {
            auto systemDetailsType = static_cast<SystemDetailsType>(userResponse);
            std::map<std::string, std::string> requestedInfo = m_dataModel.getSystemDetails(systemDetailsType);
            displayRequestedInfo(systemDetailsType, requestedInfo);
        } else {
            std::list<std::string> requestedInfo = m_dataModel.getCurrentRunningProcesses();
            displayRequestedInfo(requestedInfo);
        }

        // when done, promt the user to pick another option
        printf("Please choose another option from the menu below:\n");
        displayUiMenu();
}

void DataVisualizationController::displayRequestedInfo(SystemDetailsType systemDetailsType, std::map<string, string> requestedInfo)
{
    // displays requested info for options 1, 2 and 3
    switch (systemDetailsType) {
    case SystemDetailsType::OsDetails:
        printf("The operation system details are:\n"
               "Name: %s\n "
               "Version: %s\n", requestedInfo.at("osName"), requestedInfo.at("osVersion"));
        break;
    case SystemDetailsType::MachineDetails:
        printf("The machine details are: "
               "Name: %s\n "
               "Model: %s\n"
               "Manufacturer: %s\n",
               requestedInfo.at("name"), requestedInfo.at("model"),requestedInfo.at("manufacturer"));
        break;

    case SystemDetailsType::MemoryDetails:
        printf("The memory details are: \n"
               "Total memory: %s \n "
               "Used memory: %s \n "
               "Free memory: %s \n",
               requestedInfo.at("total"), requestedInfo.at("used"), requestedInfo.at("free"));
        break;
    }
}
void DataVisualizationController::displayRequestedInfo(std::list<string> requestedInfo)
{
    // displays the requested info for option 4
    printf("The list of currently running processes is: \n");

    int i = 0;
    for (std::string listelement : requestedInfo) {
        printf("%d. %s \n", i, listelement);
        i++;
    }
}

bool DataVisualizationController::isUserAskingForInfo(int userResponse)
{
    // check if user response is valid
    if (userResponse > 0 && userResponse < 5) {
        return true;
    } else {
        return false;
    }
}
