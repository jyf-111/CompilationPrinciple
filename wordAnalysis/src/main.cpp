#include "WordAnalysis.h"
int main(int argc, char* argv[]) {
    WordAnalysis wordAnalysis;
    try {
        wordAnalysis.analysis();
        wordAnalysis.printResult();
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
