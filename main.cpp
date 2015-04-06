#include <iostream>
#include <stdio.h>
#include <functional>
#include <future>
#include "Network/APIServer.h"
#include "Analyse/ParserIMDB.h"
#include "Analyse/ParserTVDB.h"
#include "Thread/Search.h"

#include <windows.h>

using namespace std;

int main(int argc, char **argv) {

    string serie;
    cout << "Entrez le nom de la série recherchée" << endl;
    getline(cin, serie);
    
    //Remplacement des ' ' par '+'
    for(string::iterator it = serie.begin(); it != serie.end(); ++it)
        if(*it == ' ')
            *it = '+';
              
    
    promise<Show> promiseShow;
    future<Show> futureShow = promiseShow.get_future();
    
    Search::getShow(serie, &promiseShow);
        
    Show show = futureShow.get();
    
    cout << show.toString() << endl;
    
    return 0;
}