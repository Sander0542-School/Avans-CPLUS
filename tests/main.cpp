#include <vector>
#include "HttpClientTests.hpp"
#include "InterpreterTests.hpp"
#include "StackTests.hpp"

int main() {
    auto tests = new std::vector<TestsBase*>{
            new HttpClientTests,
            new StackTests,
            new InterpreterTests,
    };

    for (const auto& test: *tests)
        test->run();

    Assert::PrintResult();
}