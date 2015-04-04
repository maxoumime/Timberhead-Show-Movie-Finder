#include "ParserTVDB.h"

//Méthode globale permettant la récupération des resultats d'une recherche
Show ParserTVDB::parseShow(string xml)
{        
    Show show;
    
    //Liste des séries correspondant à la recherche
    tinyxml2::XMLDocument doc;
    doc.Parse((const char*)xml.c_str());

    //BALISE <xml>
    tinyxml2::XMLNode * pRootXml = doc.FirstChild();    

    if (pRootXml == nullptr) return show;
    
    //BALISE <Data>
    tinyxml2::XMLNode * pData = pRootXml->NextSibling();
    
    if (pData == nullptr) return show;
    
    //BALISE <Series>
    tinyxml2::XMLNode * eSeries = pData->FirstChild();
    
    if(eSeries == nullptr) return show;
    
    string title = eSeries->FirstChildElement("SeriesName")->GetText();
    show.setTitle(title);
    
    string plot = eSeries->FirstChildElement("Overview")->GetText();
    show.setPlot(plot);
    
    return show;

}

ParserTVDB::ParserTVDB() {
}

ParserTVDB::ParserTVDB(const ParserTVDB& orig) {
}

ParserTVDB::~ParserTVDB() {
}

