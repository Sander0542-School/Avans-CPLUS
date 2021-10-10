#include "StringUtil.hpp"

std::vector<std::string> StringUtil::split(const std::string& string) {
    std::stringstream stringstream(string);
    std::string piece;
    std::vector<std::string> pieces;

    while (std::getline(stringstream, piece))
    {
        pieces.push_back(piece);
    }

    return pieces;
}

bool StringUtil::starts_with(const std::string& string, const std::string& begin) {
    return string.rfind(begin, 0) == 0;
}

bool StringUtil::is_number(const std::string& string) {
    return !string.empty() && std::find_if(string.begin(), string.end(), [](unsigned char c) { return !std::isdigit(c); }) == string.end();
}

void StringUtil::reverse(std::string& str) {
    std::reverse(str.begin(), str.end());
}

void StringUtil::rotate(std::string& str, int size) {
    auto z = str.length();
    for (size_t i = 0; i <= (z); i++)
    {
        if (str[i] < 91 && str[i] > 64)
        {
            if (str[i] < 78)
                str[i] = str[i] + size;
            else
                str[i] = str[i] - size;
        }
        if (str[i] < 123 && str[i] > 96)
        {
            if (str[i] < 110)
                str[i] = str[i] + size;
            else
                str[i] = str[i] - size;
        }
    }
}
