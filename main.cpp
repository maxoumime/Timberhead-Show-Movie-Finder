#include <iostream>
#include <stdio.h>
#include "Network/APIServer.h"
#include "Analyse/ParserIMDB.h"
#include "Analyse/ParserTVDB.h"

using namespace std;

int main() {

    APIServer apiIMDB("IMDB", "http://omdbapi.com/", "");
    
    APIServer apiTVDB("TheTVDB", "http://thetvdb.com/api/", "BC89D32369F3103D");
    
    string serie;
    cout << "Entrez le nom de la série recherchée" << endl;
    getline(cin, serie);
    
    //Remplacement des ' ' par '+'
    for(string::iterator it = serie.begin(); it != serie.end(); ++it)
        if(*it == ' ')
            *it = '+';
        
    //string result = apiIMDB.fetch("?t="+serie+"&r=xml", false);
    string result = apiTVDB.fetch("GetSeries.php?seriesname="+serie, false);
          
    Show show = ParserTVDB::parseShow(result);
    
    cout << show.toString() << endl;
    
    return 0;
}