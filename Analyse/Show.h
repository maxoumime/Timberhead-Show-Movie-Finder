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

    string title;       // "Sherlock"
    string plot;        // intrigue
    string genre;       // "Crime"
    string year;        // "2010-"
    string urlPicture;  // Url de l'image
    int seasonNbr;      //
    bool cancelled;
    vector<Personne> casting;
    int rating;
    string runTime;     // "90 min"

public:


};


