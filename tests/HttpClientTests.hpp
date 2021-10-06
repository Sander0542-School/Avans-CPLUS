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
        Assert::Start("Http Client Success");
        HttpClient httpClient = HttpClient("https://httpstat.us/");

        std::string result;
        auto success = httpClient.get("200", &result);

        Assert::True(success);
        Assert::Same(std::string("200 OK"), result);
    }

    static void test_not_found() {
        Assert::Start("Http Client Not Found");
        HttpClient httpClient = HttpClient("https://httpstat.us/");

        std::string result;
        auto success = httpClient.get("404", &result);

        Assert::False(success);
    }
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENTTESTS_HPP
