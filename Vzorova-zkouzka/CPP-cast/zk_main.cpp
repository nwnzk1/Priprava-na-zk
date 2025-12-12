#include "logger.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    // Inicializace náhodných čísel
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Logger logger;
    Server server;

    // server.run(50);      
    server.run(10);

    cout << "Soubor vytvoren" << endl;
    
    
    return 0;
}

