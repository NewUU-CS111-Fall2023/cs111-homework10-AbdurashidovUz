#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum State { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q_accept, q_reject };

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
        transitionTable[{q0, 1}] = {q1, '_', 'R'};
        transitionTable[{q1, 1}] = {q1, 1, 'R'};
        transitionTable[{q1, 'c'}] = {q2, 'c', 'R'};

        // ... (Complete the rest of the transition rules)

        transitionTable[{q_accept, '_'}] = {q_accept, '_', 'S'};
        transitionTable[{q_reject, '_'}] = {q_reject, '_', 'S'};
    }

    void run() {
        while (state != q_accept && state != q_reject) {
            int symbol = tape[head];
            auto transition = transitionTable[{state, symbol}];
            state = get<0>(transition);
            tape[head] = get<1>(transition);

            if (get<2>(transition) == 'R') {
                head++;
                if (head == tape.size()) tape.push_back('_'); // Extend tape if necessary
            } else if (get<2>(transition) == 'L') {
                head = max(0, head - 1);
            }
        }

        if (state == q_accept) {
            cout << "Output: ";
            for (int i = 0; i < tape.size(); ++i) {
                if (tape[i] == 1) {
                    cout << '1';
                }
            }
            cout << endl;
        } else {
            cout << "Multiplication rejected.\n";
        }
    }
};

int main() {
    // Sample input: 0 1 1 1 1 c 1 1 1 1 1 0
    vector<int> input = {0, 1, 1, 1, 1, 'c', 1, 1, 1, 1, 1, 0};
    
    TuringMachine tm(input);
    tm.run();

    return 0;
}
