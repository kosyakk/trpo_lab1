#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>

#include "statefile.h"

class Output : public QObject
{
    Q_OBJECT

public:
    static Output& getInstance() { return m_instance; }

public slots:
    void output(StateFile file);

private:
    static Output m_instance;

    Output(QObject *parent = nullptr);
};

#endif // OUTPUT_H
