#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void vytvorSoubor(string filename) {
    ofstream File(filename);
    if (!File.is_open()) {
        cerr << "Nelze vytvorit soubor" << filename << endl;
        return;
    }

    File << "Freakyas Kopecek" << endl;
    File << "Marecek Parecek" << endl;
    File << "Matej Freakytny" << endl;
    
    cout << "Soubor " << filename << " se vytvoril" << endl;
}


int main()
{
    // VYTVORENI SOUBORU DO SLOZKY Cpp FILE
    // string soubor = ("freaky");           
    // vytvorSoubor(soubor)


    // VYTVORENI SOUBORU DO SLOZKY PRO PYTHON - budeš to mít jiný než já
    string cesta = "C:\\Jetbrains\\PyCharm\\Zaklady\\cpptopython.txt";
    vytvorSoubor(cesta);
}
