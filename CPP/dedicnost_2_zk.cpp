#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/* 

vytvoření textové souboru zamestanci.txt s daty:

P;Matej Novotny;20;42000.0;3;2000.0
T;Matyas Kopecek;11;50450.0;8;580.0
P;Marek Musil;21;40000;1;2000.0
T;Matej Malek;10;48500.0;50;580.0 

// můžeš si schválně změnit čísla, které jsou ve formátu int na čísla ve formátu double pro vyzkoušení try-catch 

*/

using namespace std;

class Zamestnanec {
protected:
    string jmeno;
    int identifikator;
    double zakladniPlat;
public:
    Zamestnanec(string jmeno, int identifikator, double zakladniPlat) {
        this->jmeno = jmeno;
        this->identifikator = identifikator;
        this->zakladniPlat = zakladniPlat;
    }

    virtual ~Zamestnanec() {}

    virtual double vypocitejMzdu() = 0;

    virtual void vypisInfo() {
        cout <<"Jmeno: " << this->jmeno << "Identifikator : " << this->identifikator << "Zakladni plat : " << this->zakladniPlat << endl;
    }

};

class Programator : public Zamestnanec {
private:
    int pocetProjektu;
    double bonusZaProjekt;
public:
    Programator(string jmeno, int identifikator, double zakladniPlat, int pocetProjektu, double bonusZaProjekt) : Zamestnanec(jmeno, identifikator, zakladniPlat) {
        this->pocetProjektu = pocetProjektu;
        this->bonusZaProjekt = bonusZaProjekt;
    }

    ~Programator() {}

    double vypocitejMzdu() override {
        double mzda;
        mzda = zakladniPlat + (pocetProjektu * bonusZaProjekt);
        cout << "Mzda pro tento mesic je: " << mzda << endl;
        return mzda;
    }

    void vypisInfo() override {
        cout << "Jmeno: " << this->jmeno << ", Identifikator: " << this->identifikator << ", Zakladni plat: " << 
            this->zakladniPlat << ", Pocet projektu: " << this->pocetProjektu << endl;
    }
};

class Tester : public Zamestnanec {
private:
    int pocetChyb;
    double srazkaZaChybu;
public:
    Tester(string jmeno, int identifikator, double zakladniPlat, int pocetChyb, double srazkaZaChybu) : Zamestnanec(jmeno, identifikator, zakladniPlat) {
        this->pocetChyb = pocetChyb;
        this->srazkaZaChybu = srazkaZaChybu;
    }

    ~Tester() {}

    double vypocitejMzdu() override {
        double mzda;
        mzda = zakladniPlat - (pocetChyb * srazkaZaChybu);
        cout << "Mzda pro tento mesic je: " << mzda << endl;
        return mzda;
    }

    void vypisInfo() override {
        cout << "Jmeno: " << this->jmeno << ", Identifikator: " << this->identifikator << ", Zakladni plat: " << 
            this->zakladniPlat << ", Pocet chyb byl: " << this->pocetChyb << endl;
    }
};

int main()
{

    vector<Zamestnanec*> seznamZamestancu;


    ifstream File("zamestanci.txt");
    if (!File.is_open()) {
        cerr << "Nepodarilo se otevrit soubor";
        return 1;
    }

    string radek;


    while (getline(File, radek)) {
        stringstream ss(radek);
        string pozice, jmeno, identifikator_str, zakladniPlat_str, pocetProjektu_str, bonusZaProjekt_str, pocetChyb_str, srazkaZaChybu_str;

        getline(ss, pozice, ';');
        getline(ss, jmeno, ';');
        getline(ss, identifikator_str, ';');
        getline(ss, zakladniPlat_str, ';');

        // try-catch kvuli nalezení chyby, nemusí tam být (dávat si pozor na formát textového souboru - jestli všechny čísla sedí pro int/double/long kvuli stoi/stod/stol 
        try {
            int identifikator = stoi(identifikator_str);
            double zakladniPlat = stod(zakladniPlat_str);

            if (pozice == "P")
            {
                getline(ss, pocetProjektu_str, ';');
                getline(ss, bonusZaProjekt_str, ';');
                int pocetProjektu = stoi(pocetProjektu_str);
                double bonusZaProjekt = stod(bonusZaProjekt_str);

                seznamZamestancu.push_back(new Programator(jmeno, identifikator, zakladniPlat, pocetProjektu, bonusZaProjekt));
            }
            else if (pozice == "T")
            {
                getline(ss, pocetChyb_str, ';');
                getline(ss, srazkaZaChybu_str, ';');
                int pocetChyb = stoi(pocetChyb_str);
                double srazkaZaChybu = stod(srazkaZaChybu_str);

                seznamZamestancu.push_back(new Tester(jmeno, identifikator, zakladniPlat, pocetChyb, srazkaZaChybu));
            }

        } // Gemini generated kvůli abort() chybě
        catch
        (const std::invalid_argument& e) {
            cerr << "CHYBA DAT (Konverze): Chyba formatu cisla na radku: " << radek << endl;
        }
        catch (const std::exception& e) {
            cerr << "NEZNÁMÁ CHYBA na radku: " << radek << ". Detail: " << e.what() << endl;
        }

    }

    File.close();

    // vypis vektorů
    for (Zamestnanec*& z_ptr : seznamZamestancu) {
        z_ptr->vypisInfo();
        z_ptr->vypocitejMzdu();
    }

    // delete vektorů
    for (Zamestnanec*& z_ptr : seznamZamestancu) {
        delete z_ptr;
    }

    return 0;
}


