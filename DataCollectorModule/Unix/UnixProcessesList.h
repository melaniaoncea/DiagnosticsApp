#ifndef UNIXPROCESSESLIST_H
#define UNIXPROCESSESLIST_H

#include<list>
#include<string>

#include "DataCollectorModule/AbstractProcessesList.h"

class UnixProcessesList : public AbstractProcessesList
{
public:
    UnixProcessesList();

    void setProcessesList() override;
    std::list<std::string> getRunningProcessesList() const override;


private:
    std::list<std::string> m_runningProcessesList;
};

#endif // UNIXPROCESSESDETAILS_H
