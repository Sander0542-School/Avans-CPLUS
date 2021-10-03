#include "Stack.hpp"
#include <iostream>

Stack::Stack() {
    items = new std::vector<std::string>();
}

void Stack::push(const std::string value) {
    std::cout << "push " << value << "\n";
    items->push_back(value);
}

void Stack::push(const int value) {
    std::cout << "push " << value << "\n";
    items->push_back(std::to_string(value));
}

std::string Stack::pop() noexcept {
    if (items->size() > 0) {
        auto value = items->back();
        items->pop_back();
        std::cout << "pop " << value << "\n";
        return value;
    }

    return "";
}

std::string Stack::peek() const noexcept {
    if (items->size() > 0) {
        std::cout << "peek " << items->back() << "\n";
        return items->back();
    }

    return "";
}

void Stack::clear() noexcept {
    items->clear();
}
