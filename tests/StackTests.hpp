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

        Assert::Same(empty, stack.pop());

        std::string result = "example";

        stack.push(result);

        Assert::Same(result, stack.pop());
        Assert::Same(empty, stack.peek());
    }

    static void test_peek() {
        Stack stack;

        Assert::Same(empty, stack.peek());

        std::string result = "example";

        stack.push(result);

        Assert::Same(result, stack.peek());
    }
};


#endif //SPEUREN_MET_KRUL_TESTSBASE_HPP
