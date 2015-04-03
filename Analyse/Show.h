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
        
    string getTitle();
    string getPlot();
    string getGenre();
    string getYear();
    string getUrlPicture();
    int getSeasonNbr();
    bool isCancelled();
    vector<Personne> getCasting();
    int getRating();
    string getRunTime();
    
    void setTitle(string);
    void setPlot(string);
    void setGenre(string);
    void setYear(string);
    void setUrlPicture(string);
    void setSeasonNbr(int);
    void setCancelled(bool);
    void setCasting(vector<Personne>);
    void setRating(int);
    void setRunTime(string);

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
};


