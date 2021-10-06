#include "iostream"
#include "HttpClient.hpp"
#include "Interpreter.hpp"

const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";
const std::string startFile = "start.txt";

int main() {
    try
    {
        HttpClient httpClient = {baseUrl};
        Interpreter interpreter;

        std::string result = startFile;
        bool isEnd;

        do
        {
            std::cout << "Loading contents from " << baseUrl << result << "\n";
            std::string contents;
            bool success = httpClient.get(result, &contents);

            if (!success)
            {
                std::cout << "Could not load file.\n";
                return 0;
            }

            isEnd = interpreter.execute(contents, &result);
        } while (!isEnd);

        std::cout << "The secret messages is \"" << result << "\".\n";
    }
    catch (...)
    {
        std::cout << "There was an error";
        throw;
    }
}