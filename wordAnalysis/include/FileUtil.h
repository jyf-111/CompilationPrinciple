#pragma once

#include <fstream>
#include <iostream>
#include <istream>
#include <memory>

using std::ifstream;
using std::ios;
using std::string;

class FileUtil {
    ifstream* in;

   public:
    FileUtil(string fileName);
    ~FileUtil();
    char getNextChar();
    char peekNextChar();
    [[nodiscard]] bool hasNextChar() const noexcept;
};
