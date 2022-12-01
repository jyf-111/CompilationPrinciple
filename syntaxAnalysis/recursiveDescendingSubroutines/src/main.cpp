/*
 * E->TG
 * G->+TG
 * G->-TG
 * G->ε
 * T->FS
 */
// i+i*i#

#include "recursiveDescending.h"

std::string str = "i+i*i#";
std::multimap<char, std::string> recursiveDescending::table = {
	{'E', "TG"},
	{'G', "+TG"},
	{'G', "-TG"},
	{'G', ""},
	{'T', "FS"},
	{'S', "*FS"},
	{'S', "/FS"},
	{'S', ""},
	{'F', "(E)"},
	{'F', "i"},
};

int main(int argc, char* argv[]) {
    recursiveDescending rd;
    rd.printStatus(0, "#E", str, {});
    rd.solve(1, "#E", str, std::vector<int>{});
    return 0;
}
