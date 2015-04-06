#pragma once

#include "Show.h"
#include "Parser.h"
#include <string>
#include <sstream>
#include <iostream>
#include "../include/tinyxml2/tinyxml2.h"

using namespace std;

class ParserTVDB : public Parser{
public:
    ParserTVDB();
    ParserTVDB(const ParserTVDB& orig);
    virtual ~ParserTVDB();
    Show parseShow(string);
private:

};
