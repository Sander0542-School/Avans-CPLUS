#include "Stack.hpp"

Stack::Stack() {
    _items = new std::vector<std::string>();
}

Stack::~Stack() {
    delete _items;
}

void Stack::push(const std::string& value) {
    _items->push_back(value);
}

void Stack::push(const int value) {
    _items->push_back(std::to_string(value));
}

std::string Stack::pop() noexcept {
    if (_items->size() > 0)
    {
        auto value = _items->back();
        _items->pop_back();
        return value;
    }

    return "";
}

std::string Stack::peek() const noexcept {
    if (_items->size() > 0)
    {
        return _items->back();
    }

    return "";
}

void Stack::clear() noexcept {
    _items->clear();
}
