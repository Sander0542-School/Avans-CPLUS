#ifndef SPEUREN_MET_KRUL_STRINGUTIL_HPP
#define SPEUREN_MET_KRUL_STRINGUTIL_HPP

#include <sstream>
#include <string>
#include <vector>

class StringUtil {
public:
    static std::vector<std::string> split(const std::string string);

    static bool starts_with(const std::string string, const std::string begin);

    static std::string reverse(const std::string str);

    static std::string rotate(std::string str, int size);
};


#endif //SPEUREN_MET_KRUL_STRINGUTIL_HPP
