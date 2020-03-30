#include "UnixProcessesList.h"

UnixProcessesList::UnixProcessesList()
{
}

void UnixProcessesList::setProcessesList()
{
    m_runningProcessesList.clear();

    m_runningProcessesList.push_back("Process 1");
    m_runningProcessesList.push_back("Process 2");
    m_runningProcessesList.push_back("Process 3");
}

list<string> UnixProcessesList::getRunningProcessesList() const
{
    return m_runningProcessesList;
}
