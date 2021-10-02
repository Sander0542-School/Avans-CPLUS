#include "iostream"
#include "HttpClient.hpp"

const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";

int main() {
    auto httpClient = std::make_unique<HttpClient>(baseUrl);

    std::cout << httpClient->Get("start.txt");
}