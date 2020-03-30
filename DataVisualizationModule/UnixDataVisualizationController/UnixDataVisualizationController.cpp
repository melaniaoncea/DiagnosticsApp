#include "UnixDataVisualizationController.h"

#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"

#include<map>
#include<string>
#include<list>
#include<iostream>

using namespace std;

void UnixDataVisualizationController::initialize(AbstractDataModel* dataModel)
{
    m_dataModel = dataModel;
}

void UnixDataVisualizationController::displayUiMenu()
{
    // display the ui menu
    std::cout << "Menu: " << endl
              << "1 - Press 1 for operating system details" << endl
              << "2 - Press 2 for machine details" << endl
              << "3 - Press 3 for memory details" << endl
              << "4 - Press 4 for the list of current running processes" << endl
              << "5 - Press 5 for exiting the application"<< endl;
    readUserResponse();
}

int UnixDataVisualizationController::readUserResponse()
{
    // get the response from the user
    int userResponse(0);

    while(std::cin >> userResponse)
    {
        // if exit -> return
        if (userResponse == 5){
            break;
        } else if (isUserAskingForInfo(userResponse)) {
            // if asking for info,process request
            processUserResponse(userResponse);
        } else {
            // if response not valid, promt the user to choose another option
            std::cout << "Please pick a valid option from the menu below:" << endl;

            displayUiMenu();
        }
    }
    return 0;
}

void UnixDataVisualizationController::processUserResponse(int userResponse)
{
    // process response based on response type and display requested info
    if (userResponse < 4) {
        auto systemDetailsType = static_cast<SystemDetailsType>(userResponse);
        std::map<std::string, std::string> requestedInfo = m_dataModel->getSystemDetails(systemDetailsType);
        displayRequestedInfo(systemDetailsType, requestedInfo);
    } else {
        std::list<std::string> requestedInfo = m_dataModel->getCurrentRunningProcesses();
        displayRequestedInfo(requestedInfo);
    }

    // when done, promt the user to pick another option
    std::cout << "Please choose another option from the menu below:" << endl;

    displayUiMenu();
}

void UnixDataVisualizationController::displayRequestedInfo(SystemDetailsType systemDetailsType, std::map<string, string> requestedInfo)
{
    // displays requested info for options 1, 2 and 3
    switch (systemDetailsType) {
    case SystemDetailsType::OsDetails: {
        //TODO - SEE IF NOT NEEDED ALL CHARS
        char* osVersion = castStringToCharArray(requestedInfo.at("osVersion"));
        char* osName = castStringToCharArray(requestedInfo.at("osName"));

        std::cout << "The operation system details are: " << endl
                  << "Name: " << osName << endl
                  << "Version: " << osVersion << endl;
        break;
    }
    case SystemDetailsType::MachineDetails: {
        char* machineName = castStringToCharArray(requestedInfo.at("name"));
        char* machineModel = castStringToCharArray(requestedInfo.at("model"));
        char* machineManufacturer = castStringToCharArray(requestedInfo.at("manufacturer"));

        std::cout << "The machine details are: " << endl
             << "Name: " << machineName << endl
             << "Model: " << machineModel << endl
             << "Manufacturer: " << machineManufacturer << endl;
        break;
    }

    case SystemDetailsType::MemoryDetails: {
        char* totalMemory = castStringToCharArray(requestedInfo.at("total"));
        char* usedMemory = castStringToCharArray(requestedInfo.at("used"));
        char* freeMemory = castStringToCharArray(requestedInfo.at("free"));

        std::cout << "The memory details are: " << endl
             << "Total memory: " << totalMemory << endl
             << "Used memory: " << usedMemory << endl
             << "Free memory: " << freeMemory << endl;
        break;
    }
    }
}
void UnixDataVisualizationController::displayRequestedInfo(std::list<string> requestedInfo)
{
    // displays the requested info for option 4
    std::cout << "The list of currently running processes is: " << endl;

    int i = 0;
    for (std::string listelement : requestedInfo) {
        char* processName = castStringToCharArray(listelement);
        std::cout << i <<". " << processName << endl;
        i++;
    }
}

bool UnixDataVisualizationController::isUserAskingForInfo(int userResponse)
{
    // check if user response is valid
    if (userResponse > 0 && userResponse < 5) {
        return true;
    } else {
        return false;
    }
}

char * UnixDataVisualizationController::castStringToCharArray(std::string &stringValue)
{
    char* castedStringValue = const_cast<char*>(stringValue.c_str());
    return castedStringValue;
}
