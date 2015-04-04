#pragma once

#include <sstream>
#include <vector>
#include <string>
#include "Personne.h"

using namespace std;

class Parser {
public:
    Parser();
    Parser(const Parser& orig);
    virtual ~Parser();
    
    static vector<string> split(const string &s, char delim, vector<string> &elems);
    static vector<string> split(const string &s, char delim);
    static vector<Personne> getPersonnes(string names, Role::EnumRole role);
    
private:

};
