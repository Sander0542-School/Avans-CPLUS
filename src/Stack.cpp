#include "Stack.hpp"

Stack::Stack() {
    items = new std::vector<std::string>();
}

void Stack::push(const std::string value) {
    items->push_back(value);
}

std::string Stack::pop() noexcept {
    auto value = items->back();
    items->pop_back();
    return value;
}

std::string Stack::peek() const noexcept {
    return items->back();
}
