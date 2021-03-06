#include <chrono>
#include <iostream>
#include "HttpClient.hpp"
#include "Interpreter.hpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    const std::string baseUrl = "https://www.swiftcoder.nl/cplus/";

    try
    {
        HttpClient httpClient;
        Interpreter interpreter;

        std::string result = "start.txt";
        bool isEnd;

        do
        {
            std::cout << "Loading contents from " << baseUrl << result << std::endl;
            std::string contents;
            bool success = httpClient.get(baseUrl + result, &contents);

            if (!success)
            {
                std::cout << "Could not load file" << std::endl;
                return 1;
            }

            isEnd = interpreter.execute(contents, result);
        } while (!isEnd);

        std::cout << "The secret messages is \"" << result << "\"." << std::endl;
    }
    catch (const SyntaxException& ex)
    {
        std::cerr << "Syntax error: " << ex.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "There was an error" << std::endl;
        return 1;
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "Program duration = " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << "[ms]" << std::endl;
}