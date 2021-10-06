#ifndef SPEUREN_MET_KRUL_ASSERT_HPP
#define SPEUREN_MET_KRUL_ASSERT_HPP

#include "iostream"

class Assert {
public:
    static int tests;
    static int errors;

    static void Start(const std::string name);

    static void PrintResult();

    template<class T>
    static void Same(T expected, T result) {
        if (expected == result)
            PrintSuccess();
        else
            PrintError("Values are not the Same");
    }

    template<class T>
    static void NotSame(T expected, T result) {
        if (expected != result)
            PrintSuccess();
        else
            PrintError("Values are the Same");
    }

    template<class T>
    static void True(T result) {
        if (result)
            PrintSuccess();
        else
            PrintError("The result is not true");
    }

    template<class T>
    static void False(T result) {
        if (!result)
            PrintSuccess();
        else
            PrintError("The result is not false");
    }

private:
    static void PrintPrefix(const std::string caller = __builtin_FUNCTION());

    static void PrintSuccess(const std::string caller = __builtin_FUNCTION());

    static void PrintError(const std::string message, const std::string caller = __builtin_FUNCTION());
};

#endif //SPEUREN_MET_KRUL_ASSERT_HPP
