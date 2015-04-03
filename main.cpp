#include <iostream>
#include <stdio.h>
#include "Network/APIServer.h"
#include "Analyse/Parser.h"

using namespace std;

int main() {

    APIServer apiIMDB = APIServer("IMDB", "", "http://omdbapi.com/");
    
    string serie;
    cout << "Entrez le nom de la série recherchée" << endl;
    cin >> serie;
    
    string result = apiIMDB.fetch("?t="+serie+"&r=xml", false);
        
    Show show = Parser::getResults(result);
    
    cout << "Titre: " << show.getTitle() << endl;
    cout << "Résumé: " << show.getPlot() << endl;
    cout << "Genre: " << show.getGenre() << endl;
    cout << "Year: " << show.getYear() << endl;
    
    return 0;
}