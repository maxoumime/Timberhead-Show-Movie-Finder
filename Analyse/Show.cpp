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
    retour = retour + "Durée: " + this->runTime + "\n";
    //retour = retour + "Note: " + int_to_string(this->rating) + "/10" + "\n"; 
    retour = retour + "Chaine: " + this->channel + "\n";

    retour = retour + "Casting: " + "\n";
    
    for(Personne &personne : this->casting){
        retour += "\t" + personne.getFirstName() + " " + personne.getLastName()
                + " : " + Role::RolesString[personne.getRole()] + "\n";
    }
    
    return retour;
}

bool Show::isNull(){
    if((this->title).size() == 0)
    {
        return true;
    }else
    {
        return false;
    }
}

Show Show::mergeShows(Show show1, Show show2){
    
    //On part du principe que le show 1 est la référence
    
    if(show1.getTitle().empty())
        show1.setTitle( show2.getTitle() );
    
    if(show1.getPlot().empty())
        show1.setPlot( show2.getPlot() );
    
    if(show1.getChannel().empty())
        show1.setChannel( show2.getChannel() );
    
    if(show1.getGenre().empty())
        show1.setGenre( show2.getGenre() );
        
    if(show1.getRating() == 0)
        show1.setRating( show2.getRating() );
    
    if(show1.getRunTime().empty())
        show1.setRunTime( show2.getRunTime() );

    if(show1.getUrlPicture().empty())
        show1.setUrlPicture( show2.getUrlPicture() );
    
    if(show1.getYear().empty())
        show1.setYear( show2.getYear() );
    
    if(show1.getCasting().empty())
        show1.setCasting( show2.getCasting() );
    else if(!show2.getCasting().empty()){
        
        vector<Personne> vCasting1 = show1.getCasting();
        vector<Personne> vCasting2 = show2.getCasting();

        vCasting1.insert(vCasting1.end(), vCasting2.begin(), vCasting2.end());
        
        vector<Personne> vCastingMerged;
        vector<string> vCastingMergedComparaison;
        for(Personne &personneFusion : vCasting1){

            string comparaisonPersonne = personneFusion.getFirstName()+":"
                    + personneFusion.getLastName()+":"
                    + Role::RolesString[personneFusion.getRole()];
            
            if(std::find(vCastingMergedComparaison.begin(), vCastingMergedComparaison.end(), comparaisonPersonne) == vCastingMergedComparaison.end()){
                vCastingMerged.push_back(personneFusion);
                vCastingMergedComparaison.push_back(comparaisonPersonne);
            }
        }
        
        show1.setCasting(vCastingMerged);
    }
    
    return show1;
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

string Show::getChannel(){
    return channel;
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

void Show::setChannel(string channel){
    this->channel = channel;
}

void Show::setCasting(vector<Personne> casting){
    this->casting = casting;
}

void Show::setRating(int rating){
    this->rating = rating;
}

void Show::setRunTime(string runtime){
    this->runTime = runtime;
}

