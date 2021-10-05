#ifndef SPEUREN_MET_KRUL_STRINGUTIL_HPP
#define SPEUREN_MET_KRUL_STRINGUTIL_HPP

#include <sstream>
#include <string>
#include <vector>

class StringUtil {
public:
    static std::vector<std::string>* split(std::string string);

    static bool starts_with(std::string string, std::string begin);

    static std::string reverse(std::string str);

    static std::string rotate(std::string str, int size);
};


#endif //SPEUREN_MET_KRUL_STRINGUTIL_HPP
