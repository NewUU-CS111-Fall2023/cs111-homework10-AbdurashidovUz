#include <iostream>
#include <cstdlib>

int main() {
    int numVariables, numClauses;

    std::cout << "Number of variables: ";
    std::cin >> numVariables;

    std::cout << "Number of clauses: ";
    std::cin >> numClauses;

    std::cout << "Generated 3-SAT formula:" << std::endl;

    for (int i = 0; i < numClauses; ++i) {
        char vars[3];

        for (int j = 0; j < 3; ++j) {
            char variable = 'A' + rand() % numVariables;
            bool isNegated = (rand() % 2 == 0);
            vars[j] = (isNegated) ? '~' : variable;
        }

        std::cout << "(" << vars[0] << " | " << vars[1] << " | " << vars[2] << ")";

        if (i < numClauses - 1) {
            std::cout << " & ";
        }
    }

    return 0;
}
