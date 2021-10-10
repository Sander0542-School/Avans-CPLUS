#include "HttpClientTests.hpp"

void HttpClientTests::run() {
    test_success();
    test_not_found();
}

void HttpClientTests::test_success() {
    Assert::Start("Http Client Success");
    HttpClient httpClient = HttpClient("https://httpstat.us/");

    std::string result;
    auto success = httpClient.get("200", &result);

    Assert::True(success);
    Assert::Same(std::string("200 OK"), result);
}

void HttpClientTests::test_not_found() {
    Assert::Start("Http Client Not Found");
    HttpClient httpClient = HttpClient("https://httpstat.us/");

    std::string result;
    auto success = httpClient.get("404", &result);

    Assert::False(success);
}