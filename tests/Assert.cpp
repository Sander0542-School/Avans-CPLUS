#include "Assert.hpp"

std::string Assert::current_name;
int Assert::tests = 0;
int Assert::errors = 0;

void Assert::Start(const std::string& name) {
    tests++;
    current_name = name;
    std::cout << std::endl;
    std::cout << "Testing " << name << ": " << std::endl;
}

void Assert::PrintResult() {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Ran " << tests << " tests and found " << errors << " errors." << std::endl;
}

void Assert::PrintError(const std::string& message, const std::string& caller) {
    errors++;
    std::cout << "    " << caller << ": ""Error (" << message << ")" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Testing " << current_name << ": " << std::endl;
    std::cerr << "    " << caller << ": ""Error (" << message << ")" << std::endl;
}

void Assert::PrintSuccess(const std::string& caller) {
    std::cout << "    " << caller << ": ""Success" << std::endl;
}