#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


struct Kontakt {
    std::string meno;
    std::string telefon;
};

void nacti_kontakty(const std::string &soubor, std::vector<Kontakt> &kontakty) {
    std::ifstream infile(soubor);
    if (!infile) {
        std::cerr << "Chyba pri otevirani souboru: " << soubor << std::endl;
        return;
    }

    std::string radek;
    while (std::getline(infile, radek)) {
        std::stringstream ss(radek);
        Kontakt k;

        std::getline(ss, k.meno, ';');
        std::getline(ss, k.telefon);

        if (!k.meno.empty() && !k.telefon.empty()) {
            kontakty.push_back(k);
        }
    }
}

void uloz_kontakty(const std::string &soubor, const std::vector<Kontakt> &kontakty) {
    std::ofstream outfile(soubor);
    if (!outfile) {
        std::cerr << "Chyba pri otevirani souboru: " << soubor << std::endl;
        return;
    }

    for (const auto &k : kontakty) {
        outfile << k.meno << ";" << k.telefon << std::endl;
    }
}

int main() {
    std::vector<Kontakt> kontakty;
    std::string soubor = "kontakty.txt";

    nacti_kontakty(soubor, kontakty);

    while (true) {
        std::cout << "\n------ Spravce kontaktu ------\n";
        std::cout << "1. Zobrazit kontakty\n";
        std::cout << "2. Pridat kontakt\n";
        std::cout << "3. Ulozit a ukoncit\n";
        std::cout << "Vyberte moznost: ";

        int volba;
        std::cin >> volba;
        std::cin.ignore();

        if (volba == 1) {
            for (const auto &k : kontakty) {
                std::cout << "Jmeno: " << k.meno
                          << ", Telefon: " << k.telefon << std::endl;
            }
        } 
        else if (volba == 2) {
            Kontakt novy;

            std::cout << "Zadejte meno: ";
            std::getline(std::cin, novy.meno);

            std::cout << "Zadejte telefon: ";
            std::getline(std::cin, novy.telefon);

            kontakty.push_back(novy);
        } 
        else if (volba == 3) {
            uloz_kontakty(soubor, kontakty);
            break;
        } 
        else {
            std::cout << "Neplatna volba.\n";
        }
    }

    return 0;
}





