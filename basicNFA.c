#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

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

// Function to validate if the input string consists only of '0' and '1' and ends with "01"
bool isValidInput(const char *input) {
    regex_t regex;
    int ret;

    // Compile the regular expression
    ret = regcomp(&regex, "^[01]*01$", REG_EXTENDED);

    if (ret != 0) {
        fprintf(stderr, "Failed to compile regular expression\n");
        return false;
    }

    // Test the input against the regular expression
    ret = regexec(&regex, input, 0, NULL, 0);

    // Free the compiled regular expression
    regfree(&regex);

    return ret == 0;  // Return true if the input matches the regular expression
}

int main() {
    char userString[100]; // Assuming a maximum input size of 100 characters

    // Prompt the user for input
    printf("Enter a string ending with 01: ");
    scanf("%s", userString);

    // Validate input and test the NFA
    if (isValidInput(userString) && isAccepted(userString)) {
        printf("\"%s\" is accepted by the NFA.\n", userString);
    } else {
        printf("\"%s\" is not valid or not accepted by the NFA.\n", userString);
    }

    return 0;
}
