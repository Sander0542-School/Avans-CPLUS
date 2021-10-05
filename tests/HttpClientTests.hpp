#ifndef SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP

#include "TestsBase.hpp"

class HttpClientTests : public TestsBase {
    void run() override {
        test_success();
        test_not_found();
    }

    static void test_success() {

    }

    static void test_not_found() {

    }
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
