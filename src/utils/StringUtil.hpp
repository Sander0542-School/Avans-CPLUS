#ifndef SPEUREN_MET_KRUL_STRINGUTIL_HPP
#define SPEUREN_MET_KRUL_STRINGUTIL_HPP

#include <sstream>
#include <string>
#include <vector>

class StringUtil {
public:
    static std::vector<std::string> split(const std::string& string);

    static bool starts_with(const std::string& string, const std::string& begin);

    static void reverse(std::string& str);

    static void rotate(std::string& str, int size);
};


#endif //SPEUREN_MET_KRUL_STRINGUTIL_HPP
