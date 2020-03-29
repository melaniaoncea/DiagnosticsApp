#ifndef DATAVISUALIZATIONCONTROLLER_H
#define DATAVISUALIZATIONCONTROLLER_H

#include<map>
#include<string>
#include<list>

#include "DataModelModule/AbstractDataModel.h"

class DataVisualizationController
{
public:
    DataVisualizationController(AbstractDataModel& dataModel);

    void displayUiMenu();

private:
    int getUserResponse();
    void processUserResponse(int userResponse);
    void displayRequestedInfo(SystemDetailsType userResponse, std::map<std::string, std::string> requestedInfo);
    void displayRequestedInfo(std::list<std::string> requestedInfo);
    bool isUserResponseValid(int userResponse);

private:
    AbstractDataModel& m_dataModel;
};

#endif // DATAVISUALIZATIONCONTROLLER_H
