#include <iostream>
#include <string>
#include <vector>

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
        cout << "Jmeno: " << this->jmeno << "Identifikator: " << this->identifikator << "Zakladni plat: " << this->zakladniPlat << endl;
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
        cout << "Jmeno: " << this->jmeno << ", Identifikator: " << this->identifikator << ", Zakladni plat: " << this->zakladniPlat << ", Pocet projektu: " << this->pocetProjektu << endl;
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
        cout << "Jmeno: " << this->jmeno << ", Identifikator: " << this->identifikator << ", Zakladni plat: " << this->zakladniPlat << ", Pocet chyb byl: " << this->pocetChyb << endl;
    }
};

int main()
{
    Programator* zProgramator = new Programator("Matej Novotny", 22, 34500, 3, 2000);
    Tester* zTester = new Tester("Matyas Kopecek", 34, 50450, 8, 580);

    vector<Zamestnanec*> seznamZamestnancu;
    seznamZamestnancu.push_back(zProgramator);
    seznamZamestnancu.push_back(zTester);

    for (Zamestnanec*& z_ptr : seznamZamestnancu) {
        z_ptr->vypisInfo();
        z_ptr->vypocitejMzdu();
    }

    for (Zamestnanec*& z_ptr : seznamZamestnancu) {
        delete z_ptr;
    }

    return 0;
}


