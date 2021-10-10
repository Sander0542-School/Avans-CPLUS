#include "HttpClient.hpp"

size_t CurlWrite_CallbackFunc_StdString(char* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try
    {
        s->append(contents, newLength);
    }
    catch (std::bad_alloc& e)
    {
        //handle memory problem
        return 0;
    }
    return newLength;
}

bool HttpClient::get(CURL* curl, const std::string& url, std::string* contents) {
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, contents);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK)
    {
        return true;
    }

    return false;
}
