#include "APIServer.h"

APIServer::APIServer() {}

APIServer::APIServer(string _name, string _apiUrl, Parser* _parser) {
    this->name = _name;
    this->apiUrl = _apiUrl;
    this->parser = _parser;
}

APIServer::~APIServer() {
}

void APIServer::findShow(APIServer* apiServer, string nom, promise<Show>* promise){
    
    string xml = Finder::get(apiServer->apiUrl+nom);
            
    Show showResult = apiServer->parser->parseShow(xml);
    promise->set_value(showResult);
    
}

void APIServer::findShowThread(string nom, promise<Show>* promise){
   
    std::thread threadFind(&APIServer::findShow, this, nom, promise);
    threadFind.detach();
}