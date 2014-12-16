#pragma once

class APIServer {

public:
    APIServer(void);
    ~APIServer(void);

private:
    String name;        // thetvdb
    String apiUrl;      //http://thetvdb.com/api/GetSeries.php?seriesname=sherlock
    String apiKey;      //Clef de l'api
};




