#include "StringUtil.hpp"

std::vector<std::string>* StringUtil::split(std::string string, std::string seperator) {
    std::stringstream stringstream(string);
    std::string piece;
    auto pieces = new std::vector<std::string>;

    while (std::getline(stringstream, piece))
    {
        pieces->push_back(piece);
    }

    return pieces;
}

bool StringUtil::starts_with(std::string string, std::string begin) {
    return string.rfind(begin, 0) == 0;
}

std::string StringUtil::reverse(std::string str) {
    if (str.empty()) return "";

    return str.back() + reverse(str.substr(0, str.length() - 1));
}

std::string StringUtil::rotate(std::string str, int size) {
    int z = str.length(), i = 0;
    for (i = 0; i <= (z); i++)
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
    return str;
}
