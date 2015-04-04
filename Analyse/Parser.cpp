#include "Parser.h"

Parser::Parser(){}

Parser::~Parser(){}

vector<string> Parser::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
    
    return elems;
}


vector<string> Parser::split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
    
vector<Personne> Parser::getPersonnes(string names, Role::EnumRole role){
    vector<string> nomsVectorString = split(names.c_str(), ',');
    vector<Personne> personnes;
    for (auto &personneString : nomsVectorString){  

        if(personneString[0] == ' ')
            personneString = personneString.erase(0, 1);

        vector<string> nom = split(personneString, ' ');
        Personne personne(nom.at(0), nom.at(1), role);
        personnes.push_back(personne);
    }
    
    return personnes;
}
