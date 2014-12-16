#pragma once

#include <richedit.h>

class Parser {

public:
    Parser();
    static vector<Show> getResults(String words);
};