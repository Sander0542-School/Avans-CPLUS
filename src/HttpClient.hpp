#ifndef SPEUREN_MET_KRUL_HTTPCLIENT_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENT_HPP

#include <xstring>
#include "curl/curl.h"

class HttpClient {
public:
    HttpClient(const std::string baseUrl);

    ~HttpClient();

    std::string Get(const std::string) const;

private:
    const std::string baseUrl;
    CURL* curl;
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENT_HPP
