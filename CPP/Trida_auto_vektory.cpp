#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Auto {
private:
    string znacka;
    string model;
    int rokVyroby;
    int najetoKm;

    string filename;

public:

    Auto() = default;

    Auto(string znacka, string model, int rokVyroby, int najetoKm)
    {
        this->znacka = znacka;
        this->model = model;
        this->rokVyroby = rokVyroby;
        this->najetoKm = najetoKm;
    }

    void nastavData(string znacka, string model, int rokVyroby, int najetoKm) 
    {
        this->znacka = znacka;
        this->model = model;
        this->rokVyroby = rokVyroby;
        this->najetoKm = najetoKm;
    }

    void vypisInfo() 
    {
        std::cout << "Znacka: " << this->znacka << ", Model: " << this->model << ", Rok vyroby: " << this->rokVyroby << ", Najeto km: " << this->najetoKm << endl;
    }

    void stariAuta() 
    {
        int rok = 2025;
        int stari = rok - this->rokVyroby;
        std::cout << "Stari vozu je: " << stari << " let" << endl;
    }
};


int main()
{
    ifstream File("auta.txt");
    if (!File.is_open()) 
    {
        std::cerr << "Chyba, nepodarilo se otevrit soubor" << endl;
    }

    vector<Auto> auta;
    std::string radek;

    while (getline(File, radek)) 
    {
        stringstream ss(radek);
        string znacka, model, rVstr, nKstr;

        getline(ss, znacka, ';');
        getline(ss, model, ';');
        getline(ss, rVstr, ';');
        getline(ss, nKstr, ';');

        int rokVyroby = stoi(rVstr);
        int najetoKm = stoi(nKstr);

        Auto a;
        a.nastavData(znacka, model, rokVyroby, najetoKm);
        auta.push_back(a);                                       // push_back vloží auta do konce vektoru

    }

    File.close();

    for (Auto& a : auta)                   // typ& promenna : kontejner 
    {
        a.vypisInfo();
        a.stariAuta();
    }
}


