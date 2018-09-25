/*  Given an expression string exp , write a program to examine whether the pairs 
    and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
    For example, the program should print true for
    exp = “[()]{}{[()()]()}” and false for exp = “[(])”
*/

#include<iostream>
#include<stack>

bool parentheses(char* input) {
    std::stack<char> brackets_stack;
    for(char* it = input; *it; ++it) {
        if (*it == '(' || *it == '[' || *it == '{') {
            brackets_stack.push(*it);
            continue;
        } else if(brackets_stack.empty()) {
            return false;
        }
        else if (brackets_stack.top() == '(' && *it == ')' ||
                 brackets_stack.top() == '[' && *it == ']' ||
                 brackets_stack.top() == '{' && *it == '}') {
            brackets_stack.pop();
        }
    }

    return brackets_stack.empty();
}

void test_parentheses(char* input, bool is_correct = true) {
    std::cout << "TEST ";
    if (parentheses(input) == is_correct) {
        std::cout << "[ PASSED ]" << std::endl;
    } else {
        std::cout << "[ FAILED ]" << std::endl;
    }
}

int main(void) {
    test_parentheses("", true);
    test_parentheses("()", true);
    test_parentheses("[()]", true);
    test_parentheses("{[()]}", true);
    test_parentheses("{[()]()[{}][]}", true);

    test_parentheses("(", false);
    test_parentheses("}", false);
    test_parentheses("(]", false);
    test_parentheses("[(])", false);
    test_parentheses("{[()]()[{}]}}", false);
}