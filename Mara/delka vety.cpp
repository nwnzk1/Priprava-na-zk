#include <iostream>
#include <string>
#include <fstream>



int main()
{
	std::ifstream soubor("text_test.txt");
	if(! soubor.is_open()) {
		std::cout<<"Soubor se nepodarilo otevrit." << std::endl;
		return 0;
	}

	char znak;
	std::string celej_text;

	while(soubor.get(znak)){
		if(znak !=' ') {
			celej_text += znak;
		}
	
	}
	
	int delka = celej_text.length();
	std::cout << "Delka textu je: " << delka << " znaku." << std::endl;
}

