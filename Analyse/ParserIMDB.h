#pragma once

#include "Show.h"
#include "Parser.h"
#include <string>
#include "../include/tinyxml2/tinyxml2.h"

using namespace std;

class ParserIMDB : public Parser{
public:
    ParserIMDB();
    ParserIMDB(const ParserIMDB& orig);
    virtual ~ParserIMDB();
    Show parseShow(string);
private:

};
