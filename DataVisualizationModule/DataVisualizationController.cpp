#include "DataVisualizationController.h"
#include<iostream>
#include<map>
#include<string>
#include<list>

#include "DataModelModule/AbstractDataModel.h"

using namespace std;

DataVisualizationController::DataVisualizationController(AbstractDataModel& dataModel):
    m_dataModel(dataModel)
{

}

void DataVisualizationController::displayUiMenu()
{
    // display the ui menu
    std::cout << "Menu:" << endl
              << "1 - Press 1 for operating system details" << endl
              << "2 - Press 2 for machine details" << endl
              << "3 - Press 3 for memory details" << endl
              << "4 - Press 4 for the list of current running processes" << endl
              << "5 - Press 5 for exiting the application" << endl;
    getUserResponse();
}

int DataVisualizationController::getUserResponse()
{
    // get the response from the user
    int userResponse;
    while ( std::cin >> userResponse)
    {
        // verify that user response is valid
        // if exit -> return
        if (userResponse == 5){
            break;
        } else if (isUserResponseValid(userResponse)) {
            // if valid process request
            processUserResponse(userResponse);
        }  else {
            // if response not valid, promt the user to choose another option
            std::cout << "Please pick a valid option from the menu below:" << endl;
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
        std::cout << "Please choose another option from the menu below:" << endl;
        displayUiMenu();
}

void DataVisualizationController::displayRequestedInfo(SystemDetailsType systemDetailsType, std::map<string, string> requestedInfo)
{
    // displays requested info for options 1, 2 and 3
    switch (systemDetailsType) {
        case SystemDetailsType::OsDetails: {
            std::cout << "The operation system details are:" << endl
                      << "Name: " << requestedInfo.at("osName") << endl
                      << "Version: " << requestedInfo.at("osVersion") << endl;
        }
            break;
        case SystemDetailsType::MachineDetails: {
            std::cout << "The machine details are:" << endl
                      << "Name: " << requestedInfo.at("name") << endl
                      << "Model: " << requestedInfo.at("model") << endl
                      << "Manufacturer : " << requestedInfo.at("manufacturer") <<endl;
        }
            break;
        case SystemDetailsType::MemoryDetails: {
            std::cout << "The memory details are:" << endl
                      << "Total memory: " << requestedInfo.at("total") << endl
                      << "Used memory: " << requestedInfo.at("used") << endl
                      << "Free: " << requestedInfo.at("free") <<endl;
        }
            break;
    }
}

void DataVisualizationController::displayRequestedInfo(std::list<string> requestedInfo)
{
    // displays the requested info for option 4
    std::cout << "The list of currently running processes is:" << endl;

    int i = 0;
    for (std::string listelement : requestedInfo) {
        std::cout << i << ". " << listelement << endl;
        i++;
    }
}

bool DataVisualizationController::isUserResponseValid(int userResponse)
{
    // check if user response is valid
    if (userResponse > 0 && userResponse < 5) {
        return true;
    } else {
        return false;
    }
}
