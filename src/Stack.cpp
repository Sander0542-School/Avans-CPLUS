#include "Stack.hpp"

Stack::Stack() {
    items = new std::vector<std::string>();
}

Stack::~Stack() {
    delete items;
}

void Stack::push(const std::string value) {
    items->push_back(value);
}

void Stack::push(const int value) {
    items->push_back(std::to_string(value));
}

std::string Stack::pop() noexcept {
    if (items->size() > 0)
    {
        auto value = items->back();
        items->pop_back();
        return value;
    }

    return "";
}

std::string Stack::peek() const noexcept {
    if (items->size() > 0)
    {
        return items->back();
    }

    return "";
}

void Stack::clear() noexcept {
    items->clear();
}
