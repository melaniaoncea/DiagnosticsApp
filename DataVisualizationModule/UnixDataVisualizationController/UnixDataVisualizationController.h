#ifndef UNIXDATAVISUALIZATIONCONTROLLER_H
#define UNIXDATAVISUALIZATIONCONTROLLER_H

#include "DataVisualizationModule/AbstractDataVisualizationController.h"
#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"

#include<map>
#include<string>
#include<list>

using namespace std;

class UnixDataVisualizationController : public AbstractDataVisualizationController
{
public:
    UnixDataVisualizationController() = default;

    void initialize(AbstractDataModel *dataModel) override;
    void displayUiMenu() override;

private:
    int readUserResponse();
    void processUserResponse(int userResponse) override;
    void displayRequestedInfo(SystemDetailsType userResponse, map<string, string> requestedInfo) override;
    void displayRequestedInfo(list<string> requestedInfo) override;
    bool isUserAskingForInfo(int userResponse) override;
    char* castStringToCharArray(string & stringValue) override;

private:
    AbstractDataModel* m_dataModel = nullptr;
};

#endif // UNIXDATAVISUALIZATIONCONTROLLER_H
