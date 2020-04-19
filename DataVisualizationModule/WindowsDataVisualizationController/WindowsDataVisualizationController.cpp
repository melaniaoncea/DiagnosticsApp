#include "WindowsDataVisualizationController.h"

#include<map>
#include<string>
#include<list>
#include<iostream>

#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"

using std::cout;
using std::cin;

void WindowsDataVisualizationController::initialize(shared_ptr<AbstractDataModel> dataModel)
{
    m_dataModel = dataModel;
}

void WindowsDataVisualizationController::displayUiMenu()
{
    // display the ui menu
    cout << "Menu:" << endl
         << "1 - Press 1 for operating system details" << endl
         << "2 - Press 2 for machine details" << endl
         << "3 - Press 3 for memory details" << endl
         << "4 - Press 4 for the list of current running processes" << endl
         << "5 - Press 5 for exiting the application" << endl;

    readUserResponse();
}

int WindowsDataVisualizationController::readUserResponse()
{
    // get the response from the user
    int userResponse(0);
    int status {1};
    while(cin >> userResponse)
    {
        // verify user response
        // if exit -> return
        if (userResponse == 5){
            status = 0;
            break;
        } else if (isUserAskingForInfo(userResponse)) {
            // if asking for info,process request
            processUserResponse(userResponse);
        } else {
            // if response not valid, promt the user to choose another option
            cout << "Please pick a valid option from the menu below:" << endl;

            displayUiMenu();
        }
    }
    return status;
}

void WindowsDataVisualizationController::processUserResponse(int userResponse)
{
    // process response based on response type and display requested info
    if (userResponse < 4) {
        auto systemDetailsType = static_cast<SystemDetailsType>(userResponse);
        const map<string, string>& requestedInfo = m_dataModel->getSystemDetails(systemDetailsType);
        displayRequestedInfo(systemDetailsType, requestedInfo);
    } else {
        const list<string>& requestedInfo = m_dataModel->getCurrentRunningProcesses();
        displayRequestedInfo(requestedInfo);
    }

    // when done, promt the user to pick another option
    cout << "Please choose another option from the menu below:" << endl;

    displayUiMenu();
}

void WindowsDataVisualizationController::displayRequestedInfo(SystemDetailsType systemDetailsType, map<string, string> requestedInfo)
{
    // displays requested info for options 1, 2 and 3
    switch (systemDetailsType) {
        case SystemDetailsType::OsDetails: {
            cout << "The operation system details are: " << endl
                 << "Name: " << requestedInfo.at("osVersion") << endl
                 << "Version: " << requestedInfo.at("osName") << endl;
            break;
        }
        case SystemDetailsType::MachineDetails: {
            cout << "The machine details are: " << endl
                 << "Name: " << requestedInfo.at("name") << endl
                 << "Model: " << requestedInfo.at("model") << endl
                 << "Manufacturer: " << requestedInfo.at("manufacturer") << endl;
            break;
        }

        case SystemDetailsType::MemoryDetails: {
            cout << "The memory details are: " << endl
                   << "Total memory: " << requestedInfo.at("total") << endl
                   << "Used memory: " << requestedInfo.at("used") << endl
                   << "Free memory: " << requestedInfo.at("free") << endl;
            break;
        }
    }
}
void WindowsDataVisualizationController::displayRequestedInfo(list<string> requestedInfo)
{
    // displays the requested info for option 4
    cout << "The list of currently running processes is: \n";

    int i {0};
    for (const string &listelement : requestedInfo) {
        cout << i <<"." << listelement << endl;
        i++;
    }
}

bool WindowsDataVisualizationController::isUserAskingForInfo(int userResponse)
{
    // check if user is asking for info
    if (userResponse > 0 && userResponse < 5) {
        return true;
    } else {
        return false;
    }
}
