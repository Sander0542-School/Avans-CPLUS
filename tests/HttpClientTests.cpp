#include "HttpClientTests.hpp"

void HttpClientTests::run() {
    test_success();
    test_not_found();
}

void HttpClientTests::test_success() {
    Assert::Start("Http Client Success");
    std::unique_ptr<CURL, void (*)(CURL*)> curl{curl_easy_init(), &curl_easy_cleanup};

    std::string result;
    auto success = HttpClient::get(curl.get(), "https://httpstat.us/200", &result);

    Assert::True(success);
    Assert::Same(std::string("200 OK"), result);
}

void HttpClientTests::test_not_found() {
    Assert::Start("Http Client Not Found");
    std::unique_ptr<CURL, void (*)(CURL*)> curl{curl_easy_init(), &curl_easy_cleanup};

    std::string result;
    auto success = HttpClient::get(curl.get(), "https://httpstat.us/404", &result);

    Assert::False(success);
}