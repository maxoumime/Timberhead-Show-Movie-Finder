#include <iostream>

#include "Network/APIServer.h"

using namespace std;

int main() {

    APIServer apiServer = APIServer();

    apiServer.fetch("GetSeries.php?seriesname=Sherlock");

    return 0;
}