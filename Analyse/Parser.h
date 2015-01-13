#pragma once

//#include <richedit.h>
#include "Show.h"
#include <string>

class Parser {

public:
    Parser();
    ~Parser();
    static vector<Show> getResults(string words);
};