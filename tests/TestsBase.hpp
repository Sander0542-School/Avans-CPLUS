#ifndef SPEUREN_MET_KRUL_TESTSBASE_HPP
#define SPEUREN_MET_KRUL_TESTSBASE_HPP

#include "Assert.hpp"

class TestsBase {
public:
    static const std::string empty;

    virtual void run() = 0;
};


#endif //SPEUREN_MET_KRUL_TESTSBASE_HPP
