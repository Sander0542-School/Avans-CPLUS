#include "iostream"
#include "../src/Stack.hpp"

int main() {
    Stack stack;
    stack.push("1");

    auto stack2{stack};

    stack2.push("2");

    std::cout << stack.pop() << std::endl;
    std::cout << stack2.pop() << std::endl;
    std::cout << stack2.pop() << std::endl;
}