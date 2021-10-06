#include "Assert.hpp"

int Assert::tests = 0;
int Assert::errors = 0;

void Assert::Start(const std::string name) {
    tests++;
    std::cout << std::endl;
    std::cout << "Testing " << name << ": " << std::endl;
}

void Assert::PrintResult() {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Ran " << tests << " tests and found " << errors << " errors." << std::endl;
}

void Assert::PrintPrefix(const std::string caller) {
    std::cout << "    " << caller << ": ";
}

void Assert::PrintError(const std::string message, const std::string caller) {
    errors++;
    PrintPrefix(caller);
    std::cout << "Error (" << message << ")" << std::endl;
}

void Assert::PrintSuccess(const std::string caller) {
    PrintPrefix(caller);
    std::cout << "Success" << std::endl;
}