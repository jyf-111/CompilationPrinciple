#include "WordAnalysis.h"

#include <cctype>
#include <cstdlib>
#include <type_traits>
#include <unordered_set>

#include "WordEnum.h"

const std::unordered_set<string> WordAnalysis::reservedWords = {
    "main",   "int",      "long",    "short",   "float", "double",
    "char",   "unsigned", "signed",  "const",   "void",  "volatile",
    "enum",   "struct",   "union",   "if",      "else",  "goto",
    "switch", "case",     "do",      "while",   "for",   "continue",
    "break",  "return",   "default", "typedef", "auto",  "register",
    "extern", "static",   "sizeof"};
const std::unordered_set<string> WordAnalysis::operators = {
    "+",  "-",  "*",  "/",  "%",  "++", "--", "=",  "+=", "-=",
    "*=", "/=", "%=", "==", "!=", ">",  "<",  ">=", "<=", "&&",
    "||", "!",  "&",  "|",  "^",  "~",  "<<", ">>", ">>>"};
const std::unordered_set<string> WordAnalysis::delimiters = {
    "(", ")", "[", "]", "{", "}", ",", ";", ".", ":", "?", "#", "\"", "\'"};

WordAnalysis::WordAnalysis(string fileName) {
    fileUtil = std::make_unique<FileUtil>(fileName);
}
bool WordAnalysis::isoperator(char c) {
    return operators.find(string(1, c)) != operators.end();
}
bool WordAnalysis::isdelimiter(char c) {
    return delimiters.find(string(1, c)) != delimiters.end();
}

void WordAnalysis::errorHandler(string s) {
    throw std::runtime_error("error: " + s);
    return;
}

void WordAnalysis::analysis() {
    string currentWord;
    string currentDigit;
    string currentOperator;
    while (fileUtil->hasNextChar()) {
        char c = fileUtil->getNextChar();
        if (isalpha(c)) {
            // is aplha
            currentWord += c;
            continue;
        } else {
            if (!currentWord.empty()) {
                if (reservedWords.find(currentWord) != reservedWords.end()) {
                    // is reserved word
                    result.emplace_back(WordEnum::ReservedWord, currentWord);
                } else {
                    // is not reserved word
                    result.emplace_back(WordEnum::Identifier, currentWord);
                }
                currentWord.clear();
            }
        }
        if (isdigit(c)) {
            // is digit
            currentDigit += c;
            continue;
        } else {
            if (!currentDigit.empty()) {
                result.emplace_back(WordEnum::Constant, currentDigit);
                currentDigit.clear();
            }
        }
        if (isoperator(c)) {
            // is operator
            currentOperator += c;
            continue;
        } else {
            if (!currentOperator.empty()) {
                if (operators.find(currentOperator) != operators.end())
                    result.emplace_back(WordEnum::Operator, currentOperator);
                else {
                    errorHandler("no such operater" + currentOperator);
                }
                currentOperator.clear();
            }
        }
        if (isdelimiter(c)) {
            // is delimiter
            result.emplace_back(WordEnum::Delimiter, string(1, c));
            continue;
        }
        // not a word or digit
        // if is space, tab, newline, carriage return, form feed, vertical tab
        if (isspace(c)) continue;

        errorHandler("no such char" + string(1, c));
    }
}

void WordAnalysis::printResult() const noexcept {
    for (auto& i : result) {
        std::cout << static_cast<std::underlying_type<WordEnum>::type>(i.first)
                  << " " << i.second << std::endl;
    }
}
