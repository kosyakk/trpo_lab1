#ifndef FILESTATE_H
#define FILESTATE_H

#include <QString>
#include <QDir>

class StateFile
{
public:

    enum State
    {
        NOT_EXIST,
        EXIST,
        CHANGED
        //DELETED
    };

    StateFile() = default;
    StateFile(QString path);
    //StateFile(const StateFile& file);
    //StateFile(StateFile&& file);
    ~StateFile() = default;

    State getState();
    int getSize();
    QString getFilePath();

    bool operator==(const QString& path);

    bool update();

protected:
    int m_fileSize;
    QString m_filePath;
    State m_state;
};

#endif // FILESTATE_H
