#ifndef SPEUREN_MET_KRUL_STACKTESTS_HPP
#define SPEUREN_MET_KRUL_STACKTESTS_HPP

#include "../src/Stack.hpp"
#include "TestsBase.hpp"

class StackTests : public TestsBase {
public:
    static void run();

    static void test_pop();

    static void test_peek();
};


#endif //SPEUREN_MET_KRUL_STACKTESTS_HPP
