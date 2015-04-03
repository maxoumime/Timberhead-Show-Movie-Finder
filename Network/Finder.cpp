#include "Finder.h"
#include "curl/curl.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string Finder::get(string url) {

    CURL *curl;
    CURLcode rescode;

    string format, readBuffer;

    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

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
                format = ct;
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
        
//    cout << readBuffer << endl;
    
    return readBuffer;
}