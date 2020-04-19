#ifndef UNIXPROCESSESLIST_H
#define UNIXPROCESSESLIST_H

#include "DataCollectorModule/AbstractProcessesList.h"

#include<list>
#include<string>

using namespace std;

class UnixProcessesList : public AbstractProcessesList
{
public:
    UnixProcessesList();

    void setProcessesList() override;
    const list<string>& getRunningProcessesList() const override;


private:
    list<string> m_runningProcessesList;
};

#endif // UNIXPROCESSESDETAILS_H
