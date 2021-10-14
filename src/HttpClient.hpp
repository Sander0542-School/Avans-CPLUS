#ifndef SPEUREN_MET_KRUL_HTTPCLIENT_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENT_HPP

#include <memory>
#include <string>
#include "curl/curl.h"

class HttpClient {
public:
    HttpClient();

    bool get(const std::string& url, std::string* contents);

private:
    std::unique_ptr<CURL, void (*)(CURL*)> _curl;
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENT_HPP
