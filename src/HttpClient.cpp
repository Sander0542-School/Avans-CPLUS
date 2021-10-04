#include "HttpClient.hpp"

size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try
    {
        s->append((char*) contents, newLength);
    }
    catch (std::bad_alloc& e)
    {
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
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
}

HttpClient::~HttpClient() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

bool HttpClient::get(const std::string file, std::string* contents) const {
    std::string url = baseUrl + file;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, contents);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK)
        {
            return true;
        }
    }

    return false;
}