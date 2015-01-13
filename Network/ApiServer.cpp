#include "APIServer.h"
#include <curl/curl.h>

APIServer::APIServer() {
    this->name = "TheTVDB";
    this->apiKey = "BC89D32369F3103D";
    this->apiUrl = "http://thetvdb.com/api/";
}

APIServer::APIServer(string _name, string _apiKey, string _apiUrl) {
    this->name = _name;
    this->apiKey = _apiKey;
    this->apiUrl = _apiUrl;
}

string APIServer::fetch(string url) {

    CURL *curl;
    CURLcode rescode;

    string urlToCall = this->apiUrl+url;

    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, urlToCall.c_str());
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* Perform the request, res will get the return code */
        rescode = curl_easy_perform(curl);
        /* Check for errors */
        if(rescode != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(rescode));
        else if(CURLE_OK == rescode) {
            char *ct;
            /* ask for the content-type */
            rescode = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == rescode) && ct)
                printf("We received Content-Type: %s\n", ct);
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    return 0;
}

APIServer::~APIServer() {
}