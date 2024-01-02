#pragma once

#include <string>
#include <iostream>

class Logger
{
private:
    std::string m_name;
public:
    Logger(std::string name) : m_name(name)
    {

    }
    ~Logger()
    {

    }

    void Log(std::string message)
    {
        std::cout << m_name << ": " << message << std::endl;
    }
};