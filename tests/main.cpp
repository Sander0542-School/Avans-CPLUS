#include "HttpClientTests.hpp"
#include "InterpreterTests.hpp"
#include "StackTests.hpp"

int main() {
    HttpClientTests::run();
    StackTests::run();
    InterpreterTests::run();

    Assert::PrintResult();
}