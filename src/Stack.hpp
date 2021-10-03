#ifndef SPEUREN_MET_KRUL_STACK_HPP
#define SPEUREN_MET_KRUL_STACK_HPP

#include "string"
#include "vector"

class Stack {
public:
    Stack();

    void push(const std::string value);

    void push(const int value);

    std::string pop() noexcept;

    std::string peek() const noexcept;

    void clear() noexcept;

private:
    std::vector<std::string>* items;
};


#endif //SPEUREN_MET_KRUL_STACK_HPP
