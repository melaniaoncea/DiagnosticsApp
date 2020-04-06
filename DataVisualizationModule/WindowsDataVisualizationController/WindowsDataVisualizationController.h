#ifndef WINDOWSDATAVISUALIZATIONCONTROLLER_H
#define WINDOWSDATAVISUALIZATIONCONTROLLER_H

#include "DataVisualizationModule/AbstractDataVisualizationController.h"
#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"

#include<map>
#include<string>
#include<list>

using namespace std;

class WindowsDataVisualizationController : public AbstractDataVisualizationController
{
public:
    WindowsDataVisualizationController() = default;

    void initialize(AbstractDataModel* dataModel) override;
    void displayUiMenu() override;

private:
    int readUserResponse() override;
    void processUserResponse(int userResponse) override;
    void displayRequestedInfo(SystemDetailsType userResponse, map<string, string> requestedInfo) override;
    void displayRequestedInfo(std::list<string> requestedInfo) override;
    bool isUserAskingForInfo(int userResponse) override;
    char* castStringToCharArray(string& stringValue) override;

private:
    AbstractDataModel* m_dataModel = nullptr;
};

#endif // WINDOWSDATAVISUALIZATIONCONTROLLER_H
