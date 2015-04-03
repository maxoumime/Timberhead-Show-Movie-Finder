#include "Show.h"

Show::Show(){
    
}

Show::~Show(){
    
}

string Show::getTitle(){
    return title;
}

string Show::getPlot(){
    return plot;
}

string Show::getGenre(){
    return genre;
}

string Show::getYear(){
    return year;
}

string Show::getUrlPicture(){
    return urlPicture;
}

int Show::getSeasonNbr(){
    return seasonNbr;
}

bool Show::isCancelled(){
    return cancelled;
}

vector<Personne> Show::getCasting(){
    return casting;
}

int Show::getRating(){
    return rating;
}

string Show::getRunTime(){
    return runTime;
}


void Show::setTitle(string title){
    this->title = title;
}

void Show::setPlot(string plot){
    this->title = title;
}

void Show::setGenre(string genre){
    this->title = title;
}

void Show::setYear(string year){
    this->year = year;
}

void Show::setUrlPicture(string urlPicture){
    this->urlPicture = urlPicture;
}

void Show::setSeasonNbr(int seasonNbr){
    this->seasonNbr = seasonNbr;
}

void Show::setCancelled(bool cancelled){
    this->cancelled = cancelled;
}

void Show::setCasting(vector<Personne> casting){
    this->casting = casting;
}

void Show::setRating(int rating){
    this->rating = rating;
}

void Show::setRunTime(string runtime){
    this->runTime = runTime;
}

