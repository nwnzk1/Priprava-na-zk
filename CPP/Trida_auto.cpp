#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Auto {
private:
    string znacka;
    string model;
	int rokVyroby;
    int najetoKm;
    std::string filename;

public:

    Auto(std::string filename) 
    {
        this->filename = filename;
    }
    

    void vypisInfo()
    {
        std::string radek;

        std::ifstream File(this->filename);
        if (!File.is_open()) {
            std::cerr << "Chyba, soubor " << filename << " se nepodarilo otevrit" << endl;
            return;
        }

        while (std::getline(File, radek))
        {

            std::stringstream ss(radek);
            std::string znacka, model;
            std::string rokVyrobyStr;
            std::string najetoKmStr;

            std::getline(ss, znacka, ';');
            std::getline(ss, model, ';');
            std::getline(ss, rokVyrobyStr, ';');   // čte charaktery -> musím si zadefinovat string rokVyrobyStr -> fuknce stoi převede string na int 
            std::getline(ss, najetoKmStr, ';');


            this->rokVyroby = std::stoi(rokVyrobyStr);
            this->najetoKm = std::stoi(najetoKmStr);
            this->znacka = znacka;
            this->model = model;
            this->rokVyroby = rokVyroby;
            this->najetoKm = najetoKm;

            std::cout << "Znacka: " << this->znacka << ", Model: " << this->model << ", Rok vyroby: " << this->rokVyroby << ", Najeto km: " << this->najetoKm << endl;
        }
        File.close();
    }
};



int main()
{
    Auto autoTxt("auta.txt");
    autoTxt.vypisInfo();
}
