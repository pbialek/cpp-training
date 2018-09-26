#include<iostream>
#include<stack>

std::stack<char> Stack;

template <typename T>
void insert_bottom(T input) {
    if(Stack.empty()) {
        Stack.push(input);
    } else {
        T tmp = Stack.top();
        Stack.pop();
        insert_bottom(input);
        Stack.push(tmp);
    }
}

template <typename T>
void stack_reverser() {
    if(not Stack.empty()) {
        T x = Stack.top();
        Stack.pop();
        stack_reverser<T>();

        insert_bottom(x);
    }
}

int main(void) {

    for(auto& item : {'a','b','c','d'}) {
        Stack.push(item);
    }

    stack_reverser<char>();

    std::cout << "Reversed stack:" << std::endl;
    while(not Stack.empty()) {
        std::cout << Stack.top() << std::endl;
        Stack.pop();
    }
};