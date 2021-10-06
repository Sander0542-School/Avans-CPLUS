#ifndef SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP
#define SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP

#include "TestsBase.hpp"
#include "../src/Interpreter.hpp"

class InterpreterTests : public TestsBase {
public:
    void run() override {
        test_files();
    }

    static void test_files() {
        Assert::Start("Interpreter Files");
        Interpreter interpreter;
    }
};

#endif //SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP