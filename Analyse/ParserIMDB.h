#pragma once

#include "Show.h"
#include "Parser.h"
#include <string>

using namespace std;

class ParserIMDB : public Parser{
public:
    ParserIMDB();
    ParserIMDB(const ParserIMDB& orig);
    virtual ~ParserIMDB();
    static Show parseShow(string);
private:

};
