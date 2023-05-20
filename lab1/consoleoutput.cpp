#include "consoleoutput.h"
#include <iostream>

ConsoleOutput ConsoleOutput::m_instance;

ConsoleOutput::ConsoleOutput(QObject *parent) : QObject(parent){}

void ConsoleOutput::output(StateFile file)
{
    std::cout << file.getFilePath().toStdString();

    switch (file.getState())
    {

    case StateFile::State::NOT_EXIST:
        std::cout << " file not exist." << std::endl;
        break;

    case StateFile::State::EXIST:
        std::cout << " file exist. Size: " << file.getSize() << std::endl;
        break;

    case StateFile::State::CHANGED:
        std::cout << " file changed. Size: " << file.getSize() << std::endl;
        break;

    //case StateFile::State::DELETED:
    //    std::cout << " file deleted." << std::endl;
    //    break;

    default:
        break;
    }

}
