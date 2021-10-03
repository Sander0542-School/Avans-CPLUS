#include "iostream"
#include "HttpClient.hpp"
#include "Interpreter.hpp"

const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";
const std::string startFile = "start.txt";

int main() {
    try
    {
        auto httpClient = std::make_unique<HttpClient>(baseUrl);
        auto interpreter = std::make_unique<Interpreter>();

        std::string result = startFile;
        bool isEnd;

        do
        {
            std::cout << "Loading contents from " << baseUrl << result << "\n";
            std::string contents = httpClient->get(result);

            isEnd = interpreter->execute(contents, &result);
        } while (!isEnd && result != "");

        std::cout << "The secret messages is \"" << result << "\".\n";
    }
    catch (...)
    {
        std::cout << "There was an error";
        throw;
    }
}