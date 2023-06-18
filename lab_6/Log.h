#pragma once
#include<iostream>
#include<fstream>
#include <chrono>
#include <ctime>

namespace utilits {
    enum class Levels {
        Release,
        Debug
    };
    std::ostream& operator<< (std::ostream& out, Levels level) {
        switch (level) {
        case Levels::Release:
            out << "Release";
            break;
        case Levels::Debug:
            out << "Debug";
            break;
        default:
            out << "Error";
            break;
        }
        return out;
    }

    class Log {
    private:
        static std::ofstream m_out;
        static Levels m_level;
    public:
        static void SetFile(const std::string& fileName) {
            m_out.open(fileName);
        }
        static void SetLevel(Levels level) { m_level = level; }
        static void Write(const std::string& logText) {
            if (m_level != Levels::Release) {
                std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
                std::time_t timeT = std::chrono::system_clock::to_time_t(time);
                std::cerr << std::ctime(&timeT) << m_level << " " << logText << std::endl;
                m_out << std::ctime(&timeT) << m_level << " " << logText << std::endl;
            }
        }

    };
    std::ofstream Log::m_out;
    Levels Log::m_level = Levels::Release;

}
