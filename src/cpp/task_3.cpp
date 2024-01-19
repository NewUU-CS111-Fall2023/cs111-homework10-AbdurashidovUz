#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum State { q0, q1, q2, q3, q4, q5, q_accept, q_reject };

class TuringMachine {
private:
    vector<int> tape;
    int head;
    State state;

    map<pair<State, int>, tuple<State, int, char>> transitionTable;

public:
    TuringMachine(const vector<int>& input) : tape(input), head(0), state(q0) {
        // Initialize transition rules
        // (State, Symbol) -> (New State, New Symbol, Move Direction)
        transitionTable[{q0, 1}] = {q0, 1, 'R'};
        transitionTable[{q0, 0}] = {q1, 0, 'R'};
        // ... (Rest of the transition rules)

        transitionTable[{q5, 1}] = {q5, 1, 'L'};
        transitionTable[{q5, '_'}] = {q_accept, '_', 'S'};
    }

    void run() {
        while (state != q_accept && state != q_reject) {
            int symbol = tape[head];
            auto transition = transitionTable[{state, symbol}];
            state = get<0>(transition);
            tape[head] = get<1>(transition);

            if (get<2>(transition) == 'R') {
                head++;
                if (head == tape.size()) tape.push_back(0); // Extend tape if necessary
            } else if (get<2>(transition) == 'L') {
                head = max(0, head - 1);
            }
        }

        if (state == q_accept) {
            cout << "Output: 1 1 (First number is greater or equal)\n";
        } else {
            cout << "Output: 1 (Second number is greater)\n";
        }
    }
};

int main() {
    // Sample input: 0 1 1 1 c 1 1 1 1 0
    vector<int> input = {0, 1, 1, 1, 2, 1, 1, 1, 1, 0};
    
    TuringMachine tm(input);
    tm.run();

    return 0;
}
