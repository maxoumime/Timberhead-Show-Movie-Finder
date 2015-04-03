#include "APIServer.h"
#include "Finder.h"

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

APIServer::~APIServer() {
}

string APIServer::fetch(string path, bool withKey){


    if(withKey)
        return Finder::get(this->apiUrl+this->apiKey+"/"+path);
    else return Finder::get(this->apiUrl+path);

}