#include "recursiveDescending.h"

#include <algorithm>
#include <exception>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

void recursiveDescending::printStatus(const int& status,
                                      const std::string& symbol,
                                      const std::string& str,
                                      const std::vector<int>& outter) {
    std::cout << status << ": symbol: " << symbol << "   str: " << str
              << "   outter: ";
    std::copy(outter.cbegin(), outter.cend(),
              std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;
}

void recursiveDescending::rollback(int& status, std::string& symbol,
                                   std::string& str, std::vector<int>& outter) {
    if (stash.empty()) {
        throw std::runtime_error("no more stash");
    }
    auto [status_, symbol_, str_, outter_] = stash.back();
    status = status_;
    symbol = symbol_;
    str = str_;
    outter = outter_;
    stash.pop_back();
    std::cout << "[backto]" << status << " ";
}

void recursiveDescending::solve(int status, std::string symbol,
                                             std::string str,
                                             std::vector<int> outter) {
    // outter symbol
    int derivation = 0;
    // have_try
    std::multimap<int, std::string> have_try;

    for (int status = 1;; status++) {
        // accept
        if (symbol == "#" && str == "#") {
            std::cout << status << " : Accept" << std::endl;
            break;
        }
        // get top
        char top = symbol.back();

        if (!(top >= 'A' && top <= 'z') || top == 'i' || top == '#') {
            if (top == str.at(0)) {
                // match
                str.erase(0, 1);
                symbol.pop_back();
            } else {
                // dismatch
                rollback(status, symbol, str, outter);
            }
        } else {
            // last status
            stash.emplace_back(status - 1, symbol, str, outter);
            symbol.pop_back();
            // derivation
            // try all way
            auto tableRange = table.equal_range(top);
            auto changed = false;
            for (auto it = tableRange.first; it != tableRange.second; ++it) {
                std::string tmp = it->second;
                if (have_try.find(status) != have_try.end()) {
                    int flag = false;
                    auto range = have_try.equal_range(status);
                    for (auto it = range.first; it != range.second; ++it) {
                        if (it->second == tmp) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) continue;
                }
                outter.push_back(derivation++);
                // have not try
                // do try
                have_try.insert(std::make_pair(status, tmp));
                changed = true;
                std::reverse(tmp.begin(), tmp.end());
                symbol += tmp;
                break;
            }
            if (!changed) {
                if (stash.empty()) {
                    throw std::runtime_error("no more way to do");
                }
                // recursive again
                rollback(status, symbol, str, outter);
            }
        }
        printStatus(status, symbol, str, outter);
    };
}
