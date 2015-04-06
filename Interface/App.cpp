#include "App.h"

string int_to_string(int input){
    ostringstream ss;
    ss << input;
    return ss.str();
}

App::App() {
}

App::~App() {
}

//Méthode permettant l'affichage de la page d'accueil en fonction de la taille de la console
int App::initializeHome() {
 
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
 
    //Récupération de la taille du terminal
    //int rows = w.ws_row; Non utilisé
    int columns = w.ws_col;

    //Affichage du nom de l'application
    string title = "TimberHead : le fabuleux moteur de recherche ! ";
       
    cout.width(columns);
    cout.fill(' ');
    cout << setiosflags(ios::right) << title << endl;
        
    cout.fill('-');
    cout.width(columns);
    cout << "\n";    
   
    return 0;
}

string App::getRequest()
{
    string serie;
    cout << "Entrez le nom de la série recherchée (ou Ctrl-C pour quitter): ";
    getline(cin, serie);
    return serie;
}

void App::displayResult(Show show)
{
    if(show.isNull())
    {
        cout << "Aucun résultat pour votre recherche :(" << endl;
    }else
    {
        string head = "Résultat de votre recherche";
        string result;

        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        //Récupération de la taille du terminal
        int columns = w.ws_col;
        App::displayTitle("~ Informations générales", columns);
        
        cout << App::displayInOneLine(columns, "Title ", show.getTitle()) << endl;
        cout << App::displayInOneLine(columns, "Résumé ", show.getPlot()) << endl;
        cout << App::displayInOneLine(columns, "Genre ", show.getGenre()) << endl;
        cout << App::displayInOneLine(columns, "Année ", show.getYear()) << endl;
        cout << App::displayInOneLine(columns, "Durée ", show.getRunTime()) << endl;
        cout << App::displayInOneLine(columns, "Note ", int_to_string(show.getRating())+ "/10") << endl;
        cout << App::displayInOneLine(columns, "Chaine ", show.getChannel()) << endl;

        App::displayTitle("~ Distribution de la série", columns);
        
        for(Personne &personne : show.getCasting()){
            string name = personne.getFirstName() + " " + personne.getLastName();
            cout << App::displayInOneLine(columns, Role::RolesString[personne.getRole()], name) << endl;
        }
    }
}


string App::displayInOneLine(int colums, string start, string end){
    string result;
    result = result + start;
    int rest = colums - (start.size() + end.size());
  
    while(rest > 0)    {        
        result = result + " ";
        rest --;
    }
    
    result = result + end;    
    return result;
}

void App::displayTitle(string title, int columns)
{
    cout.fill('*');
    cout.width(columns);
    cout << "\n";
        
    int size = columns - title.size();
    size = size / 2;
    for(int i =0; i<size; i++){
        cout << " ";
    }
    cout << title;
    for(int i =0; i<size; i++){
        cout << " ";
    }
    cout << endl;
    cout.fill('*');
    cout.width(columns);
    cout << "\n";
}
