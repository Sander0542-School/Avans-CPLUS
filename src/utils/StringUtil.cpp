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
    std::string result;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (isalpha(str[i]))
        {
            if ((tolower(str[i]) - 'a') < size + 1)
                result.append(1, str[i] + size);
            else
                result.append(1, str[i] - size);
        }
        else
        {
            result.append(1, str[i]);
        }
    }
    return result;
}
