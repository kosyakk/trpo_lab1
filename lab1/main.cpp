#include <QtCore/QCoreApplication>

#include "filetracking.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //FileTracking tracking;

    QObject::connect(&FileTracking::getInstance(), &FileTracking::changeFile, &ConsoleOutput::getInstance(), &ConsoleOutput::output);

    FileTracking::getInstance().addFile("C:/test/empty.txt");
    FileTracking::getInstance().addFile("C:/test/notEmpty.txt");
    FileTracking::getInstance().addFile("C:/test/willDelete.txt");

    while(true)
    {
        FileTracking::getInstance().update();
    }

    return a.exec();
}
