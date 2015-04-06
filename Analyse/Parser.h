#pragma once

#include <sstream>
#include <vector>
#include <string>
#include "Personne.h"
#include "Show.h"

using namespace std;

class Parser {
public:
    Parser();
    virtual ~Parser();
    
    static vector<string> split(const string &s, char delim, vector<string> &elems);
    static vector<string> split(const string &s, char delim);
    static vector<Personne> getPersonnes(string names, Role::EnumRole role);
    virtual Show parseShow(string) = 0;
private:

};
