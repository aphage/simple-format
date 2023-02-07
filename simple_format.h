// MIT License

// Copyright (c) 2023 aphage

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <string>
#include <sstream>
#include <stdexcept>

static void vformat(std::stringstream& ss, const std::string& format, uint32_t i) {
    for(; i < format.length(); i++) {
        if(format[i] == '{' && i+1 < format.length() && format[i+1] == '}') {
            throw std::invalid_argument("too many argument");
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
