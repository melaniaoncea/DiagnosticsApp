#ifndef WINDOWSPROCESSESLIST_H
#define WINDOWSPROCESSESLIST_H

#include<list>
#include<string>

#include "DataCollectorModule/AbstractProcessesList.h"

using std::list;
using std::string;

class WindowsProcessesList : public AbstractProcessesList
{
public:
    WindowsProcessesList();

    void setProcessesList() override;
    const list<string>& getRunningProcessesList() const override;


private:
    list<string> m_runningProcessesList;
};

#endif // WINDOWSPROCESSESDETAILS_H
