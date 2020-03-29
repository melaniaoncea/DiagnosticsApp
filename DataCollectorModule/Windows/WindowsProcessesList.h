#ifndef WINDOWSPROCESSESLIST_H
#define WINDOWSPROCESSESLIST_H

#include<list>
#include<string>

#include "DataCollectorModule/AbstractProcessesList.h"


class WindowsProcessesList : public AbstractProcessesList
{
public:
    WindowsProcessesList();

    void setProcessesList() override;
    std::list<std::string> getRunningProcessesList() const override;


private:
    std::list<std::string> m_runningProcessesList;
};

#endif // WINDOWSPROCESSESDETAILS_H
