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
    
    tinyxml2::XMLElement* titleElement = eSeries->FirstChildElement("SeriesName");
    
    if(titleElement != nullptr){
        string title = titleElement->GetText();
        show.setTitle(title);
    }
    
    tinyxml2::XMLElement* plotElement = eSeries->FirstChildElement("Overview");
    if(plotElement != nullptr){
        string plot = plotElement->GetText();
        show.setPlot(plot);
    }
    
    tinyxml2::XMLElement* yearElement = eSeries->FirstChildElement("FirstAired");
    if(yearElement != nullptr){
        string year = yearElement->GetText();
        year.resize(4);
        show.setYear(year);
    }
    
    tinyxml2::XMLElement* channelElement = eSeries->FirstChildElement("Network");
    if(channelElement != nullptr){
        string channel = channelElement->GetText();
        show.setChannel(channel);
    }
    
    return show;

}

ParserTVDB::ParserTVDB() {
}

ParserTVDB::ParserTVDB(const ParserTVDB& orig) {
}

ParserTVDB::~ParserTVDB() {
}

