#ifndef SPEUREN_MET_KRUL_ASSERT_HPP
#define SPEUREN_MET_KRUL_ASSERT_HPP

#include "iostream"

class Assert {
public:
    template<class T>
    static void same(T expected, T result) {
        if (expected != result)
        {
            throw std::runtime_error("Values are not the same");
        }
    }

    template<class T>
    static void not_same(T expected, T result) {
        if (expected == result)
        {
            throw std::runtime_error("Values are the same");
        }
    }
};


#endif //SPEUREN_MET_KRUL_ASSERT_HPP
