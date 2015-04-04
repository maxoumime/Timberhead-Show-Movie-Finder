#include "ParserIMDB.h"
#include "../include/tinyxml2/tinyxml2.h"

//Méthode globale permettant la récupération des resultats d'une recherche
Show ParserIMDB::parseShow(string xml)
{        
    Show show;
    
    //Liste des séries correspondant à la recherche
    tinyxml2::XMLDocument doc;
    doc.Parse((const char*)xml.c_str());

    //BALISE <xml>
    tinyxml2::XMLNode * pRootXml = doc.FirstChild();    

    if (pRootXml == nullptr) return show;
    
    //BALISE <root>
    tinyxml2::XMLNode * pRoot = pRootXml->NextSibling();    
    
    //Suivant la réponse positive ou négative, IMDB ne répond pas le <xml>
    tinyxml2::XMLElement* rootResponseElement;
    if(pRootXml->ToElement() != nullptr)
        rootResponseElement = pRootXml->ToElement();
    else rootResponseElement = pRoot->ToElement();
    
    string response = rootResponseElement->Attribute("response");

    if (pRoot == nullptr || response == "False") return show;
    
    //BALISE <movie>
    tinyxml2::XMLElement * eMovie = pRoot->FirstChild()->ToElement();
    
    if(eMovie == nullptr) return show;
    
    string title = eMovie->Attribute("title");
    show.setTitle(title);
    
    string plot = eMovie->Attribute("plot");
    show.setPlot(plot);
    
    string genre = eMovie->Attribute("genre");
    show.setGenre(genre);
    
    string year = eMovie->Attribute("year");
    
    //Comportement étrange, quand '2010-', length devient 7
    //Et quand 2010-2012, length devient 11
    if(year.length() == 7)
        year.resize(4);
    show.setYear(year);
    
    string urlPicture = eMovie->Attribute("poster");
    show.setUrlPicture(urlPicture);
    
    vector<Personne> casting;
    
    
    string writerString = eMovie->Attribute("actors");
    if(writerString != "N/A"){
        vector<Personne> acteurs = getPersonnes(writerString, Role::EnumRole::Actor);
        casting.insert(casting.begin(), acteurs.begin(), acteurs.end());
    }
    
    string writersString = eMovie->Attribute("writer");
    if(writersString != "N/A"){
        vector<Personne> writers = getPersonnes(writersString, Role::EnumRole::Writer);
        casting.insert(casting.begin(), writers.begin(), writers.end());
    }
    
    string directorsString = eMovie->Attribute("director");
    if(directorsString != "N/A"){
        vector<Personne> directors = getPersonnes(directorsString, Role::EnumRole::Director);
        casting.insert(casting.begin(), directors.begin(), directors.end());
    }
        
    show.setCasting(casting);
    
    string rating = eMovie->Attribute("imdbRating");
    if(rating != "N/A"){
        show.setRating(atoi(rating.c_str()));
    }  
    
    return show;

}

ParserIMDB::ParserIMDB() {
}

ParserIMDB::ParserIMDB(const ParserIMDB& orig) {
}

ParserIMDB::~ParserIMDB() {
}

