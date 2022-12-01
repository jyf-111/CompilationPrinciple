#include "WordAnalysis.h"
int main(int argc, char* argv[]) {
    try {
		WordAnalysis wordAnalysis("input.c");
        wordAnalysis.analysis();
        wordAnalysis.printResult();
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
