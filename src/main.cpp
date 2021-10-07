#include "chrono"
#include "iostream"
#include "HttpClient.hpp"
#include "Interpreter.hpp"

const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";
const std::string startFile = "start.txt";

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    try
    {
        HttpClient httpClient = {baseUrl};
        Interpreter interpreter;

        std::string result = startFile;
        bool isEnd;

        do
        {
            std::cout << "Loading contents from " << baseUrl << result << std::endl;
            std::string contents;
            bool success = httpClient.get(result, &contents);

            if (!success)
            {
                std::cout << "Could not load file" << std::endl;
                return 0;
            }

            isEnd = interpreter.execute(contents, result);
        } while (!isEnd);

        std::cout << "The secret messages is \"" << result << "\"." << std::endl;
    }
    catch (...)
    {
        std::cerr << "There was an error" << std::endl;
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "Program duration = " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << "[ms]" << std::endl;
}