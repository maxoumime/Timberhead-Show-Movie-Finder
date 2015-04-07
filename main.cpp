#include <iostream>
#include <stdio.h>
#include <functional>
#include <future>
#include "Interface/App.h"
#include "Network/APIServer.h"
#include "Analyse/ParserIMDB.h"
#include "Analyse/ParserTVDB.h"
#include "Thread/Search.h"

using namespace std;

int runSearch()
{
    string serie = App::getRequest();

    //Remplacement des ' ' par '+'
    for(string::iterator it = serie.begin(); it != serie.end(); ++it){
        if(*it == ' ')
            *it = '+';
        else if(*it == '\t')
            *it = '+';
    }    
            
    promise<Show> promiseShow;
    future<Show> futureShow = promiseShow.get_future();
    
    Search::getShow(serie, &promiseShow);        
    Show show = futureShow.get();    
    App::displayResult(show);  
    return runSearch();
}

int main(int argc, char **argv) {

    App::initializeHome();
    runSearch();
    
    return 0;
}



