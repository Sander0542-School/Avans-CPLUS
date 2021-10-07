#include "StringUtil.hpp"

std::vector<std::string> StringUtil::split(const std::string &string) {
    std::stringstream stringstream(string);
    std::string piece;
    std::vector<std::string> pieces;

    while (std::getline(stringstream, piece)) {
        pieces.push_back(piece);
    }

    return pieces;
}

bool StringUtil::starts_with(const std::string &string, const std::string &begin) {
    return string.rfind(begin, 0) == 0;
}

void StringUtil::reverse(std::string& str) {
    std::reverse(str.begin(), str.end());
}

void StringUtil::rotate(std::string &str, int size) {
    int z = str.length();
    for (int i = 0; i <= (z); i++) {
        if (str[i] < 91 && str[i] > 64) {
            if (str[i] < 78)
                str[i] = str[i] + size;
            else
                str[i] = str[i] - size;
        }
        if (str[i] < 123 && str[i] > 96) {
            if (str[i] < 110)
                str[i] = str[i] + size;
            else
                str[i] = str[i] - size;
        }
    }
}
