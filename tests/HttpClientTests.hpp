#ifndef SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP

#include "TestsBase.hpp"
#include "../src/HttpClient.hpp"

class HttpClientTests : public TestsBase {
    void run() override {
        test_success();
        test_not_found();
    }

    static void test_success() {
        HttpClient httpClient = HttpClient("https://httpstat.us/");

        std::string result;
        auto success = httpClient.get("200", &result);

        Assert::True(success);
        Assert::Same(std::string("200 OK"), result);
    }

    static void test_not_found() {
        HttpClient httpClient = HttpClient("https://httpstat.us/");

        std::string result;
        auto success = httpClient.get("404", &result);

        Assert::False(success);
    }
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
