#ifndef SPEUREN_MET_KRUL_STACKTESTS_HPP
#define SPEUREN_MET_KRUL_STACKTESTS_HPP

#include "../src/Stack.hpp"
#include "TestsBase.hpp"

class StackTests : public TestsBase {
public:
    void run() override {
        test_pop();
        test_peek();
    }

    static void test_pop() {
        Stack stack;

        Assert::same(empty, stack.pop());

        std::string result = "example";

        stack.push(result);

        Assert::same(result, stack.pop());
        Assert::same(empty, stack.peek());
    }

    static void test_peek() {
        Stack stack;

        Assert::same(empty, stack.peek());

        std::string result = "example";

        stack.push(result);

        Assert::same(result, stack.peek());
    }
};


#endif //SPEUREN_MET_KRUL_TESTSBASE_HPP
