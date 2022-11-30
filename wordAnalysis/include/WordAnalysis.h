#pragma once

#include <memory>
#include <utility>
#include <unordered_set>
#include <vector>

#include "FileUtil.h"
#include "WordEnum.h"

class WordAnalysis {
   private:
    std::unique_ptr<FileUtil> fileUtil;
    WordEnum wordEnum;
    std::vector<std::pair<WordEnum, string>> result;
	bool isoperator(char c);
	bool isdelimiter(char c);
	static const std::unordered_set<string> reservedWords;
	static const std::unordered_set<string> operators;
	static const std::unordered_set<string> delimiters;
	void errorHandler(string s);

   public:
    WordAnalysis();
    void analysis();
	void printResult();
};
