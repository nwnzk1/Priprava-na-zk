
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
    Kontakt k;
    while (infile >> k.meno >> k.telefon) {
        kontakty.push_back(k);
    }
	infile.close();
}

void uloz_kontakty(const std::string &soubor, const std::vector<Kontakt> &kontakty) {
    std::ofstream outfile(soubor);
    if (!outfile) {
        std::cerr << "Chyba pri otevirani souboru: " << soubor << std::endl;
        return;
    }
    for (const auto &k : kontakty) {
        outfile << k.meno << " " << k.telefon << std::endl;
    }
    
}

int main()
{
    std::vector<Kontakt> kontakty;
	std::string soubor = "kontakty.txt";
    nacti_kontakty("kontakty.txt", kontakty);

    while(true) {
		std::cout <<" ------Spravce kontaktu------ \n";
        std::cout << "1. Zobrazit kontakty\n";
        std::cout << "2. Pridat kontakt\n";
        std::cout << "3. Ulozit a ukoncit\n";
        std::cout << "Vyberte moznost: ";
        int volba;
        std::cin >> volba;
        if (volba == 1) {
            for (const auto &k : kontakty) {
                std::cout << "Meno: " << k.meno << ", Telefon: " << k.telefon << std::endl;
            }
        } else if (volba == 2) {
            Kontakt novy_kontakt;
            std::cout << "Zadejte meno: ";
            std::cin >> novy_kontakt.meno;
            std::cout << "Zadejte telefon: ";
            std::cin >> novy_kontakt.telefon;
            kontakty.push_back(novy_kontakt);
        } else if (volba == 3) {
            uloz_kontakty(soubor, kontakty);
            break;
        } else {
            std::cout << "Neplatna volba, zkuste to znovu.\n";
		}
    }
}


