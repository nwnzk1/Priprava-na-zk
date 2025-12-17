#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void nacti_ukoly(const std::string &HA,std::vector<std::string> &ukoly) {
    std::ifstream soubor(HA);
    if (!soubor.is_open()) {
		std::cout << "Soubor se nepodařilo otevřít." << std::endl;
    }
    std::string radek;
    while(std::getline(soubor,radek)) {
        if (!radek.empty())
            ukoly.push_back(radek);
    
    }
    

}

void uloz_ukoly(const std::string &HA,const std::vector<std::string> &ukoly) {
 std::ofstream soubor(HA);
    if (!soubor.is_open()) {
        std::cout << "Soubor se nepodařilo otevřít." <<std::endl;
    }
   for(const auto &u: ukoly) {
        soubor << u << std::endl;
   }
}


int main()
{
    int x;
    std::string soubor = "HA.txt";
	std::vector<std::string> ukoly;
	nacti_ukoly(soubor, ukoly);
	while (true) {

	std::cout << "                                        " << std::endl;
	std::cout << "      Aplikace ToDo list!" << std::endl;
    std::cout << "                                " << std::endl;
	std::cout << "Vyberte si jednu z nasledujicich moznosti:" << std::endl;
	std::cout << "1. Pridat ukol" << std::endl;
    std::cout << "2. Zobrazit ukoly" << std::endl;
	std::cout << "3. Odebrat ukol" << std::endl;
	std::cout << "4. Ukoncit aplikaci" << std::endl;
	int volba;
    std::cout << "Zde zadejte vasi volbu(Musi se jednat o cisla 1-4!!): ";
    std::cin >> volba;
        if(volba==1) {
            std::cin.ignore(); 
            std::string novy_ukol;
            std::cout << "Zadejte novy ukol: ";
            std::getline(std::cin, novy_ukol); // načte celý řádek
            ukoly.push_back(novy_ukol);        // uloží do vectoru
            uloz_ukoly(soubor, ukoly);
			/* něco tady nefunguje,protože se to neukládá do souvoru
            
            std::string novy_ukol; std::cout << "Zadejte novy ukol: "; 
            std::cin >> novy_ukol; 
            std::getline(std::cin, novy_ukol); 
            ukoly.push_back(novy_ukol); 
            uloz_ukoly(soubor, ukoly);  */

        }
        else if (volba == 2) {
            std::cout << "Seznam ukolu: " << std::endl;
            if(soubor.empty()) {
                std::cout << "Zadny ukol zde neni." << std::endl;
            }
            
            while (!ukoly.empty())
            {
                for(size_t i = 0; i < ukoly.size(); i++) {
                    std::cout << i + 1 << ". " << ukoly[i] << std::endl;
				}
				break;
            }
        }

        else if(volba==3){
			int index;
            std::cout << "Zadejte cislo ukolu,ktery checete odstranit: ";
			std::cin >> index;
            if(index < 1|| index > ukoly.size()) {
				std::cout << "Nepaltne cislo ukolu." << std::endl;
            }
            else {
                ukoly.erase(ukoly.begin() + (index - 1));
				uloz_ukoly(soubor, ukoly);
				//možná se dá zjednodušit takto
            }
        }
         else if (volba == 4) {
            break;
        }
    }
}
