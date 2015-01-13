#pragma once

//#include <richedit.h>
#include "Show.h"
#include <string>

class Parser {

public:
    Parser();
    static vector<Show> getResults(string words);
};