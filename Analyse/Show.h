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


    String getTitle();

    void setTitle(String title);

    String getSummary();

    void setSummary(String summary);

    String getUrlPicture();

    void setUrlPicture(String urlPicture);

    int getSeasonNbr();

    void setSeasonNbr(int seasonNbr);

    bool isCancelled();

    void setCancelled(bool cancelled);

    long getCasting();

    void setCasting(long casting);

    int getNote();

    void setNote(int note);

private:
    String title;
    String summary;
    String urlPicture;
    int seasonNbr;
    bool cancelled;
    vector<Personne> casting;
    int note;

};