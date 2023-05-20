#include <QtCore/QCoreApplication>

#include "filetracking.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileTracking tracking;

    QObject::connect(&tracking, &FileTracking::changeFile, &ConsoleOutput::getInstance(), &ConsoleOutput::output);

    tracking.addFile("C:/test/empty.txt");
    tracking.addFile("C:/test/notEmpty.txt");
    tracking.addFile("C:/test/willDelete.txt");

    while(true)
    {
        tracking.update();
    }

    return a.exec();
}
