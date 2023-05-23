#ifndef FILETRACKING_H
#define FILETRACKING_H

#include <QVector>

#include "consoleoutput.h"

class FileTracking : public QObject
{
    Q_OBJECT

public:
    static FileTracking& getInstance() { return m_instance; }

    bool checkForExistence(QString filepath);
    void addFile(QString filepath);

    void update();

signals:
    void changeFile(StateFile files);

private:
    QVector<StateFile> m_filesForCheck;

    static FileTracking m_instance;

    FileTracking(QObject *parent = nullptr);
};


#endif // FILETRACKING_H
