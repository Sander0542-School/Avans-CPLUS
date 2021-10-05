#ifndef SPEUREN_MET_KRUL_HTTPCLIENT_HPP
#define SPEUREN_MET_KRUL_HTTPCLIENT_HPP

#include <string>
#include "curl/curl.h"

class HttpClient {
public:
    HttpClient(const std::string baseUrl);

    ~HttpClient();

    HttpClient(const HttpClient& httpClient) = delete;

    HttpClient(HttpClient&& httpClient) = delete;

    HttpClient& operator=(const HttpClient& httpClient) = delete;

    HttpClient& operator=(HttpClient&& httpClient) = delete;

    bool get(const std::string file, std::string* contents) const;

private:
    const std::string baseUrl;
    CURL* curl;
};


#endif //SPEUREN_MET_KRUL_HTTPCLIENT_HPP
