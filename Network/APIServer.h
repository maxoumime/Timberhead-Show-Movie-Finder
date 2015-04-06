#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include "../Analyse/Parser.h"
#include "Finder.h"

class APIServer {

public:
    APIServer(void);
    APIServer(std::string, std::string, Parser*);
    ~APIServer(void);
    static void findShow(APIServer*, std::string, std::promise<Show>*);
    void findShowThread(std::string, std::promise<Show>*);

private:
    std::string name;
    std::string apiUrl;
    Parser* parser;
};




