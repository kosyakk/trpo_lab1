#include "filetracking.h"

FileTracking::FileTracking() {};
FileTracking::~FileTracking() {};

bool FileTracking::checkForExistence(QString filepath)
{
    bool check = false;
    for (int i = 0; i < m_filesForCheck.size(); i++)
    {
        if (m_filesForCheck[i] == filepath)
        {
            check = true;
            break;
        }
    }

    return check;
}

void FileTracking::addFile(QString filepath)
{
    if (checkForExistence(filepath))
        return;

    m_filesForCheck.push_back({filepath});

    emit changeFile(m_filesForCheck[m_filesForCheck.size()-1]);
}

void FileTracking::update()
{
    for (int i = 0; i < m_filesForCheck.size(); i++)
    {
        if (m_filesForCheck[i].update())
        {
            emit changeFile(m_filesForCheck[i]);
        }
    }
}

