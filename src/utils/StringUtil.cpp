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

void StringUtil::reverse(std::string& str) {
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);
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
