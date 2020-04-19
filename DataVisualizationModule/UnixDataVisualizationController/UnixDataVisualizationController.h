#ifndef UNIXDATAVISUALIZATIONCONTROLLER_H
#define UNIXDATAVISUALIZATIONCONTROLLER_H

#include "DataVisualizationModule/AbstractDataVisualizationController.h"
#include "DataVisualizationModule/DataModelModule/AbstractDataModel.h"

#include<map>
#include<string>
#include<list>
#include<memory>

using std::string;
using std::list;
using std::map;

class UnixDataVisualizationController : public AbstractDataVisualizationController
{
public:
    UnixDataVisualizationController() = default;

    void initialize(shared_ptr<AbstractDataModel> dataModel) override;
    void displayUiMenu() override;

private:
    int readUserResponse();
    void processUserResponse(int userResponse) override;
    void displayRequestedInfo(SystemDetailsType userResponse, map<string, string> requestedInfo) override;
    void displayRequestedInfo(list<string> requestedInfo) override;
    bool isUserAskingForInfo(int userResponse) override;

private:
    shared_ptr<AbstractDataModel> m_dataModel {nullptr};
};

#endif // UNIXDATAVISUALIZATIONCONTROLLER_H
