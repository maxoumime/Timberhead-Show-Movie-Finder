#pragma once

//#include <richedit.h>
#include "Show.h"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class Parser {

public:
    Parser();
    ~Parser();
    static Show getResults(string);
};