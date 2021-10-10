#ifndef SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP
#define SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP

#include "map"
#include "TestsBase.hpp"
#include "../src/HttpClient.hpp"
#include "../src/Interpreter.hpp"

class InterpreterTests : public TestsBase {
public:
    static void run();

    static void test_files();
};

#endif //SPEUREN_MET_KRUL_INTERPRETERTESTS_HPP