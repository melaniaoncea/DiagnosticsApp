#include "WindowsProcessesList.h"

#include<list>
#include<string>
#include<windows.h>

WindowsProcessesList::WindowsProcessesList()
{
}

void WindowsProcessesList::setProcessesList()
{
    m_runningProcessesList.clear();

    // could be retrieved by using EnumProcessModules from windows.h

    m_runningProcessesList.push_back("Process 1");
    m_runningProcessesList.push_back("Process 2");
    m_runningProcessesList.push_back("Process 3");
}

std::list<std::string> WindowsProcessesList::getRunningProcessesList() const
{
    return m_runningProcessesList;
}
