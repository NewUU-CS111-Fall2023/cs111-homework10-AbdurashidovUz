#include <iostream>
#include <vector>

using namespace std;

enum State {
    q0, // Initial state
    q1, // Move to the right until 0 is found
    q2, // Move to the right until the end of the first number
    q3, // Move to the right until the separator is found
    q4, // Move to the right until the end of the second number
    q5, // Move to the left until the end of the result
    q_accept, // Accept state
    q_reject // Reject state
};

class TuringMachine {
private:
    vector<char> tape;
    int head;
    State state;

public:
    TuringMachine(const string& input) : tape(input.begin(), input.end()), head(0), state(q0) {}

    void run() {
        while (state != q_accept && state != q_reject) {
            switch (state) {
                case q0:
                    if (tape[head] == '1') {
                        state = q1;
                    } else {
                        state = q_reject;
                    }
                    break;

                case q1:
                    if (tape[head] == '1') {
                        head++;
                    } else if (tape[head] == '0') {
                        state = q2;
                    } else {
                        state = q_reject;
                    }
                    break;

                case q2:
                    if (tape[head] == '1') {
                        head++;
                    } else if (tape[head] == '0') {
                        state = q3;
                    } else {
                        state = q_reject;
                    }
                    break;

                case q3:
                    if (tape[head] == '1') {
                        head++;
                    } else if (tape[head] == '0') {
                        state = q4;
                    } else {
                        state = q_reject;
                    }
                    break;

                case q4:
                    if (tape[head] == '1') {
                        head++;
                    } else if (tape[head] == '0') {
                        state = q5;
                    } else {
                        state = q_reject;
                    }
                    break;

                case q5:
                    if (tape[head] == '1') {
                        head--;
                    } else if (tape[head] == '0') {
                        state = q_accept;
                    } else {
                        state = q_reject;
                    }
                    break;

                default:
                    state = q_reject;
                    break;
            }
        }

        if (state == q_accept) {
            cout << "Addition successful.\n";
        } else {
            cout << "Addition failed.\n";
        }
    }
};

int main() {
    // Example input: "1111101111" (represents 5 + 6)
    string input;
    cout << "Enter the unary representation of two numbers separated by 0: ";
    cin >> input;

    TuringMachine tm(input);
    tm.run();

    return 0;
}
