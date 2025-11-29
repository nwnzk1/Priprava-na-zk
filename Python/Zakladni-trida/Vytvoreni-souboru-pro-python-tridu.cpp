#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void vytvorSoubor(string filename) {
    ofstream File(filename);
    if (!File.is_open()) {
        cerr << "Nepodarilo se vytvorit soubor " << filename << endl;
        return;
    }

    File << "Aragorn, 10, 100" << endl;
    File << "Legolas, 12, 80" << endl;
    File << "Gimli, 11, 120" << endl;

    cout << "Vytvoril se soubor " << filename << endl;
}

int main()
{
    string soubor = "C:\\Jetbrains\\PyCharm\\Zaklady\\zaklad_trid.txt";
    vytvorSoubor(soubor);
}
