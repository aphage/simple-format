#pragma once

#include <string>
#include <sstream>

template <typename T>
void vformat(std::stringstream& ss, const std::string& format, uint32_t i, T value) {
    for(; i < format.length(); i++) {
        if(format[i] == '{' && i+1 < format.length() && format[i+1] == '}') {
            ss << value;
            i += 2;
        } else {
            ss << format[i];
        }
    }
}

template <typename T, typename... Args>
void vformat(std::stringstream& ss, const std::string& format, uint32_t i, T value, Args... args) {
    for(; i < format.length(); i++) {
        if(format[i] == '{' && i+1 < format.length() && format[i+1] == '}') {
            ss << value;
            vformat(ss, format, i + 2, args...);
            return;
        } else {
            ss << format[i];
        }
    }
}

template <typename... Args>
std::string format(const std::string& format, Args... args) {
    std::stringstream ss;
    vformat(ss, format, 0, args...);
    return ss.str();
}
