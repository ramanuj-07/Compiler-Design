#include <stdio.h>
#include <stdbool.h>

#define NUM_STATES 2

bool isAccepted(const char *input) {
    int currentState = 0;

    while (*input != '\0') {
        
        char symbol = *input;

        switch (currentState) {
            case 0:
                if (symbol == 'a') {
                    currentState = 1;
                }
                break;
            case 1:
                if (symbol == 'a') {
                    currentState = 0;
                }
                break;
        }

        // Move to the next input symbol
        input++;
    }

    // Check if the final state is the accepting state
    return currentState == 1;
}

int main() {

    const char *testStrings[] = {"a", "aa", "aaa", "aaaa", "aaaaa"};

    for (int i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); i++) {
        if (isAccepted(testStrings[i])) {
            printf("\"%s\" is accepted by the NFA.\n", testStrings[i]);
        } else {
            printf("\"%s\" is not accepted by the NFA.\n", testStrings[i]);
        }
    }

    return 0;
}
