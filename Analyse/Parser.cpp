#include "Parser.h"
#include "../include/tinyxml2/tinyxml2.h"

//Méthode globale permettant la récupération des resultats d'une recherche
Show Parser::getResults(string xml)
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
    
    if (eMovie == nullptr) return show;
    
    string title = eMovie->Attribute("title");
    show.setTitle(title);
    
    string plot = eMovie->Attribute("plot");
    show.setPlot(plot);
    
    string genre = eMovie->Attribute("genre");
    show.setGenre(genre);
    
    string year = eMovie->Attribute("year");
    show.setYear(year);
    
    string urlPicture = eMovie->Attribute("poster");
    show.setUrlPicture(urlPicture);
    

    /*
    show.setPlot( eMovie->Attribute("plot") );
    show.setGenre( eMovie->Attribute("genre") );
    show.setYear( eMovie->Attribute("year") );
    show.setUrlPicture( eMovie->Attribute("poster") );
   
    
//    show.setCasting(  );
    if(eMovie->Attribute("rating") != "N/A"){
        show.setRating(atoi(eMovie->Attribute("rating")));
    }
     */
    
    
    return show;

}

Parser::Parser() {

}

Parser::~Parser() {
}