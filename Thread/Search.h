#pragma once

#include <string>
#include <functional>
#include <future>
#include <thread>
#include "../Analyse/Show.h"
#include "../Network/APIServer.h"
#include "../Analyse/Parser.h"
#include "../Analyse/ParserIMDB.h"
#include "../Analyse/ParserTVDB.h"

using namespace std;

class Search {
public:
    Search();
    virtual ~Search();
    static void getShow(string, promise<Show>*);
private:

};