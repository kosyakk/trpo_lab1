#include "statefile.h"

StateFile::StateFile(QString path)
{
    m_filePath = path;
    QFileInfo file(m_filePath);

    if (file.exists())
    {
        m_fileSize = file.size();
        m_state = State::EXIST;
    }
    else
    {
        m_fileSize = 0;
        m_state = State::NOT_EXIST;
    }
}

StateFile::StateFile(const StateFile& file) : QObject()
{
    m_filePath = file.m_filePath;
    m_fileSize = file.m_fileSize;
    m_state = file.m_state;
}

StateFile::StateFile(StateFile&& file)
{
    m_filePath = file.m_filePath;
    m_fileSize = file.m_fileSize;
    m_state = file.m_state;
}

StateFile::State StateFile::getState()
{
    return m_state;
}

int StateFile::getSize()
{
    return m_fileSize;
}

QString StateFile::getFilePath()
{
    return m_filePath;
}

bool StateFile::operator==(const QString& path)
{
    return  path == m_filePath;
}

bool StateFile::update()
{
    QFileInfo file(m_filePath);

    bool stateNow = false;

    if (file.exists())
    {
        int currentSize = file.size();
        switch (m_state)
        {

        case NOT_EXIST:
        case DELETED:
            m_state = EXIST;
            m_fileSize = currentSize;
            stateNow = true;
            break;

        case State::EXIST:
        case State::CHANGED:
            if (m_fileSize != currentSize)
            {
                m_state = State::CHANGED;
                m_fileSize = currentSize;
                stateNow = true;
            }
            break;

        default:
            break;
        }
    }
    else
    {
        switch (m_state)
        {

        case NOT_EXIST:
            break;

        case EXIST:
        case CHANGED:
            m_state = DELETED;
            m_fileSize = -1;
            stateNow = true;
            break;

        case DELETED:
            break;

        default:
            break;
        }
    }

    return stateNow;
}
