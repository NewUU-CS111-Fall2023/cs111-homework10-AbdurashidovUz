#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random 3-SAT formula
vector<vector<int>> generate3SATFormula(int numVariables, int numClauses) {
    vector<vector<int>> formula;

    srand(time(0));  // Seed for random number generation

    for (int i = 0; i < numClauses; ++i) {
        vector<int> clause;
        for (int j = 0; j < 3; ++j) {
            int variable = rand() % numVariables + 1;  // Random variable from 1 to numVariables
            int negate = rand() % 2;  // 0 or 1 to determine if the variable should be negated
            clause.push_back(negate ? -variable : variable);
        }
        formula.push_back(clause);
    }

    return formula;
}

// Function to print the 3-SAT formula
void print3SATFormula(const vector<vector<int>>& formula) {
    for (const auto& clause : formula) {
        cout << "(" << clause[0] << " or " << clause[1] << " or " << clause[2] << ") and ";
    }
    cout << "\n";
}

int main() {
    int numVariables = 5;
    int numClauses = 10;

    vector<vector<int>> formula = generate3SATFormula(numVariables, numClauses);

    cout << "Generated 3-SAT Formula:\n";
    print3SATFormula(formula);

    return 0;
}
