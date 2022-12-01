#pragma once

#include <memory>
#include <source_location>
#include <unordered_set>
#include <utility>
#include <vector>
#include <source_location>

#include "FileUtil.h"
#include "WordEnum.h"

class WordAnalysis {
   private:
    std::unique_ptr<FileUtil> fileUtil;
    WordEnum wordEnum;
    std::vector<std::pair<WordEnum, string>> result;
    bool isoperator(char);
    bool isdelimiter(char);
    static const std::unordered_set<string> reservedWords;
    static const std::unordered_set<string> operators;
    static const std::unordered_set<string> delimiters;
    void errorHandler(string,std::source_location);

   public:
    WordAnalysis(string);
    void analysis();
    void printResult();
};
