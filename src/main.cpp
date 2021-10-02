#include "iostream"
#include "HttpClient.hpp"

const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";
const std::string startFile = "start.txt";

int main() {
    try {
        auto httpClient = std::make_unique<HttpClient>(baseUrl);

        std::cout << httpClient->get(startFile);
    } catch (std::exception exception) {
        std::cout << "There was an error";
    }
}