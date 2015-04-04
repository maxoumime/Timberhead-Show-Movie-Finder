#include "APIServer.h"
#include "Finder.h"

APIServer::APIServer() {}

APIServer::APIServer(string _name, string _apiUrl, string _apiKey) {
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