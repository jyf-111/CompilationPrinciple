#pragma once
#include <iostream>
#include <map>
#include <tuple>
#include <unordered_map>
#include <vector>

class recursiveDescending {
    using record = std::tuple<int, std::string, std::string, std::vector<int>>;
    static std::multimap<char, std::string> table;

   public:
    std::vector<record> stash;
    void printStatus(const int& status, const std::string& symbol,
                     const std::string& str, const std::vector<int>& outter);

    void solve(int status, std::string symbol, std::string str,
               std::vector<int> outter);
    void rollback(int& status, std::string& symbol, std::string& str,
                  std::vector<int>& outter
    );
};
