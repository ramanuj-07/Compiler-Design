#include <stdio.h>
#include <stdbool.h>

// Number of states in the NFA
#define NUM_STATES 3

// Function to check if the string is accepted by the NFA
bool isAccepted(const char *input) {
    int currentState = 0;

    // Loop through the input string
    while (*input != '\0') {
        char symbol = *input;

        // Transition based on the current state and input symbol
        switch (currentState) {
            case 0:
                if (symbol == '0') {
                    currentState = 1;
                }
                break;
            case 1:
                if (symbol == '1') {
                    currentState = 2;
                } else if (symbol == '0') {
                    currentState = 1;
                }
                break;
            case 2:
                // Accepting state
                break;
        }

        // Move to the next input symbol
        input++;
    }

    // Check if the final state is the accepting state
    return currentState == 2;
}

int main() {
    // Test the NFA with some input strings
    const char *testStrings[] = {"0101", "001", "1001", "1010101", "011"};

    for (int i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); i++) {
        if (isAccepted(testStrings[i])) {
            printf("\"%s\" is accepted by the NFA.\n", testStrings[i]);
        } else {
            printf("\"%s\" is not accepted by the NFA.\n", testStrings[i]);
        }
    }

    return 0;
}
