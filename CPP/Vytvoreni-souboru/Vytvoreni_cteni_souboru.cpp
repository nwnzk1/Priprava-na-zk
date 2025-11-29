#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Vozidlo {
protected:
    string znacka;
    int rokVyroby;
public:
    Vozidlo(string znacka, int rokVyroby) {     // konstruktor
        this->znacka = znacka;
        this->rokVyroby = rokVyroby;
    }

    virtual ~Vozidlo() {}                // destruktor

    virtual void vypisInfo() = 0;      // = 0 nám udělá z této funkce čiště virtuální funkci -> class Vozidlo = 
                                      // = abstraktní třída (nemůžeme vytvářet instance, pouze z této třídy můžeme dědit)
};

class Auto : public Vozidlo {
public:
    int pocetDveri;

    Auto(string znacka, int rokVyroby, int pocetDveri) : Vozidlo(znacka, rokVyroby) {
        this->pocetDveri = pocetDveri;
    }

    void vypisInfo() override {          // override kontroluje jestli funkce odvozené třídy přepisuje virtuální funkci v základní třídě
        std::cout << "Znacka: " << this->znacka << ", Rok vyroby: " << this->rokVyroby << ", Pocet dveri: " << this->pocetDveri << endl;
    }
};

class Motocykl : public Vozidlo {
public:
    bool maKapota;

    Motocykl(string znacka, int rokVyroby, bool maKapota) : Vozidlo(znacka, rokVyroby) {
        this->maKapota = maKapota;
    }

    void vypisInfo() override {
        std::cout << "Znacka: " << this->znacka << ", Rok vyroby: " << this->rokVyroby << ", Ma kapotu: " << (this->maKapota ? "Ano" : "Ne") << endl;
    }
};

// FUNKCE PRO VYTVORENI SOUBORU

void vytvorSoubor(string nazevSouboru) {
    ofstream outFile(nazevSouboru);            // vytvoreni souboru pomocí funkce ofstream
    if (!outFile.is_open()) {                 // .txt kontrola 
        cerr << "Nelze vytvorit soubor " << nazevSouboru << endl;
        return;
    }

    // Zapis dat do souboru
    outFile << "AUTO, Skoda, 2018, 5" << endl;
    outFile << "MOTOCYKL, Honda, 2020, 1" << endl;
    outFile << "AUTO, Hyundai, 2022, 5" << endl;
    outFile << "MOTOCYKL, Yamaha, 2009, 0" << endl;
    outFile.close();

    cout << "Soubor " << nazevSouboru << " byl vytvoren" << endl;  // .txt kontrola
}

// FUNKCE PRO PARSOVANI SOUBORU + ULOZENI DAT ZE SOUBORU

void parsujSoubor(string nazevSouboru, vector<Vozidlo*>& vozidla) {       // & = reference, !!!! dulezite -> pokud by tam nebyla, 
                                                                         // data by se znicili pri skonceni funkce parsujSoubor a doslo by k memory leaku
                                                                        // + by se nic nevypsalo ve funkci for (Vozidlo* v_ptr : seznamVozidel)

    ifstream File(nazevSouboru);
    if (!File.is_open()) {
        cerr << "Nepodarilo se otevrit soubor " << nazevSouboru << endl;
    }

    string radek;

    while (getline(File, radek)) {
        stringstream ss(radek);
        string typ, znacka, rokVyroby_str, pocetDveri_str, maKapotu_str;

        getline(ss, typ, ',');
        getline(ss, znacka, ',');
        getline(ss, rokVyroby_str, ',');

        int rokVyroby = stoi(rokVyroby_str);
        
        if (typ == "AUTO") {
            getline(ss, pocetDveri_str, ',');
            int pocetDveri = stoi(pocetDveri_str);

            vozidla.push_back(new Auto(znacka, rokVyroby, pocetDveri));
        }
        else if (typ == "MOTOCYKL") {
            getline(ss, maKapotu_str, ',');
            int maKapotu = stoi(maKapotu_str);
            
            if (maKapotu == 1){
                maKapotu = true;
            }
            else if (maKapotu == 0) {
                maKapotu = false;
            }

            vozidla.push_back(new Motocykl(znacka, rokVyroby, maKapotu));
        }
    }

    File.close();
}


int main()
{
    string soubor = ("vozidla.txt");
    vytvorSoubor(soubor);

    vector<Vozidlo*> seznamVozidel;

    parsujSoubor(soubor, seznamVozidel);

    for (Vozidlo* v_ptr : seznamVozidel) {
        v_ptr->vypisInfo();

    }

    for (Vozidlo* v_ptr : seznamVozidel) {
        delete v_ptr;
    }

    return 0;
}
