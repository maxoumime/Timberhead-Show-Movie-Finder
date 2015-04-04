#include "Show.h"

Show::Show(){
    
}

Show::~Show(){
    
}

string Show::toString(){
    
    string retour = "";
    
    retour = retour + "Titre: " + this->title + "\n";
    retour = retour + "Résumé: " + this->plot + "\n";
    retour = retour + "Genre: " + this->genre + "\n";
    retour = retour + "Année: " + this->year + "\n";
    retour = retour + "Note: " + to_string(this->rating) + "\n"; 

    retour = retour + "Casting: " + "\n";
    
    for(Personne &personne : this->casting){
        retour += "\t" + personne.getFirstName() + " " + personne.getLastName()
                + " : " + Role::RolesString[personne.getRole()] + "\n";
    }
    
    return retour;
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
    this->plot = plot;
}

void Show::setGenre(string genre){
    this->genre = genre;
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

