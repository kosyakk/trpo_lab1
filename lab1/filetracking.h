#ifndef FILETRACKING_H
#define FILETRACKING_H

#include <QVector>

#include "output.h"

class ThreadWorker;

class FileTracking : public QObject
{
    Q_OBJECT

public:
    FileTracking();
    ~FileTracking();

    bool checkForExistence(QString filepath);
    void addFile(QString filepath);

    void update();

signals:
    void changeFile(StateFile files);

private:
    QVector<StateFile> m_filesForCheck;
};


#endif // FILETRACKING_H
