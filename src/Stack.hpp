#ifndef SPEUREN_MET_KRUL_STACK_HPP
#define SPEUREN_MET_KRUL_STACK_HPP

#include "string"
#include "vector"

class Stack {
public:
    Stack();

    ~Stack();

    Stack(const Stack& stack) {
        _items = new std::vector<std::string>{stack._items->begin(), stack._items->end()};
    }

    Stack& operator=(const Stack& stack) {
        Stack tmp{stack};
        std::swap(*this, tmp);
        return *this;
    }

    Stack(Stack&& stack) noexcept: _items{stack._items} {
        stack._items = nullptr;
    }

    Stack& operator=(Stack&& stack) noexcept {
        std::swap(_items, stack._items);
        return *this;
    }

    void push(const std::string value);

    void push(const int value);

    std::string pop() noexcept;

    std::string peek() const noexcept;

    void clear() noexcept;

private:
    std::vector<std::string>* _items;
};


#endif //SPEUREN_MET_KRUL_STACK_HPP
