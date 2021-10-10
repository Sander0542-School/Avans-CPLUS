#include "StackTests.hpp"

void StackTests::run() {
    test_peek();
    test_pop();
}

void StackTests::test_pop() {
    Assert::Start("Stack Pop");
    Stack stack;

    Assert::Same(empty, stack.pop());

    std::string result = "example";

    stack.push(result);

    Assert::Same(result, stack.pop());
    Assert::Same(empty, stack.peek());
}

void StackTests::test_peek() {
    Assert::Start("Stack Peek");
    Stack stack;

    Assert::Same(empty, stack.peek());

    std::string result = "example";

    stack.push(result);

    Assert::Same(result, stack.peek());
}