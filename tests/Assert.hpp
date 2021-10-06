#ifndef SPEUREN_MET_KRUL_ASSERT_HPP
#define SPEUREN_MET_KRUL_ASSERT_HPP

#include "iostream"

class Assert {
public:
    template<class T>
    static void Same(T expected, T result) {
        if (expected != result)
        {
            throw std::runtime_error("Values are not the Same");
        }
    }

    template<class T>
    static void NotSame(T expected, T result) {
        if (expected == result)
        {
            throw std::runtime_error("Values are the Same");
        }
    }

    template<class T>
    static void True(T result) {
        if (!result)
        {
            throw std::runtime_error("The result is not true");
        }
    }

    template<class T>
    static void False(T result) {
        if (result)
        {
            throw std::runtime_error("The result is not false");
        }
    }
};


#endif //SPEUREN_MET_KRUL_ASSERT_HPP
