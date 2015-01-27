#include <iostream>

#include "Network/APIServer.h"

using namespace std;

int main() {

    APIServer apiTheTVDB = APIServer("TheTVDB","BC89D32369F3103D","http://thetvdb.com/api/");

    string resultat = apiTheTVDB.fetch("GetSeries.php?seriesname=Sherlock", false);

    printf("%s\n", resultat.c_str());
    printf("\n\n---------------------\n\n");

    resultat = apiTheTVDB.fetch("languages.xml", true);

    printf("%s\n", resultat.c_str());
    printf("\n\n---------------------\n\n");

    APIServer apiIMDB = APIServer("IMDB", "", "http://omdbapi.com/");
    resultat = apiIMDB.fetch("?t=Sherlock&r=xml", false);

    printf("%s\n", resultat.c_str());

    return 0;
}