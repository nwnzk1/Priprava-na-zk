#include <iostream>
#include <fstream>  
#include <sstream>
#include <string>

using namespace std;

class Vozidlo {
protected:
    string znacka;
    string model;
    int rokVyroby;
public:
    Vozidlo(string znacka, string model, int rokVyroby) 
    {
        this->znacka = znacka;
        this->model = model;
        this->rokVyroby = rokVyroby;
    }

    ~Vozidlo() { cout << "Destruktor Vozidlo" << endl; };

    void vypisInfo() 
    {
        std::cout << "Znacka: " << this->znacka << ", Model: " << this->model << ", Rok vyroby: " << this->rokVyroby << endl;
    }

    void nastartuj() 
    {
        std::cout << "Znacka: " << this->znacka << ", Model: " << this->model << ", Rok vyroby: " << this->rokVyroby << endl;
    }

};

class OsobniAuto : public Vozidlo {
private:
    int pocetDveri;
public:
    OsobniAuto(string znacka, string model, int rokVyroby, int pocetDveri) : Vozidlo(znacka, model, rokVyroby) 
    {
        this->pocetDveri = pocetDveri;
    }

    ~OsobniAuto() { cout << "Destruktor OsobniAuto" << endl; };

    void vypisInfo()
    {
        Vozidlo::vypisInfo();
        cout << "Pocet dveri je: " << this->pocetDveri << endl;
    }
};

class NakladniVozidlo : public Vozidlo {
private:
    double nosnostKg;
public:
    NakladniVozidlo(string znacka, string model, int rokVyroby, double nosnostKg) : Vozidlo(znacka, model, rokVyroby) 
    {
        this->nosnostKg = nosnostKg;
    }

    ~NakladniVozidlo() { cout << "Destruktor NakladniVozidlo" << endl; };

    void nastartuj() {
        Vozidlo::nastartuj();
        cout << "Nakladni vozidlo je pripraveno vyrazit s vahou " << this->nosnostKg << " kg" <<endl;
    }
};

int main()
{
    OsobniAuto Skoda("Skoda", "Octavia", 2020, 5);
    NakladniVozidlo Volvo("Volvo", "FH16", 2014, 40000);

    Skoda.vypisInfo();
    Volvo.nastartuj();

    return 0;
}

