#include "Stack.hpp"

void Stack::push(const std::string& value) {
    _items.push_back(value);
}

std::string Stack::pop() noexcept {
    if (!_items.empty())
    {
        auto value = _items.back();
        _items.pop_back();
        return value;
    }

    return "";
}

std::string Stack::peek() const noexcept {
    if (!_items.empty())
    {
        return _items.back();
    }

    return "";
}

void Stack::clear() noexcept {
    _items.clear();
}
