#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to check if a formula is satisfiable
bool isSatisfiable(const vector<int>& variables, const vector<vector<int>>& formula);

// Function to evaluate a formula with a given assignment
bool evaluateFormula(const vector<vector<int>>& formula, const unordered_map<int, bool>& assignment);

int main() {
    // Example usage:
    vector<int> variables = {1, 2, 3};
    vector<vector<int>> cnfFormula = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};

    bool result = isSatisfiable(variables, cnfFormula);

    cout << "Is the formula satisfiable? " << (result ? "Yes" : "No") << endl;

    return 0;
}

bool isSatisfiable(const vector<int>& variables, const vector<vector<int>>& formula) {
    int numVariables = variables.size();
    for (int i = 0; i < (1 << numVariables); ++i) {
        unordered_map<int, bool> assignment;
        for (int j = 0; j < numVariables; ++j) {
            assignment[variables[j]] = static_cast<bool>((i >> j) & 1);
        }
        if (evaluateFormula(formula, assignment)) {
            return true;
        }
    }
    return false;
}

bool evaluateFormula(const vector<vector<int>>& formula, const unordered_map<int, bool>& assignment) {
    for (const auto& clause : formula) {
        bool clauseSatisfied = false;
        for (int literal : clause) {
            if ((literal > 0 && assignment.at(literal)) || (literal < 0 && !assignment.at(-literal))) {
                clauseSatisfied = true;
                break;
            }
        }
        if (!clauseSatisfied) {
            return false;
        }
    }
    return true;
}
