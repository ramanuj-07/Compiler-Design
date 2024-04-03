from pyformlang.finite_automaton import NondeterministicFiniteAutomaton, State, Symbol
import matplotlib as mt

def nfa_from_regex(regex):
    nfa = NondeterministicFiniteAutomaton()

    start_state = State(0)
    accepting_state = State(1)

    nfa.add_start_state(start_state)
    nfa.add_final_state(accepting_state)

    current_state = start_state

    for char in regex:
        if char.isalpha():
            next_state = State(len(nfa.states))
            nfa.add_transition(current_state, Symbol(char), next_state)
            current_state = next_state

    nfa.add_transition(current_state, Symbol(""), accepting_state)

    return nfa

# Get user input for a regular expression
regex_str = input("Enter a regular expression: ")

# Create an NFA from the regular expression
nfa = nfa_from_regex(regex_str)
# Display the NFA
print("\nGenerated NFA:")
print(nfa)
mt.plot(nfa)