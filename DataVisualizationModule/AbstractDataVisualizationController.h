#ifndef ABSTRACTDATAVISUALIZATIONCONTROLLER_H
#define ABSTRACTDATAVISUALIZATIONCONTROLLER_H

#include "DataModelModule/AbstractDataModel.h"

#include<map>
#include<string>
#include<list>
#include<memory>

using namespace std;

class AbstractDataVisualizationController
{
public:
    AbstractDataVisualizationController() = default;
    virtual ~AbstractDataVisualizationController() = default;

    virtual void initialize(shared_ptr<AbstractDataModel> dataModel) = 0;
    virtual void displayUiMenu() = 0;

protected:
    virtual int readUserResponse() = 0;
    virtual void processUserResponse(int userResponse) = 0;
    virtual void displayRequestedInfo(SystemDetailsType userResponse, map<string, string> requestedInfo) = 0;
    virtual void displayRequestedInfo(list<string> requestedInfo) = 0;
    virtual bool isUserAskingForInfo(int userResponse) = 0;
};

#endif // ABSTRACTDATAVISUALIZATIONCONTROLLER_H
