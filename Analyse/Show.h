#pragma once

#include <vector>
#include <iterator>
#include "Personne.h"

using namespace std;

class Show
{
public:
    Show(void);
    ~Show(void);

private:

    String title;       // "Sherlock"
    String plot;        // intrigue
    String genre;       // "Crime"
    Strinf year;        // "2010-"
    String urlPicture;  // Url de l'image
    int seasonNbr;      //
    bool cancelled;
    vector<Personne> casting;
    int rating;
    String runTime;     // "90 min"

public:


};


