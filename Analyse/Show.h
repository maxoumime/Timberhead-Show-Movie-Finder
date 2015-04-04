#pragma once

#include <vector>
#include <iterator>
#include <algorithm>
#include "Personne.h"
#include <iostream>

using namespace std;

class Show
{
public:
    Show(void);
    ~Show(void);
        
    string getTitle();
    string getPlot();
    string getGenre();
    string getYear();
    string getUrlPicture();
    string getChannel();
    vector<Personne> getCasting();
    int getRating();
    string getRunTime();
    
    void setTitle(string);
    void setPlot(string);
    void setGenre(string);
    void setYear(string);
    void setUrlPicture(string);
    void setChannel(string);
    void setCasting(vector<Personne>);
    void setRating(int);
    void setRunTime(string);
    
    string toString();
    static Show mergeShows(Show, Show);

private:

    string title;       // "Sherlock"
    string plot;        // intrigue
    string genre;       // "Crime"
    string year;        // "2010-"
    string urlPicture;  // Url de l'image
    string channel;     // Chaine de diffusion de la série
    vector<Personne> casting;
    int rating;
    string runTime;     // "90 min"
};


