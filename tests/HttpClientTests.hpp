#ifndef SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP

#include "TestsBase.hpp"
#include "../src/HttpClient.hpp"

class HttpClientTests : public TestsBase {
    void run() override;

    static void test_success();

    static void test_not_found();
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
