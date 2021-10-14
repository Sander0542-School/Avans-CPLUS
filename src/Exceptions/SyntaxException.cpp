#include "SyntaxException.hpp"

SyntaxException::SyntaxException(const char* message) noexcept: runtime_error(message) {

}

char const* SyntaxException::what() const noexcept {
    return runtime_error::what();
}
