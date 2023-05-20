#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>

#include "statefile.h"

class ConsoleOutput : public QObject
{
    Q_OBJECT

public:
    static ConsoleOutput& getInstance() { return m_instance; }

public slots:
    void output(StateFile file);

private:
    static ConsoleOutput m_instance;

    ConsoleOutput(QObject *parent = nullptr);
};

#endif // OUTPUT_H
