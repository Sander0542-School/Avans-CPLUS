#include <iostream>
#include <vector>
#include "StackTests.hpp"

int main() {
    auto tests = new std::vector<TestsBase*>{
            new StackTests,
    };

    for (const auto& test: *tests)
        test->run();

    std::cout << "All tests ran successfully" << std::endl;
}