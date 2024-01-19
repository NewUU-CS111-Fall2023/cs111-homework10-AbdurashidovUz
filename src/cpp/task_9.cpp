#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Structure to represent a clause in CNF
struct Clause {
    vector<int> literals;
};

// Function to check if a clause is satisfied by a given assignment
bool isClauseSatisfied(const Clause& clause, const unordered_set<int>& assignment) {
    for (int literal : clause.literals) {
        if (assignment.count(literal) > 0) {
            // If at least one literal in the clause is true, the clause is satisfied
            return true;
        }
    }
    // If no literals in the clause are true, the clause is not satisfied
    return false;
}

// Function to check if a CNF formula is satisfied by a given assignment
bool isCNFSatisfied(const vector<Clause>& cnf, const unordered_set<int>& assignment) {
    for (const Clause& clause : cnf) {
        if (!isClauseSatisfied(clause, assignment)) {
            // If any clause is not satisfied, the whole CNF formula is not satisfied
            return false;
        }
    }
    // All clauses are satisfied, the CNF formula is satisfied
    return true;
}

int main() {
    // Example CNF formula: (A or B) and (C or ~D)
    vector<Clause> cnf = { {{1, 2}}, {{3, -4}} };

    // Example truth value assignment: A=true, B=false, C=false, D=true
    unordered_set<int> assignment = {1, -2, -3, 4};

    // Check if the CNF formula is satisfied by the assignment
    bool isSatisfied = isCNFSatisfied(cnf, assignment);

    // Output the result
    cout << (isSatisfied ? "Satisfied" : "Not Satisfied") << endl;

    return 0;
}

