#include "Parser.h"
#include "../include/tinyxml2/tinyxml2.h"

//Méthode globale permettant la récupération des resultats d'une recherche
Show Parser::getResults(string words)
{
    //Liste des séries correspondant à la recherche
    tinyxml2::XMLDocument doc;
    doc.Parse((const char*)words.c_str());

    tinyxml2::XMLElement *elem = doc.FirstChildElement()->ToElement();
    
    Show show;
    
    show.setTitle( elem->Attribute("title") );
    show.setPlot( elem->Attribute("plot") );
    show.setGenre( elem->Attribute("genre") );
    show.setYear( elem->Attribute("year") );
    show.setUrlPicture( elem->Attribute("poster") );
    
    string actors = elem->Attribute("casting");
    
//    show.setCasting(  );
    if(elem->Attribute("rating") != "N/A"){
        show.setRating(atoi(elem->Attribute("rating")));
    }
    
    
    return show;

}

Parser::Parser() {

}

Parser::~Parser() {
}