#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include "../Analyse/Show.h"
#include <stdlib.h>
#include <sys/ioctl.h>


using namespace std;

class App {

public:
    App(void);
    ~App(void);
    static int initializeHome();
    static string getRequest();
    static void displayResult(Show show);
    static string displayInOneLine(int columns, string start, string end);
    static void displayTitle(string title, int columns);
};