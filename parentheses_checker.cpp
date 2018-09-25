/*  Given an expression string exp , write a program to examine whether the pairs 
    and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
    For example, the program should print true for
    exp = “[()]{}{[()()]()}” and false for exp = “[(])”
*/

#include<iostream>
#include<stack>
#include<string>

bool parentheses(std::string input) {
    std::stack<char> brackets_stack;
    for(char current_bracket : input) {
        if (current_bracket == '(' || current_bracket == '[' || current_bracket == '{') {
            brackets_stack.push(current_bracket);
            continue;
        } else if(brackets_stack.empty()) {
            return false;
        }
        else if (brackets_stack.top() == '(' && current_bracket == ')' ||
                 brackets_stack.top() == '[' && current_bracket == ']' ||
                 brackets_stack.top() == '{' && current_bracket == '}') {
            brackets_stack.pop();
        }
    }

    return brackets_stack.empty();
}

void test_parentheses(std::string input, bool is_correct = true) {
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