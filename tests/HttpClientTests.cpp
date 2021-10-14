#include "HttpClientTests.hpp"

void HttpClientTests::run() {
    test_success();
    test_not_found();
}

void HttpClientTests::test_success() {
    Assert::Start("Http Client Success");

    std::string result;
    HttpClient httpClient;
    auto success = httpClient.get("https://httpstat.us/200", &result);

    Assert::True(success);
    Assert::Same(std::string("200 OK"), result);
}

void HttpClientTests::test_not_found() {
    Assert::Start("Http Client Not Found");

    std::string result;
    HttpClient httpClient;
    auto success = httpClient.get("https://httpstat.us/404", &result);

    Assert::False(success);
}