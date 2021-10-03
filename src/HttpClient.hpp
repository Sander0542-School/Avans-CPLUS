#ifndef SPEUREN_MET_KRUL_HTTPCLIENT_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENT_HPP

#include <xstring>
#include "curl/curl.h"

class HttpClient {
public:
    HttpClient(const std::string baseUrl);

    ~HttpClient();

    bool get(const std::string file, std::string* contents) const;

private:
    const std::string baseUrl;
    CURL* curl;
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENT_HPP
