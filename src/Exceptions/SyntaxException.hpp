#ifndef SPEUREN_MET_KRUL_SYNTAXEXCEPTION_HPP
#define SPEUREN_MET_KRUL_SYNTAXEXCEPTION_HPP

#include <stdexcept>

struct SyntaxException : public std::runtime_error {
public:
    explicit SyntaxException(char const* message) noexcept;

    virtual char const* what() const noexcept;
};

#endif //SPEUREN_MET_KRUL_SYNTAXEXCEPTION_HPP
