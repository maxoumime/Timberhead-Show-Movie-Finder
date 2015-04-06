#include "Search.h"

Search::Search() {
}

Search::~Search() {
}

void Search::getShow(string serie, promise<Show>* promise){
    
    ParserIMDB parserIMDB;
    ParserTVDB parserTVDB;
        
    APIServer apiIMDB("IMDB", "http://omdbapi.com/?r=xml&t=", (Parser*)&parserIMDB);
    APIServer apiTVDB("TheTVDB", "http://thetvdb.com/api/GetSeries.php?seriesname=", (Parser*)&parserTVDB);
        
    std::promise<Show> promShowIMDB;
    std::promise<Show> promShowTVDB;
    
    future<Show> futIMDB = promShowIMDB.get_future();
    future<Show> futTVDB = promShowTVDB.get_future();

    
    //Lancer un thread ici pour chacun
    apiIMDB.findShowThread(serie, &promShowIMDB);
    apiTVDB.findShowThread(serie, &promShowTVDB);
    
    Show showIMDB = futIMDB.get();
    Show showTVDB = futTVDB.get();
    
    Show show = Show::mergeShows(showIMDB, showTVDB);
    
    promise->set_value(show);
}