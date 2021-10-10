#ifndef SPEUREN_MET_KRUL_HTTPCLIENT_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENT_HPP

#include <memory>
#include <string>
#include "curl/curl.h"

class HttpClient {
public:
    static bool get(CURL* curl, const std::string& url, std::string* contents);
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENT_HPP
