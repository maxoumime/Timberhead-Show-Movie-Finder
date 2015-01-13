#pragma once

#include <string>

using namespace std;

class APIServer {

public:
    APIServer(void);
    ~APIServer(void);

private:
    string name;        // thetvdb
    string apiUrl;      //http://thetvdb.com/api/GetSeries.php?seriesname=sherlock
    string apiKey;      //Clef de l'api
};




