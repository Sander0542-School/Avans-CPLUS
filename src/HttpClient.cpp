#include "HttpClient.hpp"

size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*) contents, newLength);
    }
    catch (std::bad_alloc& e) {
        //handle memory problem
        return 0;
    }
    return newLength;
}

HttpClient::HttpClient(const std::string baseUrl) : baseUrl{baseUrl} {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
}

HttpClient::~HttpClient() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

std::string HttpClient::Get(const std::string file) const {
    std::string result = "";
    std::string url = baseUrl + file;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }

    return result;
}