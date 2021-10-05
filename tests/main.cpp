#include <iostream>
#include <vector>
#include "HttpClientTests.hpp"
#include "StackTests.hpp"

int main() {
    auto tests = new std::vector<TestsBase*>{
            new HttpClientTests,
            new StackTests,
    };

    for (const auto& test: *tests)
        test->run();

    std::cout << "All tests ran successfully" << std::endl;
}