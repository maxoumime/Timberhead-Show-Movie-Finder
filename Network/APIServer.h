#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

class APIServer {

public:
    APIServer(void);
    APIServer(std::string, std::string, std::string);
    ~APIServer(void);
    std::string fetch(std::string, bool);

private:
    std::string name;        // thetvdb
    std::string apiUrl;      //http://thetvdb.com/api/GetSeries.php?seriesname=sherlock
    std::string apiKey;      //Clef de l'api
};




